#include "Setup.h"
#include "LevelService.h"
#include "GyroscopeService.h"
#include "LogService.h"
#include "EngineService.h"

#ifdef DEBUG
shared_ptr<LogService> logService;
#endif
shared_ptr<GyroscopeService> gyroscopeService;
shared_ptr<LevelService> levelService;
shared_ptr<EngineService> engineService;

void setup()
{
#ifdef DEBUG
    logService = shared_ptr<LogService>(new LogService());
#endif
    gyroscopeService = shared_ptr<GyroscopeService>(new GyroscopeService());
    engineService = shared_ptr<EngineService>(new EngineService(
        MAX_SPEED,
        STABLE_SPEED
#ifdef DEBUG
        ,
        logService
#endif
        ));
    levelService = shared_ptr<LevelService>(new LevelService(
        gyroscopeService,
        engineService
#ifdef DEBUG
        ,
        logService
#endif
        ));
}

void loop()
{
    levelService->refreshState();
}
