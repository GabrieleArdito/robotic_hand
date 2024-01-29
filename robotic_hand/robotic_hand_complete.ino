#include <Servo.h>
Servo myservo_pollice;
Servo myservo_indice;
Servo myservo_medio;
Servo myservo_anulare;
Servo myservo_mignolo;
int pollice;
int indice;
int medio;
int anulare;
int mignolo;

void setup() {
Serial.begin(9600);
myservo_pollice.attach(9);
myservo_indice.attach(10);
myservo_medio.attach(11);
myservo_anulare.attach(12);
//myservo_mignolo.attach(13);

}

void loop() {
pollice = analogRead(A0);
indice = analogRead(A1);
medio = analogRead(A2);
anulare = analogRead(A3);
mignolo = analogRead(A4);
Serial.println(mignolo);

pollice = map(pollice, 0, 3000, 0, 1600);
indice = map(indice,  0, 6000, 0, 800);
medio = map(medio,  0, 6000, 0, 800);
anulare = map(anulare,  0, 6000, 0, 719);
mignolo = map(mignolo,  0, 6000, 0, 719);

myservo_pollice.write(pollice);
myservo_indice.write(indice);
myservo_medio.write(medio);
myservo_anulare.write(anulare);
myservo_mignolo.write(mignolo);

delay(150);
}