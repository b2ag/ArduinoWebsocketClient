#include "Arduino.h"
#include <WiFi.h>
#include <SPI.h>
#include <WebSocketClient.h>

char ssid[] = "networkSSID";
char pass[] = "password";

char server[] = "echo.websocket.org";
WebSocketClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.connect(server);
  client.setDataArrivedDelegate(dataArrived);
  client.send("Hello World!");
}

void loop() {
  client.monitor();
}

void dataArrived(WebSocketClient client, String data) {
  Serial.println("Data Arrived: " + data);
}
