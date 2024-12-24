#include <Arduino.h>
#include "sensing.h"
#include "main.h"

extern SensorsClass Sensors;

struct BoardStatus
{
    uint8_t sleeping = false;
};
static BoardStatus status;

// Sleep threshold.
float sleepLightThreshold = LIGHT_DEFAULT_SLEEP_THRESHOLD;

void powerUp()
{
    Serial.println("waking...");
    // XTrayWiFi.powerUp();
    status.sleeping = false;
}

void powerDown()
{
    Serial.println("sleeping...");
    // XTrayWiFi.powerDown();
    status.sleeping = true;
}

void updateSleeping()
{
    float light = Sensors.light.get();

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

void setup() {
  Serial.begin(115200);
  Sensors.init();
  Serial.println("Check 1 success");
}

void loop() {
  static auto lasttime = 0;
  auto currenttime = millis();
  //Check sleep condition
  if(currenttime - lasttime > 499)
  {
    Serial.println("Check 2 success");
    updateSleeping();
  }
}

