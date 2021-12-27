#include <WiFi.h>
#include <PubSubClient.h>

// SETUP VARS
const char *ssid = "";
const char *passphrase = "";
IPAddress server(10, 20, 5, 1);
const int port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;

const int ledPin = 2;

void setup_wifi()
{
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, passphrase);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();

  client.setServer(server, port);
  client.subscribe("esp32-output");
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);
}

void callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32-output, you check if the message is either "on" or "off".
  // Changes the output state according to the message
  if (String(topic) == "esp32-output")
  {
    Serial.print("Changing output to ");
    if (messageTemp == "on")
    {
      Serial.println("on");
      digitalWrite(ledPin, HIGH);
    }
    else if (messageTemp == "off")
    {
      Serial.println("off");
      digitalWrite(ledPin, LOW);
    }
  }
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client"))
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32-output");
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
void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  // long now = millis();
  // if (now - lastMsg > 5000)
  // {
  //   lastMsg = now;

  //   client.publish("esp32/test", "connected");
  // }
}
