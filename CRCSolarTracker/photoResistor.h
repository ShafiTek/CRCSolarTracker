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


 public:
	void init();
};

extern PhotoResistorClass PhotoResistor;

#endif

