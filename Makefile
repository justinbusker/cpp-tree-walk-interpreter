C=g++ 

FILES= ./src/main.cpp ./src/Lox.cpp ./src/Token.cpp ./src/Scanner.cpp

all:
	$(C) -std=c++17 $(FILES) 

clean:
	rm a.out
