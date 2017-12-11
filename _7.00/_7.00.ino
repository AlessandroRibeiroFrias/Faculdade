int ledvermelhoA = 8;
int ledamareloA  = 9;
int ledverdeA    = 10;

int ledvermelhoB = 11;
int ledamareloB  = 12;
int ledverdeB    = 13;

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
long tempo1 = 8000;
long tempo2 = 0;
long tempoBrasil = 0;
long tempoHerval = 0;

int SemaforoVerdeBrasil = 0;
int SemaforoVerdeHerval = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledvermelhoA, OUTPUT);
  pinMode(ledamareloA, OUTPUT);
  pinMode(ledverdeA, OUTPUT);
  pinMode(ledvermelhoB, OUTPUT);
  pinMode(ledamareloB, OUTPUT);
  pinMode(ledverdeB, OUTPUT);
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
  Serial.print("\nValor do Sensor0: "); 
  Serial.println(iniciaSensor0);
  Serial.print("\nValor do Sensor1: "); 
  Serial.println(iniciaSensor1);
  Serial.print("\nValor do Sensor2: "); 
  Serial.println(iniciaSensor2);
  Serial.print("\nValor do Sensor3: "); 
  Serial.println(iniciaSensor3);
}
void fuzzy_primario(){
  Serial.println("FUZZY PRIMARIO");
  ler_sensores();
  if ((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (tempo2 < 20))
{
    while((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (tempo2 < 20)){
      Serial.println("Sem movimento lado A e sem movimento do lado B");
      Serial.println(tempo2);
     tempo2++;
     delay(1000);
     ler_sensores();
    }
    
}
  if ((SemaforoVerdeBrasil == 1) && (iniciaSensor0 < 400 || iniciaSensor1 < 400)){
      while((iniciaSensor0 < 400 || iniciaSensor1 < 400) && (iniciaSensor2 == 1 && iniciaSensor3 == 1) && (tempoBrasil < 20)){
        Serial.println("Movimento somente na Brasil");
         Serial.println("Tempo verde na Brasil");
         Serial.println(tempoBrasil);
        tempoBrasil++;
        delay(1000);
        ler_sensores();
      }
  }

  if ((SemaforoVerdeHerval == 1) && (iniciaSensor2 == 0 || iniciaSensor3 == 0)){
      while((iniciaSensor0 > 400 && iniciaSensor1 > 400) && (iniciaSensor2 == 0 || iniciaSensor3 == 0) && (tempoHerval < 20)){
        if((SemaforoVerdeBrasil == 0) && (iniciaSensor0 < 400 || iniciaSensor1 < 400) ){
          Serial.println("Entrou !!");
          delay(30000);
        }
        Serial.println("Movimento somente na Herval");
        Serial.println(tempoHerval);
        tempoHerval++;
        delay(1000);
        ler_sensores();
      }
  } 
}
void loop() 
{

  digitalWrite(ledamareloB, LOW);
  digitalWrite(ledvermelhoB, HIGH);
  digitalWrite(ledvermelhoA, HIGH);
    delay(1000);
  digitalWrite(ledvermelhoA, LOW);
  digitalWrite(ledverdeA, HIGH);
  // tempo do primeiro verde;
  Serial.println("VERDE NA BRASIL");
  Serial.println("VERMELHO NA HERVAL");
  //delay(10000);
  SemaforoVerdeHerval = 0;
  SemaforoVerdeBrasil = 1;
  fuzzy_primario();
  tempo2 = 0;
  tempoBrasil = 0;
  tempoHerval = 0;
  digitalWrite(ledverdeA, LOW);
  digitalWrite(ledamareloA, HIGH);
    delay(2000);  
  digitalWrite(ledamareloA, LOW);           
  digitalWrite(ledvermelhoA, HIGH);
  digitalWrite(ledvermelhoB, HIGH);
    delay(1000);
  digitalWrite(ledvermelhoB, LOW);
  digitalWrite(ledverdeB, HIGH);
   Serial.println("VERMELHO NA BRASIL");
   Serial.println("VERDE NA HERVAL");
  //delay(8000);
  SemaforoVerdeBrasil = 0;
  SemaforoVerdeHerval = 1;
  fuzzy_primario();
  tempo2 = 0;
  tempoBrasil = 0;
  tempoHerval = 0;
  digitalWrite(ledverdeB, LOW);
  digitalWrite(ledamareloB, HIGH);
    delay(2000);

  tempo1 = 8000;

}



