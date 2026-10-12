#include <WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const int patientButton = 18;
const int nurseButton = 19;
const int ledPin = 13;

bool callActive = false;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(patientButton, INPUT_PULLUP);
  pinMode(nurseButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
}
Serial.println("WiFi Connected!");
client.setServer(mqtt_server, mqtt_port);
if (client.connect("NurseCallESP32_4240")) {
  Serial.println("MQTT Connected!");
} else {
  Serial.println("MQTT Connection Failed!");
}
}

void loop() {
  client.loop();
 if (digitalRead(patientButton) == LOW && !callActive) {
  callActive = true;
  client.publish("nursecall4240/room1", "CALL");
  Serial.println("Patient Call Sent!");
}

 if (digitalRead(nurseButton) == LOW && callActive) {
  callActive = false;
  client.publish("nursecall4240/room1", "CLEARED");
  Serial.println("Patient Call Cleared!");
}

  digitalWrite(ledPin, callActive ? HIGH : LOW);

  delay(50);
}
