#include <Servo.h>

// Definição dos servos para cada dedo
Servo servoDedao;              // Servo do dedão (polegar)
Servo servoIndicador;          // Servo do dedo indicador
Servo servoMedio;              // Servo do dedo médio
Servo servoAnelar;             // Servo do dedo anelar
Servo servoMindinho;           // Servo do dedo mindinho

int numero = 0;                // Variável para armazenar o número aleatório

void setup() {
  // Configuração dos pinos
  pinMode(13, INPUT);          // Botão de controle
  pinMode(8, OUTPUT);          // LED 1
  pinMode(9, OUTPUT);          // LED 2
  pinMode(10, OUTPUT);         // LED 3
  pinMode(11, OUTPUT);         // LED 4
  pinMode(12, OUTPUT);         // LED 5

  // Conectar os servos aos pinos correspondentes
  servoDedao.attach(6);        // Dedo dedão no pino 6
  servoIndicador.attach(5);    // Dedo indicador no pino 5
  servoMedio.attach(4);        // Dedo médio no pino 4
  servoAnelar.attach(3);       // Dedo anelar no pino 3
  servoMindinho.attach(2);     // Dedo mindinho no pino 2
}

void loop() {
  // Quando o botão é pressionado, os LEDs acendem
  while (digitalRead(13) == HIGH) {
    // Liga e desliga os LEDs sequencialmente
    for (int i = 8; i <= 12; i++) {
      digitalWrite(i, HIGH);
      delay(500); // Aguarda 500 milissegundos
      digitalWrite(i, LOW);
    }

    // Gera um número aleatório entre 1 e 3
    numero = random(1, 4); // 4 é exclusivo

    // Espera 4 segundos antes de realizar o gesto
    delay(4000); 

    // Executa a ação correspondente ao número gerado
    if (numero == 1) {
      // Papel
      servoDedao.write(0); 
      servoIndicador.write(0);
      servoMedio.write(0);
      servoAnelar.write(0);
      servoMindinho.write(0);
    } else if (numero == 2) {
      // Tesoura
      servoDedao.write(0); 
      servoIndicador.write(180);
      servoMedio.write(180);
      servoAnelar.write(0);
      servoMindinho.write(0);
    } else if (numero == 3) {
      // Pedra
      servoDedao.write(130); 
      servoIndicador.write(180);
      servoMedio.write(180);
      servoAnelar.write(180);
      servoMindinho.write(180);
    }

    // Espera 5 segundos antes de fechar a mão
    delay(5000); 
    
    // Fecha a mão (todos os dedos na posição fechada)
    servoDedao.write(0); 
    servoIndicador.write(0);
    servoMedio.write(0);
    servoAnelar.write(0);
    servoMindinho.write(0);
  }
}
