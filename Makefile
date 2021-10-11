GCC=gcc
CFLAGS=-Wall # mostrar todos os warnings

CPROG = $(wildcard *.c)
CPROG := $(CPROG:Prompt.c=)

all: main

.PHONY: main

main: $(CPROG)
	@echo $(CPROG)
	$(GCC) $(CFLAGS) $(CPROG) -o $@