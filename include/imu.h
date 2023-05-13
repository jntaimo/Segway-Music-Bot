#include <string.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>

void imuSetup();
void updateIMU();
void printIMU();

extern sensors_event_t gyroEvent;
extern float roll;
extern float pitch;
extern float yaw;
extern float pitchRate;