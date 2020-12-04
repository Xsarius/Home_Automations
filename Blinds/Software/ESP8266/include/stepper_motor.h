// Library controlling movement of 28byj_28 stepper motor (5V)	//
// with ULN2003 driver.											//

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "handle_connection.h"

extern int current_steps
;

class stepper_28BYJ_48 {
public:

	int pin1, pin2, pin3, pin4;

	void setUp(int, int, int, int);
    void revolution(int);
   

private:
	void setOutput(int);
	int lookup[8] = {HIGH, LOW, LOW, LOW};
    int motorStepDelay = 3;  //variable to set stepper speed in miliseconds [ms]
	int countStPerRev = 2038; // number of steps per full revolution

};
