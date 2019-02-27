long temperature = 0;
int tempPin = 0;
const int switch1 = 12;
int rightTemp = 0;
int leftTemp = 0;
int currentTemp = 0;
int state = HIGH;
int firstRead = 1;
int maxTemp = 0;
void setup()
{
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

  pinMode(switch1, INPUT_PULLUP);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int getTemp(){
  int currentTemp = analogRead(tempPin);
  currentTemp = (5.0 * currentTemp * 100.0)/1024.0;
  if(firstRead){
    maxTemp = currentTemp;
    firstRead = 0;
  }
  return currentTemp;
}

void show(int left, int right){
  if(left == 0){
    showRight();
    display(right);
  } else {
      showRight();
      display(right);
      delay(10);
      showLeft();
      display(left);
      delay(10);
  }
}

void showLeft(){
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void showRight(){
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

}

void loop(){
  state = digitalRead(switch1);
  currentTemp = getTemp();
    if(currentTemp > maxTemp){
      maxTemp = currentTemp;
    }
    rightTemp = currentTemp % 10;
    leftTemp = currentTemp / 10;

  if(state == HIGH){

    show(leftTemp, rightTemp);
  }else{
    int maxLeft = maxTemp / 10;
    int maxRight = maxTemp % 10;
    show(maxLeft, maxRight);
  }
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

