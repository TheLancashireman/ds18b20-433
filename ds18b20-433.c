/* ds18b20-433.c - a remote temperature sensor
 *
 * (c) David Haworth
 *
 *  This file is part of ds18b20-433.
 *
 *  ds18b20-433 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ds18b20-433 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ds18b20-433.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 *                             |--v--|
 *                    PB5/Rst -|1   8|- Vcc
 *          (ds18b20 I/O) PB3 -|2   7|- PB2
 *           (serial out) PB4 -|3   6|- PB1
 *                        Gnd -|4   5|- PB0/PCINT0
 *                             |-----|
*/

#include "ds18b20-433.h"
#include "tinylib.h"
#include "tinyio.h"
#include <avr/pgmspace.h>

int main(void)
{
	u16_t temp = DS18B20_INVALID_TEMP;

	printf(PSTR("Hello, world!\n"));

	for (;;)
	{
		temp = ds18b20_read_temp();
		printf(PSTR("Temperature 0x%04x\n"), temp);
	}

	return 0;
}
