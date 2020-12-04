#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <DHT_U.h>
#define wifi_ssid "Redmi"
#define wifi_password "deeku12345"
#define mqtt_server "192.168.179.1"

#define sensor_data_topic "testing"

//#define DHTPIN 13
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE, 27);
//int moist_Sensor = 0;
//int value= 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  //pinMode(D8, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
  //dht.begin();
  delay(1000);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String pay_load="";
  for (int i = 0; i < length; i++) {
    pay_load+=(char)payload[i];
  }
  Serial.print(pay_load);
  Serial.println();

  if (pay_load == "on") {
    Serial.print("Turning On");
   digitalWrite(D8, HIGH);
  } 
  else {
    digitalWrite(D8, LOW);
  }

}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // if (client.connect("ESP8266Client")) {
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe("testing");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

String temp;
String hum;
String moist;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
 // int t = dht.readTemperature();
  //int h = dht.readHumidity();
  //int m = analogRead(moist_Sensor);
  //m = m/20;
  //temp=String(t).c_str();
  //hum=String(h).c_str();
  //moist=String(m).c_str();
  String sensor = "Message From NODE MCU";
  
 // if (isnan(h) || isnan(t)) {
    //Serial.println("Failed to read from DHT sensor!");
    //return;
 // }
  Serial.println(sensor);
  client.loop();
  client.publish(sensor_data_topic, String(sensor).c_str(), true);
  delay(3000);
}
