/* ds18b20-t85.h - header file for ds18b20-433 project
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
#ifndef DS18B20_T85_H
#define DS18B20_T85_H	1

/* ds18b20-433 port and pin selections for ATtiny85
*/

#define ASYNC_TX_PORT	'B'
#define ASYNC_TX_PIN	PB4
#define T1W_PORT		'B'
#define T1W_PIN			PB3

/* Other options. ToDo: put in common header?
*/
#define ASYNC_BITRATE	9600
#define PASSIVE_TIME	1
#define HZ				1000000

#endif
