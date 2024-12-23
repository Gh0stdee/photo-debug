#include <define.h>
#include <Adafruit_Sensor.h>
struct SensorsClass
{
    void init();

    struct Light
    {
        void init();
        float get() const;    // Gets normalised [0-1] reading.
        float getRaw() const; // Gets raw reading.
        bool isAvailable() const;
    } light;
};

extern SensorsClass Sensors;