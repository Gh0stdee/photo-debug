#ifndef DEFINES_H
#define DEFINES_H

#define LIGHT_MIN_VALUE               ((uint32_t)100)
#define LIGHT_MAX_VALUE               ((uint32_t)3000)
#define LIGHT_DEFAULT_SLEEP_THRESHOLD 0.3  //0.05 Below threshold => SLEEP, Above threshold => AWAKE.
#define LIGHT_DEBUG_INTERVAL          499 // How often light value is printed.
#define LIGHT_SENSOR_PIN              34

// MCU clock speed (in MHz). Options: 80, 160, 240.
#define SLEEP_MCU_CLOCK_SPEED 80
#define AWAKE_MCU_CLOCK_SPEED 240


// WiFi Stuff
#define wifi_ssid "ilfandkym"
#define wifi_pwd  "94263770"

#endif