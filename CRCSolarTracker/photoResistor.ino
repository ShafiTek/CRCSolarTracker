const int phResisPin0 = A0;
const int phResisPin1 = A1;
int phResisState[2];
int lightPin = 0;  //define a pin for Photo resistor
int ledPin = 11;     //define a pin for LED

int mean1 = 0;
long mean1Avg = 0;
int mean2 = 0;
long mean2Avg = 0;
int loopSize = 0;
bool calComp = false;

void setup()
{
	Serial.begin(9600);  //Begin serial communcation
	pinMode(ledPin, OUTPUT);
}

void loop()
{
	if (loopSize >= 300) {
		if (!calComp) {
			calComp = true;
			mean1Avg = mean1 / 1000;
			mean2Avg = mean2 / 1000;
		}
		Serial.print("Old Resis Measure: ");
		Serial.println(mean1Avg);
		Serial.print("New Resis Measure: ");
		Serial.println(mean2Avg);
		Serial.println("---------------------");
	}
	else {
		phResisState[0] = analogRead(phResisPin0);
		phResisState[1] = analogRead(phResisPin1);
		mean1 += phResisState[0];
		mean2 += phResisState[1];
		Serial.print("Old Resis: ");
		Serial.println(phResisState[0]);
		Serial.print("New Resis: ");
		Serial.println(phResisState[1]);
		Serial.println("---------------------");
	}

	loopSize++;

}