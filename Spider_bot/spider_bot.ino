#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 7
#define ECHO_PIN 8

long duration;
long distance;

NewPing sonar(TRIGGER_PIN, ECHO_PIN);

Servo servoPin3;
Servo servoPin5;
Servo servoPin6;
Servo servoPin9;
Servo servoPin10;
Servo servoPin11;

int vel = 1;
int velster = 1;
int pos = 0;     // Variable for servo position
int ledPin1 = 2; // Pin for the first LED
int ledPin2 = 4; // Pin for the second LED
int repeatCount = 3; // Number of desired repetitions

void setup() {
  servoPin3.attach(3);  // Attach Servo object to pin 
  servoPin5.attach(5);
  servoPin6.attach(6);  // Attach Servo object to pin 
  servoPin9.attach(9);
  servoPin10.attach(10);
  servoPin11.attach(11);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);   

  pinMode(ledPin1, OUTPUT); // Set the pin of the first LED as OUTPUT
  pinMode(ledPin2, OUTPUT); // Set the pin of the second LED as OUTPUT 

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration / 58.2;

  if (distance > 20) {

    Serial.println("Far");

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);

    //CHANGE THE SERVO VALUES TO YOUR PREFERENCES!!

    // First movement
    for (pos = 0; pos <= 90; pos += 1) {
      servoPin5.write(pos);
      delay(vel);  // Adjust the servo movement speed by changing this value
    }
    delay(100);  

    for (pos = 0; pos <= 60; pos += 1) {
      servoPin3.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 60; pos >= 0; pos -= 1) {
      servoPin5.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 0; pos <= 60; pos += 1) {
      servoPin11.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 60; pos >= 0; pos -= 1) {
      servoPin11.write(pos);
      delay(vel);  
    }

    for (pos = 60; pos >= 0; pos -= 1) {
      servoPin3.write(pos);
      delay(vel);  
    }
    delay(100);  

    // Second movement
    for (pos = 90; pos >= 0; pos -= 1) {
      servoPin9.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 60; pos >= 0; pos -= 1) {
      servoPin6.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 0; pos <= 90; pos += 1) {
      servoPin9.write(pos);
      delay(5);  
    }
    delay(100);  

    for (pos = 60; pos >= 0; pos -= 1) {
      servoPin10.write(pos);
      delay(vel);  
    }
    delay(100);  

    for (pos = 0; pos <= 60; pos += 1) {
      servoPin10.write(pos);
      delay(vel);  
    } 

    for (pos = 0; pos <= 60; pos += 1) {
      servoPin6.write(pos);
      delay(vel);  
    }
    delay(100);  

  } else {
    
    Serial.println("Close");

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    
    delay(1000);

    for (int i = 0; i < repeatCount; i++) {
  
      for (pos = 0; pos <= 90; pos += 1) {
        servoPin5.write(pos);
        delay(velster);
      }
      delay(100);

      for (pos = 0; pos <= 60; pos += 1) {
        servoPin3.write(pos);
        delay(velster);
      }
      delay(100);

      for (pos = 60; pos >= 0; pos -= 1) {
        servoPin5.write(pos);
        delay(velster);
      }
      delay(100);

      for (pos = 90; pos >= 0; pos -= 1) {
        servoPin9.write(pos);
        delay(vel);  
      }
      delay(100);

      for (pos = 0; pos <= 100; pos += 1) {
        servoPin6.write(pos);
        delay(1);
      }

      for (pos = 0; pos <= 90; pos += 1) {
        servoPin9.write(pos);
        delay(1);  
      }
      delay(100);  

      for (pos = 0; pos <= 60; pos += 1) {
        servoPin11.write(pos);
        delay(velster);
      }
      delay(100);

      for (pos = 60; pos >= 0; pos -= 1) {
        servoPin11.write(pos);
        delay(velster);
      }
      delay(100);

      for (pos = 60; pos >= 0; pos -= 1) {
        servoPin3.write(pos);
        delay(velster);
      }
      for (pos = 100; pos >= 0; pos -= 1) {
        servoPin6.write(pos);
        delay(15);
      }
      delay(100);

    }
  }
}
