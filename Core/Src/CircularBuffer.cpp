#include "CircularBuffer.h"
//#include <iostream>

	CircularBuffer::CircularBuffer(){}
	
	void CircularBuffer::add(float num)
	{
	    if (back < front)
	    {
	        front++;
	    }
	    eep[back] = num;
	    back++;
	    if (back >= MAX)
	    {
	        front++;
	        back = 0;
	    }
	    if (front >= MAX)
	    {
	        front = 0;
	    }
	    
	}
	
	float CircularBuffer::getSum()
	{
	    float sum = 0.0;
	    for (int i=0; i<(int)(sizeof(eep)/sizeof(eep[0])); i++)
		{
			sum += eep[i];
		}
	    return sum;
	}

	/*void CircularBuffer::printData()
	{
	    for (int i=0; i<sizeof(eep)/sizeof(eep[0]); i++)
	    {
	        std::cout << eep[i] << std::endl;
	    }
	}*/
	
	bool CircularBuffer::isEmpty()
	{
	    return front==back ? true : false;
	}
	
	void CircularBuffer::empty()
	{
	    front = 0;
	    back = 0;
	    
	    for(int i=0; i<MAX; i++)
	    {
	        eep[i] = 0.0;
	    }
	}
