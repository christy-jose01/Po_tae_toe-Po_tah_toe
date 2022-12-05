#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include "functions.h"

using namespace std;

int main (int argc, char** argv){
	// throw error if we dont have the right arguments
	if (argc < 3){
		throw std::invalid_argument("Usage: ./wordrange <INPUT FILE> <OUTPUT FILE> ");
	}

	// line 17 - 21 are copied from my hw2 wrapper.cpp file
	ifstream input;
	ofstream output;
	// opens the respective input and output files
	input.open(argv[1]);
	output.open(argv[2]);

	// line 24 - 28 are copied from the treewrapper file from the BST codes folder
	string command; // to store the next command and operation
	char *com, *dummy; // for using with strtok, strtol
	char *str1; 
	char *str2;
	char *op;

  BST myBST; // initializing the linked list	

	while(getline(input, command)){
		// check if command is empty
		if(command.length()== 0){
			continue;
		}
		com = strdup(command.c_str());
		op = strtok(com, " "); // tokenize the first thing in the string

		if(strcmp(op, "i") == 0){
			str1 = strtok(NULL, " "); // this is the first string
			cout << "Insert " + string(str1) <<endl;
			myBST.insert(str1);
		}

		if(strcmp(op, "r") == 0){
			str1 = strtok(NULL, "\t"); // this is the first string
			str2 = strtok(NULL, "\t"); // this is the second string
			output << myBST.range(str1, str2) << endl;
		}
	}
	input.close();
	output.close();
}
