#include <vector>
#include <iostream>
#include "Token.h"

class Scanner {
private:

	std::string source;
	std::vector<Token>* tokens = new std::vector<Token>;
	
	int start = 0;
	int current = 0;
	int line = 1;

	Scanner(std::string source){
		this->source = source;
	}
};
