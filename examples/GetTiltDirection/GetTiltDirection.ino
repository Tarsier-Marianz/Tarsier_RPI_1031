#include "Tarsier_RPI_1031.h"

Tarsier_RPI_1031 _direction_Sensor(4, 5);

void setup()
{
    Serial.begin(9600);
    //_direction_Sensor.setPins(4, 5);     // alternative way of pin configuration
}

void loop()
{
    Serial.print("Direction: ");
    Serial.println(_direction_Sensor.getDirection());
}