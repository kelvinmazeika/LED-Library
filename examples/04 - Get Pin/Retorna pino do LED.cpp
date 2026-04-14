/**
 * Código de exemplo para demonstrar o uso do método getPin() da classe Led, que retorna o pino onde o LED está conectado.
 */

#include <Arduino.h>
#include "LED.h"

Led ledA(37); // Cria e inicia o objeto LED no pino 37.

bool iniciado = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
 
  if(!iniciado){
    Serial.println(ledA.getPin()); // Retorna o pino do LED, e em seguida printa na Serial.
    iniciado = true;
  }
  

  ledA.update(); // Atualiza as saídas do LED.
} 