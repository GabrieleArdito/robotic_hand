#include <Servo.h>

Servo servoPin5;
Servo servoPin9;

int vel = 5; // Regola la velocità più bassa per un movimento più lento
int pos5 = 0;  // Variabile per la posizione del servo 5
int pos9 = 0;  // Variabile per la posizione del servo 9
int repeatCount = 3; // Numero di ripetizioni desiderate

void setup() {
  servoPin5.attach(5);
  servoPin9.attach(9);

  Serial.begin(9600);
}

void loop() {
  // Simulazione del movimento di piegamento su e giù per i servo 5 e 9
  for (int i = 0; i < repeatCount; i++) {
    // Movimento di piegamento verso il basso
    for (pos5 = 0, pos9 = 90; pos5 <= 90; pos5 += 1, pos9 -= 1) {
      servoPin5.write(pos5);
      servoPin9.write(pos9);
      delay(vel);
    }
    delay(300);

    // Movimento di ritorno verso l'alto
    for (pos5 = 90, pos9 = 0; pos5 >= 0; pos5 -= 1, pos9 += 1) {
      servoPin5.write(pos5);
      servoPin9.write(pos9);
      delay(vel);
    }
    delay(300);
  }
}
