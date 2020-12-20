#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 5 - błąd dzielenia przez 0 (element na diagonali = 0)
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int p = mat->r;
	int n = p - 1; // zamiana na początku może być niewyraźna, ale po rozpisaniu na kartce
	double sum = 0;// z n zamiast p-1 wszystko ładniej wygląda, bo w mallocu nie mamy miejsca na \0,
	for(int i = n; i >= 0; i--){ // ktore siedzi w ostatniej komorce, na ktore trzeba uwazac...
		if(mat->data[i][i] == 0) // sprawdza czy nie ma zera na diagonali
			return 5; 

		for(int j = i+1; j < n+1; j++){
			sum += mat->data[i][j] * x->data[j][0];
		}
		x->data[i][0] = (b->data[i][0] - sum)/mat->data[i][i];
	}
	return 0;
}
