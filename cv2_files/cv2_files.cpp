#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

/*Napište program, který bude kopírovat libovolný soubor(textový či binární) a to tak,
že jedna polovina vstupního souboru jde do souboru "kopie-1" a druhá do "kopie-2".*/

int main()
{

	printf("Vytvoreni souboru a zapis\n");

	FILE* fw;
	fw  = fopen("soubor.txt", "w+");
	for (int i = 0; i < 25; i++) {
		fprintf(fw, "%d ", i);
	}
	fclose(fw);
	//čtení souboru
	/*printf("cteni na obrazovku");

	FILE* fr;
	int a;
	fr = fopen("soubor.txt", "r");
	if (fr == NULL) {
		printf("soubor neexistuje");
		return 10;
	}
	while (fscanf(fr,"%d",&a) != EOF)
	{
		printf("%d ",a);
	}
	fclose(fr);
	*/

	//rozdělit přichozí soubor na dva

	FILE* fr;
	
	int a;
	fr = fopen("soubor.txt", "rb");
	if (fr == NULL) {
		printf("soubor neexistuje");
		return 10;
	}

	FILE* fcopy1;
	fcopy1 = fopen("copy1.txt", "wb+");
	FILE* fcopy2;
	fcopy2 = fopen("copy2.txt", "wb+");

	fseek(fr, 0L, SEEK_END); //posunutí na konec souboru
	long size = ftell(fr);
	long polovina = size / 2;
	printf("Velikost je : %d \n ", size);
	rewind(fr); //posunutí zpět na začátek
	char c;

	for (int i = 0; i <= polovina; i++) {
		fread(&c, sizeof(char), 1, fr);
		printf("%c", c);
		fwrite(&c, sizeof(c), 1, fcopy1);

	}
	for (int i = polovina; i <= size; i++) {
		fread(&c, sizeof(char), 1, fr);
		printf("%c", c);
		fwrite(&c, sizeof(c), 1, fcopy2);
	}	
}

