/*
*    Example-Code that emulates a DS2433 4096 bits EEPROM
*
*   Tested with
*    - DS9490R-Master, atmega328@16MHz as Slave
*/

#include "OneWireHub.h"
#include "DS2433.h"

constexpr uint8_t pin_onewire   { 8 };

auto hub = OneWireHub(pin_onewire);
auto ds2433 = DS2433(0xb3, 0x65, 0xf9, 0x04, 0xd0, 0x14, 0x10);

void setup()
{

    // Setup OneWire
    hub.attach(ds2433);

   uint8_t mem[] = {0x74, 0xf3, 0x48}; // paste in teh Hex-code from the python script 

  ds2433.writeMemory(mem, sizeof(mem), 0x00);
  
}

void loop()
{
    // following function must be called periodically
    hub.poll();
} 
