#define ldr A0
#define temp A2
#define amp A3
#define volt A5
#define led 13
#define btn 2

void setup() {
  pinMode(led, OUTPUT);//Pino 13 como saida do led
  pinMode(btn,INPUT);//Botao como entrada de dados
  pinMode(volt,INPUT);// Sensor de voltagem
  pinMode(ldr, INPUT); // Sensor de luz
  Serial.begin(9600);
  
}
void ligaLed(){
  digitalWrite(led, HIGH);  
}
void apagaLed(){
  digitalWrite(led, LOW); 
}

void loop() {   
  Serial.println(analogRead(amp));
  delay(100);
  if(digitalRead(btn) == HIGH ){ //Se botão for apertado apaga led
      apagaLed();  // 
  }else{
      ligaLed();
  }
  
}
