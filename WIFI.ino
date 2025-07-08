#include <WiFi.h>

// Replace with your Wi-Fi credentials
const char* ssid = "xxxxxxxxxxxxxx";
const char* password = "xxxxxxxxxxx";

WiFiServer server(80);  // HTTP server on port 80

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Show IP address
  Serial.println("\nWi-Fi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients

  if (client) {
    Serial.println("New Client Connected");

    // Wait until the client sends some data
    while (!client.available()) {
      delay(1);
    }

    // Read the request
    String request = client.readStringUntil('\r');
    Serial.println("Request: " + request);
    client.flush();

    // Send response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println();
    client.println("Hello from ESP32!");

    delay(1);
    client.stop();
    Serial.println("Client disconnected");
  }
}
