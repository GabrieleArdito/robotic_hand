const int flexPin = A0; // Pin analogico a cui è collegato il sensore di flessione

void setup() {
  Serial.begin(9600); // Inizializzazione della comunicazione seriale
}

void loop() {
  int flexValue = analogRead(flexPin); // Leggi il valore analogico dal sensore di flessione

  // Stampare il valore letto sulla porta seriale
  Serial.print("flex value: ");
  Serial.println(flexValue);

  delay(1000); // Attendi un secondo prima di effettuare una nuova lettura
}
