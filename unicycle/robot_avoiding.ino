#include <Servo.h>

#define echoPin 8
#define trigPin 9
#define MRa 6               // Right motor 1st pin PWM
#define MRb 11              // Right motor 2nd pin PWM
#define MLb 5               // Left motor 2nd pin PWM
#define MLa 3               // Left motor 1st pin PWM

long duration;
long distance;

int speed = 255; // Velocità dei motori (da 0 a 255)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MLa, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  delay(10);

  if (distance >= 20) {    
    analogWrite(MRb, speed); // Move Forward
    digitalWrite(MRa, LOW);
    analogWrite(MLb, speed);
    digitalWrite(MLa, LOW); 
  } else if ((distance < 15) && (distance > 0)) { // Condition For Presence Of Obstacle
    digitalWrite(MRb, LOW); // Stop
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);
    delay(100);
    
    
    digitalWrite(MRb, LOW); // Move Backward
    digitalWrite(MRa, speed);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, speed);
    delay(500);
    digitalWrite(MRb, LOW); // Stop
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);
    delay(100);
    digitalWrite(MRb, speed); // Move Left
    digitalWrite(MRa, LOW);
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    delay(500);
  }
}
