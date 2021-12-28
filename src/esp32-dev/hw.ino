void setup_hw()
{
  pinMode(LED_PIN, OUTPUT);
}

void led_on()
{
  Serial.println("on");

  digitalWrite(LED_PIN, HIGH);
}

void led_off()
{
  Serial.println("off");

  digitalWrite(LED_PIN, LOW);
}