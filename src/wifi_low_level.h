#ifndef WIFI_LOW_LEVEL_H
#define WIFI_LOW_LEVEL_H


class WiFiStuff
{
public:

    // Commands.
    void powerUp();
    void powerDown();
    void init();
    //void syncTime();

private:
    bool connect();
};

#endif