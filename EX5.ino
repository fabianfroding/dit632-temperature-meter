long temperature=0;
int analogPin=A0;

int convertTemperature(int temp){
  return 1;
}

void setup() {
  // put your setup code here, to run once:
#include <util/delay.h>

#define REG8(x) *((unsigned char *) (x))     // A macro to use for IO R/W
#define OUT_PORTD   0x2B
#define IN_PORTB    0x23
#define DDR_D       0x2A
#define DDR_B       0x24
#define BLINK_DELAY_MS  1000
#define DDRC 0xff



  

Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);

digitalWrite(10,LOW); //PIN 5 CATHODE
digitalWrite(11,LOW); //PIN 10 CATHODE
}

void loop() {
int temperature = convertTemperature (analogRead(analogPin));
Serial.println(temperature);

delay(10);

digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(10);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);

}