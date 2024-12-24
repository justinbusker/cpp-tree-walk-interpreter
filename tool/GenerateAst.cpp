#include <vector>
#include <iostream>
#include <fstream>

void defineType(std::ofstream myFile, std::string baseName, std::vector<std::vector<std::string>> types){

	for (std::vector<std::string> classes : types){


		for (std::string myClass : classes){
			std::cout << myClass << std::endl;
			myFile << "\t" << myClass << "\n";
		}

	}
}

void defineAST(std::string outputDir, std::string baseName, std::vector<std::vector<std::string>> types) {
	std::string path = outputDir + "/" + baseName + ".cpp";
	std::ofstream myFile(path);

	myFile << "#include <vector>\n\nclass " + baseName + " { \n\n";

	

	myFile << "};\n";
	defineType(myFile, baseName, types);
	myFile.close();
}



int main() {
	std::vector<std::vector<std::string>> test = {{"Hello"}, {"Test", "Cheese"}};
	defineAST(".", "test", test);
}
