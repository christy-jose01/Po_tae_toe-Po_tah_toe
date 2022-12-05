#include "bard.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv){
	
    ifstream shake; // stream for shakesphere file
    shake.open("shakespeare-cleaned5.txt"); // open shakesphere file

    string w; // this stores the word in the current line 
		char *inserting;

		LinkedList analysis; // initialized LL
		analysis.construct_array();

    //insert word
    while(getline(shake, w)){
		//	printf("%s\n",&w[0]);
			inserting = strdup(w.c_str());
			analysis.insert_word(inserting);
		//	printf("inserted: %s\n",inserting);
    }

		analysis.display();
    shake.close();

    if (argc < 3) // must provide two arguments as input
     {
         throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); // throw error
     }

     ifstream input; // stream for input file
     ofstream output; // stream for output file

     input.open(argv[1]); // open input file
     output.open(argv[2]); // open output file

	//inspired by Linkedlist practice hw0

		// reading the input file
		string line; // stores the string of the line
		char *len_str; 
		int len;
		char *rank_str;
		int rank;
		char *buff;
		char *rr;
		char *l;

		while(getline(input, line)){
			buff = strdup(line.c_str()); 
			len_str = strtok(buff, " "); // tokenize input command
			len = strtol(len_str, &l, 10); // turns len_str from str to int
			rank_str = strtok(NULL, " "); // string for rank
			rank = strtol(rank_str, &rr, 10); // turns rank_str from str to int
			// writing ans in output
			output << analysis.find(len,rank) << endl;
		}
		input.close();
		output.close();
		analysis.deleteArray();
}
