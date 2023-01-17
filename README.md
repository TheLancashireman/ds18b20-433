# ds18b20-433 remote temperature sensor

A remote temperature sensor module using a DS18B20 temperature sensor.
The project has various build options:

* Transmit by wired asynchronous serial protocol.
* Transmit by 433 MHz RF.
* [Future] Transmit by infra-red 38 kHz.

## Hardware

* Attiny microcontroller (ATtinyx5 or ATtinyx4, depending on build options)
* DS18B20 1-wire temperature sensor

Options:
* RFM64W 433 MHz RF module (HopeRF) for RF option
* A 3.3v-capable USB-serial interface (e.g. FT232L board) for direct connection to PC
* A 3.3v-capable micro (e.g. STM32, RP2040) for data-logging

## Additional libraries

* tiny-bare-metal

## License

GPL v3 or later.  See the LICENSE file
