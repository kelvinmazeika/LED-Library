#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Uma classe para controle não bloqueante de um LED.
 *  Contém métodos para ligar, desligar, piscar
 *  e alternar o estado do LED.
 * 
 * @param pin O pino onde o LED está conectado.
 * 
 * @note O método update() deve ser chamado dentro do
 * loop() para que o controle do LED funcione corretamente.
 */
class Led
{

private:
    uint8_t pin;
    bool state;
    bool turnOffTime;
    uint32_t turnOffTimeValue;
    bool blinkOn;
    uint32_t blinkTimeValue;
    uint16_t blinkQuantity;

    /**
    * @brief Função para controlar o tempo de desligamento do LED.
     * @note Esta função é chamada dentro do método update()
    */
    void functionTurnOffTime();
    /**
    * @brief Função para controlar o piscar do LED.
     * @note Esta função é chamada dentro do método update()
     */
    void functionBlink();

public:

    /**
     * @brief Constrói um objeto Led.
     * @param pin O pino onde o LED está conectado.
     */
    Led(uint8_t pin); //* Método construtor

    /**
     * @brief Liga o LED e cancela modos automáticos.
     */
    void on();

    /**
     * @brief Liga o LED por um tempo determinado e cancela modos automáticos.
     * @param duration O tempo em milissegundos para manter o LED ligado.
     */
    void on(uint32_t duration);

    /**
     * @brief Desliga o LED e cancela modos automáticos.
     */
    void off();

    /**
     * @brief Pisca o LED com uma frequência padrão de 1 Hz e cancela modos automáticos.
     */
    void blink();

    /**
     * @brief Pisca o LED com uma frequência específica e cancela modos automáticos.
     * @param frequency A frequência em Hz.
     */
    void blink(float frequency);

    /**
     * @brief Pisca o LED com uma frequência e quantidade específicas e cancela modos automáticos.
     * @param frequency A frequência em Hz.
     * @param quantity A quantidade de piscadas.
     */
    void blink(float frequency, uint16_t quantity);

    /**
     * @brief Alterna o estado do LED e cancela modos automáticos.
     */
    void toggle();

    /**
     * @brief Define o estado do LED.
     * @param state O estado desejado (true para ligado, false para desligado).
     */
    void setState(bool state);

    /**
     * @brief Obtém o estado atual do LED.
     */
    bool getState();

    /**
     * @brief Obtém o pino onde o LED está conectado.
     */
    uint8_t getPin();

    /**
     * @brief Atualiza o estado do LED.
     * @note Esta função deve ser chamada dentro do loop() para que o controle do LED funcione corretamente.
     */
    void update();
};

#endif