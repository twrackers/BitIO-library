# BitIO #

----------

The `BitIO` library allows an ordered set of GPIO pins to be used as a multi-bit digital input port.

This library is useful for sketches which require a byte value which needs to be settable during runtime.  A good example of this would be to set the address of an I<sup>2</sup>C peripheral, either the device being programmed or a separate device with which this device will communicate.  

In an application where multiple processors will be acting as peripherals on the same I<sup>2</sup>C bus, each needs a unique 7-bit address.  (A few addresses are reserved by the I<sup>2</sup>C standard.)  If these addresses were hard-coded into the sketch for each peripheral, the source file for each would need to be edited with distinct byte constants, such as `const byte i2cAddr = 0x70;`.  If instead the device had some uncommitted GPIO pins, those pins could be connected to jumper blocks or dual-inline switches, allowing bits to be read at runtime to adjust the address to be used on each device.  If, say, you want to allow a range of addresses of 0x70 to 0x7F, the low four bits needs to be adjustable.  To accomplish this on a processor which is not yet using GPIO pins A0, A1, 8, and 9, you could do the following.

    #include <BitIO.h>
	. . .
	const byte i2CBaseAddr = 0x70;
	byte i2cAddr;		// will hold actual address after setup
	. . .
	void setup() {
		. . .
		// A0 and A1 are 'analog input' GPIO on Arduino.
		// All four bits can be used as digital inputs.
		// DIM() macro defined in BitIO.h.
		const int addrIn[] = {A0, A1, 8, 9};
		BitIO addrBits(addrIn, DIM(addrIn));	// DIM returns 4 here
		i2cAddr = i2cBaseAddr + addrBits.readByte();
		. . .
	}

The four pins will be read in the order given and will be assigned from high to low order.  So if pins A0 and A1 were left unconnected (since all pins are set to `INPUT_PULLUP` mode in the class constructor) and pins 8 and 9 were grounded, the BitIO `readByte()` method would return bits `1100` or hex value 0xC.  This would result in `i2cAddr` being set to `0x7C`.

This class *can* be used to read the assigned GPIO pins repeatedly in the `loop()` function, but it's more intended to be used only during initialization in `setup()`.

## Examples ##

See sketch `BitIO_test` in the `examples` directory of this repository for a sample use of the `BitIO` library.

## Installation ##

Instructions for installing the `BitIO` library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/BitIO-library/blob/main/INSTALL.md](https://github.com/twrackers/BitIO-library/blob/main/INSTALL.md).
