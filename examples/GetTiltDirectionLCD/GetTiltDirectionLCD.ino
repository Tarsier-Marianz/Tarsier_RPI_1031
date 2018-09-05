#include "Tarsier_RPI_1031.h"
#include <LiquidCrystal.h>

LiquidCrystal _lcd(12, 11, 5, 4, 3, 2);
Tarsier_RPI_1031 _direction_Sensor(8, 9);

void setup() {
  Serial.begin(9600);
  _lcd.begin(16, 2);
  _lcd.home();
  //_direction_Sensor.setPins(8, 9);     // alternative way of pin configuration
}

void loop() {
  float direction = _direction_Sensor.getDirection();
  Serial.print("Direction: ");
  Serial.println(direction);
  _lcd.setCursor(0, 0);
  _lcd.print("Direction: ");
  _lcd.setCursor(0, 1);
  _lcd.print(direction);
}