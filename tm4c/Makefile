# Specify the target architecture and toolchain
TARGET = cortex-m4
TOOLCHAIN = arm-none-eabi
CC = ${TOOLCHAIN}-gcc
LD = ${TOOLCHAIN}-ld

# Linker script (adjust the path if needed)
LDSCRIPT = startup_cortex_m4.ld

#Includes
#INCLUDES = /opt/homebrew/opt/arm-none-eabi-gcc/lib/gcc/arm-none-eabi/14.2.0/include

# C compiler flags (adjust as needed)
#CFLAGS = -I $(INCLUDES) -mcpu=$(TARGET) -mthumb -fno-builtin -Wall -g
CFLAGS = -I -mcpu=$(TARGET) -mthumb -fno-builtin -Wall -g

# Linker flags
#LDFLAGS = -L ${INCLUDES) -T $(LDSCRIPT)
LDFLAGS = -L -T $(LDSCRIPT)

# Libraries
LIBS =

# Project, source and build root dir
PROJ_ROOT = $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
SRC = ${PROJ_ROOT}/src
BUILD = ${PROJ_ROOT}/build

all: blink.elf

blink.o: $(SRC)/blink.c
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(LIBS)

blink.elf: blink.o
	${LD} $(LDFLAGS) -o $(BUILD)/$@ $(BUILD)/$^

clean:
	rm -rf build/*