/*
 * CircularBuffer.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Richard
 */

#ifndef INC_CIRCULARBUFFER_H_
#define INC_CIRCULARBUFFER_H_

	// Assuming 10kHz sampling rate with 20ms windows: # of samples = 200
	#define MAX 200

	class CircularBuffer
	{
		private:
		float eep[MAX];
		int front = 0;
		int back = 0;

		public:
		CircularBuffer();
		void add(float num);
		//void printData();
		bool isEmpty();
		void empty();
		float getSum();
		float getPrevious();

	};



#endif /* INC_CIRCULARBUFFER_H_ */
