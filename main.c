#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void barra();
void imprimir();
void esquerda();
void direita();
void valoresbolinha();
void movimentacaodabolinha();
void gameover();
int x=3,y=6;

char matriz[9][11]; //MATRIX DO JOGO
int movimentacao[2] = {0, 0};
int posicaoatual[2] = {7, 5};
int posicaoanterior[2] = {0, 0};

int main(void){
	char tecla;
	barra(); //Chamada da funçao de inicialização ok

	while(1){
		if(kbhit()){ // Se eu digitar alguma coisa então a compilação entrará nessa condicional, acionando a movimentação da barra
			tecla = getch();		
			switch(tecla){
				case 97: esquerda();
					break;
				case 100: direita();      
					break;
				case 113: exit(0);
	
				default: printf("Teclas Permitidas:\n (A) Esquerda  (D) Direita\n");
					break;
			}
		}
		system("cls");
		imprimir();
		movimentacaodabolinha();
		if (matriz[30][1] == 'G') { // Se a função game over for ativada, o while será interrompido
			break;
		}
	}

	printf("\n\n");
	return 0;
}

void barra(){ //Função para criar a barra do jogador
	int i,j,c;
	
	for(i=0;i<9;i++)
		for(j=0;j<11;j++)
			matriz[i][j] = ' ';
			
	
	for(c = 3; c < 7; c++) {
		matriz[8][c] = '*';
	}
	
	for (i=1;i<5;i++) {
		for (j=1;j<10;j++) {
			matriz[i][j] = '#';
		}
	}
	 imprimir(); //Chamada da função imprimir
}


void imprimir(){
	int i,j;
	
	for(i=0;i<9;i++){
		printf("|");
		for(j=0;j<11;j++){
			if (i == posicaoatual[0] && j == posicaoatual[1]) {
				printf("O");
			} else {
				printf("%c",matriz[i][j]);
			}
		}		
		printf("|\n");
	}
}

void esquerda(){//Função que move o '*' para a esquerda

  int i;
  
  if(x>0) { //Adicionando limite para a extremidade esquerda
	  for(i=0;i<4;i++){
		matriz[8][x+i-1] = '*';
		matriz[8][x+i] = ' ';
	  }
	  x -=1;
	  y -=1;
	}
}

void direita(){//Função ques move o '*' para a direita
    int i;
    
	if(y<10){//Adicionanddo limite para a extremidade direita
	
	    for(i=0;i<4;i++){
	 		matriz[8][y-i+1] = '*';
	 		matriz[8][y-i] = ' ';
			
		}
		x +=1;
		y +=1;
	}
}

void valoresbolinha() { // Função que determina os valores que serão somados ou subtraidos nas linhas e colunas
	if (posicaoatual[0] == 7 && posicaoatual[1] <= y && posicaoatual[1] >= x) {
		if (posicaoatual[1] <= x+1) {
			movimentacao[0] = -1;
			movimentacao[1] = -1;
		}
		else {
			movimentacao[0] = -1;
			movimentacao[1] = 1;
		}
	}
	else if(posicaoatual[1] == 0) {
		movimentacao[1] = 1;
	}
	else if(posicaoatual[1] == 11) {
		movimentacao[1] = 1;
	}
	else if(posicaoatual[0] == 0) {
		movimentacao[0] = 1;
	}
	else if(posicaoatual[0] == 8) {
		gameover();
	}
	else {
		posicaoatual[0] += movimentacao[0];
		posicaoatual[1] += movimentacao[1];
	}
}
void movimentacaodabolinha() { // Funcao de atribuir na 'O' a sua proxima posição;
	valoresbolinha();
	posicaoanterior[0] = posicaoatual[0];
	posicaoanterior[1] = posicaoatual[1];
	posicaoatual[0] += movimentacao[0];
	posicaoatual[1] += movimentacao[1];
}
void gameover() { // Função caso vc perda o jogo
	matriz[3][1] = 'G';
	matriz[3][2] = 'A';
	matriz[3][3] = 'M';
	matriz[3][4] = 'E';
	
	matriz[3][6] = 'O';
	matriz[3][7] = 'V';
	matriz[3][8] = 'E';
	matriz[3][9] = 'R';
}
