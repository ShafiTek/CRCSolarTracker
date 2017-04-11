// 
// 
// 

#include "photoResistor.h"

void PhotoResistorClass::init(int pinA, int pinB, int pinC, int pinD)
{
	phResisPin0 = pinA;
	phResisPin1 = pinB;
	phResisPin2 = pinC;
	phResisPin3 = pinD;

	pinMode(phResisPin0, INPUT); // initialize pin 0 as an output for the photoresistor
	pinMode(phResisPin1, INPUT); // initialize pin 1 as an output for the photoresistor
	pinMode(phResisPin2, INPUT); // initialize pin 2 as an output for the photoresistor
	pinMode(phResisPin3, INPUT); // initialize pin 3 as an output for the photoresistor
}

void PhotoResistorClass::readNewAnalogValues() {
	// read the state of the pushbutton value:
	phResisState[0] = analogRead(phResisPin0);
	phResisState[1] = analogRead(phResisPin1);
	phResisState[2] = analogRead(phResisPin2);
	phResisState[3] = analogRead(phResisPin3);
}

void PhotoResistorClass::updateAvgValue() {
	avg_up = (phResisState[0] + phResisState[3]) / 2; // average value top
	avg_down = (phResisState[1] + phResisState[2]) / 2; // average value down
	avg_left = (phResisState[0] + phResisState[1]) / 2; // average value left 
	avg_right = (phResisState[2] + phResisState[3]) / 2; // average value right
}

PhotoResistorClass PhotoResistor;

