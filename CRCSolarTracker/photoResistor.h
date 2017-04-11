// photoResistor.h

#ifndef _PHOTORESISTOR_h
#define _PHOTORESISTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PhotoResistorClass
{
 protected:
	 int phResisPin0;
	 int phResisPin1;
	 int phResisPin2;
	 int phResisPin3;
	 const int phResisSize = 4;
	 int phResisState[4];
 public:
	 int avg_up;	// avg of the top photoresistors
	 int avg_down; // avg of the bottom photoresistors
	 int avg_left; // avg of the left photoresistors
	 int avg_right; // avg of the right photoresistors

	void init(int, int, int, int);
	void readNewAnalogValues();
	void updateAvgValue();
};

extern PhotoResistorClass PhotoResistor;

#endif

