#include <put_blocks.h>
int pos_r[19][5] = {{0, 1, 1, 1, 2}, {0, 1, 1, 2, 3}, {0, 0, 0, 1, 2}, {0, 1, 1, 2, 3},
				    {0, 0, 1, 2, 3}, {0, 1, 1, 1, 2}, {0, 1, 2, 2, 3}, {0, 0, 0, 1, 2},
				    {0, 0, 1, 2, 3}, {0, 0, 0, 1, 2}, {0, 1, 2, 2, 3}, {0, 1, 1, 1, 3},
				    {0, 0, 1, 1, 2}, {0, 1, 1, 2, 3}, {0, 0, 1, 1, 2}, {0, 1, 1, 2, 3},
				    {0, 1, 2, 3, 4}, {0, 0, 0, 0, 1}, {0, 0, 1, 1, 2}					};

int pos_c[19][4] = {{1, 0, 1, 2}, {1, 0, 1, 1}, {0, 1, 2, 1}, {0, 0, 1, 0},
					{0, 1, 0, 0}, {0, 0, 1, 2}, {1, 1, 0, 1}, {0, 1, 2, 2},
					{0, 1, 1, 1}, {0, 1, 2, 0}, {0, 0, 0, 1}, {2, 0, 1, 2},
					{0, 1, 1, 2}, {1, 0, 1, 0}, {1, 2, 0, 1}, {0, 0, 1, 1},
					{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 1, 0, 1}				};

void put_blocks(bool matrix[45+5][15], int row, int col, int begin_col, int type){
	int colb = begin_col - 1;
	int rowb = row;
	for(int i = row-1; i >= 0; --i){
		bool ok_to_fall = true;
		for(int k = 0; k < 4; ++k){
			int x = i + pos_r[type][k];
			int y = colb + pos_c[type][k];
			if(matrix[x][y] == 1){
				ok_to_fall = false;
				break;
			}
		}
		if(ok_to_fall) rowb = i;
		else break;
	}
	for(int i = 0; i < 4; ++i){
		int x = rowb + pos_r[type][i];
		int y = colb + pos_c[type][i];
		matrix[x][y] = 1;
	}
	if(rowb == row) return;
	check_line(matrix, row, col, rowb, pos_r[type][4]);
}
