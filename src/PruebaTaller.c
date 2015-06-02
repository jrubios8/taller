/*
 ============================================================================
 Name        : PruebaTaller.c
 Author      : Javier Rubio Sánchez
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

int buscar(struct Garaje taller[], char matricula[]) {

	int i = 0;
	do {
		if (strcasecmp((matricula), taller[i].matricula) == 0)
			return i;
	} while (++i < 25);

	return -1;
}

int insertar(struct Garaje coche, struct Garaje taller[]) {

	if (buscar(taller, coche.matricula) != -1)
		return 1;
	else {
		int i;
		for (i = 0; i < 25; i++) {
			if (strcasecmp(taller[i].matricula, "0") == 0) {
				taller[i] = coche;
				return 0;
			}
		}
	}
}

int borrar(struct Garaje taller[], char matricula[]) {

	int i = buscar(taller, matricula);

	if (i != -1) {
		strcpy(taller[i].matricula, "0");
		strcpy(taller[i].marca, "0");
		strcpy(taller[i].modelo, "0");
		taller[i].cv = 0;
		return 0;
	} else
		return 1;
}

void imprimir(struct Garaje taller[], char matricula[]) {

	int i = buscar(taller, matricula);

	if (i == -1)
		printf("1\n\n");
	else {
		printf("\nIntroduce los datos del coche %d", i + 1);
		printf("Matricula del vehículo: ");
		printf("%s\n", taller[i].matricula);
		printf("Marca del vehículo: ");
		printf("%s\n", taller[i].marca);
		printf("Modelo del vehículo: ");
		printf("%s\n", taller[i].modelo);
		printf("Potencia del vehículo: ");
		printf("%d\n\n", taller[i].cv);
	}
}

void ordenar(struct Garaje taller[]) {

	struct Garaje aux;

	int i;
	for (i = 0; i < 24; i++) {
		int j;
		for (j = i + 1; j < 25; j++) {
			if (strcasecmp(taller[i].matricula, taller[j].matricula) > 0) {
				aux = taller[i];
				taller[i] = taller[j];
				taller[j] = aux;
			}

		}
	}
}

int main(void) {

	setbuf(stdout, NULL);

	struct Garaje taller[25];
	struct Garaje aux;

	int i;
	for (i = 0; i < 25; i++) {
		strcpy(taller[i].matricula, "_");
	}

	int caso = 0;
	char CasoEscogido[30];

	do {

		printf(
				"1. Introducir un vehículo en el taller (alta)\n2. Sacar un vehículo del taller (baja)\n3. Obtener datos del vahículo seleccionado\n4. Ordenar información de los vehículos\n"
						"5. Salir\n");

		scanf("%d", &caso);
		setbuf(stdin, NULL);

		switch (caso) {
		case 1:
			printf("Introduce matricula\n");
			gets(aux.matricula);
			printf("Introduce marca\n");
			gets(aux.marca);
			printf("Introduce modelo\n");
			gets(aux.modelo);
			printf("Introduce potencia\n");
			scanf("%d", &aux.cv);
			setbuf(stdin, NULL);
			printf("%d", insertar(aux, taller));
			break;
		case 2:
			printf("Introduce matricula\n");
			scanf("%s", &CasoEscogido);
			printf("%d", borrar(taller, CasoEscogido));
			break;
		case 3:
			printf("Introduce matricula\n");
			scanf("%s", &CasoEscogido);
			imprimir(taller, CasoEscogido);
			break;
		case 4:
			ordenar(taller);

			for (i = 0; i < 25; i++) {
				printf("%s\n", taller[i].matricula);
			}
			break;
		case 5:
			break;
		default:
			break;
		}

	} while (caso != 5);

	return (EXIT_SUCCESS);
}
