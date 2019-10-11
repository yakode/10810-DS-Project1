#include <check_line.h>
void check_line(bool matrix[45+5][15], int row, int col, int start_row, int height){
	int row_check = start_row;
	for(int i = 0; i < height && row_check < row; ++i){
		bool rst = true; //whole line reset to zero
		for(int j = 0; j < col; ++j){
			if(matrix[row_check][j] == 0){
				rst = false;
				break;
			}
		}
		if(rst){
			for(int p = row_check; p < row+3; ++p)
				for(int q = 0; q < col; ++q)
					matrix[p][q] = matrix[p+1][q];
		}else{
			row_check++;
		}
	}
}
