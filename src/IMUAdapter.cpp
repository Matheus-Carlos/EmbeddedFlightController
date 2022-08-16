#include "IMUAdapter.h"

#define GYRO_RANGE 250
#define ACC_OFFSET 2048
#define ACC_TO_G 1.0/16834.0
#define GYRO_TO_RAD_S 3.1415/180.0/131.2

IMUAdapter::IMUAdapter() {

}


void IMUAdapter::begin() {
    fusion.setup( imu.ax(), imu.ay(), imu.az() );

    imu.setup();
    imu.setBias();
}

void IMUAdapter::update() {
    fusion.update( imu.gy(), imu.gx(), imu.gz(), imu.ay(), imu.ax(), imu.az() );
}


void IMUAdapter::getRPY(float rot[]) {
    rot[0] = -fusion.roll();
    rot[1] = fusion.pitch();
    rot[2] = fusion.yaw();
}

void IMUAdapter::printRotation() {
    Serial.print("Roll:");
    Serial.print(-fusion.roll() * 180.0/3.1415);
    Serial.print(" Pitch:");
    Serial.print(fusion.pitch() * 180.0/3.1415);
    Serial.print(" Yaw:");
    Serial.print(fusion.yaw() * 180.0/3.1415);
    Serial.print(" ");
}