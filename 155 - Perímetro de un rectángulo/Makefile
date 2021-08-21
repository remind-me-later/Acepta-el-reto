.POSIX:
.SUFFIXES:

CC     = cc
CWARN  = -Wall -Wextra -Wdeclaration-after-statement -Werror -pedantic
CFLAGS = -O3 -s

.PHONY: all
all: a.out

a.out: main.c
	$(CC) $(CFLAGS) $(CWARN) -o $@ $^

.PHONY: test
test: tests/input.txt tests/expected.txt a.out
	@./a.out <$< 2>&1 | diff -q $(word 2, $?) - >/dev/null || \
		(echo "Test failed" && exit 1) && \
		(echo "Success, tests passed")

.PHONY: clean
clean:
	rm -f a.out

