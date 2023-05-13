#include <Arduino.h>
#include "pid.h"

float runPID(float error,float last_error, float kp, float ki, float kd, float &sumError, float maxSumError, float loopTime){
    sumError += error*loopTime;
    //avoid integral windum
    sumError = constrain(sumError, -maxSumError, maxSumError);
    //standard PID configuration
    float P = kp*error;
    float I = ki*sumError;
    float D = kd*(error-last_error)/loopTime;
    return P + I + D;
}