# Tarsier RPI-1031 Direction Sensor.

![Image2](documentation/RPI-1031.png?raw=true "RPI-1031 Direction Sensor")

A minimal *Arduino library* for **RPI-1031** Direction Sensor. 

*RPI-1031 4-Direction Sensor* detects X & Y tilt or motion in 4 quadrant direction. two-bit logic outputs latches and indicates the most recent motion direction.

## Documentation

- `Tarsier_RPI_1031()` <br> Default constructor, selects the
  default pins as connected by the digital pins *4* and *5*.
- `Tarsier_RPI_1031(byte S1_Pin, byte S2_Pin)` <br>
  Alternate constructor for connections remapped by user on its desired configuration.
- `void setPins(byte S1_Pin, byte S2_Pin)` <br> Another alternate way to configure pin connection of the Arduino board to RPI-1031 4-Direction Sensor.
- `enum Direction getDirection()` <br> function to get the tilt position of the sensor. It returns four directions such **TOP**, **RIGHT**, **LEFT** and **BOTTOM**.

## Example
A simple demo on how to use this libray, or see [example](https://github.com/Tarsier-Marianz/Tarsier_RPI_1031/tree/master/examples) folder of this repo.
```c++

#include "Tarsier_RPI_1031.h"

int TILT_S1_PIN    = 4;
int TILT_S2_PIN    = 5;

Tarsier_RPI_1031 _dir_Sensor(TILT_S1_PIN, TILT_S2_PIN);

void setup(){
    Serial.begin(9600);
    // alternate way of pin configuration
    // if not set (S1 & S2 pins) in constructor
    //_dir_Sensor.setPins(TILT_S1_PIN, TILT_S2_PIN);
}

void loop(){
    Serial.print("Direction: ");
    Serial.println(_dir_Sensor.getDirection());
}

```
