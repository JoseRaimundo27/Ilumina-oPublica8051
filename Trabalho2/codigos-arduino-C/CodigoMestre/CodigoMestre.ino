#define btn 2 // Botao acionando diretamente a interrupção

void setup() {
  //PINOS:
  pinMode(btn, INPUT);

  // INTERRUPÇÕES:
  attachInterrupt(digitalPinToInterrupt(btn),desligaTudo,CHANGE);

  //SERIAL:
  Serial.begin(9600);
}

void loop() {
}

void desligaTudo(){
  Serial.print('F');
  Serial.flush();
  
}
