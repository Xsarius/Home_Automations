////////////////////////////////////////////////////
// Configuration file of automated blinds module //
//////////////////////////////////////////////////

////////////////////
// Network Setup //
//////////////////

// WiFi //
// Make sure to update this for your own WiFi network!
#define ssid "SynologySmartConnect"
#define wifi_password "bsdM7XmzWd4uP4f"
#define WIFI_CONNECT_TIMEOUT_S 5

// MQTT //
// Make sure to update this for your own MQTT Broker!
#define mqtt_server "192.168.1.4"
#define mqtt_port 1883
#define mqtt_username "openhabian"
#define mqtt_password "openhabian"
#define percentage_topic "esp8266/livingroom/blinds/state"

// The client id identifies the ESP8266 device. Think of it a bit like a name, like Greg.
#define clientID "ESP8266_1"

/* Write down used names in your network (server doesn't differ them automatically) :
ESP8266_1
ESP8266_2
*/

// Serial //
#define serial_baudrate 115200

//////////////////
// Motor Setup //
////////////////

// Steps //
#define MAX_STEPS 14400 //maximum number of steps

/* Maximum number of motors connected to one NodeMCUv3(ESP8266-12E) is 2, 
   however there are 3 GPIO pins left (D0, TX, RX) which can be used freely, 
   TX, RX needs to be switched by adding pinMode(RX, FUNCTION_3) in the beggining of the program.
   See https://github.com/esp8266/Arduino/issues/584 for more details. */

// Motor 1 pins //
#define MOTOR1_PIN1 D1
#define MOTOR1_PIN2 D2
#define MOTOR1_PIN3 D3
#define MOTOR1_PIN4 D4

// Motor 2 pins //
#define MOTOR2_PIN1 D5
#define MOTOR2_PIN2 D6
#define MOTOR2_PIN3 D7
#define MOTOR2_PIN4 D8
