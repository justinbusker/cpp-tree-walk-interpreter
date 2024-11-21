#include <iostream>
#include <fstream>
#include <sstream>

class Lox{
public:
	static int main(int argc, char *argv[] ){
		if(argc > 2){
			std::cerr << "Usage: jlox [script]" << std::endl;
		} else if (argc == 2){
			std::string file(argv[1]);
			runFile(file);
		} else {
			runPrompt();
		}

		return 0;
	}

private:

	// running file from input
	static void runFile(std::string file){
		std::ifstream myfile(file);
		std::string curText;
		std::string fullText = "";
		while(getline(myfile, curText)){
			fullText += curText + "\n";
		}
		std::cout << fullText;
	}
	
	// runs whatever user enters
	static void runPrompt(){
			std::string text = "";
		while(true){
			std::cout << "> ";
			std::cin >> text;
		}
	}

	static void run(std::string source){

	    /* Scanner scanner = new Scanner(source);
			List<Token> tokens = scanner.scanTokens();

			for (Token token : tokens){
				std::cout << token << std:e
			}
			
	*/
	}

	static void error(int line, std::string message){
		report(line, "", message);
	}

	static void report(int line, std::string where, std::string message){
		std::cerr << "[Line " << line << "] Error" << where << ": " << message << std::endl;
	}
};

int main(int argc, char *argv[]){
	Lox test;
	test.main(argc, argv);
}
