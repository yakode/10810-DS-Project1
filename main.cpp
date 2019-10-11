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
		if(block_type == "T1")      put_t1(matrix, row, col, start_col);
		else if(block_type == "T2") put_t2(matrix, row, col, start_col);
		else if(block_type == "T3") put_t3(matrix, row, col, start_col);
		else if(block_type == "T4") put_t4(matrix, row, col, start_col);
		else if(block_type == "L1") put_l1(matrix, row, col, start_col);
		else if(block_type == "L2") put_l2(matrix, row, col, start_col);
		else if(block_type == "L3") put_l3(matrix, row, col, start_col);
		else if(block_type == "L4") put_l4(matrix, row, col, start_col);
		else if(block_type == "J1") put_j1(matrix, row, col, start_col);
		else if(block_type == "J2") put_j2(matrix, row, col, start_col);
		else if(block_type == "J3") put_j3(matrix, row, col, start_col);
		else if(block_type == "J4") put_j4(matrix, row, col, start_col);
		else if(block_type == "S1") put_s1(matrix, row, col, start_col);
		else if(block_type == "S2") put_s2(matrix, row, col, start_col);
		else if(block_type == "Z1") put_z1(matrix, row, col, start_col);
		else if(block_type == "Z2") put_z2(matrix, row, col, start_col);
		else if(block_type == "I1") put_i1(matrix, row, col, start_col);
		else if(block_type == "I2") put_i2(matrix, row, col, start_col);
		else if(block_type == "O") put_o (matrix, row, col, start_col);

		if(is_game_over) break;
	}
	inFile.close();
	fstream outFile;
	outFile.open("Tetris.output", ios::out);
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			outFile << matrix[i][j];
		}
		outFile << '\n';
	}
	outFile.close();
	return 0;
}
