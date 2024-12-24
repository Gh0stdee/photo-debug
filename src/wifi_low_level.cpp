#include <WiFi.h>
#include "define.h"
#include "wifi_low_level.h"

WiFiStuff XTrayWiFi;

void WiFiStuff::powerUp() 
{
    WiFi.setSleep(WIFI_PS_MIN_MODEM); 
    Serial.println("Wifi power up");
}
void WiFiStuff::powerDown() 
{   WiFi.setSleep(WIFI_PS_MAX_MODEM);
    Serial.println("Wifi power down");
}

void WiFiStuff::init()
{
    WiFi.mode(WIFI_STA);
    Serial.println("set to wifi station mode");
    if (connect()) {
        
    }
    Serial.println("Finished init.");
}

bool WiFiStuff::connect()
{
    WiFi.begin(wifi_ssid,wifi_pwd);
    Serial.printf("Connecting to WiFi...");

    
    while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
    }
    Serial.println("");
    Serial.println("Connected to Wifi.");
    return true;
}
