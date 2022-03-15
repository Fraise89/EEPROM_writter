#include "Function.h"

// convert an unsigned integer into a binary number
String ToBinary( uint8_t data_a )
{
    String word_l;
    while(data_a!=0) {word_l=(data_a%2==0 ?"0":"1")+word_l; data_a/=2;}
    return word_l;
}
// write data inside the EEPROM
bool WriteData( uint8_t addr_a, uint8_t data_a )
{
  uint8_t addr_l[ADDR_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t data_l[DATA_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  digitalWrite( WREN, LOW );
  ClearDataBus();

  String word_l = ToBinary( addr_a );
  // convert addr String into an uint8_t array
  for( uint8_t i = 0; i < word_l.length(); i++)
  {
    addr_l[ ADDR_SIZE - 1 - i ] = uint8_t( word_l.charAt( word_l.length() - 1 - i ) ) - 48;
  }
  word_l = ToBinary( addr_a );
  // convert data String into an uint8_t array
  for( uint8_t i = 0; i < word_l.length(); i++)
  {
    data_l[ i ] = uint8_t( word_l.charAt( word_l.length() - 1 - i ) ) - 48;
  }

  // set Address
  for( uint8_t i = 0; i < ADDR_SIZE; i++ )
  {
    bool value = addr_l[i] == 1 ? true : false;
    switch( i )
    {
      case 0:
        digitalWrite( ADDR0, value );
        break;
      case 1:
        digitalWrite( ADDR1, value );
        break;
      case 2:
        digitalWrite( ADDR2, value );
        break;
      case 3:
        digitalWrite( ADDR3, value );
        break;
      case 4:
        digitalWrite( ADDR4, value );
        break;
      case 5:
        digitalWrite( ADDR5, value );
        break;
      case 6:
        digitalWrite( ADDR6, value );
        break;
      case 7:
        digitalWrite( ADDR7, value );
        break;
    }
  }
  for( uint8_t i = 0; i < DATA_SIZE; i++ )
  {
    bool value = data_l[i] == 1 ? true : false;
    switch( i )
    {
      case 0:
        digitalWrite( DATA0, value );
        break;
      case 1:
        digitalWrite( DATA1, value );
        break;
      case 2:
        digitalWrite( DATA2, value );
        break;
      case 3:
        digitalWrite( DATA3, value );
        break;
      case 4:
        digitalWrite( DATA4, value );
        break;
      case 5:
        digitalWrite( DATA5, value );
        break;
      case 6:
        digitalWrite( DATA6, value );
        break;
      case 7:
        digitalWrite( DATA7, value );
        break;
    }
  }
  delayMicroseconds( 1 );
  // write
  digitalWrite( WREN, HIGH );
  delayMicroseconds( 1 );
  digitalWrite( WREN, LOW );
  delayMicroseconds( 1 );

  ClearDataBus( );
  
  return true;
}
//initialise address pins
bool InitialiseAddrPins( void )
{
  pinMode( ADDR0, OUTPUT );
  pinMode( ADDR1, OUTPUT );
  pinMode( ADDR2, OUTPUT );
  pinMode( ADDR3, OUTPUT );
  pinMode( ADDR4, OUTPUT );
  pinMode( ADDR5, OUTPUT );
  pinMode( ADDR6, OUTPUT );
  pinMode( ADDR7, OUTPUT );
}
//initialise data pins
bool InitialiseDataPins( void )
{
  pinMode( DATA0, OUTPUT );
  pinMode( DATA1, OUTPUT );
  pinMode( DATA2, OUTPUT );
  pinMode( DATA3, OUTPUT );
  pinMode( DATA4, OUTPUT );
  pinMode( DATA5, OUTPUT );
  pinMode( DATA6, OUTPUT );
  pinMode( DATA7, OUTPUT );
}
// clear the data bus
bool ClearDataBus( void )
{
  digitalWrite( DATA0, LOW );
  digitalWrite( DATA1, LOW );
  digitalWrite( DATA2, LOW );
  digitalWrite( DATA3, LOW );
  digitalWrite( DATA4, LOW );
  digitalWrite( DATA5, LOW );
  digitalWrite( DATA6, LOW );
  digitalWrite( DATA7, LOW );
}
