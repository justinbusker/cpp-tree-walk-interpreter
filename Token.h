#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"
class Token {

	enum TokenType type;
	std::string lexeme;
	void* literal;
	int line;


public:

	Token(TokenType type, std::string lexeme, void* literal, int line);
	std::string toString();
};

#endif
