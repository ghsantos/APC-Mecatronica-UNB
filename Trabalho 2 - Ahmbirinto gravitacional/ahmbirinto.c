/* @ ahmbirinto.c
 * @ disciplina: Algoritmos e Programação de Computadores
 * @ Aluno: Gustavo Henrique de Oliveira Santos
 *
 * Ahmbirinto Gravitacional
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void gira_antihorario(int nivel, char matrizaux[22] [22]){

	int x, y;
	char matriz_h [22] [22];

	for(x=0; x<nivel; x++){
		for(y=0; y<nivel; y++){
			matriz_h [x] [y] = matrizaux [x] [y];
		}
	}

	for(x=0; x<nivel; x++){
		for(y=0; y<nivel; y++){
			matrizaux [x] [y] = matriz_h [y] [nivel - x -1];
		}
	}
}

void gira_horario(int nivel, char matrizaux[22] [22]){

	int x, y;
	char matriz_h [22] [22];

	for(x=0; x<nivel; x++){
		for(y=0; y<nivel; y++){
			matriz_h [x] [y] = matrizaux [x] [y];
		}
	}

	for(x=0; x<nivel; x++){
		for(y=0; y<nivel; y++){
			matrizaux [x] [y] = matriz_h [nivel - y - 1] [x];
		}
	}


}

void geramatriz(int nivel, char matrizaux[22] [22], char paredes, char Ahm, char saida_lab){


	int x, y, ale, ale2;

	srand((unsigned)time(NULL));
	ale = rand()%100;

	for(x=0; x<nivel; x++){
		for(y=0; y<nivel; y++){
			ale = rand()%100;
			if(x==0 || y==0 || x==(nivel-1) || y==(nivel-1)){
				matrizaux [x] [y] = paredes;
			} else{
				if(ale%7==0){
					matrizaux [x] [y] = paredes;
				} else{
					matrizaux [x] [y] = ' ';
				}
			}
		}
	}

	if(paredes == '*'){
		matrizaux [0] [0] = '#';
	} else {
		matrizaux [0] [0] = '*';
	}

	ale = rand()%(nivel-2);
	ale2 = rand()%(nivel-2);

	matrizaux [ale + 1] [ale2 + 1] = saida_lab;

	ale = rand()%(nivel-2);
	ale2 = rand()%(nivel-2);

	matrizaux [1] [ale2 + 1] = Ahm;

}

void configuracoes(int *nivel, char *sent_horario, char *sent_anthorario, char *tec_termino, char *Ahm, char *paredes, char *saida_lab){

	int opcao=0, op_controles=0, sair_controles;
	char novo_sent_horario;
	int escolha=0;
	char op1 [3], op2 [2], op3 [2];
	char novo_ahm, nova_parede, nova_saida;

	do{
		printf("\e[H\e[2J");
		if(!(opcao==0 || opcao==1 || opcao==2 || opcao==3)){
			printf("\n");
			printf("《Opção invalida! Tente novamente》\n");
		}

		opcao=10;

		printf("\n");
		printf("  ╔══════════════════════════╗\n");
		printf("  ║  1 -    Dificuldade      ║\n");
		printf("  ╚══════════════════════════╝\n");
		printf("\n");
		printf("  ╔══════════════════════════╗\n");
		printf("  ║  2 -     Controles       ║\n");
		printf("  ╚══════════════════════════╝\n");
		printf("\n");
		printf("  ╔══════════════════════════╗\n");
		printf("  ║  3 - Configuração Visual ║\n");
		printf("  ╚══════════════════════════╝\n");
		printf("\n");
		printf("  ╔══════════════════════════╗\n");
		printf("  ║  0 -      Voltar         ║\n");
		printf("  ╚══════════════════════════╝\n");
		scanf("%d", &opcao);
		while(getchar()!='\n');

		if(opcao==1){

			

			

			do{

				if(*nivel==1){
					op1[0] = '<';
					op1[1] = '-';
					op1[2] = '\0';
					op2[0] = ' ';
					op2[1] = ' ';
					op2[2] = '\0';
					op3[0] = ' ';
					op3[1] = ' ';
					op3[2] = '\0';
				} else if(*nivel==2){
					op1[0] = ' ';
					op1[1] = ' ';
					op1[2] = '\0';
					op2[0] = '<';
					op2[1] = '-';
					op2[2] = '\0';
					op3[0] = ' ';
					op3[1] = ' ';
					op3[2] = '\0';
				} else if(*nivel==3){
					op1[0] = ' ';
					op1[1] = ' ';
					op1[2] = '\0';
					op2[0] = ' ';
					op2[1] = ' ';
					op2[2] = '\0';
					op3[0] = '<';
					op3[1] = '-';
					op3[2] = '\0';
				}

				printf("\e[H\e[2J");
				printf("\n");
				printf("  ╔══════════════════════════╗\n");
				printf("  ║  1 -  Fácil  (10x10)   %s║\n", op1);
				printf("  ╚══════════════════════════╝\n");
				printf("\n");
				printf("  ╔══════════════════════════╗\n");
				printf("  ║  2 -  Médio  (15x15)   %s║\n", op2);
				printf("  ╚══════════════════════════╝\n");
				printf("\n");
				printf("  ╔══════════════════════════╗\n");
				printf("  ║  3 - Difícil (20x20)   %s║\n", op3);
				printf("  ╚══════════════════════════╝\n");
				printf("\n");
				printf("  ╔══════════════════════════╗\n");
				printf("  ║  0 -      Voltar         ║\n");
				printf("  ╚══════════════════════════╝\n");

				scanf("%d", &escolha);
				while(getchar()!='\n');

				if(escolha==1 || escolha==2 || escolha==3){
					*nivel=escolha;
				}

			}while(escolha!=0);

		} else if(opcao==2){

			do{
				printf("\e[H\e[2J");
				printf("\n");
				printf("  ╔═══════════════════════════╗\n");
				printf("  ║ 1 -   Sentido Horário:   %c║\n", *sent_horario);
				printf("  ╚═══════════════════════════╝\n");
				printf("\n");
				printf("  ╔═══════════════════════════╗\n");
				printf("  ║ 2 -Sentido anti-horário: %c║\n", *sent_anthorario);
				printf("  ╚═══════════════════════════╝\n");
				printf("\n");
				printf("  ╔═══════════════════════════╗\n");
				printf("  ║ 3 -  Tecla de término:   %c║\n", *tec_termino);
				printf("  ╚═══════════════════════════╝\n");
				printf("\n");
				printf("  ╔═══════════════════════════╗\n");
				printf("  ║ 0 -       Voltar          ║\n");
				printf("  ╚═══════════════════════════╝\n");

				scanf("%d", &op_controles);
				while(getchar()!='\n');

				if(op_controles==1){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 1 -   Sentido Horário     ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &novo_sent_horario);

						if(novo_sent_horario== *sent_anthorario || novo_sent_horario== *tec_termino){
							sair_controles=1;
						} else if(novo_sent_horario != '\n'){
							*sent_horario = novo_sent_horario;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

				if(op_controles==2){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 2 - Sentido anti-horário  ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &novo_sent_horario);

						if(novo_sent_horario== *sent_horario || novo_sent_horario== *tec_termino){
							sair_controles=1;
						} else if(novo_sent_horario != '\n'){
							*sent_anthorario = novo_sent_horario;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

				if(op_controles==3){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 3 -  Tecla de término     ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &novo_sent_horario);

						if(novo_sent_horario== *sent_anthorario || novo_sent_horario== *sent_horario){
							sair_controles=1;
						} else if(novo_sent_horario != '\n'){
							*tec_termino = novo_sent_horario;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

			}while(op_controles != 0);


		} else if(opcao==3){

			printf("\n");
			do{
				printf("\e[H\e[2J");
				printf("\n");
				printf("  ╔════════════════════════════╗\n");
				printf("  ║ 1 -         Ahm:          %c║\n", *Ahm);
				printf("  ╚════════════════════════════╝\n");
				printf("\n");
				printf("  ╔════════════════════════════╗\n");
				printf("  ║ 2 - Paredes do labirinto: %c║\n", *paredes);
				printf("  ╚════════════════════════════╝\n");
				printf("\n");
				printf("  ╔════════════════════════════╗\n");
				printf("  ║ 3 - Saída do labirinto:   %c║\n", *saida_lab);
				printf("  ╚════════════════════════════╝\n");
				printf("\n");
				printf("  ╔════════════════════════════╗\n");
				printf("  ║ 0 -       Voltar           ║\n");
				printf("  ╚════════════════════════════╝\n");

				scanf("%d", &op_controles);
				while(getchar()!='\n');

				if(op_controles==1){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 1 -         Ahm           ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &novo_ahm);

						if(novo_ahm== *paredes || novo_ahm== *saida_lab){
							sair_controles=1;
						} else if(novo_ahm != '\n'){
							*Ahm = novo_ahm;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

				if(op_controles==2){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 2 - Paredes do labirinto  ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &nova_parede);

						if(nova_parede== *Ahm || nova_parede== *saida_lab){
							sair_controles=1;
						} else if(nova_parede != '\n'){
							*paredes = nova_parede;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

				if(op_controles==3){

					sair_controles=0;

					do{
						printf("\e[H\e[2J");

						printf("  ╔═══════════════════════════╗\n");
						printf("  ║ 3 -  Saída do labirinto   ║\n");
						printf("  ╚═══════════════════════════╝\n");
						printf("\n");

						if(sair_controles==1){
							printf("《  Caractere já utilizado! 》\n");
							printf("《     Tente Novamente!     》\n");
							printf("\n");
						}

						printf("《 Digite o novo caractere: 》\n");
						scanf("%c", &nova_saida);

						if(nova_saida== *Ahm || nova_saida== *paredes){
							sair_controles=1;
						} else if(nova_saida != '\n'){
							*saida_lab = nova_saida;
							sair_controles=0;
						}
					}while(sair_controles!=0);
				}

			}while(op_controles != 0);
		}

	}while(opcao!=0);
}

void jogar(int nivel, char sent_horario, char sent_anthorario, char tec_termino, char Ahm, char paredes, char saida_lab){
	int modo = nivel;
	int x, y, i, mecheu=0, vencer=0;
	char matriz [22] [22];
	char comando, enter;

	switch(modo){
		case 1:
			nivel = 12;
			geramatriz(nivel, matriz, paredes, Ahm, saida_lab);
			break;
		case 2:
			nivel = 17;
			geramatriz(nivel, matriz, paredes, Ahm, saida_lab);
			break;
		case 3:
			nivel = 22;
			geramatriz(nivel, matriz, paredes, Ahm, saida_lab);
			break;
	}
	
	do{

		do{
			mecheu=0;

			printf("\e[H\e[2J");
			for(x=0; x<nivel; x++){
				for(y=0; y<nivel; y++){
					printf("%c ", matriz [x] [y]);
				}
				printf("\n");
			}

			for(i=0; i<60000000; i++);

			for(x=(nivel-1); x>=0; x--){
				for(y=(nivel-1); y>=0; y--){
					if(matriz [x] [y] == Ahm && matriz [x+1] [y] == ' '){
						matriz [x] [y] = ' ';
						matriz [x+1] [y] = Ahm;
						mecheu=1;
					}

					if(matriz [x] [y] == Ahm && matriz [x+1] [y] == saida_lab){
						vencer=1;
						mecheu=0;
					} 
				}
			}
		}while(mecheu==1);

		if(vencer==1){
			
			do{
				printf("\e[H\e[2J");
				printf("  ╔═══════════════════════════════╗\n");
				printf("  ║                               ║\n");
				printf("  ║           PARABENS!           ║\n");
				printf("  ║     Você recuperou o Ahm      ║\n");
				printf("  ║         com sucesso!          ║\n");
				printf("  ║                               ║\n");
				printf("  ║          ┌───────┐            ║\n");
				printf("  ║          │  ^-^  │            ║\n");
				printf("  ║          └──┐ .──┘            ║\n");
				printf("  ║             │/                ║\n");
				printf("  ║             %c                 ║\n", Ahm);
				printf("  ║                               ║\n");
				printf("  ║   ╔═══════════════════════╗   ║\n");
				printf("  ║   ║  Aperte [Enter] para  ║   ║\n");
				printf("  ║   ║     voltar ao menu    ║   ║\n");
				printf("  ║   ╚═══════════════════════╝   ║\n");
				printf("  ╚═══════════════════════════════╝\n");
				scanf("%c", &enter);
			}while(getchar()!='\n');

		} else{

			printf("\n");
			printf("Comandos: \n");
			printf("%c para girar no Sentido Horário\n", sent_horario);
			printf("%c para girar no Sentido anti-horário\n", sent_anthorario);
			printf("%c para sair\n", tec_termino);
			printf("\n");

			scanf(" %c", &comando);

			if(comando == sent_horario){
				gira_horario(nivel, matriz);
			} else if(comando == sent_anthorario){
				gira_antihorario(nivel, matriz);
			} else if(comando==tec_termino){

				do{
					printf("\e[H\e[2J");
					printf("  ╔════════════════════════════════╗\n");
					printf("  ║                                ║\n");
					printf("  ║           GAME OVER            ║\n");
					printf("  ║ Você decidiu voltar a estudar  ║\n");
					printf("  ║ e abandonar o Ahm para sempre! ║\n");
					printf("  ║                                ║\n");
					printf("  ║           ┌───────┐            ║\n");
					printf("  ║           │  ;-;  │            ║\n");
					printf("  ║           └──┐ .──┘            ║\n");
					printf("  ║              │/                ║\n");
					printf("  ║              %c                 ║\n", Ahm);
					printf("  ║                                ║\n");
					printf("  ║    ╔═══════════════════════╗   ║\n");
					printf("  ║    ║  Aperte [Enter] para  ║   ║\n");
					printf("  ║    ║     voltar ao menu    ║   ║\n");
					printf("  ║    ╚═══════════════════════╝   ║\n");
					printf("  ╚════════════════════════════════╝\n");
					scanf("%c", &enter);
				}while(getchar()!='\n');

			}
		}

	}while(!(comando == tec_termino || vencer==1));

}

int main(void){

	int opcao=0;
	int nivel=2;
	char sent_horario='>';
	char sent_anthorario='<';
	char tec_termino='q';
	char Ahm = '@';
	char paredes = '*';
	char saida_lab = 'X';

	do{
		printf("\e[H\e[2J");
		printf("  ╔════════════════════════╗\n");
		printf("  ║AHMBIRINTO GRAVITACIONAL║\n");
		printf("  ╚════════════════════════╝\n");
		printf("\n");

		if(!(opcao==0 || opcao==1 || opcao==2)){
			printf("《Opção invalida! Tente novamente》\n");
		}

		opcao=10;

		printf("\n");
		printf("  ╔════════════════════════╗\n");
		printf("  ║  1 -    JOGAR          ║\n");
		printf("  ╚════════════════════════╝\n");
		printf("\n");
		printf("  ╔════════════════════════╗\n");
		printf("  ║  2 -  COFIGURAÇÕES     ║\n");
		printf("  ╚════════════════════════╝\n");
		printf("\n");
		printf("  ╔════════════════════════╗\n");
		printf("  ║  0 -    SAIR           ║\n");
		printf("  ╚════════════════════════╝\n");

		scanf("%d", &opcao);
		while(getchar()!='\n');

		if(opcao==1){
			jogar(nivel, sent_horario, sent_anthorario, tec_termino, Ahm, paredes, saida_lab);
		} else if(opcao==2){
			configuracoes(&nivel, &sent_horario, &sent_anthorario, &tec_termino, &Ahm, &paredes, &saida_lab);
		}

	}while(opcao!=0);
	
	return 0;
}
