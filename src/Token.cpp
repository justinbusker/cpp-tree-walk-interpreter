#include <any>
#include "TokenType.h"
#include "Token.hpp"
#include <iostream>


Token::Token(TokenType type, std::string lexeme, std::any literal, int line){
	this->type = type;
	this->lexeme = lexeme;
	this->literal = literal;
	this->line = line;
}

std::string Token::toString(){
	return  lexeme + " " ;
}
