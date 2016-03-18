#define relay1 8
#define relay2 9
#define relay3 10
#define LDR A0
#define Buzzer 11
#define Laser 2
#define RX A2
#define TX A3
#define LDRtrigger 100
#define delaytime 5000
#define armedled 12
int Buffer = 0;
int LDRvalue = 0;
byte arm = 0;
void setup()
{
  Serial.begin(115200);
  pinMode(LDR, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Laser, OUTPUT);
  pinMode(armedled, OUTPUT);
}

void loop()
{
  Buffer = Serial.read();
  switch (Buffer) {
    case '1':
      digitalWrite(relay1, HIGH);
      //Serial.println("relay1=on");
      Serial.print("5");
      break;
    case '2':
      //Serial.println("Armed");
      arm = 1;
      digitalWrite(armedled, HIGH);
      digitalWrite(Laser, HIGH);
      Serial.print("1");
      break;
    case '3':
      //Serial.println("Unarmed");
      arm = 0;
      digitalWrite(armedled, LOW);
      digitalWrite(Laser, LOW);
      Serial.print("2");
      break;
    case '4':
      digitalWrite(relay1, LOW);
      //Serial.println("relay1=off");
      Serial.print("6");
      break;
    case '5':
      digitalWrite(relay2, HIGH);
      //Serial.println("relay2=on");
      break;
    case '6':
      digitalWrite(relay2, LOW);
      //Serial.println("relay2=off");
      break;
    case '7':
      digitalWrite(relay3, HIGH);
      //Serial.println("relay3=on");
      break;
    case '8':
      digitalWrite(relay3, LOW);
      //Serial.println("relay3=off");
      break;
  }
  LDRvalue = analogRead(LDR);
  if (LDRvalue == LDRtrigger && arm == 1)
  {
    digitalWrite(Buzzer, HIGH);
    //Serial.println("ALARM!!!");
    Serial.print("3");
    delay(delaytime);
    digitalWrite(Buzzer, LOW);
  }
}

