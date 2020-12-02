
#include "config.h"
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

extern const char* host;
extern const char* software_version;

extern ESP8266WebServer httpServer(80);
extern ESP8266HTTPUpdateServer httpUpdater;

void operate();