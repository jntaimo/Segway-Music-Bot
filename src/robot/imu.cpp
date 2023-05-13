
#include "imu.h"
Adafruit_BNO055 bno = Adafruit_BNO055(55);

sensors_event_t gryoEvent;

float yaw = 0;
float pitch = 0;
float roll = 0;
float pitchRate = 0;

void imuSetup()
{
    if(!bno.begin())
    {
    /* There was a problem detecting the BNO055 ... check your connections */
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    }
    delay(1000);
    bno.setExtCrystalUse(true);
}

void printIMU(){
    Serial.printf("Roll: %.2f ° Pitch: %.2f ° Yaw: %.2f ° Pitch rate: %.2f °/s\n", roll, pitch, yaw, pitchRate);
}

//reads the current gyro readings and stores them in the gyro event and roll/pitch/yaw variables
//also stores the pitchRate
//should be called at 100HZ
void updateIMU(){
    bno.getEvent(&gyroEvent);
    imu::Vector<3> gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
    yaw = gyroEvent.orientation.heading;
    pitch = gyroEvent.orientation.pitch;
    roll = gyroEvent.orientation.roll;
    pitchRate = gyro.z();
}


