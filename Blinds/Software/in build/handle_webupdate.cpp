#include "handle_webupdate.h"

// for HTTPupdate
const char* host = "Blinds_control_side";
const char* software_version = "version 6 no MQTT";

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

// for HTTPudate
void operate()
{
  MDNS.begin(host);
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  MDNS.addService("http", "tcp", 80);

  httpServer.on("/", handleRoot);
  httpServer.on("/pre_update", handle_update);
  httpServer.onNotFound(handle_NotFound);

 if (WiFi.status() == WL_CONNECTED)     // check if WiFi connection is present
  {
    // Wifi is connected
    httpServer.handleClient();    // for HTTPupdate
  }

}

void handleRoot() {
  //Serial.println("Connected to client");
  httpServer.send(200, "text/html", SendHTML());
}
void handle_OnConnect() {
  //Serial.println("Connected to client");
  httpServer.send(200, "text/html", SendHTML());
}
void handle_update() {
  httpServer.send(200, "text/html", "<a href=\"/update\">Update</a>");
}

void handle_NotFound() {
  httpServer.send(404, "text/plain", "Not found");
}

String SendHTML() {
  String ptr = "<!DOCTYPE html><html>\n";
  ptr += "<head><meta name=\"viewport\"content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>";
  ptr += host;
  ptr += "</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 25px auto 30px;} h3 {color: #444444;margin-bottom: 30px;}\n";
  ptr += ".button {width: 150px;background-color: #1abc9c;border: none;color: white;padding: 13px 10px;text-decoration: none;font-size: 20px;margin: 0px auto 15px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-1 {background-color: #34495e;}\n";
  ptr += ".button-1:active {background-color: #2c3e50;}\n";
  ptr += ".button-2 {background-color: #0d41d1;}\n";
  ptr += ".button-2:active {background-color: #082985;}\n";
  ptr += ".button-update {background-color: #a32267;}\n";
  ptr += ".button-update:active {background-color: #961f5f;}\n";
  ptr += "p {font-size: 18px;color: #383535;margin-bottom: 15px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";

  return ptr;
}