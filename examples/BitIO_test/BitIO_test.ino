#include <Arduino.h>
#include <BitIO.h>

#include <Streaming.h>

const int pins[] = {A0, A1, A2, 9, 10, 11};
BitIO bits(pins, DIM(pins));

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial << _BIN(bits.readByte()) << endl;
  delay(100);
}
