/**      @file: 160029783.c
 *     @author: Gustavo Henrique de Oliveira Santos
 * @disciplina: Algoritmos e Programação de Computadores
 * @Implementação do "Jogo da Vida" de Conway
 *
 * Implementação do "Jogo da Vida" de Conway, complete o código das funções
 * atualiza e gera_ppm. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Poucas linhas de modo que "caiba na tela"... Quando todo o código estiver
 * pronto, tente comentar o código para exibição na tela e analisar arquivos com
 * dimensões maiores. */
#define LINHAS 20
#define COLUNAS 50

#define VIVO '*'
#define MORTO ' '

typedef char status;
typedef status campo[LINHAS][COLUNAS];

/* Inicializa com o padrão "blinker". */
void blinker(campo m) {
	int i = LINHAS/2, j = COLUNAS/2;
	m[i-1][j] = m[i][j] = m[i+1][j] = VIVO;
}

/* Inicializa com o padrão "beacon". */
void beacon(campo m) {
	int i = LINHAS/2, j = COLUNAS/2;
	m[i-2][j-2] = m[i-2][j-1] = VIVO;
	m[i-1][j-2] = m[i-1][j-1] = VIVO;
	m[i+1][j+1] = m[i+1][j] = VIVO;
	m[i][j+1] = m[i][j] = VIVO;
}

/* Inicializa com o padrão "Figure 8". */
void figure8(campo m) {
	int i = LINHAS/2, j = COLUNAS/2;
	m[i-2][j-2] = m[i-2][j-1] = m[i-2][j] = VIVO;
	m[i-1][j-2] = m[i-1][j-1] = m[i-1][j] = VIVO;
	m[i][j-2] = m[i][j-1] = m[i][j] = VIVO;
	m[i+1][j+1] = m[i+1][j+2] = m[i+1][j+3] = VIVO;
	m[i+2][j+1] = m[i+2][j+2] = m[i+2][j+3] = VIVO;
	m[i+3][j+1] = m[i+3][j+2] = m[i+3][j+3] = VIVO;
}

/* Inicializa com o padrão "glider". */
void glider(campo m) {
    m[1][3] = VIVO;
	m[2][1] = m[2][3] = VIVO;
	m[3][2] = m[3][3] = VIVO;
}

/* Inicializa todas as células do campo dado conforme a opção de entrada dada. */
void inicializa(campo m, char opcao) {
	memset(m, MORTO, sizeof(campo)); /* todas a células mortas */

	switch(opcao) {
		case '2':
			beacon(m);
			break;
		case '3':
			figure8(m);
			break;
		case '4':
			glider(m);
			break;
		default:
			blinker(m);
		}
}

/* Escreve o campo na saída padrão. */
void exibe(campo m) {
	int i, j;

	for(i = 0; i < LINHAS; ++i) {
		for(j = 0; j < COLUNAS; ++j)
			printf("%c", m[i][j]);
		printf("\n");
	}
}

/* Atualiza o campo conforme as regras do jogo:
 *
 * 1) Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
 * 2) Qualquer célula viva com mais de três vizinhos vivos morre de
 * superpopulação.
 * 3) Qualquer célula morta com exatamente três vizinhos vivos se torna uma
 * célula viva.
 * 4) Qualquer célula viva com dois ou três vizinhos vivos continua no mesmo
 * estado para a próxima geração. */
void atualiza(campo m) {
	/* Atenção, uma célula que esteja na borda do campo não possui vizinho(s)
	 * além da borda. Por exemplo, uma célula de canto tem apenas os 3 vizinhos
	 * "para dentro" do campo.*/
	int x, y, n;
	campo aux;

	for(x=0; x<LINHAS; x++){
		for(y=0; y<COLUNAS; y++){
			aux[x] [y]=m[x] [y];
		}
	}

	for(x=0; x<LINHAS; x++){
		for(y=0; y<COLUNAS; y++){
			n=0;

			if(m[x-1] [y-1]==VIVO){
				n++;
			}
			if(m[x-1] [y]==VIVO){
				n++;
			}
			if(m[x+1] [y-1]==VIVO){
				n++;
			}
			if(m[x] [y+1]==VIVO){
				n++;
			}
			if(m[x+1] [y+1]==VIVO){
				n++;
			}
			if(m[x+1] [y]==VIVO){
				n++;
			}
			if(m[x-1] [y+1]==VIVO){
				n++;
			}
			if(m[x] [y-1]==VIVO){
				n++;
			}

			if(n<2 && m[x] [y]==VIVO){
				aux[x] [y]=MORTO;
			} else if(n>3 && m[x] [y]==VIVO){
				aux[x] [y]=MORTO;
			} else if(n==3 && m[x] [y]==MORTO){
				aux[x] [y]=VIVO;
			}
		}
	}

	for(x=0; x<LINHAS; x++){
		for(y=0; y<COLUNAS; y++){
			m[x] [y]=aux[x] [y];
		}
	}
}

/* Gera um arquivo PPM do campo dado. O nome do arquivo deve ser conway-##.ppm
 * onde ## representa dois dígitos com o valor do contador passado como
 * argumento. Por exemplo, cont = 0 gera o arquivo conway-00.ppm, cont = 37 gera
 * o arquivo conway-37.ppm. Assuma que 0 <= cont < 100. */
void gera_ppm(campo m, int cont) {

	int x, y;

	char nome[100];
	char aux[2];

	if(cont<10){
		sprintf(nome, "conway-0%d.ppm", cont);
	} else{
		sprintf(nome, "conway-%d.ppm", cont);
	}

	printf("%s\n", aux);

	FILE *fp = fopen(nome, "w+");

	if(fp != NULL){
		
		fprintf(fp, "P3\n");
		fprintf(fp, "%d %d\n", COLUNAS, LINHAS);
		fprintf(fp, "255\n");

		for(x=0; x<LINHAS; x++){
			for(y=0; y<COLUNAS; y++){
				if(m[x] [y] == VIVO){
					fprintf(fp, "255 255 255\n");
				} else{
					fprintf(fp, "0 0 0\n");
				}
			}
		}


		fclose(fp);
	}

}

/* Laço principal de execução. A configuração inicial depende do segundo
 * argumento dado. */
int main(int argc, char **argv) {
	int i, ciclos = 1;
	campo jogo_da_vida;

	inicializa(jogo_da_vida, argc < 2 ? '0' : argv[1][0]);

	do {
		printf("\nDigite a quantidade de ciclos:");
		scanf("%d", &ciclos);
	} while(0 < ciclos && ciclos >= 100);

	for(i = 1; i <= ciclos; ++i) {
		system("clear");
		printf("Ciclo %d:\n", i);
		exibe(jogo_da_vida);
		printf("\n\nPressione [Enter] para continuar.");
		getchar();

		gera_ppm(jogo_da_vida, i);

		atualiza(jogo_da_vida);
	}

    return 0;
}