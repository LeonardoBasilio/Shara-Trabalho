#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void barra();
void imprimir();
void esquerda();
void direita();
void valoresbolinha();
void movimentacaodabolinha();
void gameover();
void tralhas();
int x=4,y=8;
int d = 1;
char posicaodetralha = ' ';
char matriz[10][12]; //MATRIX DO JOGO
int movimentacao[2] = {0, 0};
int posicaoatual[2] = {8, 6};
int posicaoanterior[2] = {0, 0};
int score = 0;

int main(void){
	char tecla;
	barra(); //Chamada da fun�ao de inicializa��o 
	imprimir();
	while(d){
		
		usleep(225000);
			if(kbhit()){ // Se eu digitar alguma coisa ent�o a compila��o entrar� nessa condicional, acionando a movimenta��o da barra
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
			movimentacaodabolinha();
	}

	printf("\n\n");
	return 0;
}

void barra(){ //Fun��o para criar a barra do jogador
	int i,j,c;
	
	for(i=0;i<9;i++)
		for(j=0;j<12;j++)
			matriz[i][j] = ' ';
			
	
	for(c = x; c <= y; c++) {
		matriz[9][c] = '*';
	}
	
	for (i=1;i<5;i++) {
		for (j=1;j<11;j++) {
			matriz[i][j] = '#';
		}
	}
}


void imprimir(){
	int i,j;
	
	for(i=0;i<=9;i++){
		printf("|");
		for(j=0;j<12;j++){
			printf("%c", matriz[i][j]);
		}	
		printf("|\n");
		
		
	}
	printf("\n \n");
	printf("Score = %d ",score);
}

void esquerda(){//Fun��o que move o '*' para a esquerda

  int i;
  
  if(x>0) { //Adicionando limite para a extremidade esquerda
	  for(i=0;i<5;i++){
		matriz[9][x+i-1] = '*';
		matriz[9][x+i] = ' ';
	  }
	  x -=1;
	  y -=1;
	}
}

void direita(){//Fun��o ques move o '*' para a direita
    int i;
    
	if(y<11){//Adicionanddo limite para a extremidade direita
	
	    for(i=0;i<5;i++){
	 		matriz[9][y-i+1] = '*';
	 		matriz[9][y-i] = ' ';
			
		}
		x +=1;
		y +=1;
	}
}

void valoresbolinha() { // Fun��o que determina os valores que ser�o somados ou subtraidos nas linhas e colunas de acordo com a posi�ao atual
	if (posicaoatual[0] == 8 && posicaoatual[1] <= y+1 && posicaoatual[1] >= x-1) {
		if (posicaoatual[1] <= x+1) {
			movimentacao[0] = -1;
			movimentacao[1] = -1;
		}
		else if (posicaoatual[1] >= y-1){
			movimentacao[0] = -1;
			movimentacao[1] = 1;
		}
		else {
			movimentacao[0] = -1;
			movimentacao[1] = 0;
		}
	}
	if(posicaoatual[1] == 0) {
		movimentacao[1] = 1;
	}
	if(posicaoatual[1] == 11) {
		movimentacao[1] = -1;
	}
	if(posicaoatual[0] == 0) {
		movimentacao[0] = 1;
	}
	if(posicaoatual[0] == 9) {
		gameover();
	}
}
void movimentacaodabolinha() { // Funcao de atribuir na 'O' a sua proxima posi��o; 
	valoresbolinha();
	posicaoanterior[0] = posicaoatual[0];
	posicaoanterior[1] = posicaoatual[1];
	tralhas();
	posicaoatual[0] += movimentacao[0];
	posicaoatual[1] += movimentacao[1];
	posicaodetralha = matriz[posicaoatual[0]][posicaoatual[1]];
	matriz[posicaoanterior[0]][posicaoanterior[1]] = ' ';
	matriz[posicaoatual[0]][posicaoatual[1]] = 'O';
	imprimir();
	
}
void gameover() { // Fun��o caso vc perda o jogo
	int i, j;
	for(i=0;i<9;i++)
		for(j=0;j<11;j++)
			matriz[i][j] = ' ';
	system("cls");
	matriz[3][1] = 'G';
	matriz[3][2] = 'A';
	matriz[3][3] = 'M';
	matriz[3][4] = 'E';
	
	matriz[3][6] = 'O';
	matriz[3][7] = 'V';
	matriz[3][8] = 'E';
	matriz[3][9] = 'R';
	d = 0; // Acaba com o while
}
void tralhas() {
	if (posicaodetralha == '#') { // Verifica se a posicao atual tinha um '#', se sim vai mudar a movimenta�ao
		if (movimentacao[0] == 1 && movimentacao[1] == 1) {
			movimentacao[0] = -1;score+=1;
		}
		else if(movimentacao[0] == -1 && movimentacao[1] == -1) {
			movimentacao[0] = 1;score+=1;
		}
		else if(movimentacao[0] == 1 && movimentacao[1] == -1) {
			movimentacao[0] = -1;score+=1;
		}
		else if(movimentacao[0] == -1 && movimentacao[1] == 1) {
			movimentacao[0] = 1;score+=1;
		}
		else if(movimentacao[0] == -1 && movimentacao[1] == 0) {
			movimentacao[0] = 1;score+=1;
		}
		else if(movimentacao[0] == 1 && movimentacao[1] == 0) {
			movimentacao[0] = -1;score+=1;
		}
	}
}
