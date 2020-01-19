#include "LevelService.h"

LevelService::LevelService(
    shared_ptr<GyroscopeService> gyroscopeService
#ifdef DEBUG
    ,shared_ptr<LogService> logService
#endif
)
{
    _gyroscopeService = gyroscopeService;
#ifdef DEBUG
    _logService = logService;
#endif
}

void LevelService::refreshState()
{
#ifdef DEBUG
    _logService->debug("refreshState requested");
#endif

    auto level = _gyroscopeService->getLevel();

#ifdef DEBUG
    _logService->debug("Current level is: x=" + String(level.getX()) + ", y=" + String(level.getY()));
#endif

    level.getX();
}

float LevelService::proportion(float x1, float y1, float y2)
{
    return x1 * y2 / y1;
}