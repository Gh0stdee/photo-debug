#include <Arduino.h>
#include "sensing.h"
#include "wifi_low_level.h"
#include "main.h"
#include <WiFi.h> 

extern SensorsClass Sensors;
extern WiFiStuff XTrayWiFi;

struct BoardStatus
{
    uint8_t sleeping = false; //initially awake
};
static BoardStatus status;

// Sleep threshold.
float sleepLightThreshold = LIGHT_DEFAULT_SLEEP_THRESHOLD;

void powerUp()
{
    Serial.println("waking...");
    Serial.println();
    XTrayWiFi.powerUp();
    delay(10);
    setCpuFrequencyMhz(AWAKE_MCU_CLOCK_SPEED);
    Serial.printf("Current CpuFrequency: %d\n",getCpuFrequencyMhz());
    status.sleeping = false;
}

void powerDown()
{
    Serial.println("sleeping...");
    Serial.println();
    delay(10);
    setCpuFrequencyMhz(SLEEP_MCU_CLOCK_SPEED);
    Serial.printf("Current CpuFrequency: %d\n",getCpuFrequencyMhz());   
    XTrayWiFi.powerDown();
    status.sleeping = true;
}

void updateSleeping()
{
    float light = Sensors.light.get();
    Serial.printf("Board status: %d\n", status.sleeping);

    if (!status.sleeping && light <= sleepLightThreshold) {
        powerDown();
    } 
    else if  (status.sleeping && light > sleepLightThreshold) {
        powerUp();
    }
    else
    {

    }
    static uint32_t lt;
    if (millis() - lt > LIGHT_DEBUG_INTERVAL) {
        lt = millis();
        Serial.printf("light:%.3f\n", light);
    }
}

void setup() 
{
    Serial.begin(115200);
    Sensors.init();
    XTrayWiFi.init();
}

void loop() {
    static auto lasttime = 0; 
    auto currenttime = millis();
    //Check sleep condition
    if(currenttime - lasttime > 499)
    {
    lasttime = currenttime;
    updateSleeping();
    }
}

