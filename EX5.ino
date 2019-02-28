long temperature = 0;
int analogPin = A0;
int dipSwitchPin1 = 10;
int dipSwitchPin2 = 11;

void setup()
{

  Serial.begin(9600);

  pinMode(dipSwitchPin1, INPUT); //dip switch
  pinMode(dipSwitchPin2, INPUT); //dip switch

  pinMode(2, OUTPUT); //7 digit display
  pinMode(3, OUTPUT); //7 digit display
  pinMode(4, OUTPUT); //7 digit display
  pinMode(5, OUTPUT); //7 digit display
  pinMode(6, OUTPUT); //7 digit display
  pinMode(7, OUTPUT); //7 digit display
  pinMode(8, OUTPUT); //7 digit display

  pinMode(9, OUTPUT);  //7 digit display
  pinMode(12, OUTPUT); //7 digit display

  digitalWrite(9, LOW);  //PIN 5 CATHODE
  digitalWrite(12, LOW); //PIN 9 CATHODE
}

int convertTemperature(int temp)
{
  //temp algorithm
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

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
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

  if (digitalRead(dipSwitchPin1) == 1)
  {
    Serial.println("HIGH");
    Serial.println(digitalRead(dipSwitchPin1));
    Serial.println(digitalRead(dipSwitchPin2));
    //show max temperature [placeholder=  1 && 1]

    display(0);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);

    delay(10);
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    display(0);
    delay(10);
  }
  else if (digitalRead(dipSwitchPin1) == 0)
  {
    Serial.println("LOW");
    Serial.println(digitalRead(dipSwitchPin1));
    Serial.println(digitalRead(dipSwitchPin2));

    //show current temperature [placeholder =  0 && 0]
    display(0);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);

    delay(10);
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    display(0);
    delay(10);
  }
  else
  {
    Serial.println("ERROR");
    Serial.println(digitalRead(dipSwitchPin1));
    Serial.println(digitalRead(dipSwitchPin2));
    //show 1 && 0
    display(1);
    digitalWrite(12, LOW);
    digitalWrite(9, HIGH);

    delay(10);
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    display(0);
    delay(10);
  }
  delay(1000);
}
