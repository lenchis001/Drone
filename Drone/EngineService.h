#include "Setup.h"

#include "shared_ptr.h"
#include "LogService.h"
#include "EngineType.h"

#ifndef CLASS_ENGINE_SERVICE
#define CLASS_ENGINE_SERVICE

class EngineService
{
private:
    shared_ptr<LogService> _logService;

public:
    EngineService(
        unsigned short maxSpeed,
        unsigned short stableSpeed
#ifdef DEBUG
        ,
        shared_ptr<LogService> logService
#endif
    );

    void setPower(EngineType type, float power);
};

#endif