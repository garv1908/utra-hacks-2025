#include <Servo.h>
#define OE_PIN 1  
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6


// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

int speed = 255;

Servo servo;

const int servoPin = 7;
int pos = 0;

// Variables for Color Pulse Width Measurements
int r = 0;
int g = 0;
int b = 0;

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

void motorSetup() {
  // Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void setup() {
	// Setup Serial Monitor
	Serial.begin(9600);
  motorSetup();
	colourSetup();

	// servo writup
	servo.attach(servoPin);
	servo.write(10);
	delay(1000);
}

void loop() {
	// GET PULSE WIDTH
	r = getRedPW();
	// Delay to stabilize sensor
	delay(200);

	g = getGreenPW();
	delay(200);

	b = getBluePW();
	delay(200);

  setMotorSpeed();
  goStraight();
  delay(2000);
  while (!isBlack(r, g, b)) {
    goStraight();
  }
	colourTest();


}

bool isBlack(int r, int g, int b) {
  return (r > 200 && g > 200 && b > 200);
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

void setMotorSpeed(int speed) {
  // Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, speed);
	analogWrite(enB, speed);
}

void goStraight() {
  // Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
}

void reverse() {
  	// Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
}

void uTurn() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

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
