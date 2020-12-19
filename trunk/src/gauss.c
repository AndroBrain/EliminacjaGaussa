#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	/**
	 * Tutaj należy umieścić właściwą implemntację.
	 */
	for(int column = 0; column < mat->c; column++){
		if(mat->data[column][column]==0){
			// Jest to macierz osobliwa !
			return 1;
		}
		for(int row = column+1; row < mat->r; row ++){
			double ratio = mat->data[row][column]/mat->data[column][column];
			for(int columnEliminator = 0; columnEliminator < mat->c; columnEliminator++){
				mat->data[row][columnEliminator] = mat->data[row][columnEliminator] - ratio * mat->data[column][columnEliminator];
			}	
		}
	}

	return 0;
}

