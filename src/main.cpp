#include <Arduino.h>
#include "sensing.h"
#include "main.h"

static auto lasttime = 0; 

extern SensorsClass Sensors;

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
    // XTrayWiFi.powerUp();
    delay(10);
    setCpuFrequencyMhz(AWAKE_MCU_CLOCK_SPEED);
    status.sleeping = false;
}

void powerDown()
{
    Serial.println("sleeping...");
    Serial.println();
    delay(10);
    setCpuFrequencyMhz(SLEEP_MCU_CLOCK_SPEED);
    // XTrayWiFi.powerDown();
    status.sleeping = true;
}

void updateSleeping()
{
    float light = Sensors.light.get();
    Serial.printf("Board status: %d\n", status.sleeping);
    //delay(2000);

    if (!status.sleeping && light <= sleepLightThreshold) {
        powerDown();
    } 
    else if  (status.sleeping && light > sleepLightThreshold) {
        powerUp();
    }
    else
    {

    }
    //static uint32_t lt;
    if (millis() - lasttime > LIGHT_DEBUG_INTERVAL) {
        lasttime = millis();
        Serial.printf("light:%.3f\n", light);
    }
}

void setup() {
  Serial.begin(115200);
  Sensors.init();
  Serial.println("Check 1 success");
}

void loop() {
  auto currenttime = millis();
  //Check sleep condition
  if(currenttime - lasttime > 499)
  {
    Serial.println("Check 2 success");
    updateSleeping();
  }
}

