//Sensores ultrasonicos
int TRIG = 2;
int ECO = 4;
int TRIG2 = 22;
int ECO2 = 23;
int DURACION;
int DISTANCIA;
int DURACION2;
int DISTANCIA2;

//Motores
int input1 = 5;
int input2 = 18;
int input1b = 19;
int input2b = 21;

//FALSE = gira izq
//TRUE = gira der
bool giro = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECO2, INPUT);
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
    //Avanza si no hay obstaculos
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    

  } else if (DISTANCIA <= 10 && giro == false ){

    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);

    giro = true;


  } else if (DISTANCIA <= 10 && giro == true ){

    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, HIGH);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);
    delay(5000);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);

    giro = false;


  }else {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input1b, LOW);
    digitalWrite(input2b, LOW);

  }
}


  







