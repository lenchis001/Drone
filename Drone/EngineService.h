#ifndef CLASS_ENGINE_SERVICE
#define CLASS_ENGINE_SERVICE

#include "Setup.h"

#include "LogService.h"
#include "EngineType.h"

class EngineService
{
private:
    LogService* _logService;

public:
    EngineService(
        unsigned short maxSpeed,
        unsigned short stableSpeed
#ifdef DEBUG
        ,
        LogService* logService
#endif
    );

    void setPower(EngineType type, float power);
};

#endif