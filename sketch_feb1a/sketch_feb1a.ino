#include <Servo.h>

#define speed 150

// Variables for Color Pulse Width Measurements
int r = 0;
int g = 0;
int b = 0;


// Servo servo;

// const int servoPin = ;
// int pos = 0;


void setup() {
	// Setup Serial Monitor
	Serial.begin(9600);
  motorSetup();
	colourSetup();

	// servo writup
	// servo.attach(servoPin);
	// servo.write(10);
	delay(1000);
}

void loop() {
	pickUpRGB();
	delay(200);
  colourTest();
  setMotorSpeed(speed);
  goStraight();
  delay(2000);
  while (!isBlack(r, g, b)) {
    Serial.println("in while loop");
    goStraight();
    colourTest();
  }
  delay(5000);
}
