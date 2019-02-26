long temperature = 0;
int analogPin = A0;
int dipSwitchPin1 = 10;
int dipSwitchPin2 = 11;

int val = -1; //dip switch value

void setup()
{
  // put your setup code here, to run once:
#include <util/delay.h>

#define REG8(x) *((unsigned char *)(x)) // A macro to use for IO R/W
#define OUT_PORTD 0x2B
#define IN_PORTB 0x23
#define DDR_D 0x2A
#define DDR_B 0x24
#define BLINK_DELAY_MS 1000
#define DDRC 0xff

  Serial.begin(9600);

  pinMode(dipSwitchPin1, INPUT_PULLUP); //dip switch
  pinMode(dipSwitchPin2, INPUT_PULLUP); //dip switch

  pinMode(2, OUTPUT); //7 digit display
  pinMode(3, OUTPUT); //7 digit display
  pinMode(4, OUTPUT); //7 digit display
  pinMode(5, OUTPUT); //7 digit display
  pinMode(6, OUTPUT); //7 digit display
  pinMode(7, OUTPUT); //7 digit display
  pinMode(8, OUTPUT); //7 digit display

  pinMode(9, OUTPUT);  //7 digit display
  pinMode(11, OUTPUT); //7 digit display

  digitalWrite(9, LOW);  //PIN 5 CATHODE
  digitalWrite(11, LOW); //PIN 9 CATHODE
}

int convertTemperature(int temp)
{
  return 1;
}

void display(int d)
{
  if (d >= 0 || d <= 9)
  {
    Serial.println("ciao");
    switch (d)
    {
    case 1:
      Serial.println("case 1");
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;
    case 2:
      Serial.println("case 2");
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 3:
      Serial.println("case 3");

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 4:
      Serial.println("case 4");

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;
    case 5:
      Serial.println("case 5");

      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 6:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 7:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;
    case 8:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;

    case 9:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      break;

    default:
      Serial.println("DEFAULT");
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      break;
    }
  }
}

void loop()
{
  Serial.println("TEST");
  if (digitalRead(dipSwitchPin1) == HIGH && digitalRead(dipSwitchPin2) == HIGH)
  {
    Serial.println("HIGH");
  }
  else
  {
    Serial.println("LOW");
  }
  display(1);
  digitalWrite(11, LOW); //set one digit to turned on
  digitalWrite(9, HIGH); //the other to turned off

  delay(10);
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  display(3);
  delay(10);
}