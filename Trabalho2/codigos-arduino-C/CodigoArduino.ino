#define an5 A5
#define led 13
#define btn 2

void setup() {
  pinMode(led, OUTPUT);//Pino 13 como saida do led
  pinMode(btn,INPUT);//Pino 0 como entrada para interrupção int0
  pinMode(an5,INPUT);
  Serial.begin(9600);
  
}
void ligaLed(){
  digitalWrite(led, HIGH);   // LED LIGADO POR DEFAULT
}
void apagaLed(){
  digitalWrite(led, LOW); 
}

void loop() {   
  Serial.println(analogRead(an5));
  delay(100);
  if(digitalRead(btn) == HIGH ){ //Se botão for apertado apaga led
      apagaLed();  // 
  }else{
      ligaLed();
  }
  
}
