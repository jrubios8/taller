/*
 ============================================================================
 Name        : PruebaTaller.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Garaje {
	char matricula[7];
	char marca[30];
	char modelo[30];
	int cv;

};

int size(struct Garaje taller[]) {
	return sizeof(taller) / sizeof(taller[0]);
}

int buscar(struct Garaje taller[], char matricula[]) {
	int i = 0;
	do {
		if (strcasecmp(matricula, taller[i].matricula) == 0)
			return i;
	} while (i++ < size(taller));

}

void ordenar(struct Garaje taller[]) {
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = i + 1; j < 3; ++j) {
			if (taller[i].cv < taller[j].cv) {
				taller[i] = taller[j];
				taller[j] = aux;
			}
		}
	}

}

int main(void) {
	setbuf(stdout, NULL);
	int num = 3, i;
	struct Garaje taller[num];
	for (i = 0; i < num; ++i) {
		printf("\nIntroduce los datos del coche %d", i + 1);
		printf("\nMatricula: ");
		gets(taller[i].matricula);
		printf("\nMarca: ");
		gets(taller[i].marca);
		printf("\nModelo: ");
		gets(taller[i].modelo);
		printf("\nCV: ");
		scanf(taller[i].cv);
	}
	for (i = 0; i < num; ++i) {
		printf("Matricula %s, Marca %s, CV %d", taller[i].matricula,
				taller[i].marca, taller[i].modelo, taller[i].cv);
	}

	return EXIT_SUCCESS;
}
