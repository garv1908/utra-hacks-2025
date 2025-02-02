// Motor A connections
int enA = 11;
int in1 = 13;
int in2 = 12;
// Motor B connections
int enB = 10;
int in3 = 9;
int in4 = 8;

int rt = 515;

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
  Serial.println("trying to go forward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("wrote direction");
  delay(2000);
}

void goBack() {
  // Turn on motor A & B
  Serial.println("trying to go back");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);


  Serial.println("wrote direction");
  delay(2000);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(rt);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(rt);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void uTurn() {
  turnRight();
  turnRight();
}

void break(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}