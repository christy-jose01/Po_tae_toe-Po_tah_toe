#pragma once
#include <iostream>
#include <stack>
#include "list.h"
// this was inspired by https://www.geeksforgeeks.org/stack-in-cpp-stl/

using namespace std;

class Queen{
	private:
		bool **board;
	public:
		void create_matrix(int); // constructor
		void fill_board(int,int, int);
		void delete_board(int n); // destructor
		void print_board(int); // display
		int remaining_queens(int, int);
		// the following functions check the paths
		bool check_row(int, int);
		bool check_col(int, int);
		bool check_rd_diagonal(int, int, int);
		bool check_ld_diagonal(int, int, int);
		// the following functions mark the paths
		// these are also helper functions for fill_board
		// void mark_row(int, int);
		// void mark_col(int, int);
		// void mark_rd_diagonal(int, int, int);
		// void mark_ld_diagonal(int, int, int);

		// this function finds possible queen spots
	 List propogate_board(int);
};
