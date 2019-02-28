//temp
long temperature = 0;
int analogPin = A0;
//dip switch
int dipSwitchPin1 = 10;
int dipSwitchPin2 = 11;
//led
int cathode1 = 8;
int cathode2 = 9;
int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;

void setup()
{

  Serial.begin(9600);

  pinMode(dipSwitchPin1, INPUT); //dip switch
  pinMode(dipSwitchPin2, INPUT); //dip switch

  pinMode(a, OUTPUT);          //7 digit display
  pinMode(b, OUTPUT);          //7 digit display
  pinMode(c, OUTPUT);          //7 digit display
  pinMode(d, OUTPUT);          //7 digit display
  pinMode(e, OUTPUT);          //7 digit display
  pinMode(f, OUTPUT);          //7 digit display
  pinMode(g, OUTPUT);          //7 digit display
  pinMode(cathode1, OUTPUT);   //7 digit display
  pinMode(cathode2, OUTPUT);   //7 digit display
  digitalWrite(cathode1, LOW); //PIN 5 CATHODE
  digitalWrite(cathode2, LOW); //PIN 9 CATHODE
}

int convertTemperature(int temp)
{
  //temp algorithm
  return 1;
}

void display(int number)
{
  if (number >= 0 || number <= 9)
  {
    Serial.println("ciao");
    switch (number)
    {
    case 1:
      Serial.println("case 1");
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 2:
      Serial.println("case 2");
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 3:
      Serial.println("case 3");

      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 4:
      Serial.println("case 4");

      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 5:
      Serial.println("case 5");

      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;

    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;

    default:
      Serial.println("DEFAULT");
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    }
  }
}

void loop()
{

  // if (digitalRead(dipSwitchPin1) == 1)
  // {
  //   Serial.println("HIGH");
  //   Serial.println(digitalRead(dipSwitchPin1));
  //   Serial.println(digitalRead(dipSwitchPin2));
  //   //show max temperature [placeholder=  1 && 1]

  //   display(0);
  //   digitalWrite(12, LOW);
  //   digitalWrite(9, HIGH);

  //   delay(10);
  //   digitalWrite(12, HIGH);
  //   digitalWrite(9, LOW);
  //   display(0);
  //   delay(10);
  // }
  // else if (digitalRead(dipSwitchPin1) == 0)
  // {
  //   Serial.println("LOW");
  //   Serial.println(digitalRead(dipSwitchPin1));
  //   Serial.println(digitalRead(dipSwitchPin2));

  //   //show current temperature [placeholder =  0 && 0]
  //   display(0);
  //   digitalWrite(12, LOW);
  //   digitalWrite(9, HIGH);

  //   delay(10);
  //   digitalWrite(12, HIGH);
  //   digitalWrite(9, LOW);
  //   display(0);
  //   delay(10);
  // }
  // else
  // {
  //   Serial.println("ERROR");
  //   Serial.println(digitalRead(dipSwitchPin1));
  //   Serial.println(digitalRead(dipSwitchPin2));
  //   //show 1 && 0
  //   display(1);
  //   digitalWrite(12, LOW);
  //   digitalWrite(9, HIGH);

  //   delay(10);
  //   digitalWrite(12, HIGH);
  //   digitalWrite(9, LOW);
  //   display(0);
  //   delay(10);
  // }

  display(1);
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);

  delay(10);
  digitalWrite(cathode1, HIGH);
  digitalWrite(cathode2, LOW);
  display(0);
  delay(10);
  delay(1000);
}