
void put_t2(bool matrix[45+5][15], int row, int col, int begin_col){
	//0/1/0
	//1/1/0
	//0/1/0
	//^
	int colb = begin_col - 1;
	int rowb = row;
	for(int i = row-1; i >= 0; --i){
		if(matrix[i+1][colb] == 0 && matrix[i][colb+1] == 0)
			rowb = i;
		else
			break;
	}
	matrix[rowb][colb+1] = 1;
	matrix[rowb+1][colb] = 1;
	matrix[rowb+1][colb+1] = 1;
	matrix[rowb+2][colb+1] = 1;
	if(rowb == row) return;
	check_line(matrix, row, col, rowb, 3);
}
