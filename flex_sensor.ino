const int flexPin = A0; // Analog pin to which the flex sensor is connected

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int flexValue = analogRead(flexPin); // Read the analog value from the flex sensor

  // Print the read value on the serial port
  Serial.print("flex value: ");
  Serial.println(flexValue);

  delay(1000); // Wait for one second before taking a new reading
}
