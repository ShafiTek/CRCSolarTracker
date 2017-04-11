/*
 Name:		CRCSolarTracker.ino
 Created:	3/23/2017 8:02:43 PM
 Authors:	Alex, Yoosuf
*/

#include "photoResistor.h"
#include "Stepper.h"
using namespace std;

/*
		PHOTORESISTOR POSITIONS
	0(UP/LEFT)		|	 3(UP/RIGHT)
	----------------------------------
	1(DOWN/LEFT)	|	2 (DOWN/RIGHT)
*/

/********
VARIABLES
*********/
const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
									 // for your motor

/******
OBJECTS
*******/
PhotoResistorClass photoResistor; // instantiate the photoResistor class

// Solar Tracker #1
Stepper stepperA0(stepsPerRevolution, 4, 5, 6, 7);
Stepper stepperB0(stepsPerRevolution, 8, 9, 10, 11);
Stepper stepperC0(stepsPerRevolution, 12, 13, 14, 15);

// Solar Tracker #2
Stepper stepperA1(stepsPerRevolution, 16, 17, 18, 19);
Stepper stepperB1(stepsPerRevolution, 20, 21, 22, 23);
Stepper stepperC1(stepsPerRevolution, 24, 25, 26, 27);

/********************
FUNCTION DECLARATIONS
********************/
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);	// begin serial communication

	/* CHANGE PHOTORESISTOR PIN NUMBERS HERE */
	photoResistor.init(A0, A1, A2, A3); // initialize the photoresistors with analong pin numbers
}

// the loop function runs over and over again until power down or reset
void loop() {
	photoResistor.readNewAnalogValues(); // update the value of the photoresistors upon every iteration
	photoResistor.updateAvgValue(); // update the average value of the photoresistors upon every iteration

	/* VERTICAL MOVEMENT */
	if (photoResistor.avg_up > photoResistor.avg_down) {
		// move stepper motors in positive Y direction
	}
	else if (photoResistor.avg_up < photoResistor.avg_down) {
		// move stepper motors in negative Y direction
	}


	/* HORIZONTAL MOVEMENT */
	if (photoResistor.avg_left > photoResistor.avg_right) {
		// move stepper motors in postive X direction
	}
	else if (photoResistor.avg_left < photoResistor.avg_right) {
		// move stepper motors in negative X direction
	}
	else if (photoResistor.avg_left == photoResistor.avg_right) {
		// nothing
	}

	// WRITE TO THE SERVO MOTOR HERE.
	// This will move 

	//delay(100);
}