WiFiClient wifiClient;
PubSubClient client(wifiClient);

// long lastMsg = 0;
// char msg[50];
// int value = 0;

void setup_mqtt()
{
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.subscribe(MQTT_COMMAND_TOPIC);
  client.setCallback(mqtt_callback);
}

void loop_mqtt()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}

void mqtt_callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  mqtt_command_callback(topic, messageTemp);
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(MQTT_CLIENT_ID))
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe(MQTT_COMMAND_TOPIC);

      if (MQTT_BONJOUR_TOPIC != "")
      {
        client.publish(MQTT_BONJOUR_TOPIC, "connected");
      }
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
