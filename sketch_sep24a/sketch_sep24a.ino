int pinPulsador=4;
int pinLed=2;
void setup()
{ 
  pinMode(pinPulsador, INPUT);
  pinMode(pinLed, OUTPUT);
}
void loop()
{
  if (digitalRead(pinPulsador) == HIGH) {
    digitalWrite(pinLed, HIGH);
  } 
  else {
    digitalWrite(pinLed, LOW);
  }
  delay(10);
}