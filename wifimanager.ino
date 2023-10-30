#define BLYNK_TEMPLATE_ID "TMPL3LYW2c3o-"
#define BLYNK_TEMPLATE_NAME "ledControl"
#define BLYNK_AUTH_TOKEN "8drrZE13ByA7ORDg63zmlUW_DDYCpQ39"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <BlynkSimpleEsp8266.h>

const int flashButtonPin = 0; 

void setup() {
  Serial.begin(115200);

  pinMode(flashButtonPin, INPUT);
  pinMode(D8, OUTPUT);

  WiFiManager wifiMn;

  if (!wifiMn.autoConnect("Esp Web Portal")) {
    Serial.println("Failed to connect and hit timeout");
    ESP.reset();
    delay(1000);
  }
  Serial.println("Connected to Wi-Fi!");

  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();
}

void loop() {
  Blynk.run();
  if (digitalRead(flashButtonPin) == LOW) {
    WiFiManager wifiMn;
    wifiMn.resetSettings();
     ESP.reset();
    Serial.println("WiFi settings reset");
    delay(1000); 
  }
  //Your code here
}

BLYNK_WRITE(V0){
  param.asInt() ? digitalWrite(D8, HIGH):  digitalWrite(D8, LOW);
}
