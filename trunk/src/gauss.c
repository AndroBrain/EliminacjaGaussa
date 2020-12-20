#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - macierz nie jest kwadratowa ilość kolumn i wierszy się nie zgadza
 * Zwraca 3 - macierz b ma inną ilość wierszy niż macierz A
 * Zaraca 4 - macierz b ma więcej niż 1 kolumnę
 */

int eliminate(Matrix *mat, Matrix *b){


	if(mat->c != mat->r)
		return 2;
	if(mat->r != b->r)
		return 3;
	if(b->c > 1)
		return 4;

	for(int column = 0; column < mat->c; column++){
		if(mat->data[column][column]==0){
			// Jest to macierz osobliwa !
			return 1;
		}
		for(int row = column+1; row < mat->r; row ++){
			double ratio = mat->data[row][column]/mat->data[column][column];
		 	b->data[row][0] = b->data[row][0] - ratio * b->data[column][0];
			for(int columnEliminator = 0; columnEliminator < mat->c; columnEliminator++){
				mat->data[row][columnEliminator] = mat->data[row][columnEliminator] - ratio * mat->data[column][columnEliminator];
			}	
		}
	}

	return 0;
}

