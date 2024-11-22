int TRIG = 2;
int ECO = 4;
int DURACION;
int DISTANCIA;
int input1 = 5;
int input2 = 18;

int input1b = 19;
int input2b = 21;


bool giro = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input1b, OUTPUT);
  pinMode(input2b, OUTPUT);
  Serial.begin(9600);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);

  if (DISTANCIA >= 10){
    
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    

  } else if (DISTANCIA <= 10 && giro == false){
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);
    delay(1000);
    
    giro = true
    
  } else if (DISTANCIA <= 10 && giro == true){
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, HIGH);
    digitalWrite(input2b, LOW);
    delay(1000);

    giro = false

  }
}


  







