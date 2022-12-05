#include "functions.h"

using namespace std;

BST :: BST(){
	root = NULL;
}

// the insert function is inspired by bst.cpp file in BST codes
void BST :: insert(string str){
	if(find(str)){
		return;
	} 
	else {
		Node *to_insert = new Node(str);
		if(root == NULL){
			root = to_insert;
		} else {
			insert(root, to_insert);
		}
	}
}

void BST :: insert(Node *start, Node *to_insert){
	if(start == NULL){
		return;
	}

	if(to_insert->key <= start->key){
		if(start->left == NULL){
			start->left = to_insert; // make this node the left child
      to_insert->parent = start; // set the parent pointer
      return;
		
		} else {
			insert(start->left, to_insert);
			return;
		}
	}
	else{
		if(start->right == NULL){
			start->right = to_insert; // make this node the right child
      to_insert->parent = start; // set the parent pointer
      return;

		} else{
			insert(start->right, to_insert);
			return;
		}
	}
}

// the find function is inspired by bst.cpp from BST codes
Node *BST :: find(string to_find){
	return find(root, to_find);
}

Node *BST :: find(Node *start, string to_find){
	// base case
	if(start == NULL || start->key == to_find){
		return start;
	}
	// smaller one is on the left side
	if(to_find < start->key){
		return find(start->left, to_find);
	} // larger one is on the right side 
	else {
		return find(start->right, to_find);
	}
}

int BST :: range(string str1, string str2){
	// // safety. This will never happen
	// if(str1 > str2){
	// 	return 0;
	// }
	
	// base case : empty BST
	if(!root){
		return 0;
	} else{
		range(root, str1, str2);
	}
}

int BST :: range(Node *start, string low, string high){
	// base case: we reach the end
	if(start == NULL){
		return 0;
	}
	
	// case : the high and low are the same and they match the node's key
	// this will never happen bc we can "assume" that low < high
	if(start->key == high && start->key == low){
		return 1;
	}

	// case: current node is in range
	if(start->key <= high && start->key >= low){
		return 1 + range(start->right, low, high) + range(start->left, low, high);
	}

	// case: current node is out of range (smaller than low)
	else if(start->key < low){
		return range(start->right, low, high);
	}

	// case: current is out of range (larger than high)
	else{
		return range(start->left, low, high);
	}
}
