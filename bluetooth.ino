#include "BluetoothSerial.h"

BluetoothSerial SerialBT;  // Create Bluetooth Serial object

void setup() {
  Serial.begin(115200);              // Serial monitor
  SerialBT.begin("ESP32-Bluetooth"); // Bluetooth device name

  Serial.println("Bluetooth Started. Pair with 'ESP32-Bluetooth'");
  SerialBT.println("ESP32 Bluetooth Test: Ready to receive");
}

void loop() {
  // Check if Bluetooth received data
  if (SerialBT.available()) {
    String received = SerialBT.readStringUntil('\n');
    Serial.print("Received via Bluetooth: ");
    Serial.println(received);
    
    // Echo back to sender
    SerialBT.print("Echo: ");
    SerialBT.println(received);
  }

  // Optional: also send a heartbeat message every 10 seconds
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 10000) {
    SerialBT.println("ESP32 is alive...");
    lastMsg = millis();
  }
}
