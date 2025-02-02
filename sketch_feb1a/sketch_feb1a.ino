#include <Servo.h>

#define speed 170
#define distanceThreshold 3
// Variables for Color Pulse Width Measurements

extern int rgb[3];  // Declare in another file
extern int distanceFromWall;

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
  colourTest();
  ultrasoundTest();
  setMotorSpeed(speed);
  goForward();
  while (!isBlack(rgb)) {
    distanceFromWall = getDistanceFromWall();
    while (distanceFromWall > distanceThreshold && distanceFromWall != 0) {
      goForward();
      Serial.println(distanceFromWall > distanceThreshold);
      Serial.println(distanceFromWall);
      distanceFromWall = getDistanceFromWall();
    }
    brake();
    delay(2000);
    goBack();
    delay(500);
    brake();
    pickUpRGB();
    colourTest();
    if (isBlack(rgb)) {
      Serial.println("FINISHED!");
      delay(10000);
      // exit(0);
    }
    else if (isRed(rgb)) {
      Serial.println("saw red, taking a uturn");
      uTurn();
    }
    else if (isGreen(rgb)) {
      Serial.println("saw green, taking a right turn");
      turnRight();
    }
    else if (isBlue(rgb)) {
      Serial.println("saw blue, taking a left turn");
      turnLeft();
    }
    Serial.println("in while loop");
    goForward();
    colourTest();
  }
  // delay(500);
}
