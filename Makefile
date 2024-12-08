C=g++ 

FILES=Lox.cpp Token.cpp Scanner.cpp

all:
	$(C) -std=c++11 $(FILES) 

clean:
	rm a.out
