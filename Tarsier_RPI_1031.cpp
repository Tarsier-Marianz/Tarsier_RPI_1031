/*
* Tarsier_RPI_1031.cpp
* 
* Created: 07/31/2018 12:07:32 PM
* Author: TARSIER
*/

#include "Tarsier_RPI_1031.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// default constructor
Tarsier_RPI_1031::Tarsier_RPI_1031()
{
  this->setPins(S1_PIN, S2_PIN);
}

Tarsier_RPI_1031::Tarsier_RPI_1031(byte S1_Pin, byte S2_Pin)
{
  this->setPins(S1_Pin, S2_Pin);
} //Tarsier_RPI_1031

void Tarsier_RPI_1031::setPins(byte S1_Pin, byte S2_Pin)
{
  this->_S1Pin = S1_Pin;
  this->_S2Pin = S2_Pin;
  pinMode(this->_S1Pin, INPUT);
  pinMode(this->_S2Pin, INPUT);
}

int Tarsier_RPI_1031::getTiltPosition(void)
{
  int S1 = digitalRead(this->_S1Pin);
  int S2 = digitalRead(this->_S2Pin);
  return (S1 << 1) | S2; //BITWISE MATH
}

enum Direction Tarsier_RPI_1031::getDirection()
{
  int position = this->getTiltPosition();
  if (position == 1)
  {
    return LEFT;
  }
  else if (position == 2)
  {
    return RIGHT;
  }
  else if (position == 3)
  {
    return BOTTOM;
  }
  else
  {
    // means position is 0
    return TOP;
  }
}
