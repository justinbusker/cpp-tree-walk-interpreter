#include "./TokenType.h"
#include <iostream>

class Token {

	enum TokenType type;
	std::string lexeme;
	std::string literal;
	int line;

	
public:

	Token(TokenType type, std::string lexeme, std::string literal, int line){
		this->type = type;
		this->lexeme = lexeme;
		this->literal = literal;
		this->line = line;
	}

	std::string toString(){
		return type + " " + lexeme + " " + literal;
	}
};
