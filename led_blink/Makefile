TARGET = test

CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
AS := arm-none-eabi-as
OBJCOPY := arm-none-eabi-objcopy

CFLAGS = -g3 -mcpu=cortex-m4 -mthumb -nostdlib -Os -ffunction-sections -fdata-sections -Wl,--gc-sections -std=c99
CFLAGS += -DSTM32F1 -DSTM32F10X_MD

INCLUDE = -I./include

LIBRARY = -L./lib -lopencm3_stm32f1

SOURCES = main.c  system_stm32f10x.c
ASMS = startup_stm32f303x8.s
OBJECTS = $(patsubst %.c, %.o, $(SOURCES)) $(patsubst %.s, %.o, $(ASMS))

OBJDIR = obj

LDSCR = STM32F103-MD.ld

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).out
	$(OBJCOPY) $< -I ihex -O binary $@

$(TARGET).out: $(OBJECTS)
	$(LD) -T $(LDSCR) $(OBJECTS) -o $@ $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.o: %.s
	$(AS) -g $< -o $@

.PHONY: clean flash

flash:
	st-flash write $(TARGET).bin 0x8000000

clean:
	rm -rf *o *.out *.bin
