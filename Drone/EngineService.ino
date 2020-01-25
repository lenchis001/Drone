#include "EngineService.h"

EngineService::EngineService(
    unsigned short maxSpeed,
    unsigned short stableSpeed
#ifdef DEBUG
    ,
    LogService* logService
#endif
)
{
    _logService = logService;
}

void EngineService::setPower(EngineType type, float power)
{
}