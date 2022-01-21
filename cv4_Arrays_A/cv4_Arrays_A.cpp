#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
/*1. Napište program, který
a.alokuje a naplní jednorozměrné pole int(v rozsahu 1 - 100)
b.napište funkci, která vyhledá všechna čísla celočíselně dělitelná 2 a uložit pozici takového prvku do pole2(pole2 bude obsahovat pouze odkazy na odpovídající pozice v prvním poli z bodu a.)
c.vypíšete všechny čísla celočíselně dělitelná 2 pomocí pole2 na obrazovku
d.napište testy */

int alloc(int **pole,int velikost);
int fill(int *pole, int velikost);
int print(int* pole, int velikost);
int modul2(int* pole, int* pole2, int velikost);
void zobraz(int** pole, int size);

int main()
{
	int* pole;
	int ret;
	int velikost = 100;
	ret = alloc(&pole, velikost);
	fill(pole, velikost);
	print(pole, velikost);
	int **pole2 = (int**)malloc(velikost * sizeof(int));
	int c = 0;
	for (int i = 0; i < velikost; i++) {
		if (pole[i] % 2 == 0) {
			pole2[c] = &pole[i];
			c = c + 1;
		}

	}
	pole[20] = 10000; //test změny pole
	pole[21] = 10001;
	printf("\n-------------------------------------------\n");
	zobraz(pole2, c);



	free(pole);
	free(pole2);
	return 0;
}

int alloc(int **pole, int velikost) {
	*pole = (int*) malloc(velikost * sizeof(int));
	if (*pole == NULL) {
		return 10;
	}
	return 0;
}
int fill(int* pole, int velikost) {
	for (int i = 1; i < velikost +1; i++) {
		pole[i-1] = i;
	}
	return 0;
}
int print(int* pole, int velikost) {
	for (int i = 0; i < velikost; i++) {
		printf("%d ", pole[i]);
	}
	return 0;
}
void zobraz(int** pole, int size) {
	for (int i = 0; i < size; i++) {
		if (pole[i] != NULL) {
			printf("pole[%d] = %d\n ", i, *pole[i]);
		}
	}
}




