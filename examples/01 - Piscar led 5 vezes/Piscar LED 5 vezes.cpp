/**
 * Código de exemplo para a biblioteca LED, que pisca um LED 5 vezes com a frequência de 2 Hz.
 */
#include <Arduino.h>
#include "LED.h"

Led ledA(37); // Cria e inicia o objeto LED no pino 37.

void setup() {
  ledA.blink(2, 5); // Pisca o led com a frequência de 2 Hz 5 vezes.
}

void loop() {
  ledA.update(); // Atualiza as saídas do LED.
} 