CC := g++
CFLAGS := -std=c++17 -Wall -O2
TEST_SRC := $(wildcard tests/*/*.cpp)

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o ./out/main
	./out/main

test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC)
	./out/test_matrix.o
