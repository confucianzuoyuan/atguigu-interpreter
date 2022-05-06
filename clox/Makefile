CFLAGS=-std=c11 -g -fno-common

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

lox: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
