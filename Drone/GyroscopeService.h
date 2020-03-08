#ifndef CLASS_GYROSCOPE_SERVICE
#define CLASS_GYROSCOPE_SERVICE

#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
//#include "MPU6050.h" // not necessary if using MotionApps include file

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

#include "Point.h"
#include "LogService.h"

class GyroscopeService
{
public:
    void init();

    void refreshState();

    Point getLevel();
private:
    MPU6050 _mpu;
    uint16_t fifoCount;
    bool dmpReady = false;
    uint16_t packetSize;
};

#endif
