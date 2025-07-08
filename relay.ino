#define RELAY_PIN 25  // GPIO25 is safe and commonly used

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.println("Relay test started...");
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);  // Relay ON
  Serial.println("Relay ON");
  delay(2000);

  digitalWrite(RELAY_PIN, LOW);   // Relay OFF
  Serial.println("Relay OFF");
  delay(2000);
}
