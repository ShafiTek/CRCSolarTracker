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
	 const int phResisSize = 3;
 public:
	 int phResisState[3];
	 int val_north;	// value of the top photoresistors (0-1023)
	 int val_southEast; // value of the south east photoresistor (0-1023)
	 int val_southWest; // value of the left photoresistors (0-1023)

	 double north;	// value of the top photoresistors (0-1023)
	 double southEast; // value of the south east photoresistor (0-1023)
	 double southWest; // value of the left photoresistors (0-1023)

	void init(int, int, int);
	void readNewAnalogValues();
	void updateAvgValue();
};

extern PhotoResistorClass PhotoResistor;

#endif

