#include "LED.h"

Led::Led(uint8_t pin) :
    pin(pin),
    state(LOW),
    turnOffTime(false),
    turnOffTimeValue(0),
    blinkOn(false),
    blinkTimeValue(0),
    blinkQuantity(0)
{
    pinMode(this->pin, OUTPUT);
}

void Led::on()
{
    this->state = HIGH;
    turnOffTime = false;
    blinkOn = false;
}

void Led::on(uint32_t duration)
{
    on();
    turnOffTime = true;
    turnOffTimeValue = millis() + duration;
    blinkOn = false;
}

void Led::off()
{
    state = LOW;
    blinkOn = false;
    turnOffTime = false;
}

void Led::blink()
{
    blinkOn = !blinkOn;
    blinkTimeValue = 1000;
    turnOffTime = false;
    blinkQuantity = -1;
}

void Led::blink(float frequency)
{
    if (frequency <= 0)
        frequency = 1;
    blinkOn = !blinkOn;
    blinkTimeValue = 500.0f / frequency;
    turnOffTime = false;
    blinkQuantity = -1;
}

void Led::blink(float frequency, uint16_t quantity)
{
    if (frequency <= 0)
        frequency = 1;
    blinkOn = !blinkOn;
    blinkTimeValue = 500.0f / frequency;
    blinkQuantity = quantity * 2;
    turnOffTime = false;
}

void Led::toggle()
{
    state = !state;
    turnOffTime = false;
    blinkOn = false;
}
void Led::setState(bool state)
{
    this->state = state;
    turnOffTime = false;
    blinkOn = false;
}

bool Led::getState()
{
    return digitalRead(this->pin);
}

uint8_t Led::getPin()
{
    return this->pin;
}

void Led::update()
{

    if (blinkOn)
        functionBlink();

    if (turnOffTime)
    {
        functionTurnOffTime();
    }
    digitalWrite(this->pin, this->state);
}

void Led::functionBlink()
{
    static uint32_t before = 0;
    if (millis() - before >= blinkTimeValue)
    {
        state = !state;
        before = millis();
        if (blinkQuantity > 0)
            blinkQuantity--;
    }
    if (blinkQuantity == 0)
        blinkOn = false;
}

void Led::functionTurnOffTime()
{
    if (millis() >= turnOffTimeValue)
    {
        state = LOW;
        turnOffTime = false;
    }
}