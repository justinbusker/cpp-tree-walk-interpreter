#include "Scanner.hpp"
#include "Token.hpp"
#include <vector>
#include <iostream>

int main(int argc, char *argv[]){

	Scanner test = Scanner("test or and + -");

	std::vector<Token*> t = test.scanTokens();

	std::cout << t.size() << std::endl;

	for (auto x : t){
		std::cout << x->toString();
	}

	return 0;
}
