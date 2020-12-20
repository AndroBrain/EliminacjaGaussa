#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

static int checkErrors(int errorCode){
	if(errorCode == 1){
		fprintf(stderr,"Błąd! Macierz nieosobliwa dzielenie przez 0.\n");
		return 1;
	}
	if(errorCode == 2){
		fprintf(stderr,"Błąd! Macierz A nie jest kwadratowa.\n");
		return 2;
	}
	if(errorCode == 3){
		fprintf(stderr,"Błąd! Ilość wierszy macierzy b nie zgadza się z ilością wierszy macierzy A.\n");
		return 3;
	}
	if(errorCode == 4){
		fprintf(stderr,"Błąd! Macierz b to macierz rozwiązań i powinna mieć tylko 1 kolumnę.\n");
		return 4;
	}
	if(errorCode == 5){
		fprintf(stderr,"Błąd! 0 wystąpiło na diagonali przy podstawianiu wstecznym.\n");
		return 5;
	}
	//Everything is alright
	return 0;
}

int main(int argc, char ** argv) {
	int errorCode;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Macierz A:\n");
	printToScreen(A);
	printf("Macierz b:\n");
	printToScreen(b);

	errorCode = eliminate(A,b);
	x = createMatrix(b->r, 1);
	// Funkcja sprawdza błędy
	if(checkErrors(errorCode) > 0){
		freeMatrix(A);
		freeMatrix(b);
		return errorCode;
	}
	if (x != NULL) {
		errorCode = backsubst(x,A,b);
		if(checkErrors(errorCode) > 0){
			freeMatrix(A);
			freeMatrix(b);
			return errorCode;
		}
		printf("Wyniki to:\n");
		printToScreen(x);
		freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
