#include <Servo.h>

#define speed 250
#define distanceThreshold 500
// Variables for Color Pulse Width Measurements

extern int rgb[3];  // Declare in another file

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
  // ultrasoundTest();
  setMotorSpeed(speed);
  goForward();
  delay(200);
  while (!isBlack(rgb)) {
    pickUpRGB();
    colourTest();
    // distanceFromWall = getDistanceFromWall();
    // while (distanceFromWall > distanceThreshold) {
    //   distanceFromWall = getDistanceFromWall();
    //   goForward();
    // }
    if (isBlack(rgb)) {
      Serial.println("FINISHED!");
      stop();
      delay(20000);
      // exit(0);
    }
    else if (isRed(rgb)) {
      Serial.println("saw red, taking a uturn");
      // uTurn();
    }
    else if (isGreen(rgb)) {
      Serial.println("saw green, taking a right turn");
      // turnRight();
    }
    else if (isBlue(rgb)) {
      Serial.println("saw blue, taking a left turn");
      // turnLeft();
    }

    Serial.println("in while loop");
    // goForward();
    colourTest();
  }
  delay(500);
}
