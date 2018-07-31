/* 
* Tarsier_RPI_1031.h
*
* Created: 07/25/2018 12:07:32 PM
* Author: TARSIER
*/

#ifndef __Tarsier_RPI_1031_H__
#define __Tarsier_RPI_1031_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#define S1_PIN 4 // set default to digital pin4
#define S2_PIN 5 // set default to digital pin5

typedef enum Direction{
	TOP,
	RIGHT,
	LEFT,
	BOTTOM,
} Direction;

class Tarsier_RPI_1031{	
  public : 
    Tarsier_RPI_1031();
	Tarsier_RPI_1031(byte S1_Pin, byte S2_Pin);
	void setPins(byte S1_Pin, byte S2_Pin);
	enum Direction getDirection(void);

  protected:
  private:	
	byte _S1Pin;
	byte _S2Pin;
	int getTiltPosition(void);

}; //Tarsier_RPI_1031

#endif //__Tarsier_RPI_1031_H__
