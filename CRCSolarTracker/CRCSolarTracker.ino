/*
 Name:		CRCSolarTracker.ino
 Created:	3/23/2017 8:02:43 PM
 Author:	Yoosuf
*/

#include <Servo.h>
#include <EEPROM.h>
using namespace std;

Servo servoMotor1; // create a servo motor object to control servos
Servo servoMotor2; // create a servo motor object to control servos

/********************
FUNCTION DECLARATIONS
********************/

/********
VARIABLES
*********/
const int phResisPin0 = A0;
const int phResisPin1 = A1;
const int phResisPin2 = A2;
const int phResisPin3 = A3;
const int phResisSize = 4;
int phResisState[4];
int horizontalServo = 90; // stand horizontal servo
int verticalServo = 90; // stand vertical servo
bool checkLastPosition = true;
int motorOneAdress = 0;
int motorTwoAdress = 2;
double tol = 0;
int oldDVert = 1;
int oldDHoriz = 1;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);	// begin serial communication
	pinMode(phResisPin0, INPUT); // initialize pin 0 as an output for the photoresistor
	pinMode(phResisPin1, INPUT); // initialize pin 1 as an output for the photoresistor
	pinMode(phResisPin2, INPUT); // initialize pin 2 as an output for the photoresistor
	pinMode(phResisPin3, INPUT); // initialize pin 3 as an output for the photoresistor
	servoMotor1.attach(9); // attaches motor to digital pin 9
	servoMotor2.attach(10); // attaches motor to digital pin 10
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (checkLastPosition) {
		verticalServo = servoMotor1.read();
		horizontalServo = servoMotor2.read();
		/*Serial.println("+++++++++++");
		Serial.println(verticalServo);
		Serial.println("+++++++++++");
		Serial.println(horizontalServo);
		Serial.println("+++++++++++");*/
		servoMotor1.write(verticalServo);
		servoMotor2.write(horizontalServo);
		checkLastPosition = false;
	}
	// read the state of the pushbutton value:
	phResisState[0] = analogRead(phResisPin0);
	phResisState[1] = analogRead(phResisPin1);
	phResisState[2] = analogRead(phResisPin2);
	phResisState[3] = analogRead(phResisPin3);

	int avt = (phResisState[0] + phResisState[3]) / 2; // average value top
	int avd = (phResisState[1] + phResisState[2]) / 2; // average value down
	int avl = (phResisState[0] + phResisState[1]) / 2; // average value left
	int avr = (phResisState[2] + phResisState[3]) / 2; // average value right

	int dvert = avt - avd; // check the diffirence of up and down
	int dhoriz = avl - avr;// check the diffirence og left and rigt

	tol = (avt + avl) / (avd + avr);

	if (avt > avd) {
			verticalServo = ++verticalServo;
			if (verticalServo > 180) {
				verticalServo = 180;
			}
		}
		else if (avt < avd) {
			verticalServo = --verticalServo;
			if (verticalServo < 0) {
				verticalServo = 0;
			}
		}

		if (avl > avr) {
			horizontalServo = --horizontalServo;

			if (horizontalServo < 0) {
				horizontalServo = 0;
			}
		}
		else if (avl < avr) {
			horizontalServo = ++horizontalServo;

			if (horizontalServo > 169) {
				horizontalServo = 169;
			}
		}
		else if (avl == avr) {
			// nothing
		}

	if (tol > 1.1 || tol < .9) {
		servoMotor1.write(verticalServo);
		servoMotor2.write(horizontalServo);
	}

	Serial.println("+++++++++++");
	Serial.println(tol);
	Serial.println("+++++++++++");

	oldDVert = dvert;
	oldDHoriz = dhoriz;

	//Serial.println(servoMotor1.read());
	Serial.println("--------------");
	//delay(100);
}