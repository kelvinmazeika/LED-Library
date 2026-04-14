#include <Arduino.h>
#include "LED.h"

Led ledA(37); // Cria e inicia o objeto LED no pino 37.

void setup() {
  
}

void loop() {
  static bool estadoLed = true;

  ledA.setState(estadoLed); // Seta o estado do LED conforme o valor da variável.

  ledA.update(); // Atualiza a saída do LED.
} 