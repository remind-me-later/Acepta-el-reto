.POSIX:

PROGRAM=volumen
BINARY=$(PROGRAM).out

CWARN= -Wall -Wextra -Werror -pedantic
CFLAGS= -O3 -flto -s $(CWARN)

all: $(BINARY)

$(BINARY): $(PROGRAM).c
	cc $(CFLAGS) -o $(BINARY) $^

test: tests/input.txt tests/expected.txt $(BINARY)
	@./$(BINARY) <$< 2>&1 | diff -q $(word 2, $?) - >/dev/null || \
		(echo "Test failed" && exit 1)
	@echo "Success, tests passed"

.PHONY: clean test
clean:
	rm -f $(BINARY)
