#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>
/*-------------------------------
Estrutura: Pixel

Descrição: A cor de cada pixel na imagem é determinada através de três valores (RGB).
Esta estrutura é utilizada na matriz de pixels da imagem criada pelo usuário.
-------------------------------*/
typedef struct {
	int r;	// valor red
	int g;	// valor green
	int b;	// valor blue
} Pixel;

/*-------------------------------
Estrutura: Imagem

Descrição: Essa estrutura será responsável por guardar todas as informações da imagem
aberta, facilitando assim a escrita das informações em um novo arquivo ppm.
-------------------------------*/
typedef struct {
	FILE *file;				// recebe o arquivo .ppm
	char nome[30];			// string com nome do arquivo ppm

	char id[3];    // variavel id da imagem, o padrão será P3
	int alt, lar;   		// variavel altura e largura da imagem
	int numDePixels;		// numero de pixels na imagem
	int max;        	// variavel de valor max de cada pixel, o padrão será 255
	Pixel **pixels; 		// criacao da matriz de pixeis para armazenar a imagem
 
} Imagem;

#endif