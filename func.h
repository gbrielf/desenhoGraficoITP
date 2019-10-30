/*-------------------------------
Função: lerOperacao
Parâmetros: in - entrada do usuario
Retorno: True - se a entrada for um comando válido / False - se não for um comando válido

Descrição: esta função é responsável por identificar o comando inserido pelo usuário e,
caso o comando seja válido, executar a respectiva função.
---------------------------------*/
void lerOperacao(char *in){
	
	/*Comando criar imagem*/
	if (strcmp(in, "image") == 0){

		int *tamanhoDaImagem;
		tamanhoDaImagem = (int *) malloc(2 * sizeof(int));

		scanf("%d %d", &tamanhoDaImagem[0], tamanhoDaImagem[1]);
		listarPixels(tamanhoDaImagem[0], tamanhoDaImagem[1]);
	}
}

/*-------------------------------
Função: listarPixels
Parâmetros: sizeX - tamanho X da imagem, sizeY - tamanho Y da imagem
Retorno: Não possui retorno (void)

Descrição: Essa função criará uma matriz de p (numero de pixels) linhas e 3
colunas, a ideia é existir uma linha para cada pixel da imagem, determinar
sua cor (em valores rgb) e armazená-lo na memória. Dessa forma, alterações
de cor nos pixels serão mais eficientes, assim como facilitará o processo de
criação do arquivo ppm caso o usuário deseje salvar sua imagem.
---------------------------------*/
void listarPixels(int sizeX, int sizeY){
	int numeroDePixels = sizeX * sizeY;

	/* criando vetor de ponteiros de alocação dinâmica */
	int **listaDePixels;
	listaDePixels = (int **) malloc(numeroDePixels * sizeof(int *));

	/* criando vetores de 3 posições de alocação dinâmica */
	for (int i = 0; i < numeroDePixels; i++){
		listarPixels[i] = (int *) calloc(3, sizeof(int));
	}
}

/*-------------------------------
Função: freeAll
Parâmetros: Não possui parâmetros
Retorno: Não possui retorno (void)

Descrição: Responsável por liberar toda a memória alocada dinamicamente ao
longo do programa.
---------------------------------*/
void freeAll(){

}
