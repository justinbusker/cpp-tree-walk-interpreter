#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <any>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Token.hpp"
class Scanner {
private:

	std::string source;
	std::vector<Token*> tokens;
	
	int start = 0;
	int current = 0;
	int line = 1;

		
	bool isAtEnd();

	bool match(char expected);

	char advance();

	void addToken(enum TokenType type);

	void addToken(enum TokenType type, std::any literal);


	char peek();

	char peekNext();

	void string();

	bool isDigit(char c);

	bool isAlpha(char c);

	bool isAlphaNumeric(char c);

	void number();

	void identifier();


	void scanToken();

	
public:

	Scanner(std::string source);

	std::vector<Token*> scanTokens();

	
};

#endif
