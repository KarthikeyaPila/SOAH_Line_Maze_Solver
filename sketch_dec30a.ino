
const int motorA_IN1 = A0;
const int motorA_IN2 = A1;
const int motorB_IN3 = A2;
const int motorB_IN4 = A3;
const int motorA_ENA = 10; 
const int motorB_ENB = 11; 

const int irSensor1 = 0; // DigP 0
const int irSensor2 = 1; // DigP 1
const int irSensor3 = 2; // DigP 2

void setup() {
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN3, OUTPUT);
  pinMode(motorB_IN4, OUTPUT);
  pinMode(motorA_ENA, OUTPUT);
  pinMode(motorB_ENB, OUTPUT);

  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);

  analogWrite(motorA_ENA, 0);
  analogWrite(motorB_ENB, 0);
}

void loop() {
  int sensor1 = digitalRead(irSensor1);
  int sensor2 = digitalRead(irSensor2);
  int sensor3 = digitalRead(irSensor3);

  if (sensor1 == HIGH && sensor2 == LOW && sensor3 == HIGH) {
    // Move Forward
    moveMotors(255, 255);
  } else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == LOW) {
    // Turn Right
    moveMotors(255, 0);
  } else if (sensor1 == LOW && sensor2 == HIGH && sensor3 == HIGH) {
    // Turn Left
    moveMotors(0, 255); 
  } else {
    // Stop
    moveMotors(0, 0);
  }
}

void moveMotors(int speedA, int speedB) {
  if (speedA > 0) {
    digitalWrite(motorA_IN1, HIGH);
    digitalWrite(motorA_IN2, LOW);
  } else if (speedA < 0) {
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, HIGH);
  } else {
    digitalWrite(motorA_IN1, LOW);
    digitalWrite(motorA_IN2, LOW);
  }

  if (speedB > 0) {
    digitalWrite(motorB_IN3, HIGH);
    digitalWrite(motorB_IN4, LOW);
  } else if (speedB < 0) {
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, HIGH);
  } else {
    digitalWrite(motorB_IN3, LOW);
    digitalWrite(motorB_IN4, LOW);
  }

  analogWrite(motorA_ENA, abs(speedA));
  analogWrite(motorB_ENB, abs(speedB));
}
