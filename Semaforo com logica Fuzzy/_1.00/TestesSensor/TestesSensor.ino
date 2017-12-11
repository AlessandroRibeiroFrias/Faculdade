  
// Programa : Sensor de presenca com modulo PIR
// Autor : Arduino e Cia

int pinoledverm = 8; //Pino ligado ao led vermelho
int pinoledazul = 9; //Pino ligado ao led azul
int pinopir = 0;  //Pino ligado ao sensor PIR
int acionamento;  //Variavel para guardar valor do sensor

void setup()
{
  Serial.print("Valor do Sensor PIR: "); 
  Serial.println(pinopir);
  pinMode(pinoledverm, OUTPUT); //Define pino como saida
  pinMode(pinoledazul, OUTPUT); //Define pino como saida
  pinMode(pinopir, INPUT);   //Define pino sensor como entrada

}

void loop()
{
  
 acionamento = analogRead(pinopir); //Le o valor do sensor PIR
 Serial.print("Valor do Sensor PIR: "); 
 Serial.println(pinopir);
 if (acionamento == LOW)  //Sem movimento, mantem led azul ligado
 {
    digitalWrite(pinoledverm, LOW);
    digitalWrite(pinoledazul, HIGH);
 }
 else  //Caso seja detectado um movimento, aciona o led vermelho
 {
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledazul, LOW);
 }
}
