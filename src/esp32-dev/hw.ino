void setup_hw()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void led_on()
{
  Serial.println("LED on");

  digitalWrite(LED_PIN, HIGH);
}

void led_off()
{
  Serial.println("LED off");

  digitalWrite(LED_PIN, LOW);
}

void relay_on()
{
  Serial.println("Relay on");

  digitalWrite(RELAY_PIN, HIGH);
}

void relay_off()
{
  Serial.println("Relay off");

  digitalWrite(RELAY_PIN, LOW);
}
