#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "POCO";
const char* password = "plchernandez";

WebServer server(80);
const int ledpin = 15;

void inicio() {
  if (server.hasArg("led1") && server.arg("led1") == "on") {
    digitalWrite(ledpin, HIGH);
  } else if (server.hasArg("led1") && server.arg("led1") == "off") {
    digitalWrite(ledpin, LOW);
  }

  String html = "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0, user-scalable=no'><title>Control led, prueba wifi</title></head><body>";
  html += "<form method='get'> ";
  html += "<button type='submit' name='led1' value='on'> Encender </button>";
  html += "<button type='submit' name='led1' value='off'> Apagar </button>";
  html += "</form></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(115200);
  Serial.println("espere, conectando...");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado a");
  Serial.println(ssid);
  Serial.print("Direccion IP asignada por router: ");
  Serial.println(WiFi.localIP());

  server.on("/", inicio);
  server.begin();
}

void loop() {
  server.handleClient();
}
