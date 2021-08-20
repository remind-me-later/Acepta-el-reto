.POSIX:
.SUFFIXES:

PROGRAM = modelo

CC     = cc
CWARN  = -Wall -Wextra -Wdeclaration-after-statement -Werror -pedantic
CFLAGS = -std=c11 -O3 -s

.PHONY: all
all: $(PROGRAM).out

$(PROGRAM).out: $(PROGRAM).c
	cc $(CFLAGS) $(CWARN) -o $@ $^

.PHONY: test
test: tests/input.txt tests/expected.txt $(PROGRAM).out
	@./$(PROGRAM).out <$< 2>&1 | diff -q $(word 2, $?) - >/dev/null || \
		(echo "Test failed" && exit 1) && \
		(echo "Success, tests passed")

.PHONY: clean
clean:
	rm -f $(PROGRAM).out

