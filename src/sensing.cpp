#include <sensing.h>
#include <Arduino.h>

void SensorsClass::init()
{
    light.init();
}

void SensorsClass::Light::init()
{
    pinMode(LIGHT_SENSOR_PIN, INPUT);
}

float SensorsClass::Light::get() const
{
    return 1.0f
           - float(min(max(uint32_t(getRaw()), LIGHT_MIN_VALUE), LIGHT_MAX_VALUE) - LIGHT_MIN_VALUE)
                 / (LIGHT_MAX_VALUE - LIGHT_MIN_VALUE);
}

float SensorsClass::Light::getRaw() const
{
    return analogRead(LIGHT_SENSOR_PIN);
}

bool SensorsClass::Light::isAvailable() const
{
    return analogRead(LIGHT_SENSOR_PIN) != 0;
}