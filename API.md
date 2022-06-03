# BitIO library API #

### *BitIO(const int\* pins, const size_t numPins)* ###

The constructor creates an instance of a `BitIO` object.  The specified GPIO pins are set to `INPUT_PULLUP` mode to allow them to be used with jumper blocks or dual-inline switches (see `readbyte()` below).

#### Arguments ####

- *pins: const int\**: Array of GPIO pin numbers which will be used as digital inputs.
- *numPins: const size_t*: Number of values in array of GPIO pin numbers.

### *byte readByte() const* ###

This method of the `BitIO` class reads the GPIO pins assigned to the object as digital inputs, interpreting them as a binary value in most-to-least significant bit order, and returns that value.  Since the constructor puts the pins in `INPUT_PULLUP` mode, pins that are left floating or are pulled up to supply voltage are read as `HIGH` or 1, while pins connected to ground will be `LOW` or 0.

#### Returns ####

- *byte*: Returns the binary value representing the states of the GPIO pins.

