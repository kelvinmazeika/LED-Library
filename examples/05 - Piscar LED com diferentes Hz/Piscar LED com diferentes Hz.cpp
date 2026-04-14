/**
 * Código de exemplo para a biblioteca LED, demonstrando o uso do método blink() com diferentes frequências.
 */

#include <Arduino.h>
#include "LED.h"

Led ledA(37); // Cria e inicia o objeto LED no pino 37.
uint8_t pinBootButton(0);

void setup() {
  pinMode(pinBootButton, INPUT_PULLUP);
}

void loop() {
 
  bool bootState = digitalRead(pinBootButton);
  static bool lastBootState = HIGH;
  static bool bootButtonFunction = false;

  if (lastBootState && !bootState) {
    bootButtonFunction = !bootButtonFunction;
  }

  lastBootState = bootState;

  switch (bootButtonFunction)
  {
  case 0:
    ledA.blink(); // Pisca o LED com a frequência padrão de 1 Hz.
    break;
  
  case 1:
    ledA.blink(5); // Pisca o LED com a frequência de 5 Hz.
    break;
  }
  

  ledA.update(); // Atualiza as saídas do LED.
} 