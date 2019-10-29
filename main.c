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

	char entrada[20];

	while(true){
		setbuf(stdin, NULL);
		fgets(entrada, 20, stdin);

		// condição de parada do loop
		if (!strncmp(entrada, "sair", 4)){
			printf("saindo\n");
			break;
		}
	}

	return 0;
}