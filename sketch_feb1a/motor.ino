
// Motor A connections
#define enA 10
#define in1 12
#define in2 2
// Motor B connections
#define enB 11
#define in3 3
#define in4 4


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


void setMotorSpeed(int s) {
  // Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
  Serial.println("enter set motor speed");
	analogWrite(enA, s);
	analogWrite(enB, s);
  Serial.println("set motor speed");
}

void goForward() {
  // Turn on motor A & B
  Serial.println("trying to go straight");
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

	delay(1000);
}

void reverse() {
  	// Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(1000);
}

void uTurn() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}