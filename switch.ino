const int ledPin1 = 2;     // GPIO2 connected to LED
const int switchPin1 = 35; // GPIO34 connected to push-button (with external pull-up)
const int ledPin2 = 4;     // GPIO2 connected to LED
const int switchPin2 = 34;
const int ledPin3 = 13;     // GPIO2 connected to LED
const int switchPin3 = 36;

void setup() {
  pinMode(ledPin1, OUTPUT);        // Set LED pin as output
  pinMode(switchPin1, INPUT);
  pinMode(ledPin2, OUTPUT);        // Set LED pin as output
  pinMode(switchPin2, INPUT);
  pinMode(ledPin3, OUTPUT);        // Set LED pin as output
  pinMode(switchPin3, INPUT);// Set switch pin as input (external pull-up required)
}

void loop() {
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);
  int switchState3 = digitalRead(switchPin3);// Read the state of the switch

  if (switchState1 == LOW) {
    digitalWrite(ledPin1, HIGH); // Turn ON LED if button is pressed (LOW)
  } else {
    digitalWrite(ledPin1, LOW);  // Turn OFF LED if button is released (HIGH)
  }
   if (switchState2 == LOW) {
    digitalWrite(ledPin2, HIGH); // Turn ON LED if button is pressed (LOW)
  } else {
    digitalWrite(ledPin2, LOW);  // Turn OFF LED if button is released (HIGH)
  }
   if (switchState3 == LOW) {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin1, HIGH);// Turn ON LED if button is pressed (LOW)
  } else {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin1, LOW);// Turn OFF LED if button is released (HIGH)
  }
}
