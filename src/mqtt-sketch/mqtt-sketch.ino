void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  setup_wifi();
  setup_mqtt();
  setup_hw();
}

void loop()
{
  loop_mqtt();
}
