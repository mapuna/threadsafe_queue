CC = gcc
CFLAGS = -std=c99 -Ofast -Wall -Werror
LDFLAGS += -lpthread
.PHONY: clean run_tests

tests: make_dir int_test string_test

make_dir: $(shell mkdir bin)

int_test: tests/int_queue.c lib/queue.c lib/queue.h
	$(CC) $(CFLAGS) tests/int_queue.c lib/queue.c $(LDFLAGS) -o bin/int_test

string_test: tests/string_queue.c lib/queue.c lib/queue.h
	$(CC) $(CFLAGS) tests/string_queue.c lib/queue.c $(LDFLAGS) -o bin/string_test

run_tests: int_test string_test
	@echo Running tests $^
	@bin/int_test
	@bin/string_test
	@echo Tests successful

clean:
	rm -rf *.o *~ bin

