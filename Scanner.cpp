#include <vector>
#include <iostream>
#include "Token.h"
#include "Lox.h"

class Scanner {
private:

	std::string source;
	std::vector<Token*> tokens;
	
	int start = 0;
	int current = 0;
	int line = 1;

	
	bool isAtEnd(){
		return current >= source.length();
	}

	bool match(char expected){
		if (isAtEnd()) return false;
		if (source.at(current) != expected) return false;

		current++;
		return true;
	}

	char advance(){
		return source.at(current++);
	}

	void addToken(enum TokenType type){
		addToken(type, nullptr);
	}

	void addToken(enum TokenType type, void* literal){
		std::string text = source.substr(start, current);
		tokens.push_back(new Token(type, text, literal, line));
	}


	char peek(){
		if(isAtEnd()) return '\0';
		return source.at(current);
	}

	void scanToken(){
		char c = advance();

		switch (c) {
			// single character tokens
			case '(': addToken(LEFT_PAREN); break;
			case ')': addToken(RIGHT_PAREN); break;
			case '{': addToken(LEFT_BRACE); break;
			case '}': addToken(RIGHT_BRACE); break;
			case ',': addToken(COMMA); break;
			case '.': addToken(DOT); break;
			case '-': addToken(MINUS); break;
			case '+': addToken(PLUS); break;
			case ';': addToken(SEMICOLON); break;
			case '*': addToken(STAR); break;

			// cases where token could be two characters
			case '!':
				addToken(match('=') ? BANG_EQUAL : BANG);
				break;
			case '=':
				addToken(match('=') ? EQUAL_EQUAL : EQUAL);
				break;
			case '<':
				addToken(match('=') ? LESS_EQUAL : LESS);
				break;
			case '>':
				addToken(match('=') ? GREATER_EQUAL : GREATER);
				break;

			// comment / slash
			case '/':
				if (match('/')){
					while(peek() != '\n' && !isAtEnd()) advance();
				} else {
					addToken(SLASH);
				}

			case ' ':
			case '\r':
			case '\t':
				break;

			case '\n':
				line++;
				break;

			default: Lox.error("Unexpected character.");

		}
	}

	
public:

	Scanner(std::string source){
		this->source = source;
	}

	std::vector<Token*> scanTokens(){
		while (!isAtEnd()){
			start = current;
			scanToken();
		}
		
		tokens.push_back(new Token(myEOF, "", nullptr, line));

		return tokens;
	}

	
};
