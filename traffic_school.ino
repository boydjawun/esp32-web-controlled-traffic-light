#include <WiFi.h>
#include <WebServer.h>

// ================== CONFIGURATION ==================
const char* ap_ssid = "YESP32";        // ← Access Point name (what you'll see in WiFi list)
const char* ap_password = "mypassword"; // ← Password for the Access Point
// ===================================================

WebServer server(80);

const int redPin = 5;
const int yellowPin = 18;
const int greenPin = 19;

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>Traffic School</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{font-family:Arial;text-align:center;background:#111;color:#fff;}";
  html += "h1{color:#ffd700;} button{font-size:24px;padding:20px 40px;margin:15px;border:none;border-radius:10px;}</style></head><body>";
  html += "<h1> 🚦 Traffic School</h1>";
  html += "<h2>Click a button to light up the signal</h2>";
  html += "<p><strong>Red Light:</strong> " + String(digitalRead(redPin) == HIGH ? "ON" : "OFF") + "</p>";
  html += "<a href='/toggleRed'><button style='background:#ff0000;color:white;'>Red Light</button></a>";
  html += "<p><strong>Yellow Light:</strong> " + String(digitalRead(yellowPin) == HIGH ? "ON" : "OFF") + "</p>";
  html += "<a href='/toggleYellow'><button style='background:#ffcc00;color:black;'>Yellow Light</button></a>";
  html += "<p><strong>Green Light:</strong> " + String(digitalRead(greenPin) == HIGH ? "ON" : "OFF") + "</p>";
  html += "<a href='/toggleGreen'><button style='background:#00ff00;color:black;'>Green Light</button></a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleToggleRed() {
  digitalWrite(redPin, !digitalRead(redPin));
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleToggleYellow() {
  digitalWrite(yellowPin, !digitalRead(yellowPin));
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleToggleGreen() {
  digitalWrite(greenPin, !digitalRead(greenPin));
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  delay(1000);  // Give Serial time to start

  // Set up pins
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  // === START WiFi ACCESS POINT ===
  Serial.println("\n==========================");
  Serial.println("Starting WiFi Access Point...");
  Serial.print("SSID: ");
  Serial.println(ap_ssid);
  Serial.print("Password: ");
  Serial.println(ap_password);

  WiFi.softAP(ap_ssid, ap_password);

  // Wait a moment for AP to fully start
  delay(1000);

  IPAddress apIP = WiFi.softAPIP();
  
  Serial.println("✅ Access Point Started Successfully!");
  Serial.println("==========================");
  Serial.print("📡 Connect to WiFi: ");
  Serial.println(ap_ssid);
  Serial.print("🔑 Password: ");
  Serial.println(ap_password);
  Serial.print("🌐 Open your browser and go to: http://");
  Serial.println(apIP);
  Serial.println("==========================");

  // Set up web server routes
  server.on("/", handleRoot);
  server.on("/toggleRed", handleToggleRed);
  server.on("/toggleYellow", handleToggleYellow);
  server.on("/toggleGreen", handleToggleGreen);

  server.begin();
  Serial.println("HTTP server started");
  Serial.println("Ready! 🎉");
}

void loop() {
  server.handleClient();
}