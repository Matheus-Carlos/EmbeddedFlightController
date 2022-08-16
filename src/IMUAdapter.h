#pragma once

#include <imuFilter.h>
#include <basicMPU6050.h>

constexpr float GAIN = 0.5;

class IMUAdapter {
    private:
        basicMPU6050<> imu;
        imuFilter<&GAIN> fusion;

    public:
        float rot[3];
        IMUAdapter();
        void begin();
        void update();
        void getRPY(float rot[]);
        void printRotation();
};