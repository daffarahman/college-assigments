CC = gcc
CFLAGS = -lm

main: main.c math_operations.c
	$(CC) -o main main.c math_operations.c $(CFLAGS)

test: test.c math_operations.c
	$(CC) -o test test.c math_operations.c $(CFLAGS)

clean:
	rm -f main test
