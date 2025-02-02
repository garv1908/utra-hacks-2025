#include "NewPing.h"

#define TRIG_PIN 0
#define ECHO_PIN 1

#define MAX_DISTANCE 250

int distanceFromWall = 900000001;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

int getDistanceFromWall() {
  ultrasoundTest();
  return sonar.ping_cm();
}

void ultrasoundTest() {
  Serial.print("Distance = ");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  delay(100);
}