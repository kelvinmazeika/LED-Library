/**
 * Código de exemplo para a biblioteca LED, demonstrando o uso do método setState() para controlar o estado do LED.
 */
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