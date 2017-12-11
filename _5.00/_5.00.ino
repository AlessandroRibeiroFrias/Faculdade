int ledvermelho1 = 8;
int ledamarelo1  = 9;
int ledverde1    = 10;

int ledvermelho2 = 11;
int ledamarelo2  = 12;
int ledverde2    = 13;

int pinoSensor0 = A5;
int pinoSensor1 = A4;
int pinoSensor2 = 2;
int pinoSensor3 = 3;


int iniciaSensor0 = 0;
int iniciaSensor1 = 0;
int iniciaSensor2 = 0;
int iniciaSensor3 = 0;

//Variável para calibração do sensor
int calibracao = 5;
long tempo1 = 8000;


void setup() 
{
  Serial.begin(9600);
  pinMode(ledvermelho1, OUTPUT);
  pinMode(ledamarelo1, OUTPUT);
  pinMode(ledverde1, OUTPUT);
  pinMode(ledvermelho2, OUTPUT);
  pinMode(ledamarelo2, OUTPUT);
  pinMode(ledverde2, OUTPUT);
  pinMode(pinoSensor0, INPUT);
  pinMode(pinoSensor1, INPUT);
  pinMode(pinoSensor2, INPUT);
  pinMode(pinoSensor3, INPUT);

  Serial.println("Semaforo com logica Fuzzy");
  Serial.println("\nCalibrando os sensores\n");
  for(int i = 0; i < calibracao; i++){
   Serial.print(".");
   delay(500);
  }
  Serial.println("\nSensores Ativado");
}
int fuzzy_primario(){
iniciaSensor0 = analogRead(pinoSensor0);
iniciaSensor1 = analogRead(pinoSensor1);
iniciaSensor2 = digitalRead(pinoSensor2);
iniciaSensor3 = digitalRead(pinoSensor3);
Serial.print("\nValor do Sensor0: "); 
Serial.println(iniciaSensor0);
Serial.print("\nValor do Sensor1: "); 
Serial.println(iniciaSensor1);
Serial.print("\nValor do Sensor2: "); 
Serial.println(iniciaSensor2);
Serial.print("\nValor do Sensor3: "); 
Serial.println(iniciaSensor3);

//Caso o lado do sensor 0 e 1 estiver verde
  if (iniciaSensor0 < 200){
    tempo1 = tempo1 + 500; 
  }

  if (iniciaSensor1 < 200){
    tempo1 = tempo1 + 5000;
  }

// Se do outro lado não tiver movimento
  if(iniciaSensor2 == 0){
    tempo1 = tempo1 - 1000;  
  }

   if(iniciaSensor3 == 0){
    tempo1 = tempo1 - 500;  
  }
  
  if(iniciaSensor0 < 200 || iniciaSensor1 < 200){
    if(iniciaSensor2 == 1 && iniciaSensor3 == 1){
      Serial.println("\nEntrou");
      Serial.println(tempo1);
      delay(5000);
      fuzzy_primario();
    }else{
      Serial.println(tempo1);
      return tempo1;
    }
  }else{
    Serial.println(tempo1);
    return tempo1;
  }
}

void loop() 
{

  digitalWrite(ledamarelo2, LOW);
  digitalWrite(ledvermelho2, HIGH);
  digitalWrite(ledvermelho1, HIGH);
    delay(1000);
  digitalWrite(ledvermelho1, LOW);
  digitalWrite(ledverde1, HIGH);
  // tempo do primeiro verde;
    delay(fuzzy_primario());
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, HIGH);
    delay(2000);  
  digitalWrite(ledamarelo1, LOW);           
  digitalWrite(ledvermelho1, HIGH);
  digitalWrite(ledvermelho2, HIGH);
    delay(1000);
  digitalWrite(ledvermelho2, LOW);
  digitalWrite(ledverde2, HIGH);
    delay(8000); 
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, HIGH);
    delay(2000);

  tempo1 = 8000;
}



