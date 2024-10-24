#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

int miArray[1] = {0};
bool motorEncendido = false;

Stepper motor (2048, 21, 18, 19, 5);

const char* ssid = "INFINITUM837A";
const char* password = "ahQn8He4p8";

WebServer server(80);
const int ledpin = 15;

void inicio() {
  if (server.hasArg("led1") && server.arg("led1") == "on") {
    digitalWrite(ledpin, HIGH);
  } else if (server.hasArg("led1") && server.arg("led1") == "off") {
    digitalWrite(ledpin, LOW);
  }

  if (server.hasArg("Stepper") && server.arg("Stepper") == "on") {
    motorEncendido = true;
  } else if (server.hasArg("Stepper") && server.arg("Stepper") == "off") {
    motorEncendido = false;
  }

  String html = "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0, user-scalable=no'><title>Control led, prueba wifi</title><style>body {background-color: #000010;} form {display: flex;flex-direction: column;margin: 50px auto;} button {background-color: #dbdb14;height: 30px;width: 200px;margin: 10px auto;border-radius: 10px;}</style></head><body>";
  html += "<form method='get'> ";
  html += "<button type='submit' name='led1' value='on'> Encender </button>";
  html += "<button type='submit' name='led1' value='off'> Apagar </button>";
  html += "<button type='submit' name='Stepper' value='on'> Motor ON </button>";
  html += "<button type='submit' name='Stepper' value='off'> Motor OFF </button>";
  html += "</form></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  motor.setSpeed(10);
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

  if (motorEncendido == true) {
    motor.step(100);
  }

}
