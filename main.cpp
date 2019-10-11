#include <iostream>
#include <fstream.h>
#include <put_blocks.h>
#include <check_line.h>
#include <is_game_over.h>

using namespace std;

int main(){
	ifstream inFile("Tetris.data");
	if(!inFile) cout << "fail to open Tetris.data \n";
	bool matrix[45+5][15] = {0};
	int row, col;
	inFile >> row >> col;
	string block_type;
	int start_col;
	while(inFile >> block_type){
		if(block_type == "End") break;
		inFile >> start_col;
		if(block_type == "T1")      put_blocks(matrix, row, col, start_col, 0 );
		else if(block_type == "T2") put_blocks(matrix, row, col, start_col, 1 );
		else if(block_type == "T3") put_blocks(matrix, row, col, start_col, 2 );
		else if(block_type == "T4") put_blocks(matrix, row, col, start_col, 3 );
		else if(block_type == "L1") put_blocks(matrix, row, col, start_col, 4 );
		else if(block_type == "L2") put_blocks(matrix, row, col, start_col, 5 );
		else if(block_type == "L3") put_blocks(matrix, row, col, start_col, 6 );
		else if(block_type == "L4") put_blocks(matrix, row, col, start_col, 7 );
		else if(block_type == "J1") put_blocks(matrix, row, col, start_col, 8 );
		else if(block_type == "J2") put_blocks(matrix, row, col, start_col, 9 );
		else if(block_type == "J3") put_blocks(matrix, row, col, start_col, 10);
		else if(block_type == "J4") put_blocks(matrix, row, col, start_col, 11);
		else if(block_type == "S1") put_blocks(matrix, row, col, start_col, 12);
		else if(block_type == "S2") put_blocks(matrix, row, col, start_col, 13);
		else if(block_type == "Z1") put_blocks(matrix, row, col, start_col, 14);
		else if(block_type == "Z2") put_blocks(matrix, row, col, start_col, 15);
		else if(block_type == "I1") put_blocks(matrix, row, col, start_col, 16);
		else if(block_type == "I2") put_blocks(matrix, row, col, start_col, 17);
		else if(block_type == "O")  put_blocks(matrix, row, col, start_col, 18);
		else break;

		if(is_game_over(matrix, row, col)) break;
	}
	inFile.close();
	fstream outFile;
	outFile.open("Tetris.output", ios::out);
	for(int i = row-1; i >= 0; --i){
		for(int j = 0; j < col; ++j){
			outFile << matrix[i][j];
		}
		outFile << '\n';
	}
	outFile.close();
	return 0;
}
