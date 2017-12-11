  int sensor0 = A5;
  int sensor1 = 1;
  int sensor2 = 2;
  int sensor3 = 3;

  int calibracao = 5;
  
void setup() {
  Serial.begin(9600);
  pinMode(sensor0,INPUT); 
  pinMode(sensor1,INPUT); 
  pinMode(sensor2,INPUT); 
  pinMode(sensor3,INPUT); 

  Serial.print("Calibrando o sensor...");
    for(int i = 0; i < calibracao; i++){
      Serial.print(".");
      delay(1000);
    }
    Serial.println("Sensor Ativado");
}

void loop() {
  sensor0 = analogRead(sensor0);
  Serial.print("Valor de sensor 0: ");
  Serial.println(sensor0);

//  sensor1 = analogRead(sensor1);
//  Serial.print("Valor de sensor 1: ");
//  Serial.println(sensor1);
//
//  sensor2 = digitalRead(sensor2);
//  Serial.print("Valor de sensor 2: ");
//  Serial.println(sensor2);
//
//  sensor3 = digitalRead(sensor3);
//  Serial.print("Valor de sensor 3: ");
//  Serial.println(sensor3);
}
