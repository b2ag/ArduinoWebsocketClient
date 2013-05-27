#include "Arduino.h"
#include <WiFi.h>
#include <SPI.h>
#include <WebSocketClient.h>

char ssid[] = "networkSSID";
char pass[] = "password";

char server[] = "echo.websocket.org";
char path[] = "/";
int port = 80;
WebSocketClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.connect(server, path, port);
  client.setDataArrivedDelegate(dataArrived);

  client.sendMessage("Hello World");
}

void loop() {
  client.catchMessages();
}

void dataArrived(WebSocketClient client, String data) {
  Serial.println("Data Arrived: " + data);
}
