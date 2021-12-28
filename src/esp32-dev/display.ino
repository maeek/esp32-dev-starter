#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
//definiujemy piny I2C, do&nbsp;których&nbsp;podłączony został wyświetlacz
#define OLED_SDA 21
#define OLED_SCL 22


Adafruit_SH1106 display(21, 22);

void print_on_screen(String message)
{
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(message);
  display.display();
}
