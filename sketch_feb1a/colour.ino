#define OE_PIN 5
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define sensorOut 10
#define blackThreshold 250

void colourSetup() {
	// colour stuff
	// Set S0 - S3 as outputs
	pinMode(OE_PIN, OUTPUT);
	digitalWrite(OE_PIN, LOW);
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	// Set Pulse Width scaling to 20%
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);
}


void pickUpRGB() {
  // GET PULSE WIDTH
	r = getRedPW();
	// Delay to stabilize sensor
	delay(200);

	g = getGreenPW();
	delay(200);

	b = getBluePW();
	delay(200);
}

bool isBlack(int r, int g, int b) {
  return (r > blackThreshold && g > blackThreshold && b > blackThreshold);
}
bool isRed(int r, int g, int b) {
  return (r < g && r < b);
}
bool isGreen(int r, int g, int b) {
  return (g < r && g < b);
}
bool isBlue(int r, int g, int b) {
  return (b < g && b < r);
}



void colourTest() {
	// Print output to Serial Monitor
	Serial.print("Red PW = ");
	Serial.print(r);
	Serial.print(" - Green PW = ");
	Serial.print(g);
	Serial.print(" - Blue PW = ");
	Serial.println(b);
}

int getRedPW() {
	// Set sensor to read Red only
	digitalWrite(S2,LOW);
	digitalWrite(S3,LOW);
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int getGreenPW() {
	// Set sensor to read Green only
	digitalWrite(S2,HIGH);
	digitalWrite(S3,HIGH);
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int getBluePW() {
	// Set sensor to read Blue only
	digitalWrite(S2,LOW);
	digitalWrite(S3,HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	return PW;
}
