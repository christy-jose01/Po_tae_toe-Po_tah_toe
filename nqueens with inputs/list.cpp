
#include "list.h"
using namespace std;

// Node class functions
// all of these functions were inspired from demo for recurssion
Node :: Node(){
	x_coor = 0;
	y_coor = 0;
	next = NULL;
}

Node :: Node(int x, int y){
	x_coor = x;
	y_coor = y;
	next = NULL;
}

// List class functions
List :: List(){
	head = NULL;
	num_sol = 0;
}

void List :: deleteList(){
	Node *curr = head;
	//base case
	if(curr==NULL){
		return;
	}
	// keep deleting every node in loop
	while(curr->next!=NULL){
		Node *temp = curr->next;
		delete(curr);
		curr = temp;
	}

	delete(curr);
}

void List :: insert(int x, int y){
	num_sol++;
	Node *latest = new Node(x, y);
	latest->next = head;
	head = latest; // make this the new head
	return;
}

void List :: sort(){
	Node *curr1 =  head, *curr2 = head;
	Node *min;
	int temp_x;
	int temp_y;

	while(curr1!=NULL){
		curr2 = curr1; // start curr2 from curr1
		min = curr2;
	
		while(curr2!=NULL){ // start traversing
			if(min->x_coor > curr2->x_coor){
				min = curr2;
			}
			curr2= curr2->next; // traverse through the loop
		}
		// now swap
		temp_x = curr1->x_coor;
		temp_y = curr1->y_coor;

		curr1->x_coor = min->x_coor;
		curr1->y_coor = min->y_coor;
		
		min->x_coor = temp_x;
		min->y_coor = temp_y;
		// done swapping

		curr1 = curr1->next; // increment curr1
	}
}

string List :: print(){
	Node *curr = head;
	string output = "";
	while(curr!=NULL){
		output = output + to_string(curr->x_coor) + " " + to_string(curr->y_coor) + " ";
		curr = curr->next;
	}
	return output;
}

string List :: print(string str){
	if (head == NULL){
		return "";
	}
	string output = to_string(head->x_coor) + " " + to_string(head->y_coor);
	Node *curr = head->next;

	while(curr!=NULL){
		output = output + str + to_string(curr->x_coor) + " " + to_string(curr->y_coor);
		curr = curr->next;
	}
	return output;
}
