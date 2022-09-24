SHELL  = /bin/sh
CC     = gcc
CFLAGS = -O2 -std=c11 -Wall -Wextra -I./include
RM     = rm -f

Sources    = $(wildcard lib/*.c)
Objects    = $(Sources:.c=.o)
Executable = josephus

.PHONY: clean

$(Executable): $(Objects)
	$(LINK.c) -o $(Executable) $(Objects)

clean:
	$(RM) $(Objects) $(Executable)
