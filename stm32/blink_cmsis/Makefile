CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=build/blink.map

# Define Includes
PROJECT_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))/..
INCLUDE_PATHS = -I$(PROJECT_ROOT)/chip_headers/CMSIS/Include -I$(PROJECT_ROOT)/chip_headers/CMSIS/Device/ST/STM32F4xx/Include
CFLAGS += $(INCLUDE_PATHS)

# Define the symbol
STM32F411xE = 1
CFLAGS += -DSTM32F411xE

# Define openocd script path
OPENOCD_SCRIPTS_ROOT = /Users/ijohnson/xpack-openocd-0.12.0-4/openocd/scripts/

all : blink.elf

main.o : main.c
	$(CC) $(CFLAGS) $^ -o build/$@

stm32f411_startup.o : stm32f411_startup.c
	$(CC) $(CFLAGS) $^ -o build/$@

blink.elf : main.o stm32f411_startup.o
	$(CC) $(LDFLAGS) build/*.o -o build/$@

load :
	openocd -f $(OPENOCD_SCRIPTS_ROOT)/board/st_nucleo_f4.cfg

clean:
	rm -rf build/*
