.POSIX:

CWARN= -Wall -Wextra -Werror -pedantic
CFLAGS= -O3

all: a.out

a.out: main.c
	cc $(CFLAGS) $(CWARN) -o a.out $^

test: tests/input.txt tests/expected.txt a.out
	@./a.out <$< 2>&1 | diff -q $(word 2, $?) - >/dev/null || \
		(echo "Test failed" && exit 1)
	@echo "Success, tests passed"

clean:
	rm a.out

.PHONY: clean test

