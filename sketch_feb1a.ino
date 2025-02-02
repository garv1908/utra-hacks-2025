#include <Servo.h>
#define OE_PIN 1  
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo servo;

const int servoPin = 7;
int pos = 0;

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

void setup() {
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

	// Setup Serial Monitor
	Serial.begin(9600);

  // servo writup
  servo.attach(servoPin);
  servo.write(10);
  delay(1000);
}

void loop() {
  // GET PULSE WIDTH
	redPW = getRedPW();
	// Delay to stabilize sensor
	delay(200);

	greenPW = getGreenPW();
	delay(200);

	bluePW = getBluePW();
	delay(200);

  colourTest();
	
}

void goStraight() {
  
}

void colourTest() {
  // Print output to Serial Monitor
	Serial.print("Red PW = ");
	Serial.print(redPW);
	Serial.print(" - Green PW = ");
	Serial.print(greenPW);
	Serial.print(" - Blue PW = ");
	Serial.println(bluePW);
}

void clawTest() {
  int degree = 95;
  for (int i = 0; i <= degree; i += 5) {
     servo.write(i);
     // Serial.print(i);
     delay(25);
   }
   delay(3000);  


   for (int i = degree; i >= 0; i -= 5) {
     servo.write(i);
     // Serial.println(i);
     delay(25);
   }
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
