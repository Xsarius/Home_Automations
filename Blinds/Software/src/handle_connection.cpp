#include "handle_connection.h"

WiFiClient wifiClient;

PubSubClient client(mqtt_server, mqtt_port, wifiClient);

bool Connect()
{
  // Connect to MQTT Server and subscribe to the topic
  if (client.connect(clientID, mqtt_username, mqtt_password))
  {
    delay(100);
    Serial.println("Connected Successfully to (" mqtt_server ") MQTT Broker!");

    if (client.subscribe(percentage_topic))
    {
      Serial.println("Subscribed successfully to Blinds Status topic!");
    }

    else
    {
      Serial.println("Subscribtion to Blinds Status topic could not be established!");
    }

    return true;
  }
  delay(100);
  Serial.println("Connection Failed!");
  return false;
}

void setup_wifi()
{
  // Connect to WiFi network
  delay(10);
  WiFi.begin(ssid, wifi_password);
  // Wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // Output the IP Address of the ESP8266
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}