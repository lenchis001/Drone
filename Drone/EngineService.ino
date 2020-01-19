#include "EngineService.h"

EngineService::EngineService(
    unsigned short maxSpeed,
    unsigned short stableSpeed
#ifdef DEBUG
    ,
    shared_ptr<LogService> logService
#endif
)
{
    _logService = logService;
}

void EngineService::setPower(EngineType type, float power)
{
}