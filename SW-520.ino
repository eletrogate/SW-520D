// DEFINIÇÕES DE PINOS
#define pinMot1A  10
#define pinMot1B  11
#define pinSensor 7
#define INTERVALO 5000
// DECLARAÇÃO DE VARIÁVEIS
unsigned long controleTempo;
int movimento;

void setup() {
  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinSensor, INPUT);
}
void loop() {
  bool ladeira = !digitalRead(pinSensor); // QUANDO ESTÁ INCLINADO == false
  int velocidade = 100 + (ladeira * 150); // SE ESTIVER INCLINADO VAI SOMAR 150 NA VELOCIDADE

  switch (movimento) {
    case -2 : {} // SEM O BREAK EXECUTA O CODIGO DE BAIXO
    case 0 : {   // if ( movimento == -2 || movimento == 0) {
        // PARADO
        digitalWrite(pinMot1A, LOW );
        digitalWrite(pinMot1B, LOW );
        break;
      }
    case 1 : {
        // MOVER PARA FRENTE
        analogWrite(pinMot1A, velocidade );
        analogWrite(pinMot1B, LOW );
        break;
      }
    case -1 : {
        analogWrite(pinMot1A, LOW );
        analogWrite(pinMot1B, velocidade );
        break;
      }
  }
  if ( millis() - controleTempo > INTERVALO) { // CONTROLA A TROCA DE MOVIMENTOS
    movimento++;
    if (movimento > 1) movimento = -2;
    if (movimento == -2 || movimento == 0) controleTempo = ((millis() - INTERVALO) + 500);
    else controleTempo = millis();
  }
}
