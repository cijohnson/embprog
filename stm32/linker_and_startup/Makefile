CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=build/linker_and_startup.map

OPENOCD_SCRIPTS_ROOT = /Users/ijohnson/xpack-openocd-0.12.0-4/openocd/scripts/

all : linker_and_startup.elf

main.o : main.c
	$(CC) $(CFLAGS) $^ -o build/$@

stm32f411_startup.o : stm32f411_startup.c
	$(CC) $(CFLAGS) $^ -o build/$@

linker_and_startup.elf : main.o stm32f411_startup.o
	$(CC) $(LDFLAGS) build/*.o -o build/$@

load :
	openocd -f $(OPENOCD_SCRIPTS_ROOT)/board/st_nucleo_f4.cfg

clean:
	del -f build/
