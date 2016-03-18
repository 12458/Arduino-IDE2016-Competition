#include  <LiquidCrystal.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#define ARMED 3
#define MODE 4
int Buffer = 0;
int MODENOW = 0;
LiquidCrystal lcd(8, 12, 9, 10, 11, 12);
void setup()
{
  pinMode(ARMED, OUTPUT);
  Serial.begin(115200);
  pinMode(MODE, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print('Welcome');
  delay(5000);
  lcd.clear();
  MODENOW = digitalRead(MODE);
}

void loop()
{
  if (MODENOW == HIGH)
  {
    Buffer = Serial.read();
    if (Buffer == '1')
    {
      lcd.clear();
      lcd.print('ARMED');
    }
    if (Buffer == '2')
    {
      lcd.clear();
      lcd.print('Disarmed');
    }
    if (Buffer == '3') {
      lcd.clear();
      lcd.print('Alarm Activated');
    }
  }
  if (MODENOW == LOW) {
    lcd.clear();
    lcd.print(RTC.get());
  }
}
