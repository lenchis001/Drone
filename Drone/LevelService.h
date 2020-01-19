#include "Arduino.h"

#include "Setup.h"
#include "Point.h"
#include "GyroscopeService.h"
#include "EngineService.h"
#include "LogService.h"
#include "shared_ptr.h"

#ifndef CLASS_LEVEL_SERVICE
#define CLASS_LEVEL_SERVICE

class LevelService
{
private:
    float _destinationRoll, _destinationPitch, _power;

    shared_ptr<GyroscopeService> _gyroscopeService;
    shared_ptr<EngineService> _engineService;
#ifdef DEBUG
    shared_ptr<LogService> _logService;
#endif

    float proportion(float x1, float y1, float y2);
    float calculateDelta(float current, float destination);

public:
    LevelService(
        shared_ptr<GyroscopeService> gyroscopeService,
        shared_ptr<EngineService> engineService
#ifdef DEBUG
        ,shared_ptr<LogService> logService
#endif
    );

    void setPower(float power);

    void refreshState();
};

#endif
