/*
 * PID.cpp
 *
 *  Created on: Apr 23, 2025
 *      Author: Richard
 */
#include "PID.h"
#include "CircularBuffer.h"

	CircularBuffer errors;

    PID::PID(float kp=0.0, float ki=0.0, float kd=0.0)
    {
        propertionalGain = kp;
        integralGain = ki;
        derivativeGain = kd;
    }

    void PID::setError(float e)
    {
    	setPreviousError();
        error = e;
        errors.add(e);
    }

    void PID::resetAccumulatedError()
    {
        accumulatedError = 0.0;
    }

    void PID::addError(float e)
    {
        accumulatedError += e;
    }

    float PID::getAccError()
    {
        return accumulatedError;
    }

    void PID::setPreviousError()
    {
    	previousError = error;
    }

    float PID::getSignal()
    {
        sum += propertionalGain*error;
        sum += integralGain*errors.getSum();
        sum += derivativeGain*(error - previousError);

        return sum;
    }




