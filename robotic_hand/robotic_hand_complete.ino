#include <Servo.h>
Servo myservo_thumb;
Servo myservo_index;
Servo myservo_middle;
Servo myservo_ring;
Servo myservo_pinky;
int thumb;
int index;
int middle;
int ring;
int pinky;

void setup() {
  Serial.begin(9600);
  myservo_thumb.attach(9);
  myservo_index.attach(10);
  myservo_middle.attach(11);
  myservo_ring.attach(12);
  //myservo_pinky.attach(13);
}

void loop() {
  thumb = analogRead(A0);
  index = analogRead(A1);
  middle = analogRead(A2);
  ring = analogRead(A3);
  pinky = analogRead(A4);
  Serial.println(pinky);

  //set the values according to your preferences
  thumb = map(thumb, 0, 3000, 0, 1600); 
  index = map(index,  0, 6000, 0, 800);
  middle = map(middle,  0, 6000, 0, 800);
  ring = map(ring,  0, 6000, 0, 719);
  pinky = map(pinky,  0, 6000, 0, 719);

  myservo_thumb.write(thumb);
  myservo_index.write(index);
  myservo_middle.write(middle);
  myservo_ring.write(ring);
  myservo_pinky.write(pinky);

  delay(150);
}
