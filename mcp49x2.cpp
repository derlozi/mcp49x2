#include "Arduino.h"
#include "SPI.h"
#include "mcp49x2.h"


mcp49x2::mcp49x2(int CS, int LDAC)
{
	_CS = CS;
	_LDAC = LDAC;
	_GAIN = 1;
	_BUF = 0;
	pinMode(_CS, OUTPUT);
	pinMode(_LDAC, OUTPUT);
	digitalWrite(_CS, HIGH);
	digitalWrite(_LDAC, HIGH);
	

}

void mcp49x2::writeDAC(unsigned int val, int ch)
{
	SPI.begin();
	bitWrite(val, 15, ch);
	bitWrite(val, 14, _BUF);
	bitWrite(val, 13, _GAIN);
	bitWrite(val, 12, 1);
	digitalWrite(_CS, LOW);
	SPI.transfer16(val);
	digitalWrite(_LDAC, LOW);
	digitalWrite(_LDAC, HIGH);
	digitalWrite(_CS, HIGH);
	SPI.end();
}

void mcp49x2::shutdownCh(int ch)
{
	SPI.begin();
	unsigned int val = 0;
	bitWrite(val, 15, ch);
	bitWrite(val, 12, 0);
	digitalWrite(_CS, LOW);
	SPI.transfer16(val);
	digitalWrite(_LDAC, LOW);
	delay(5);
	digitalWrite(_LDAC, HIGH);
	digitalWrite(_CS, HIGH);
	SPI.end();
}

void mcp49x2::setBuf(int buf)
{
	_BUF = buf;
}

void mcp49x2::setGain(int gain)
{
	_GAIN = gain;
	
}