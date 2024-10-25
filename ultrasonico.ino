int TRIG = 2;
int ECO = 4;
int DURACION;
int DISTANCIA;

#include <Stepper.h>
Stepper motor (2048, 21, 18, 19, 5);


void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  motor.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  
  if (DISTANCIA >= 10)
  {
    motor.step(100);
    
  }
}