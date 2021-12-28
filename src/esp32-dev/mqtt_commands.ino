#include <ArduinoJson.h>

void mqtt_command_callback(char *topic, StaticJsonDocument<200> json)
{
  if (String(topic) == MQTT_COMMAND_TOPIC)
  {
    if (json["action"] == "on")
    {
      led_on();
    }
    else if (json["action"] == "off")
    {
      led_off();
    }
  }
}
