//Declaração de portas digitais aos quais os led e a entrada digital do sensor vão estar conectados.
int ledvermelho = 8;
int ledamarelo = 9;
int ledverde = 10;
int ledvermelhodois = 11; 

int pinoSensorzero = A5;
int pinoSensorum = A4;
int pinoSensordois = 2;
int pinoSensortres = 3;
//Inicia o sensor em estado 0, ou seja desligado.
int iniciaSensorzero = 0;
int iniciaSensorum = 0;
int iniciaSensordois = 0;
int iniciaSensortres = 0;
//Variável para calibração do sensor
int calibracao = 5;
 
void setup() {
Serial.begin(9600);
 
//Declaração de que os LED's serão usados como saída.
pinMode(ledvermelho,OUTPUT);
pinMode(ledvermelhodois,OUTPUT);
pinMode(ledverde,OUTPUT);
pinMode(ledamarelo,OUTPUT);
 
pinMode(pinoSensorzero,INPUT); //E o sensor uma entrada.
pinMode(pinoSensorum,INPUT);
pinMode(pinoSensordois,INPUT);
pinMode(pinoSensortres,INPUT);
Serial.print("Calibrando o sensor...");
for(int i = 0; i < calibracao; i++){
Serial.print(".");
delay(1000);
}
Serial.println("Sensor Ativado");
}
 
void loop() {
iniciaSensorzero = analogRead(pinoSensorzero);
iniciaSensorum = analogRead(pinoSensorum);
iniciaSensordois = digitalRead(pinoSensordois);
iniciaSensortres = digitalRead(pinoSensortres);
 
Serial.print("Valor do Sensor 0: "); 
Serial.println(iniciaSensorzero);

Serial.print("Valor do Sensor 1: "); 
Serial.println(iniciaSensorum);

Serial.print("Valor do Sensor 2: "); 
Serial.println(iniciaSensordois);

Serial.print("Valor do Sensor 3: "); 
Serial.println(iniciaSensortres);
 
if (iniciaSensorzero < 100) {
  digitalWrite(ledvermelho, HIGH);
} else {
  digitalWrite(ledvermelho, LOW);
  }

if (iniciaSensorum < 100) {
  digitalWrite(ledvermelhodois, HIGH);
} else {
  digitalWrite(ledvermelhodois, LOW);
  }

if (iniciaSensordois == 0) {
  digitalWrite(ledamarelo, HIGH);
} else {
  digitalWrite(ledamarelo, LOW);
  }

if (iniciaSensortres == 0) {
  digitalWrite(ledverde, HIGH);
} else {
  digitalWrite(ledverde, LOW);
  }


   
}
