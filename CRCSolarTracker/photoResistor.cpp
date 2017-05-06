// 
// 
// 

#include "photoResistor.h"

void PhotoResistorClass::init(int pinA, int pinB, int pinC)
{
	phResisPin0 = pinA;
	phResisPin1 = pinB;
	phResisPin2 = pinC;

	pinMode(phResisPin0, INPUT); // initialize pin 0 as an output for the photoresistor
	pinMode(phResisPin1, INPUT); // initialize pin 1 as an output for the photoresistor
	pinMode(phResisPin2, INPUT); // initialize pin 2 as an output for the photoresistor
}

void PhotoResistorClass::readNewAnalogValues() {
	// read the state of the pushbutton value:
	phResisState[0] = analogRead(phResisPin0);
	phResisState[1] = analogRead(phResisPin1);
	phResisState[2] = analogRead(phResisPin2);
}

void PhotoResistorClass::updateAvgValue() {
	val_north = phResisState[0]; // assign nort value
	val_southEast = phResisState[1]; // assign southEast value
	val_southWest = phResisState[2]; // assign southEast value

	north = val_north / ((val_southEast + val_southWest) / 2.0);
	southEast = val_southEast / ((val_north + val_southWest) / 2.0);
	southWest = val_southWest / ((val_southEast + val_north) / 2.0);
}

PhotoResistorClass PhotoResistor;

