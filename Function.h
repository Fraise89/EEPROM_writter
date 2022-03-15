#include "Arduino.h"
#include "Constant.h"

String ToBinary          ( uint8_t data_a );
bool   WriteData         ( uint8_t addr_a, uint8_t data_a );
bool   InitialiseDataPins( void );
bool   InitialiseAddrPins( void );
bool   ClearDataBus      ( void );
