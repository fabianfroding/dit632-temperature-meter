//temperature sensor
long temperature = 0;
int tempPin = A0;
int rightTemp = 0;
int leftTemp = 0;
int maxRight = 0;
int maxLeft = 0;
int currentTemp = 0;
int maxTemp = 0;

//dip switch
const int switch1 = 10;
const int switch2 = 11;

//7 segment display
int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;
int cathode1 = 8;
int cathode2 = 9;

void setup()
{
  // pinMode(tempPin, INPUT); //temp

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

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);

  // put your setup code here, to run once:
}

int getTemp()
{
  currentTemp = analogRead(tempPin);
  currentTemp = (5.0 * currentTemp * 100.0) / 1024.0;
  Serial.print(currentTemp);
  Serial.println(" degrees C");
  return currentTemp;
}

void showLeft(int left)
{
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  display(left);
}

void showRight(int right)
{
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  display(right);
}

void display(int d)
{
  if (d >= 0 || d <= 9)
  {

    switch (d)
    {
    case 1:
      Serial.println("case 1");
      digitalWrite(0, LOW);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case 2:
      Serial.println("case 2");
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    case 3:
      Serial.println("case 3");

      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    case 4:
      Serial.println("case 4");

      digitalWrite(0, LOW);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 5:
      Serial.println("case 5");

      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 6:
      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 7:
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case 8:
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;

    case 9:
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;

    default:
      Serial.println("DEFAULT");
      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    }
  }
}

void loop()
{
  int state1 = digitalRead(switch1);
  int state2 = digitalRead(switch2);
  Serial.print(state1);
  Serial.println(" state 1");
  Serial.print(state2);
  Serial.println(" state 2");

  currentTemp = getTemp();
  if (currentTemp > maxTemp)
  {
    maxTemp = currentTemp;
  }
  rightTemp = currentTemp % 10;
  leftTemp = currentTemp / 10;

  Serial.println("CurrentTemp");
  Serial.println(currentTemp);
  unsigned long startTime = millis();
  Serial.println("normal");

  for (unsigned long elapsed = 0; elapsed < 600; elapsed = millis() - startTime)
  {
    if (state1 == LOW && state2 == LOW)
    {

      showLeft(leftTemp);
      delay(5);
      showRight(rightTemp);
      delay(5);
    }
    else if (state1 == HIGH && state2 == HIGH)
    {
      int maxLeft = maxTemp / 10;
      int maxRight = maxTemp % 10;
      showLeft(maxLeft);
      delay(5);
      showRight(maxRight);
      delay(5);
    }
  }
}