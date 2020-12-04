int REL = 8;
char input;
void setup() {
  Serial.begin(9600);
  pinMode(REL, OUTPUT);

}

void loop() {
  if(Serial.available() > 0)
  {
      input = Serial.read();
    if(input == '1')
    {
      digitalWrite(REL, HIGH);
     Serial.write("Switched ON");
    }
    if(input == '2')
    {
      digitalWrite(REL, LOW);
      Serial.write("Switched OFF");
    }
  }
   //digitalWrite(REL, HIGH);
}
