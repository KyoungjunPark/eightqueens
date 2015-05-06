#include<stdio.h>

#define BOARDLENGTH 8

void calcEightQueens();
int (*reculEightQueens(int[][BOARDLENGTH], int , int ))[BOARDLENGTH];
bool isBound(int [][BOARDLENGTH], int, int);
int main()
{
	calcEightQueens();
}
void calcEightQueens()
{
	int board [][BOARDLENGTH] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } };
	
	int (*result)[BOARDLENGTH] = reculEightQueens(board, 0, 0);

	for (int i = 0; i < BOARDLENGTH; i++){
		for (int j = 0; j < BOARDLENGTH; j++){
			printf("%2d", result[i][j]);
		}
		printf("\n");
	}
}
int (*reculEightQueens(int board [][BOARDLENGTH], int row, int col))[BOARDLENGTH]
{
	if (row == BOARDLENGTH - 1){ //ending node
		for (int i = 0; i < BOARDLENGTH; i++){
			if (!isBound(board, row, i)){
				board[row][i] = 1;
			}
		}
		return board;
	}
	else{
		for (int i = 0; i < BOARDLENGTH; i++) {
			//bounding func
			if (!isBound(board, row, i)) {
				int flagIsEnd = 0;
				board[row][i] = 1;
				board = reculEightQueens(board, row + 1, 0);
				
				for (int i = 0; i < BOARDLENGTH; i++){
					if (board[BOARDLENGTH - 1][i] == 1) flagIsEnd = 1;
				}
				if (!flagIsEnd) board[row][i] = 0;
			}
		}
		return board;
	}
}
bool isBound(int board [][BOARDLENGTH], int row, int col)
{
	for (int i = 0; i < BOARDLENGTH; i++){//row & col check
		if (board[row][i] || board[i][col]){
			return true;
		}
	}
	// \ diagonal check
	int startRow = row, startCol = col;
	while (startRow > 0 && startCol > 0){
		startRow--;
		startCol--;
	}
	while (startRow < 7 && startCol < 7){
		if (board[startRow][startCol]){
			return true;
		}
		startRow++;
		startCol++;
	}
	// / diagonal check
	startRow = row;
	startCol = col;
	while (startRow < 7 && startCol > 0){
		startRow++;
		startCol--;
	}
	while (startRow > 0 && startCol < 7){
		if (board[startRow][startCol]){
			return true;
		}
		startRow--;
		startCol++;
	}

	return false;
}