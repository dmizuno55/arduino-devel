CC = gcc
DEST = ./bin
SRC = ./src
TEST = ./test
PROG = ticker
TEST_PROG = ticker_test

$(PROG): clean
	$(CC) -o $(DEST)/$(PROG) -c $(SRC)/*.c

clean:
	rm -rf $(DEST); mkdir $(DEST)

test: $(PROG)
	$(CC) -o $(DEST)/$(TEST_PROG) $(TEST)/*.c $(SRC)/*.c