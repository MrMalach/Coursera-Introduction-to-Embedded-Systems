#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk


# Common Flags
CO_FLAGS =  -Wall -Werror -g -O0 -std=c99
		
Target	 =	c1m2


ifeq ($(PLATFORM), HOST)

# Compiler Flags and Defines
CC 		 = gcc
LD 		 = ld
OBJDMP	 = objdump
CFLAGS 	 = $(CO_FLAGS)
CPPFLAGS = -DHOST $(INCLUDES)
LDFLAGS  = -Wl,-Map=$(TARGET).map
SIZE 	 = size

else

# Compiler Flags and Defines
# Architectures Specific Flags

LINKER_FILE	= msp432p401r.lds
CPU			= cortex-m4
ARCH		= armv7e-m
SPECS		= nosys.specs

CC		 = arm-none-eabi-gcc
LD		 = arm-none-eabi-ld
OBJDMP 	 = arm-none-eabi-objdump
LDFLAGS	 = -Wl,-Map=$(TARGET).map -T -L ../$(LINKER_FILE)
CFLAGS 	 = $(CO_FLAGS) 					\
			  -mcpu=$(CPU) -m$(ARCH)	\
			  --specs=$(SPECS) -Wall	\
			  -march = armv7e-m			\
			  -mfpu = fpvv4-sp-d16		\
			  -mfloat-abi = hard
CPPFLAGs = -DMSP432 $(INCLUDES)
SIZE	 = arm-none-eabi-size



endif

OBJS = $(SOURCES:.c=.o)
ASM  = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)
PREP = $(SOURCES:.c=.i)

%.o : %.c
	$(CC) -c  $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

.PHONY: compile-all 
compile-all: $(OBJS)

.PHONY: build 
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:	rm -f *.i *.asm *.o *.out *.map

