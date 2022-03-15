An EEPROM writter program used to write data inside the EEPROM on specifics address.

To write a data on a specific address, use the WriteData function inside the arduino setup function like this:

Setup( void )
{
  WriteData( addr_a, data_a );
}

Where addr_a and data_a is an unsigned integer which can be set with a hexadecimal value
