#ifndef CLASS_LOG_SERVICE
#define CLASS_LOG_SERVICE

#include "Arduino.h"
#include "Setup.h"

#ifdef DEBUG
class LogService
{
public:
    LogService();

    template <class T>
    void debug(T value)
    {
        Serial.print("Debug: ");
        Serial.println(value);
    }
};
#endif

#endif