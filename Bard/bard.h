#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

// inspired from linkedlist.h file 

// node struct to hold data
struct Node
{
	string word;
	int freq;
	Node *next;
};

class LinkedList
{
	private:
		Node *arrlen[36]; //Array that stores the LL
	public:
		void construct_array(); // initializes the array to NULL pointers
		Node *build_ll(string); //build ll to add in insert
		void insert_word(string); //inserts word in the LL 
		Node *pop(string); // hellper function to delete in insert_word
		void insert(Node *); // helper function to sort in insert_word
		void display(); // print function
		string find(int,int); // finds the kth rank of the l len word
		void deleteArray(); // destructor
};

#endif


