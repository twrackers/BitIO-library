#ifndef _BIT_IO__H_
#define _BIT_IO__H_

#include <Arduino.h>

#define DIM(x) ((sizeof(x))/(sizeof(*(x))))

// Class to use an arbitrary set of GPIO pins for reading a binary
// value, such as defining a port where an I2C address can be set
// with jumpers or DIP switches.
//
// All assigned bits are put into INPUT_PULLUP mode by the contructor.
// To set a bit in the port to 0, tie the pin to ground.  To set it to 1,
// leave it unconnected so the pullup resistor pulls the pin to logic-high.

class BitIO
{
private:
  const size_t m_numPins; // number of pins being used
  const int* m_pins;      // points to array of pin numbers
  
public:
  // Constructor
  //
  // 'pins' is array of integer values which specify the GPIO
  // pins to be read, listed from highest-order bit down to zero bit.
  // Named pins, such as analog pins like 'A0', can be used.
  // Since a byte will be read, 'numPins' should not exceed 8.
  //
  // @param pins     pointer to array of GPIO pin numbers
  // @param numPins  number of pin numbers in array
  BitIO(const int* pins, const size_t numPins);

  // Read pins in most to least significant bit order,
  // return as single byte.
  //
  // @return byte value
  byte readByte() const;
};

#endif
