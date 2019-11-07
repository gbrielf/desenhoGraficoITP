#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main(){
	/* Introdução do programa */
	printf("*************************************\n");
	printf("Projeto de ITP - Desenho Grafico\n\n");
	printf("Autores:\nLucas Fernandes\nArthur Learth\nGabriel Furtado\n");
	printf("*************************************\n");

	/* Inicialização de variáveis, matrizes e estruturas utilizadas no programa */
	int imagemAberta = 0;	// determina se existe uma imagem sendo trabalhada no programa
	int sair = 0;	// determina se o loop que solicita a entrada do usuário deve ser reiniciado ou não

	Pixel **pixels;	// inicialização do ponteiro onde será alocada a matriz de pixels

	Imagem imagem; // inicialização da estrutura Imagem na variável imagem

	char entrada[10];	// guarda o comando inserido pelo usuário

	/* se sair == 1, o loop será encerrado */
	while(!sair) {
		/* recebendo comando do usuário */
		setbuf(stdin, NULL);

		printf("\nQual comando deseja executar?\nDigite 'ajuda' para ver a lista de comandos\n\n");
		scanf("%s", entrada);

		/* função criar nova imagem */
		if (strcmp(entrada, "imagem") == 0){

			imagemAberta = atribuiDimensoes(&imagem, pixels);

		}

		/* função abrir imagem existente */
		else if (strcmp(entrada, "abrir") == 0){
			/* codigo para abrir a imagem aqui */
			printf("A função 'abrir' ainda não foi implementada\n");
		}

		/* função salvar a imagem aberta */
		else if (strcmp(entrada, "salvar") == 0){
			/* verifica se existe uma imagem antes de salvar */
			if (imagemAberta){
					salvarImagem(&imagem, pixels);
			} else {
				printf("Erro: nenhuma imagem está aberta\n");
			}
		}

		/* função abrir ajuda com comandos */
		else if (strcmp(entrada, "ajuda") == 0){
			printf("- Lista de comandos \n");
			printf("1. imagem   (cria uma imagem)\n");
			printf("2. limpar   (preenche toda a imagem com a cor especificada)\n");
			printf("3. salvar    (salva em um arquivo ppm)\n");
			printf("4. abrir    (carrega uma imagem ppm)\n\n");
			printf("5. fechar    (encerra o programa)\n\n");
		}

		/* função fechar o programa */
		else if (strcmp(entrada, "fechar") == 0){
			/* se existir uma imagem aberta será necessário limpar toda alocação dinâmica */
			if (imagemAberta){
				/* liberando a matriz de pixel */ 
				for (int i = 0; i < imagem.lar; ++i)
					free(pixels[i]);
				free(pixels);
			}

			sair = 1;
		}

		/* funções de manipulação de imagem */
		else {
			/* a função ler operação só será executada se existir uma imagem aberta */
			if (imagemAberta)
				lerOperacao(entrada, imagem.lar, imagem.alt, pixels);	// função que interpreta o comando do usuário
			else
				printf("Erro: nenhuma imagem está aberta\n");
		}
	}

	return 0;
}
