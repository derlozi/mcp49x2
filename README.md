# mcp49x2
Arduino Library to control either of the MCP49x2 DACs, should work for all of them.

Connections:
Vdd -> 5V

CS -> any I/O Pin

SCK -> SCK

SDI -> MOSI

SHDN -> Gnd

LDAC -> any I/O Pin



Functions:

mcp49x2(int CS, int LDAC);

  Creates new Object, CS is the Pin connected to CS on the DAC, same goes for LDAC (connected to LDAC)
  

writeDAC(unsigned int val, int ch);

  Writes the unsigned int val to the Channel, where 0 is Channel A and 1 is Channel B.
  val can be between 0 and 4096, independantly form wether you use the 8-, 10 or 12 bit DAC.
  
shutdownCh(int ch);
  
  Shuts a channel down,where 0 is Channel A and 1 is Channel B. This makes the output no longer available and connects a 500k resistor       between the output and ground.
  
setBuf(int buf);
  
  Whether the outputs should be buffered or not, only mess wtih this if you know what you are doing, the preset-Value will be good for nearly all applications. Can be 1 or 0.
 
setGain(int gain);

  Whether the ouput should be amplified by 2. If it's 1, you get a normal output, if it's 0, you get the amplified signal.
