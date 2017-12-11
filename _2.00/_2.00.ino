int ledvermelho1 = 8;
int ledamarelo1  = 9;
int ledverde1    = 10;

int ledvermelho2 = 11;
int ledamarelo2  = 12;
int ledverde2    = 13;

int pinoSensor0 = 0;
int pinoSensor1 = 1;
int pinoSensor2 = 2;
int pinoSensor3 = 3;

//Inicia o sensor em estado 0, ou seja desligado.
int iniciaSensor = 0;
//Variável para calibração do sensor
int calibracao = 45;


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

  Serial.print("Semaforo com logica Fuzzy");
  Serial.print("\nCalibrando os sensores\n");
  for(int i = 0; i < calibracao; i++){
   Serial.print(".");
   delay(500);
  }
  Serial.println("\nSensores Ativado");
}
void loop() 
{

  digitalWrite(ledamarelo2, LOW);
  digitalWrite(ledvermelho2, HIGH);
  digitalWrite(ledvermelho1, HIGH);
    delay(1000);
  digitalWrite(ledvermelho1, LOW);
  digitalWrite(ledverde1, HIGH);
    delay(8000);
    fuzzy_primario();
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
}

void fuzzy_primario(){
pinoSensor0 = digitalRead(pinoSensor0);
Serial.print("\nValor do Sensor0: "); 
Serial.println(pinoSensor0);

pinoSensor1 = digitalRead(pinoSensor1);
Serial.print("\nValor do Sensor1: "); 
Serial.println(pinoSensor1);

pinoSensor2 = digitalRead(pinoSensor2);
Serial.print("\nValor do Sensor2: "); 
Serial.println(pinoSensor2);

pinoSensor3 = digitalRead(pinoSensor3);
Serial.print("\nValor do Sensor3: "); 
Serial.println(pinoSensor3);
}

