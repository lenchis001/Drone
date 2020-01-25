#include "LevelService.h"

#include "math.h"

LevelService::LevelService(
    GyroscopeService* gyroscopeService,
    EngineService* engineService
#ifdef DEBUG
    ,
    LogService* logService
#endif
)
{
    _gyroscopeService = gyroscopeService;
    _engineService = engineService;
#ifdef DEBUG
    _logService = logService;
#endif
}

void LevelService::setPower(int power)
{
    _power = power;
#ifdef DEBUG
    _logService->debug("Power updated: " + String(_power));
    _logService->debug("Power updated: " + String(_power));
#endif
}

void LevelService::setRoll(int roll)
{
    _roll = roll;
#ifdef DEBUG
    _logService->debug("Roll updated: " + String(_roll));
#endif
}

void LevelService::setPitch(int pitch)
{
    _pitch = pitch;
#ifdef DEBUG
    _logService->debug("Destination updated: " + String(_pitch));
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
    _logService->debug("Destination: roll=" + String(_roll));
    _logService->debug("Destination: pitch=" + String(_pitch));
#endif

    auto xDelta = calculateDelta(level.getX(), _roll);
    auto yDelta = calculateDelta(level.getY(), _pitch);

#ifdef DEBUG
    _logService->debug("Delta: roll=" + String(xDelta) + ", pitch=" + String(yDelta));
#endif

    auto frontLeftPower = _power - xDelta + yDelta;
    auto frontRightPower = _power + xDelta + yDelta;
    auto backLeftPower = _power - xDelta - yDelta;
    auto backRightPower = _power + xDelta - yDelta;
    _engineService->setPower(EngineType::FRONT_LEFT, frontLeftPower);
    _engineService->setPower(EngineType::FRONT_RIGHT, frontRightPower);
    _engineService->setPower(EngineType::BACK_LEFT, backLeftPower);
    _engineService->setPower(EngineType::BACK_RIGHT, backRightPower);

#ifdef DEBUG
    _logService->debug("Power: " + String(_power));
    _logService->debug("Engines power:\n" + String(frontLeftPower) + " - " + String(frontRightPower) + "\n" + String(backLeftPower) + "  - " + String(backRightPower));
#endif
}

int LevelService::proportion(int x1, int y1, int y2)
{
    return x1 * y2 / y1;
}

int LevelService::calculateDelta(int current, int destination)
{
    return abs(abs(destination) - abs(current)) * (destination > current ? 1 : -1);
}