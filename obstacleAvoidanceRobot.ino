#include <Servo.h>

Servo leftServo;
Servo rightServo;

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  leftServo.attach(5);
  rightServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 15) {
    // Obstacle detected – turn
    leftServo.write(0);   // backward
    rightServo.write(180); // forward
    delay(500);
  } else {
    // Move forward
    leftServo.write(180);
    rightServo.write(0);
  }

  delay(100);
}