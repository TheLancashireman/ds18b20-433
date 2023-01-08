# Makefile for ds18b20-433

# Copyright David Haworth
# 
# This file is part of ds18b20-433.
# 
# ds18b20-433 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# ds18b20-433 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with ds18b20-433  If not, see <http://www.gnu.org/licenses/>.


BUILD		?=	build
ISPPORT		?=	/dev/ttyUSB0
OBJ_DIR		?=	$(BUILD)/o
LIB_DIR		?=	$(BUILD)/a
TLIB_DIR	?=	../tiny-bare-metal/tinylib
TIO_DIR		?=	../tiny-bare-metal/tinyio
T1W_DIR		?=	../tiny-bare-metal/tiny1w

GCC			=	avr-gcc
GLD			=	avr-gcc
GAR			=	avr-ar
OBJCOPY		=	avr-objcopy

CC_OPT		+=	-mmcu=attiny85
CC_OPT		+=	-fno-builtin
CC_OPT		+=	-Os
CC_OPT		+=	-g
CC_OPT		+=	-Wall
CC_OPT		+=	-I $(TLIB_DIR)
CC_OPT		+=	-I $(TIO_DIR)
CC_OPT		+=	-I $(T1W_DIR)
CC_OPT		+=	-D ASYNC_BITRATE=9600
CC_OPT		+=	-D ASYNC_TX_PIN=PB4
CC_OPT		+=	-D HZ=1000000
CC_OPT		+=	-D PASSIVE_TIME=1

# Debugging
#CC_OPT		+= -D W1_PRESENCE=0
#CC_OPT		+= -D W1_DBG=1

LD_OPT		+=	-mmcu=attiny85
LD_OPT		+=	-Wl,--gc-sections
LD_OPT		+=	-Os
LD_OPT		+=	-L $(LIB_DIR)

LD_LIB		+=	-ltiny
LD_LIB		+=	-lm

OBJS		+=	$(OBJ_DIR)/ds18b20-433.o

VPATH		+=	$(TLIB_DIR)
VPATH		+=	$(TIO_DIR)
VPATH		+=	$(T1W_DIR)

.PHONY:		default clean hex upload

default:	$(BUILD)/ds18b20-433.elf

clean:
	if [ -d $(BUILD) ] ; then rm -r $(BUILD); fi

hex:		$(BUILD)/ds18b20-433.ihex

$(BUILD)/o:
	mkdir -p $(BUILD)/o

$(BUILD)/ds18b20-433.elf:	$(OBJ_DIR) $(OBJS) $(LIB_DIR)/libtiny.a
	$(GLD) $(LD_OPT) -o $@ $(OBJS) $(LD_LIB)
	

$(OBJ_DIR)/%.o:	%.c
	$(GCC) $(CC_OPT) -o $@ -c $<

$(BUILD)/ds18b20-433.ihex:	$(BUILD)/ds18b20-433.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

upload:		$(BUILD)/ds18b20-433.ihex
	avrdude -P $(ISPPORT) -b 19200 -c avrisp -p t85 -U flash:w:build/ds18b20-433.ihex:i

include $(TIO_DIR)/tinyio.make
include $(T1W_DIR)/tiny1w.make
include $(TLIB_DIR)/tinylib.make
