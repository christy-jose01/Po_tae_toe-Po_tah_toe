
#include <stack>
#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H

// the Node class was inspired by the demo of recursion 

class Node{
	public:
		Node(); // default constructor
		Node *next;
		int x_coor; // stores the x coordinate
		int y_coor; // stores the y coordinate
		Node(int, int); //constructor creates Node with num
};

// the List class was inspired by the demo of recursion

class List{
	public:
		Node *head; // stores the head of the LinkedList
		int num_sol;
		List(); // default constructor
		void deleteList(); // frees all memory of list
		void insert(int, int); // Inserts coordinates (x, y)
		void sort(); // sorts the List
		string print(); // this outputs the coordinates
		string print(string); // helper function for print
};

class Pair{
	public:
		int row;
		int col;
};
#endif
