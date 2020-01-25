#include "Setup.h"
#include "LevelService.h"
#include "GyroscopeService.h"
#include "LogService.h"
#include "EngineService.h"

#ifdef DEBUG
LogService* logService;
#endif
GyroscopeService* gyroscopeService;
LevelService* levelService;
EngineService* engineService;

void setup()
{
#ifdef DEBUG
        logService = new LogService();
#endif
        gyroscopeService = new GyroscopeService();
        engineService = new EngineService(
            MAX_SPEED,
            STABLE_SPEED
#ifdef DEBUG
            ,
            logService
#endif
            );
        levelService = new LevelService(
            gyroscopeService,
            engineService
#ifdef DEBUG
            ,
            logService
#endif
            );

        levelService->setPower(500);
        levelService->setRoll(0);
        levelService->setPitch(0);
}

void loop()
{
        levelService->refreshState();
}
