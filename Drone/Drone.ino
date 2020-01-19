#include "LevelService.h"
#include "GyroscopeService.h"
#include "LogService.h"

#ifdef DEBUG
shared_ptr<LogService> logService;
#endif
shared_ptr<GyroscopeService> gyroscopeService;
shared_ptr<LevelService> levelService;

void setup()
{
#ifdef DEBUG
    logService = shared_ptr<LogService>(new LogService());
#endif
    gyroscopeService = shared_ptr<GyroscopeService>(new GyroscopeService());
    levelService = shared_ptr<LevelService>(new LevelService(
        gyroscopeService
#ifdef DEBUG
        ,logService
#endif
        ));
}

void loop()
{
    levelService->refreshState();
}
