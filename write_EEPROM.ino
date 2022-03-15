#include "Function.h"

void setup() {
  InitialiseAddrPins( );
  InitialiseDataPins( );
  
  delay( 10 );
  
  WriteData( 0x01, 0xA0 );
  delay( 10 );
}

void loop() {
  
  delay(10000);
}
