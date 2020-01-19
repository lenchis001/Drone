#include "LogService.h"

#include "Arduino.h"

#ifdef DEBUG
LogService::LogService()
{
    Serial.begin(9600);
}
#endif