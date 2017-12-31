#include <mcp49x2.h>

  mcp49x2 mcp49x2(10, 9);//Creates a new Object with the Chip-Select-Pin as Pin 10 and  the LDAC-Pin as Pin 9

void setup() 
{

}

void loop() {//Creates a stair-Signal at Output A
mcp49x2.writeDAC(1024, 0); 
mcp49x2.writeDAC(2048, 0);
mcp49x2.writeDAC(3072, 0);
mcp49x2.writeDAC(4095, 0);
mcp49x2.writeDAC(0, 0);

}
