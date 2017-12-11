int ledvermelhoBrasil = 8;
int ledamareloBrasil  = 9;
int ledverdeBrasil    = 10;

int ledvermelhoHerval = 11;
int ledamareloHerval  = 12;
int ledverdeHerval    = 13;

int pinoSensor0 = A5;
int pinoSensor1 = A4;
int pinoSensor2 = 2;
int pinoSensor3 = 3;


int iniciaSensor0 = 0;
int iniciaSensor1 = 0;
int iniciaSensor2 = 0;
int iniciaSensor3 = 0;

//Variável para calibração do sensor
int calibracao = 20;

// Temporizadores
long temporizador = 0;
long tempoBrasil = 0;
long tempoHerval = 0;

int SemaforoVerdeBrasil = 0;
int SemaforoVerdeHerval = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledvermelhoBrasil, OUTPUT);
  pinMode(ledamareloBrasil, OUTPUT);
  pinMode(ledverdeBrasil, OUTPUT);
  pinMode(ledvermelhoHerval, OUTPUT);
  pinMode(ledamareloHerval, OUTPUT);
  pinMode(ledverdeHerval, OUTPUT);
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
  Serial.println("\nSensores Ativados");
}
void ler_sensores(){
  iniciaSensor0 = analogRead(pinoSensor0);
  iniciaSensor1 = analogRead(pinoSensor1);
  iniciaSensor2 = digitalRead(pinoSensor2);
  iniciaSensor3 = digitalRead(pinoSensor3);
//  Serial.print("\nValor do Sensor0: "); 
//  Serial.println(iniciaSensor0);
//  Serial.print("\nValor do Sensor1: "); 
//  Serial.println(iniciaSensor1);
//  Serial.print("\nValor do Sensor2: "); 
//  Serial.println(iniciaSensor2);
//  Serial.print("\nValor do Sensor3: "); 
//  Serial.println(iniciaSensor3);
}
void fuzzy_primario(){
  Serial.println("FUZZY PRIMARIO");
  ler_sensores();
  if ((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (temporizador < 20))
{
    while((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (temporizador < 20)){
      Serial.println("Sem movimento na Brasil e sem movimento na Herval");
//      Serial.println(temporizador);
     temporizador++;
     delay(1000);
     ler_sensores();
    }
    
}
  if ((SemaforoVerdeBrasil == 1) && (iniciaSensor0 < 400 || iniciaSensor1 < 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1)){
      while((iniciaSensor0 < 400 || iniciaSensor1 < 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (tempoBrasil < 20)){
        Serial.println("Movimento somente na Brasil");
        // Serial.println("Tempo verde na Brasil");
        // Serial.println(tempoBrasil);
        tempoBrasil++;
        delay(1000);
        ler_sensores();
      }
  }
  
  if ((SemaforoVerdeHerval == 1) && (iniciaSensor2 == 0 || iniciaSensor3 == 0) && (iniciaSensor0 > 400 && iniciaSensor1 > 400)){
      while((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 0 || iniciaSensor3 == 0) && (tempoHerval < 20)){
        Serial.println("Movimento somente na Herval");
       // Serial.println(tempoHerval);
        tempoHerval++;
        delay(1000);
        ler_sensores();
      }
  } 

    if ((iniciaSensor0 < 400 || iniciaSensor1 < 400) && (iniciaSensor2 == 0 || iniciaSensor3 == 0)){
      tempoBrasil = 0;
      while((iniciaSensor0 < 400 || iniciaSensor1 < 400) && (iniciaSensor2 == 0 || iniciaSensor3 == 0) && (tempoBrasil < 20)){
        Serial.println("Movimento na Brasil e Movimento na Herval");
        // Serial.println("Tempo verde na Brasil");
        // Serial.println(tempoBrasil);
        tempoBrasil++;
        delay(1000);
        ler_sensores();
      }
  }
  
}
void loop() 
{

  digitalWrite(ledamareloHerval, LOW);
  digitalWrite(ledvermelhoHerval, HIGH);
  digitalWrite(ledvermelhoBrasil, HIGH);
    delay(1000);
  digitalWrite(ledvermelhoBrasil, LOW);
  digitalWrite(ledverdeBrasil, HIGH);
  Serial.println("VERDE NA BRASIL");
  Serial.println("VERMELHO NA HERVAL");
  SemaforoVerdeHerval = 0;
  SemaforoVerdeBrasil = 1;
  fuzzy_primario();
  temporizador = 0;
  tempoBrasil = 0;
  tempoHerval = 0;
  digitalWrite(ledverdeBrasil, LOW);
  digitalWrite(ledamareloBrasil, HIGH);
    delay(2000);  
  digitalWrite(ledamareloBrasil, LOW);           
  digitalWrite(ledvermelhoBrasil, HIGH);
  digitalWrite(ledvermelhoHerval, HIGH);
    delay(1000);
  digitalWrite(ledvermelhoHerval, LOW);
  digitalWrite(ledverdeHerval, HIGH);
   Serial.println("VERMELHO NA BRASIL");
   Serial.println("VERDE NA HERVAL");
  //delay(8000);
  SemaforoVerdeBrasil = 0;
  SemaforoVerdeHerval = 1;
  fuzzy_primario();
  temporizador = 0;
  tempoBrasil = 0;
  tempoHerval = 0;
  digitalWrite(ledverdeHerval, LOW);
  digitalWrite(ledamareloHerval, HIGH);
  delay(2000);

}



