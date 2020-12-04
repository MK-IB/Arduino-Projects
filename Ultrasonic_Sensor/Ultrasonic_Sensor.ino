const int trigPin = 9;
const int echoPin = 10;
long dur;
int dist;
void setup() {
 pinMode(13, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  dur = pulseIn(echoPin, HIGH);
  dist = dur * 0.034/2;
  Serial.print(dist);
  //Serial.print("\n");
  delay(1000);
}
