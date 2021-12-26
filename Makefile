CC = g++
CFLAGS = -std=c++17 -Wall

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o ./out/main
	./out/main

test: tests/math/test_matrix.cpp
	$(CC) $(CFLAGS) -o ./out/test_matrix.o tests/math/test_matrix.cpp
	./out/test_matrix.o
