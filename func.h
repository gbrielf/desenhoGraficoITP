#ifndef FUNC_H
#define FUNC_H
#include "struct.h"


/*-------------------------------
Função: lerOperacao
Parâmetros: in - entrada do usuario, dimensões da imagem, matriz de pixels
Retorno: Nenhum

Descrição: esta função é responsável por identificar o comando inserido pelo usuário e,
caso o comando seja válido, executar a respectiva função.
---------------------------------*/
int lerOperacao(char *in, int tamX, int tamY, Pixel **pixels);

int atribuiDimensoes(Imagem *imagem, Pixel **pixels);

void abrirImagem(); //ainda não foi feita

void salvarImagem(Imagem *imagem, Pixel **pixels);


#endif