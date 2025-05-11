#include "MotorMovement.h"

	MotorMovement::MotorMovement(int pin1, int pin2, int pin3, int pin4)
	{
		pins[0] = pin1;
		pins[1] = pin2;
		pins[2] = pin3;
		pins[3] = pin4;
	}

	void MotorMovement::moveMotor(float deg, bool, dir)
	{
		steps = (int)((deg * SPR)/360);

		if (dir)
		{
			for (int i=0; i<steps; i++)
			{
				for (int k=0; k<8; k++)
				{
					/*
					 * digitalWrite(motorPins[0], outputSeq[i][0]); // assign to specific GPIO for IN1
					 * digitalWrite(motorPins[1], outputSeq[i][1]); // assign to specific GPIO for IN2
					 * digitalWrite(motorPins[2], outputSeq[i][2]); // assign to specific GPIO for IN3
					 * digitalWrite(motorPins[3], outputSeq[i][3]); // assign to specific GPIO for IN4
					 * delay(stop);
					 */
				}
			}
		}

		else
		{
			for (int i=0; i<steps; i++)
			{
				for (int k=8; k>0; k--)
				{
					/*
					 * digitalWrite(motorPins[0], outputSeq[i][0]); // assign to specific GPIO for IN1
					 * digitalWrite(motorPins[1], outputSeq[i][1]); // assign to specific GPIO for IN2
					 * digitalWrite(motorPins[2], outputSeq[i][2]); // assign to specific GPIO for IN3
					 * digitalWrite(motorPins[3], outputSeq[i][3]); // assign to specific GPIO for IN4
					 * delay(stop);
					 */
				}
			}
		}
	}
