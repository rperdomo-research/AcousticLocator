 #ifndef PID_H
    #define PID_H
    
    // Class definition goes here
    class PID
    {
    public:
        // Public members (methods and attributes)
        PID(float kp, float ki, float kd); // Constructor
        void setError(float e);
        void resetAccumulatedError();
        void addError(float e);
        float getAccError();
        float getSignal();
        void setPreviousError();
    
    private:
        // Private members
        float propertionalGain=0.0;
	    float integralGain=0.0;
	    float derivativeGain=0.0;
	
	    float accumulatedError=0.0;
	    float error=0.0;
	    float sum=0.0;
	    float previousError = 0.0;

    };
    
    #endif
