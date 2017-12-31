#ifndef mcp49x2_h
#define mcp49x2_h

#include "Arduino.h"

class mcp49x2
{
	public:
		mcp49x2(int CS, int LDAC);
		void writeDAC(unsigned int val, int ch);
		void shutdownCh(int ch);
		void setBuf(int buf);
		void setGain(int gain);
	private:
		int _CS;
		int _LDAC;
		int _GAIN;
		int _BUF;
		
};
#endif