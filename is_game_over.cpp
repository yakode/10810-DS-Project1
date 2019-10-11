#include <is_game_over.h>
bool is_game_over(bool matrix[45+5][15], int row, int col){
	for(int i = 0; i < col; ++i){
		if(matrix[row][i] == true) return true;
	}
	return false;
}
