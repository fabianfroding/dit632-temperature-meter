long temperature=0;
int analogPin=A0;

int convertTemperature(int temp){
  return (temp-32)*5/9;
}

void setup() {
  // put your setup code here, to run once:
#include <util/delay.h>

#define REG8(x) *((unsigned char *) (x))     // A macro to use for IO R/W
#define OUT_PORTD   0x2B
#define IN_PORTB    0x23
#define DDR_D       0x2A
#define DDR_B       0x24
#define BLINK_DELAY_MS  300
#define DDRC 0xff



//set port D to output=ff
REG8(DDR_D)=0xFF;
//set port B to input=0
REG8(DDR_B)=0x00;
Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(8,HIGH);

int temperature = convertTemperature (analogRead(analogPin));
Serial.println(temperature);
    _delay_ms(BLINK_DELAY_MS); // In util/delay.h

}
