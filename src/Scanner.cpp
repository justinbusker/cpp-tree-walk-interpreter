
#include "Scanner.hpp"
#include <iostream>

	const std::unordered_map<std::string, enum TokenType> keywords = {
		{"and", AND},
		{"class", CLASS},
		{"else", ELSE},
		{"false", FALSE},
		{"for", FOR},
		{"fun", FUN},
		{"if", IF},
		{"nil", NIL},
		{"or", OR},
		{"print", PRINT},
		{"return", RETURN},
		{"super", SUPER},
		{"this", THIS},
		{"true", TRUE},
		{"var", VAR},
		{"while", WHILE}
	};
	
	bool Scanner::isAtEnd(){
		return current >= source.length();
	}

	bool Scanner::match(char expected){
		if (isAtEnd()) return false;
		if (source.at(current) != expected) return false;

		current++;
		return true;
	}

	char Scanner::advance(){
		return source.at(current++);
	}

	void Scanner::addToken(enum TokenType type){
		addToken(type, NULL);
	}

	void Scanner::addToken(enum TokenType type, std::any literal){
		std::cout << "Adding token" << std::endl;
		std::string text = source.substr(start, (current - start));
		tokens.push_back(new Token(type, text, literal, line));
	}


	char Scanner::peek(){
		if(isAtEnd()) return '\0';
		return source.at(current);
	}

	char Scanner::peekNext(){
		if(current+1 >= source.length()) return '\0';
		return source.at(current + 1);
	}

	void Scanner::string() {
		while (peek() != '"' && !isAtEnd()){
			if(peek() == '\n') line++;
			advance();
		}

		if(isAtEnd()){
			//Lox.error(line, "Unterminated string.");
			std::cerr << line << " Unterminated string." << std::endl;
			return;
		}

		advance();


		std::string value = source.substr(start +1, current -1);

		addToken(STRING, value);
	}

	bool Scanner::isDigit(char c){
		return c >= '0' && c <= '9';
	}

	bool Scanner::isAlpha(char c){
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
	}

	bool Scanner::isAlphaNumeric(char c){
		return (isAlpha(c) || isDigit(c));
	}

	void Scanner::number(){
		while (isDigit(peek())) advance();

		if(peek() == '.' && isDigit(peekNext())){
			advance();

			
			while (isDigit(peek())) advance();
		}

		addToken(NUMBER, std::stod(source.substr(start, current)));
	}

	void Scanner::identifier(){
		while(isAlphaNumeric(peek())) { 
		advance(); 
		}
		std::string text = source.substr(start, (current - start));
		
		enum TokenType type;


		auto it = keywords.find(text);
		if (it == keywords.end()) {
			std::cout << "Found keyword: " << text << std::endl;
			type = IDENTIFIER;
		} else {
			type = keywords.at(text);
		}
		
		addToken(type);
	}


	void Scanner::scanToken(){
		char c = advance();

		std::cout << "current char: " << c << std::endl;

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
			case '"': string(); break;

			case ' ':
			case '\r':
			case '\t':
				break;

			case '\n':
				line++;
				break;

			default: 
				if(isDigit(c)){
					number();
				} else if(isAlpha(c)) {
					identifier();
				}

				else {
				//Lox.error("Unexpected character.");
					std::cerr << "Unexpected character." << std::endl;
				}

		}
	}

	

	Scanner::Scanner(std::string source){
		this->source = source;
	}

	std::vector<Token*> Scanner::scanTokens(){
		while (!isAtEnd()){
			start = current;
			scanToken();
		}
		
		tokens.push_back(new Token(myEOF, "", nullptr, line));

		return tokens;
	}

	
