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
#
#------------------------------------------------------------------------------

SHELL=/bin/bash
PLATFORM=HOST
SOURCES =	src/main.c 		\
			src/memory.c	\
			src/stats.c 	\
			src/data.c 		\
			src/course1.c 

INCLUDES = -I include/common/

COURSE1=true
VERBOSE=true

# Common Flags
CO_FLAGS =  -Wall -Werror -g -O0 -std=c99
		
TARGET	 =	finalAssessment


ifeq ($(PLATFORM), HOST)

	# Compiler Flags and Defines
	CC 		 = gcc
	LD 		 = ld
	OBJDMP	 = objdump
	CFLAGS 	 = $(CO_FLAGS)
	CPPFLAGS += -DHOST $(INCLUDES)
	LDFLAGS  = -Wl,-Map=$(TARGET).map
	SIZE 	 = size

else
	SOURCES+= 	src/startup_msp432p401r_gcc.c 	\
				src/system_msp432p401r.c 		\
				src/interrupts_msp432p401r_gcc.c
	
	INCLUDES+= 	-I include/CMSIS/ \
				-I include/msp432/

	# Compiler Flags and Defines
	# Architectures Specific Flags

	LINKER_FILE	= msp432p401r.lds
	CPU			= cortex-m4
	ARCH		= armv7e-m
	SPECS		= nosys.specs

	CC		 = arm-none-eabi-gcc
	LD		 = arm-none-eabi-ld
	OBJDMP 	 = arm-none-eabi-objdump
	LDFLAGS	 = -Wl,-Map=$(TARGET).map -T -L $(LINKER_FILE)
	CFLAGS 	 =  $(CO_FLAGS) 				\
				-mcpu=$(CPU) -m$(ARCH)		\
				--specs=$(SPECS) 			\
				-march = $(ARCH)			\
				-mfpu = fpvv4-sp-d16		\
				-mfloat-abi = hard
	CPPFLAGs = -DMSP432 $(INCLUDES)
	SIZE	 = arm-none-eabi-size

endif

ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

OBJS = $(SOURCES:.c=.o)		# Object files
ASM  = $(SOURCES:.c=.asm)	# Assembly
DEPS = $(SOURCES:.c=.d)		# Dependancy
PREP = $(SOURCES:.c=.i)  	# Preprocessor

%.o : %.c
	$(CC) -c  $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

.PHONY: compile-all 
compile-all: $(OBJS)

.PHONY: build 
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:	
	rm src/*.o src/*.out 	\
	src/*.map src/*.asm 	\
	src/*.i $(TARGET).out 	\
	$(TARGET).map

.PHONY: run 
run: $(TARGET).out
	$(TARGET).out