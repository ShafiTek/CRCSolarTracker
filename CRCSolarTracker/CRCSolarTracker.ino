/*
 Name:		CRCSolarTracker.ino
 Created:	3/23/2017 8:02:43 PM
 Authors:	Alex, Yoosuf
*/

#include "photoResistor.h"
using namespace std;
/*
	PHOTORESISTOR POSITIONS
			0 (NORTH)
----------------------------------
1(SOUTH/EAST)	|	2 (SOUTH/WEST)
*/

/********
VARIABLES
*********/
#define m1A 4
#define m1B 5
#define m2A 6
#define m2B 7
#define m3A 8
#define m3B 9
const int delaySec = 75;
const int delaySecLong = 500;

/******
OBJECTS
*******/
PhotoResistorClass photoResistor; // instantiate the photoResistor class

/********************
FUNCTION DECLARATIONS
********************/
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);	// begin serial communication

	/* CHANGE PHOTORESISTOR PIN NUMBERS HERE */
	photoResistor.init(A0, A1, A2); // initialize the photoresistors with analong pin numbers

	/*CHANGE MOTOR PINS HERE*/
	pinMode(m1A, OUTPUT);
	pinMode(m1B, OUTPUT);
	pinMode(m2A, OUTPUT);
	pinMode(m2B, OUTPUT);
	pinMode(m3A, OUTPUT);
	pinMode(m3B, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	photoResistor.readNewAnalogValues(); // update the value of the photoresistors upon every iteration
	photoResistor.updateAvgValue(); // update the average value of the photoresistors upon every iteration

	Serial.println("+++++++++++");
	Serial.print("Ph North: ");
	Serial.println(photoResistor.north);
	Serial.print("Ph SouthEast: ");
	Serial.println(photoResistor.southEast);
	Serial.print("Ph SouthWest: ");
	Serial.println(photoResistor.southEast);

	Serial.print("VAL North: ");
	Serial.println(photoResistor.val_north);
	Serial.print("VAL SouthEast: ");
	Serial.println(photoResistor.val_southEast);
	Serial.print("VAL SouthWest: ");
	Serial.println(photoResistor.val_southWest);
	Serial.println("+++++++++++");

	if (photoResistor.north >= 1.10) {
		// Position MOTOR
		digitalWrite(m1A, HIGH);
		delay(delaySec);
		digitalWrite(m1A, LOW);
		delay(delaySec);
		digitalWrite(m2B, HIGH);
		delay(delaySec);
		digitalWrite(m2B, LOW);
		delay(delaySec);
		digitalWrite(m3B, HIGH);
		delay(delaySec);
		digitalWrite(m3B, LOW);
		delay(delaySecLong);
	}
	else if (photoResistor.north < 0.90) {
		digitalWrite(m1B, HIGH);
		delay(delaySec);
		digitalWrite(m1B, LOW);
		delay(delaySec);
		digitalWrite(m2A, HIGH);
		delay(delaySec);
		digitalWrite(m2A, LOW);
		delay(delaySec);
		digitalWrite(m3A, HIGH);
		delay(delaySec);
		digitalWrite(m3A, LOW);
		delay(delaySecLong);
	}

	if (photoResistor.southEast >= 1.10) {
		digitalWrite(m2A, HIGH);
		delay(delaySec);
		digitalWrite(m2A, LOW);
		delay(delaySec);
		digitalWrite(m1B, HIGH);
		delay(delaySec);
		digitalWrite(m1B, LOW);
		delay(delaySec);
		digitalWrite(m3B, HIGH);
		delay(delaySec);
		digitalWrite(m3B, LOW);	
		delay(delaySecLong);
	}
	else if (photoResistor.southEast < 0.90) {
		digitalWrite(m2B, HIGH);
		delay(delaySec);
		digitalWrite(m2B, LOW);
		delay(delaySec);
		digitalWrite(m1A, HIGH);
		delay(delaySec);
		digitalWrite(m1A, LOW);
		delay(delaySec);
		digitalWrite(m3A, HIGH);
		delay(delaySec);
		digitalWrite(m3A, LOW);
		delay(delaySecLong);
	}

	if (photoResistor.southWest >= 1.10) {
		digitalWrite(m3A, HIGH);
		delay(delaySec);
		digitalWrite(m3A, LOW);
		delay(delaySec);
		digitalWrite(m1B, HIGH);
		delay(delaySec);
		digitalWrite(m1B, LOW);
		delay(delaySec);
		digitalWrite(m2B, HIGH);
		delay(delaySec);
		digitalWrite(m2B, LOW);
		delay(delaySecLong);
	}
	else if (photoResistor.southWest < 0.90) {
		digitalWrite(m3B, HIGH);
		delay(delaySec);
		digitalWrite(m3B, LOW);
		delay(delaySec);
		digitalWrite(m1A, HIGH);
		delay(delaySec);
		digitalWrite(m1A, LOW);
		delay(delaySec);
		digitalWrite(m2A, HIGH);
		delay(delaySec);
		digitalWrite(m2A, LOW);
		delay(delaySecLong);
	}
	//delay(300);
	// This will move stepper incrementally.
}