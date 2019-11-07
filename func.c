#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "func.h"

/*-------------------------------
Função: lerOperacao
Parâmetros: in - entrada do usuario, dimensões da imagem, matriz de pixels
Retorno: Nenhum

Descrição: esta função é responsável por identificar o comando inserido pelo usuário e,
caso o comando seja válido, executar a respectiva função.
---------------------------------*/

int lerOperacao(char *in, int tamX, int tamY, Pixel **pixels){

	/* Comando clear */
	if (strcmp(in, "clear") == 0){
		/* as variaveis r,g,b receberão os valores RGB inseridos pelo usuário */
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);

		for (int i = 0; i < tamX; ++i){		// para cada coluna
			for (int j = 0; j < tamY; ++j){	// para cada elemento na coluna
				pixels[i][j].r = r;
				pixels[i][j].g = g;
				pixels[i][j].b = b;
			}
		}
	}

	/* caso a operação inserida não seja compatível com nenhuma presente no programa */
	else {
		printf("Erro: comando '%s' inexistente\n", in);
	}

	return 1;
}

int atribuiDimensoes(Imagem *imagem, Pixel **pixels){

	/* atribuindo dimensões da imagem à estrutura Imagem */
	printf("Qual as dimensões da imagem?\n");
	scanf("%d %d", &imagem->lar, &imagem->alt);

	/* atribuindo o número de pixels na imagem à variável numDePixels */
	imagem->numDePixels = imagem->alt * imagem->lar;

	/* definindo padrões da imagem */
	strcpy(imagem->id, "P3");	// o id padrão das imagens geradas por esse programa será P3
	imagem->max = 255;			// o valor de cor máximo das imagens geradas por esse programa será 255

	/* criando uma matriz de estruturas tipo Pixel */
	//segmentation fault abaixo (linha 55)
	pixels = (Pixel **) realloc(pixels, imagem->lar * sizeof(Pixel *)); // criando vetor de ponteiros do tipo Pixel

	for (int i = 0; i < imagem->lar; ++i)
		pixels[i] = (Pixel *) calloc(imagem->alt, sizeof(Pixel));

	return 1;



}

void salvarImagem(Imagem *imagem, Pixel **pixels){
		/* recebendo o nome do arquivo .ppm */
		printf("Qual nome você deseja utilizar para sua imagem? (exemplo.ppm)\n");
		scanf("%s", imagem->nome);

		/* criando o arquivo da imagem em modo de escrita */
		imagem->file = fopen(imagem->nome, "w");

		/* escrevendo no arquivo criado */
		fprintf(imagem->file, "%s\n", imagem->id);										// escrevendo ID da imagem
		fprintf(imagem->file, "%d %d\n", imagem->lar, imagem->alt);		// escrevendo dimensões da imagem
		fprintf(imagem->file, "%d\n", imagem->max);										// escrevendo valor de cor máximo

		/* escrevendo os valores RGB de cada pixel da imagem */
		for (int i = 0; i < imagem->lar; ++i){						
			for (int j = 0; j < imagem->alt; ++j){
				fprintf(imagem->file, "%d ", pixels[i][j].r);		// escrevendo valor R
				fprintf(imagem->file, "%d ", pixels[i][j].g);		// escrevendo valor G
				fprintf(imagem->file, "%d\n", pixels[i][j].b);		// escrevendo valor B, com quebra de linha
			}
		}
		/* fechando arquivo de imagem */
		fclose(imagem->file);

}
