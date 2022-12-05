#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stack>

#include <string.h>

using namespace std;

class Node{
	public:
		string key;
		Node *left, *right, *parent;

		// default contructor
		Node(){
			left = right = parent = NULL;
		}

		// normal constructor
		Node(string word){
			key = word;
			left = right = parent = NULL;
		}
};

class BST{
	private:
		Node *root;
	public:
		BST(); // default constructor
		void insert(string);
		void insert(Node *, Node *);
		Node *find(string);
		Node *find(Node *, string);
		int range(string, string);
		int range(Node *, string, string);
};

#endif
