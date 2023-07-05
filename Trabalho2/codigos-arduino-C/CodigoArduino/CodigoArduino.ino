//DEFINE PORTAS DOS SENSORES/LED/BOTAO:
#define ldr A0
#define temp A2
#define amp A3
#define volt A5
#define led 13
#define btn 11 // Int 0 = pino 2

//DEFINE SAIDA DOS SENSORES
#define saida_ldr 12 

//VARIAVEIS AUXILIARES:
int valor_temp, valor_ldr, valor_amp, valor_volt; // Valores dos sensores
int status=1; // status inicia em 1 ( led começa ligado)

void setup() {
 // INTERRUPÇÕES:
  attachInterrupt(0,intBotaoLdr,CHANGE); // Configurando interrupção botao borda de descida
  attachInterrupt(1,intSensores, CHANGE); // Configurando interrupção mudança de borda

  //PINOS: 
  pinMode(led, OUTPUT);//Pino 13 como saida do led
  pinMode(btn,INPUT);//Botao como entrada de dados
  pinMode(volt,INPUT);// Sensor de voltagem
  pinMode(ldr, INPUT); // Sensor de luz
  pinMode(saida_ldr, OUTPUT);
  


  // SERIAL:
  Serial.begin(9600);  
}
void ligaLed(){
  digitalWrite(led, HIGH);  
}
void apagaLed(){
  digitalWrite(led, LOW); 
}

//FUNÇÕES DAS INTERRUPÇÕES:
void intBotaoLdr(){
  if(status == 1){
    apagaLed();
    status = 0;
  }
  else{
    apagaLed();
    status = 1;
  }
  
  
}
void intSensores(){
  apagaLed();
  }

//LOOP:
void loop() { 
  //Recebendo e convertendo valores analogicos:
  valor_temp = (analogRead(temp)/2 - 1); //Convertendo valor temp
  valor_volt = (analogRead(volt)/2); // convertendo voltagem, n ficou exato
  valor_amp = analogRead(amp); // não converti amper
  valor_ldr = analogRead(ldr);

  //Serial:
  Serial.println((analogRead(ldr)) );
  delay(100);

  //Rotina principal:
  if(status == 1){
    ligaLed(); //Led ligado por default
  }

  if(valor_ldr > 49){
    digitalWrite(saida_ldr, HIGH);
  }else {
    digitalWrite(saida_ldr, LOW);
  }
}
