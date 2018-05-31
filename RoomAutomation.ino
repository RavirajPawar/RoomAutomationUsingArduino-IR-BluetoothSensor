#include <LiquidCrystal.h> //include LCD library (standard library)
#define redLED 13 //define the LED pins

int position = 0; //keypad position
#define IR1 4
#define IR2 5
#define led 13
int read = 0;
int count = 0;
int v = 2;

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);
// pins of the LCD. (RS, E, D4, D5, D6, D7)

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("    WELCOME");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   PERSON");
  lcd.setCursor(0, 1);
  lcd.print("COUNT :           ");
  Serial.print("COUNT   :");
  lcd.setCursor(9, 1);
  lcd.print(count);
  Serial.println(count);


}

void loop()
{

  if (digitalRead(IR1) == LOW)
  {
    delay(200);
    if (digitalRead(IR2) == LOW)
    {
      v = 1;
      count++;
    }
  }
  else if (digitalRead(IR2) == LOW)
  {
    delay(200);
    if (digitalRead(IR1) == LOW)
    {
      v = 1;
      count--;
    }
  }


  else
  {
    
    if (count > 0)
    {
      if (Serial.available() > 0)
      {
        char data = Serial.read();

        switch (data)
        {

          case 'U' :  digitalWrite(led, HIGH); break;
          case 'D' :  digitalWrite(led, LOW); break;
          case 'L' :  break;
          case 'R' :  break;
          case 'C' :   break;
          case 'a' :   break;
          case 'd' : break;

          default : break;
        }


        Serial.println(data);
      }
    }
    else
    digitalWrite(led, LOW);

    if ( v == 1)
    {
      lcd.setCursor(0, 1);
      lcd.print("COUNT :            ");
      Serial.print("COUNT   :");
      lcd.setCursor(9, 1);
      lcd.print(count);
      Serial.println(count);
      v = 2;
    }
  }
}


