#include  <LiquidCrystal.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#define ARMED 3
#define MODE 7
int Buffer = 0;
int MODENOW = 0;
LiquidCrystal lcd(8, 13, 9, 10, 11, 12);
void setup()
{
  pinMode(ARMED, OUTPUT);
  Serial.begin(115200);
  pinMode(MODE, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Welcome");
  delay(5000);
  lcd.clear();
  MODENOW = digitalRead(MODE);
}

void loop()
{
  if (MODENOW == HIGH)
  {
    Buffer = Serial.read();
    switch (Buffer){
      case '1':
      lcd.clear();
      lcd.print("ARMED");
      digitalWrite(ARMED,HIGH);
      break;
      case '2':
      lcd.clear();
      lcd.print("Disarmed");
      digitalWrite(ARMED,LOW);
      break;
      case '3':
      lcd.clear();
      lcd.print("Alarm Activated!");
      break;
      case'4':
      lcd.clear();
      break;
      case '5':
      lcd.clear();
      lcd.print("Relay 1 ON");
      break;
      case '6':
      lcd.clear();
      lcd.print("Relay 1 OFF");
      break;
    }
  }
  if (MODENOW == LOW) {
    lcd.clear();
    lcd.print(RTC.get());
    lcd.print(" Second");
    lcd.setCursor(0,1);
    lcd.print("since 1/1/1970");
    delay(1000);
  }
}
