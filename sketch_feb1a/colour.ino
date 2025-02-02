#define OE_PIN 2
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
#define blackThreshold 250

int rgb[3] = { 0, 0, 0 };

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
	rgb[0] = getRedPW();
	// Delay to stabilize sensor
	delay(100);

	rgb[1] = getGreenPW();
	delay(100);

	rgb[2] = getBluePW();
	delay(100);
}

bool isBlack(int rgb[]) {
  bool a = (rgb[0] > blackThreshold && rgb[1] > blackThreshold && rgb[2] > blackThreshold);
  delay(100);
  pickUpRGB();
  bool b = (rgb[0] > blackThreshold && rgb[1] > blackThreshold && rgb[2] > blackThreshold);
  delay(100);
  pickUpRGB();
  bool c = (rgb[0] > blackThreshold && rgb[1] > blackThreshold && rgb[2] > blackThreshold);
  return (a && b && c);
}
bool isRed(int rgb[]) {
  bool a = (rgb[0] < rgb[1] && rgb[0] < rgb[2]);
  delay(100);
  pickUpRGB();
  bool b = (rgb[0] < rgb[1] && rgb[0] < rgb[2]);
  delay(100);
  pickUpRGB();
  bool c = (rgb[0] < rgb[1] && rgb[0] < rgb[2]);
  delay(100);
  pickUpRGB();
  return (a && b && c);
}
bool isGreen(int rgb[]) {
  return (rgb[1] < rgb[0] && rgb[1] < rgb[2]);
}
bool isBlue(int rgb[]) {
  return (rgb[2] < rgb[1] && rgb[2] < rgb[0]);
}

void colourTest() {
	// Print output to Serial Monitor
	Serial.print("Red PW = ");
	Serial.print(rgb[0]);
	Serial.print(" - Green PW = ");
	Serial.print(rgb[1]);
	Serial.print(" - Blue PW = ");
	Serial.println(rgb[2]);
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
