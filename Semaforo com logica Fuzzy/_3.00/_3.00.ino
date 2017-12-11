//Declaração de portas digitais aos quais os led e a entrada digital do sensor vão estar conectados.
int ledvermelho = 8;
int ledamarelo = 9;
int ledverde = 10;
int ledvermlhodois = 11;
int Sensorum = 2;
int Sensordois = 3;
int Sensortres = A5;
int Sensorquatro = A4;
//Variável para calibração do sensor
int calibracao = 5;
 
void setup() {
Serial.begin(9600);
 
//Declaração de que os LED's serão usados como saída.
pinMode(ledvermelho,OUTPUT);
pinMode(ledamarelo,OUTPUT);
pinMode(Sensortres,OUTPUT);
pinMode(Sensorquatro,OUTPUT);
 
pinMode(Sensorum,INPUT);
pinMode(Sensordois,INPUT);
pinMode(Sensortres,INPUT);
pinMode(Sensorquatro,INPUT);

Serial.print("Calibrando o sensor...");
for(int i = 0; i < calibracao; i++){
Serial.print(".");
delay(1000);
}
Serial.println("Sensor Ativado");
}
 
void loop() {
//A cada ciclo, ele faz uma nova leitura do estado do sensor de presença 
Sensorum = digitalRead(Sensorum);
Sensordois = digitalRead(Sensordois);
Sensortres = analogRead(Sensortres);
Sensorquatro = analogRead(Sensorquatro);
Serial.println("Sensor 1:");
Serial.println(Sensorum);
//Serial.println("Sensor 2:");
//Serial.println(Sensordois);
//Serial.println("Sensor 3:");
//Serial.println(Sensortres);
//Serial.println("Sensor 4:");
//Serial.println(Sensorquatro);
if (Sensorum == 0) {
  digitalWrite(ledvermelho, HIGH);
} else{
  digitalWrite(ledvermelho, LOW);
}
}
