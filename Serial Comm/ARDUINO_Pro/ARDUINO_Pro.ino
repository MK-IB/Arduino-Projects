#include<SoftwareSerial.h>
SoftwareSerial ArduinoUno(3, 2);
void setup(){
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  pinMode(3, INPUT); 
  pinMode(2, OUTPUT);
}
void loop(){
 int val=67;
//String str="ibadat";
 ArduinoUno.print(val);
 Serial.print(val);
 Serial.print('\n');
 ArduinoUno.println("\n");
 delay(300);
}

