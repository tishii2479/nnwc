CC = g++
CFLAGS = -std=c++17 -Wall
SRC = main.cpp

main: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o ./out/main
	./out/main
