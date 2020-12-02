
#include <Arduino.h>      // Standard arduino library
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <PubSubClient.h> // Allows us to connect to, and publish to the MQTT broker
#include "config.h"       // Configuration settings

void setup_wifi();

bool Connect(); 

extern WiFiClient wifiClient; 
extern PubSubClient client; // MQTT client