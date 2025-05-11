/*
 * MotorMovement.h
 *
 *  Created on: May 11, 2025
 *      Author: Richard
 */

#ifndef INC_MOTORMOVEMENT_H_
#define INC_MOTORMOVEMENT_H_

	class MotorMovement
	{
		public:
		MotorMovement(int pin1, int pin2, int pin3, int pin4);
		void moveMotor(float deg, bool dir);

		private:
		const int SPR = 128;
		int pins[4];
		int steps = 0;

		int outputSeq[8][4] = {
		  {0, 0, 0, 1},
		  {0, 0, 1, 1},
		  {0, 0, 1, 0},
		  {0, 1, 1, 0},
		  {0, 1, 0, 0},
		  {1, 1, 0, 0},
		  {1, 0, 0, 0},
		  {1, 0, 0, 1}
		};
	};



#endif /* INC_MOTORMOVEMENT_H_ */
