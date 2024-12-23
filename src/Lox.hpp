#include <iostream>
#include <fstream>
#include <sstream>

class Lox{
public:
	inline static bool hadError = false;

	static int main(int argc, char *argv[] );
		
private:

	// running file from input
	static void runFile(std::string file);
	// runs whatever user enters
	static void runPrompt();
	
	static void run(std::string source);
	
	static void error(int line, std::string message);

	static void report(int line, std::string where, std::string message);
};
