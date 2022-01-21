#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main() {
	printf("Prvni cviceni - strom ");
	int vel;
	printf("Zadej velikost pyramidy: ");
	scanf("%d", &vel);
	printf(" velikost je: %d \n", vel);

	//pyramidy

	for (int i = 0; i < vel; i++) {

		for (int k = vel; k < vel + i; k++) {
			printf(" ");
		}
			
		for (int j = 0; j < vel - i; j++) {
			printf("* ");
		}
		printf("\n");

	}
		
	//otočená pyramida

	for (int i = vel; i >= 0; i--) {

		for (int k = vel; k < vel + i; k++) {
			printf(" ");
		}

		for (int j = 0; j < vel - i; j++) {
			printf("* ");
		}
		printf("\n");

	}

	return 0;
} 