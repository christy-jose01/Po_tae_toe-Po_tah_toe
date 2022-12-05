#include "bard.h"
using namespace std;

void LinkedList :: construct_array(){
	for (int i = 0; i<36; i++){
		arrlen[i]= NULL;
	//	printf("set arr[%d] to NULL\n", i);
	}
}

Node *LinkedList :: build_ll(string vocab){
	Node *ll = new Node;
	ll->word = vocab;
	ll->freq = 1;
	ll->next = NULL;
	return ll;
}

void LinkedList :: insert_word(string vocab){
	int index = vocab.length()-1; // length of the word
	//printf("index is %d\n",index);
	// check if arrlen[len] ll doesn't exist
	if (arrlen[index]==NULL){
		printf("arrlen[%d] doesn't have a LL\n",index);
		// create a new ll
		arrlen[index] = build_ll(vocab);
		printf("arr[%d] is the word %s\n", index, &(arrlen[index]->word)[0]);
		return;
	}
	
	// if arrlen[len] does exist
	// check if vocab is already in the ll
	Node *curr = arrlen[index];
	while(curr->next!=NULL){
		if(curr->word==vocab){
			curr->freq++;
			// re-order
			Node *d = pop(vocab); 
			insert(d);
			return;
		}
		curr = curr->next;
	}
	// if we have reached this point, then word does not exist in ll
	// add the node
	curr->next = build_ll(vocab);
}

Node *LinkedList :: pop(string str){
	// search for the str
	int index = str.length()-1;
	Node *prev = NULL;
	Node *curr = arrlen[index];
	while (curr!=NULL){
		if(curr->word==str){
			// check if head
			if(prev == NULL){
				arrlen[index]= curr->next;
				return curr;
			}
			//disconnect curr
			prev->next = curr->next;
			curr->next = NULL;
			// return it
			return curr;
		}
		prev = curr;
		curr = curr->next;
	}
	return NULL;
}

void LinkedList :: insert(Node *in){
	int index = in->word.length()-1;
	Node *curr = arrlen[index];
	// loop through the LL
	while(curr->next!=NULL){
		Node *forw = curr->next;
		// arranging by alphabet
		if(curr->next->freq==in->freq){
			// the inserted word's next should be bigger
			if(curr->next->word > in->word){
				// inserting
				curr->next = in;
				in->next = forw;
			}
		}
		// arranging by frequency
		if(curr->next->freq < in->freq){
			curr->next = in;
			in->next = forw;
		}
		// incrementing
		curr = curr->next;
	}
}

void LinkedList :: display(){
	//check each word's frequency
	for(int i = 0; i < 36; i++){
		Node *curr = arrlen[i];
		while(curr!=NULL){
			printf("word: %s | %d\n", curr->word, curr->freq);
			curr = curr->next;
		}
	}
}

string LinkedList :: find(int len, int rank){
	Node *ll = arrlen[len];
	for(int i = 0; i<rank; i++){
		ll = ll->next;
	}
	return ll->word;
}

void LinkedList :: deleteArray(){
	for (int i = 0; i < 36; i++){
		// inspired by deleteList() from LinkedList
		Node *curr = arrlen[i];
		Node *n = NULL; // temporary next
		while(curr!=NULL){
			n = curr->next;
			delete(curr);
			curr = n; // iterating
		}
		arrlen[i]=NULL; // setting head to NULL
	}
}
