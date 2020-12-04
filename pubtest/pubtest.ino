#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define ssid  “Redmi 2”;
#define password  “deeku12345”;
#define mqttserver  "192.168.43.42"
#define sensor_data_topic "testing"
WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  client.setServer(mqttserver, 1883);
}

void loop() {
  if (client.connect("ESP8266Client"))
  {
  String sensor ="hello";
  client.loop();
  client.publish(sensor_data_topic, String(sensor).c_str(), true);
  Serial.println(sensor);
  }
  // put your main code here, to run repeatedly:

}
