#ifndef TOKEN_H
#define TOKEN_H
#include <any>
#include "TokenType.h"

class Token {

	enum TokenType type;
	std::string lexeme;
	std::any literal;
	int line;


public:

	Token(TokenType type, std::string lexeme, std::any literal, int line);
	std::string toString();
};

#endif
