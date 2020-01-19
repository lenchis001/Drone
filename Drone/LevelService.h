#include "Arduino.h"

#include "Setup.h"
#include "Point.h"
#include "GyroscopeService.h"
#include "LogService.h"
#include "shared_ptr.h"

#ifndef CLASS_LEVEL_SERVICE
#define CLASS_LEVEL_SERVICE

class LevelService
{
private:
    float _destinationRoll, _destinationPitch;

    shared_ptr<GyroscopeService> _gyroscopeService;
#ifdef DEBUG
    shared_ptr<LogService> _logService;
#endif

    float proportion(float x1, float y1, float y2);

public:
    LevelService(
        shared_ptr<GyroscopeService> gyroscopeService
#ifdef DEBUG
        ,shared_ptr<LogService> logService
#endif
    );

    void refreshState();
};

#endif
