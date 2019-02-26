long temperature = 0;
int tempPin = A0;

double convertTemperature(int sensor_Res)
{
  // double voltage = (sensor_Res * 5.0) / 1024; //(5*temp)/1024 is to convert the 10 bit number to a voltage reading.
  // double milliVolt = voltage * 1000;          //This is multiplied by 1000 to convert it to millivolt.

  // double tempC = (milliVolt - 500) / 10; //For TMP36 sensor. Range(−40°C to +125°C)

  double tempC = sensor_Res * 1100 / (1024 * 10);
  return tempC;
}

int i = 0;
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

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  // pinMode(tempPin, INPUT); //temp

  pinMode(2, OUTPUT); //7 digit display
  pinMode(3, OUTPUT); //7 digit display
  pinMode(4, OUTPUT); //7 digit display
  pinMode(5, OUTPUT); //7 digit display
  pinMode(6, OUTPUT); //7 digit display
  pinMode(7, OUTPUT); //7 digit display
  pinMode(8, OUTPUT); //7 digit display

  pinMode(10, OUTPUT); //7 digit display
  pinMode(11, OUTPUT); //7 digit display

  digitalWrite(10, LOW); //PIN 5 CATHODE
  digitalWrite(11, LOW); //PIN 10 CATHODE
}

void loop()
{
  // int sensor_Res = analogRead(tempPin);
  double tempC = analogRead(tempPin);
  tempC = tempC * 0.48828125;
  Serial.println(tempC);

  delay(1000);

  // display(i);
  // digitalWrite(11, LOW);  //set one digit to turned on
  // digitalWrite(10, HIGH); //the other to turned off
  // i++;
  // delay(400);
  // digitalWrite(11, HIGH);
  // digitalWrite(10, LOW);

  // display(i);
  // delay(400);
  // i++;
  // if (i == 10)
  //   i = 0;
}
