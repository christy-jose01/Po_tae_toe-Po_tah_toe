#include "queen.h"

using namespace std;

void Queen :: create_matrix(int n){
	board = (bool **)calloc(n,sizeof(bool *));
	// initialize them all to false and allocate in each row
	for(int i = 0; i < n; i++){
		board[i]=(bool *)calloc(n, sizeof(bool));
	}

}


void Queen :: fill_board(int x, int y, int n){
	// check if the inputs queen collide with each other
	// if it is clear, then add the pos
	// x = col, y = row
	if((check_row(y,n)==true)&&(check_col(x,n)==true)&&(check_ld_diagonal(x,y,n)==true) &&(check_rd_diagonal(x,y,n)==true)){
		board[y][x] = true;
	}
	
}

void Queen :: delete_board(int n){
	//received help from: https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/

	for(int i = 0; i < n; i++){
		delete[] board[i];
	}
	delete[] board;
}

void Queen :: print_board(int n){
	// top
	for(int i = 0; i < n; i++){
		if(i ==n-1){
			printf("-\n");
		}else{
			printf("-");
		}
	}
	// middle
	for(int i = 0; i < n; i++){
		printf("|");
		for(int j = 0; j < n; j++){
			printf("%d\t",board[i][j]);
		}
		printf("|\n");
	}
	// bottom
	for(int i = 0; i < n; i++){
		if(i ==n-1){
			printf("-\n");
		} else{
			printf("-");
		}
	}
}


// the following are the checking functions:
// if they return true, then it means that there was nothing in that line
// which means that we are good to go

bool Queen :: check_row(int row, int n){
	for(int i = 0; i < n; i++){
		if(board[row][i]==true){
			// there is something at that spot
			// it is not clear
			return false;
		}
	}
	return true;
}

bool Queen :: check_col(int col, int n){
	for(int i = 0; i < n; i++){
		if(board[i][col]==true){
			// there is something at the spot
			// it is not clear
			return false;
		}
	}
	return true;
}

bool Queen :: check_rd_diagonal(int x, int y, int n){
	// doing the '/' diagonal (right down)
	// find the starting point from top
	int rxd = x;
	int ryd = y;
	while(rxd<n-1 && ryd>0){
		rxd++;
		ryd--;
	} // at the end of the loop, we have our starting point

	// go down the (right down) diagonal
	while(rxd>0 && ryd<n){
		if(board[ryd][rxd]== true){
			// there is something at this spot
			return false;
		}
		rxd--;
		ryd++;

	}
	return true;
}

bool Queen :: check_ld_diagonal(int x, int y, int n){
	// doing the '\' diagonal
	// find the starting point from top
	int lxd = x;
	int lyd = y;
	while(!(lxd==0 || lyd==0)){
		lxd--;
		lyd--;
	} // at the end of the loop, we have our starting point

	// go down the (left down) diagonal
	while(!(lxd==n || lyd==n)){
		if(board[lyd][lxd]== true){
			// there is something at this spot
			return false;
		}
		lyd++;
		lxd++;
	}
	return true;
}

// this function propogates the board
// if check_row, check_col, check_rd_diagonal, && check_ld_diagonal is false, then push pair to stack
List Queen :: propogate_board(int n){
	print_board(n);
	List output;
	stack <Pair> s;
	// add the valid positions onto the stack

	for(int row = 0; row < n; row++){
		// if the row isn't clear, then skip
		
		if(check_row(row, n) == true){ 
			for(int col = 0; col <n+1; col++){

				// for edge case
				if(col == n){
					// check if stack is empty
					if(s.empty()){
						return output;
					}
					// check if stacktop.col+1 == n: then pop
					Pair stacktop;
					stacktop = s.top();
					s.pop();
					// unmark the queen
					row = stacktop.row;
					col = stacktop.col;
					board[row][col]= false;
					// continue on the next col
					// col++;
					continue;
				}

				if(check_col(col, n) == true){
					// check diagonals
					if(check_ld_diagonal(col, row, n) == true && check_rd_diagonal(col, row, n) == true){
						// add position pair to stack
						fill_board(col, row, n);
						Pair pos;
						pos.row = row;
						pos.col = col;
						s.push(pos);

						break;
					}
				}
			}
		}
	}
	// // now that we have our stack of solution, add the solutions onto the List
	// while(!s.empty()){
	// 	Pair stacktop;
	// 	stacktop = s.top();
	// 	s.pop();
	// 	// insert pairs from stacks into List
	// 	output.insert(stacktop.col+1, stacktop.row+1);
	// }

	// add the board onto List
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			if(board[row][col]==true){
				// add Pair to List
				output.insert(col+1, row+1);
			}
		}
	}	

	return output;
}
