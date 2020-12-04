const int usTrig = 2;

const int usEcho = 3;

const int IN1 = 7;

const int MTR1 = 8;

const int IN2 = 9;

const int MTR2 = 10;


long dur;

int dist;

char input;


void setup() {

Serial.begin(9600);

pinMode(usTrig, OUTPUT);
pinMode(usEcho, INPUT);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(MTR1, OUTPUT);
pinMode(MTR2, OUTPUT);

}

void loop() {
  moveFor();
  //ULTRASONIC 
  digitalWrite(usTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(usTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(usTrig, LOW);

  dur = pulseIn(usEcho, HIGH);
  dist = dur * 0.034/2;
  //if(dist <=25) turnRight();

  ///MOVING BY BT MODULE
 /* if(Serial.available()>0){
    input = Serial.read();
      if(input == '1') moveFor();
      else if(input == '0') halt();
      else if(input == '2') turnRight();
      else if(input == '3') turnLeft();
      else if(input == '4') moveBack();
  } */
}

void moveFor(){
  digitalWrite(IN1, LOW);
  digitalWrite(MTR1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(MTR2, HIGH);
}

void moveBack(){
  digitalWrite(IN1, LOW);
  digitalWrite(MTR1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(MTR2, HIGH);
}

void halt(){
  digitalWrite(IN1, LOW);
  digitalWrite(MTR1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(MTR2, LOW);
}
void turnRight(){
  digitalWrite(IN1, LOW);
  digitalWrite(MTR1, LOW);
  //delayMicroseconds(200);
  digitalWrite(IN2, LOW);
  digitalWrite(MTR2, HIGH);
}

void turnLeft(){
  digitalWrite(IN2, LOW);
  digitalWrite(MTR2, LOW);
  //delayMicroseconds(200);
  digitalWrite(IN1, LOW);
  digitalWrite(MTR1, HIGH);
}

