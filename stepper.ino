
#include <Stepper.h>
Stepper motor (2048, 21, 18, 19, 5);


void setup() {
  // put your setup code here, to run once:
  
  motor.setSpeed(5);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  motor.step(4096);
  delay(1000);
  motor.step(-4096);
  delay(1000);
 
}