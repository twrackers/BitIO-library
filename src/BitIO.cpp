#include "BitIO.h"

BitIO::BitIO(const int* pins, const size_t numPins) : 
m_numPins(numPins), m_pins(new int[numPins]) {
  // Save pin array so it cannot be altered after
  // object is contructed.
  int* sptr = pins;
  int* dptr = this->m_pins;
  size_t n = this->m_numPins;
  // For all n pins...
  while (n--) {
    // Set pin to pullup mode.
    pinMode(*sptr, INPUT_PULLUP);
    // Save pin number.
    *dptr++ = *sptr++;
  }
}

byte BitIO::readByte() const {
  // Build up result in val.
  byte val = 0;
  // Set up to iterate.
  size_t n = this->m_numPins;
  int* sptr = this->m_pins;
  // For all n pins...
  while (n--) {
    // Shift value left by 1.
    val <<= 1;
    // If GPIO pin HIGH, append a 1 bit to value.
    if (digitalRead(*sptr++) == HIGH) val |= 1;
  }
  // Return result byte to caller.
  return val;
}
