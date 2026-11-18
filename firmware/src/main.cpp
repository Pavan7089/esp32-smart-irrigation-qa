#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "HomeWiFi";
const char* password = "MyPassword123";
const char* mqtt_host = "broker.hivemq.com";

const int SOIL_PIN = 25;
const int DHT_PIN = 4;
const int RELAY_PIN = 26;

DHT dht(DHT_PIN, DHT22);
WiFiClient net;
PubSubClient mqtt(net);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  mqtt.setServer(mqtt_host, 1883);
}

void loop() {
  if (!mqtt.connected()) mqtt.connect("esp32-irrigation");
  int raw = analogRead(SOIL_PIN);
  if (raw > 2600) digitalWrite(RELAY_PIN, LOW);   // dry: pump ON
  else digitalWrite(RELAY_PIN, HIGH);             // wet: pump OFF
  char msg[64];
  snprintf(msg, sizeof(msg), "{\"soil\":%d}", raw);
  Serial.println(msg);
  mqtt.publish("farm/plot1/data", msg);
  delay(1000);
}
