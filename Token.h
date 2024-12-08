#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"
class Token {

	enum TokenType type;
	std::string lexeme;
	std::string literal;
	int line;

	Token(TokenType type, std::string lexeme, std::string literal, int line);

public:

	std::string toString();
};

#endif
