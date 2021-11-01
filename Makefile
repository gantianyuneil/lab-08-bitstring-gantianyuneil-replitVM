CC := gcc
CFLAGS := -O -Wall -Werror -g -std=c99 -D_DEFAULT_SOURCE

all: bitstring.o

test: test_bitstring
	./test_bitstring

test_bitstring: bitstring.o main.o
	$(CC) -o test_bitstring $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *~ *.o test_bitstring

.PHONY: all clean test
