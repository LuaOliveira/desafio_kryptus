GCC=gcc
CFLAGS=-Wall # mostrar todos os warnings

all: desafio

desafio: Prompt.c
	$(GCC) $(CFLAGS) Prompt.c -o desafio
	@echo COMPILOU

#%: %.c:
#	$(GCC) $(CFLAGS) $< -o $@