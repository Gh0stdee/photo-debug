#ifndef DEFINES_H
#define DEFINES_H

#define LIGHT_MIN_VALUE               ((uint32_t)100)
#define LIGHT_MAX_VALUE               ((uint32_t)3000)
#define LIGHT_DEFAULT_SLEEP_THRESHOLD 0.3  //0.05 Below threshold => SLEEP, Above threshold => AWAKE.
#define LIGHT_DEBUG_INTERVAL          499 // How often light value is printed.
#define LIGHT_SENSOR_PIN              34

#endif