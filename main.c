#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "func.h"

int main(){
	printf("*************************************\n");
	printf("Projeto de ITP - Desenho Grafico\n\n");
	printf("Autores:\nLucas Fernandes\nArthur Learth\nGabriel Furtado\n");
	printf("*************************************\n\n");

	char entrada[10];
	
	while(true){
		setbuf(stdin, NULL);
		scanf("%s", entrada);

		// condição de parada do loop
		if (!strcmp(entrada, "sair")){
			break;
		}
	}

	freeAll();
	return 0;
}