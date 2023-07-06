#include <TimerOne.h>
#define btn 2 // Botao acionando diretamente a interrupção
char valor_recebido;
String buf;
void setup() {
  //PINOS:
  pinMode(btn, INPUT);

  // INTERRUPÇÕES:
  attachInterrupt(digitalPinToInterrupt(btn),desligaTudo,CHANGE);
  Timer1.attachInterrupt(solicitaRecebimento);
  //TIMER:
  Timer1.initialize(1000000);  //Inicialização do timer 1 (auto reload)
  //SERIAL:
  Serial.begin(9600);
}

void loop() {
   while(Serial.available()>0){
      valor_recebido = Serial.read();
      if(valor_recebido == 'X'){
        buf = Serial.read();
        Serial.println(buf);
      }
      
   }
}

void solicitaRecebimento(){
  Serial.print('A'); //Pede informação para o MIC A
  Serial.flush();
}
void desligaTudo(){
  Serial.print('F');
  Serial.flush();
  
}
