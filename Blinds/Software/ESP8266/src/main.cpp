#include "EasyOTA.h"
#include "handle_connection.h"
#include "handle_input.h"
#include "data_saver.h"

int current_steps;
int target_steps;
int current_target_steps;

EasyOTA OTA(clientID);

void setup()
{

  // Debugging purpose - can be deeted afterwards to optimize software
  Serial.begin(serial_baudrate);
  Serial.println("Device:" clientID);
  Serial.println("Connecting to " ssid);
  SPIFFS.begin();

  OTA.onMessage([](const String &message, int line) {
    Serial.println(message);
  });

  OTA.addAP(ssid, wifi_password);

  // setCallback sets the function to be called when a message is received.
  client.setCallback(getTarget);

  // Connect to MQTT Broker //
  if (ConnectToMQTT())
  {
    motorPinSetup();
    lowerMotorPins();
  }

  // Read last available blinds position
  current_steps = ReadBackup();
  // Making sure it makes sense
  if (current_steps < 0)
  {
    current_steps = 0;
  }

  Serial.println(current_steps);

  target_steps = 0;
}

void loop()
{

  // If the connection is lost, try to connect again
  if (!client.connected())
  {
    ConnectToMQTT();
    motorPinSetup();
    lowerMotorPins();
  }

  // client.loop() just tells the MQTT client code to do what it needs to do itself (i.e. check for messages, etc.)
  client.loop();

  target_steps = current_target_steps;

  // Handle the message we received
  while (current_steps != target_steps)
  {
    motor1.revolution(target_steps - current_steps);
    motor2.revolution(target_steps - current_steps);

    client.loop();
    if (current_target_steps != target_steps)
    {
      break;
    }
    SaveCurrentPosition(current_steps);
  }
  if (current_steps == target_steps)
  {
    lowerMotorPins();
  }
}