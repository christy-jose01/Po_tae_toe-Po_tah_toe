#include <cstdlib>
#include <iostream>
#include <cstring> // this is for the c_str functions
#include <fstream> // this is for the ifstream functions
#include <string.h> // this has the strtok function
#include "queen.h"
using namespace std;

int main(int argc, char **argv){
	// check if there are <2 arguments
	if (argc < 3){
		throw std::invalid_argument("Usage ./nqueens <INPUT FILE> <OUTPUT FILE> \n");
	}

	ifstream input;
	ofstream output;
	// opens the respective input and output files
	input.open(argv[1]);
	output.open(argv[2]);

	//read the first number in the line = size of matrix
	string line;
	char *buff;
	char *b_size_str;
	char *dummy;
	char *xdummy;
	char *ydummy;
	int b_size;

	while(getline(input, line)){
		buff = strdup(line.c_str());
		b_size_str = strtok(buff, " "); // string of the first number
		b_size = strtol(b_size_str,&dummy, 10); //number of first number
		
		// create board
		Queen nqueen; //initializing our board
		nqueen.create_matrix(b_size);
		int pair = 0;
		
		// fill in board
		// go through each character in the line: https://cplusplus.com/reference/cstring/strtok/
		while(b_size_str!= NULL){
			// indexing to next num
			b_size_str = strtok(NULL, " "); 
			// check if we have no more coordinates
			if(b_size_str==NULL){
				break;
			}
			int x = strtol(b_size_str, &xdummy, 10);
			// indexing to next num
			b_size_str = strtok(NULL, " "); 
			int y = strtol(b_size_str, &ydummy, 10);
			printf("inserting %d,%d\n",x,y);
			nqueen.fill_board(x-1,y-1, b_size); // bc it starts at (1,1) and ends at (n,n) 
			pair++;
		}
		// solve board
		int rem = b_size - pair;
		printf("we have %d more coordinates needed\n", rem);
		List sol = nqueen.propogate_board(b_size);
		sol.sort();
		
		// write to output
		string sol_print = sol.print();
		if(sol_print.empty()){
			output<< "No solution" << std::endl;
		}else{
			output<< sol_print << std::endl;
		}
		
		// delete board
		nqueen.delete_board(b_size);
		// go to the next board

	}
	
	input.close();
	output.close();
}
