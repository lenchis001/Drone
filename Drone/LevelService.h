#ifndef CLASS_LEVEL_SERVICE
#define CLASS_LEVEL_SERVICE

#include "Arduino.h"

#include "Setup.h"
#include "Point.h"
#include "GyroscopeService.h"
#include "EngineService.h"
#include "LogService.h"

class LevelService
{
private:
    volatile int _roll, _pitch, _power;

    GyroscopeService* _gyroscopeService;
    EngineService* _engineService;
#ifdef DEBUG
    LogService* _logService;
#endif

    int proportion(int x1, int y1, int y2);
    int calculateDelta(int current, int destination);

public:
    LevelService(
        GyroscopeService* gyroscopeService,
        EngineService* engineService
#ifdef DEBUG
        ,LogService* logService
#endif
    );

    void setPower(int power);
    void setRoll(int roll);
    void setPitch(int pitch);

    void refreshState();
};

#endif
