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

  if (lastBootState && !bootState) {
    ledA.toggle(); // Altera o estado do LED quando o botão Boot for pressionado.
  }

  lastBootState = bootState;
  

  ledA.update(); // Atualiza as saídas do LED.
} 