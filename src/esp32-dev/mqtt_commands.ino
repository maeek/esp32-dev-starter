void mqtt_command_callback(char *topic, String json)
{
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, json);

  if (error)
  {
    Serial.print("Error: message deserialization failed");
    Serial.println(error.f_str());
    return;
  }

  if (String(topic) == MQTT_COMMAND_TOPIC)
  {
    const char *action = doc["action"];
    const char *data = doc["data"];

    if ((String)action == "gate_open")
    {
      relay_on();
      delay(1000);
      relay_off();
    }
  }
}
