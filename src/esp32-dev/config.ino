// Wifi
const char *WIFI_SSID = "";
const char *WIFI_PASSPHRASE = "";

// MQTT
// const char *MQTT_SERVER = "";
IPAddress MQTT_SERVER(10, 20, 5, 1);
const int MQTT_PORT = 1883;
const char *MQTT_USER = "guest";
const char *MQTT_PASSWORD = "guest";
const char *MQTT_CLIENT_ID = "esp32";
const char *MQTT_BONJOUR_TOPIC = "";
const char *MQTT_COMMAND_TOPIC = "esp32-output";
const char *MQTT_STATE_TOPIC = "esp32-input";

// PINS & GPIO
const int LED_PIN = 2;
