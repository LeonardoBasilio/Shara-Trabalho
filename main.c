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
void varredura();
void cima();
void baixo();
int x=4,y=8,z = 9;
int t,u;
int d = 1;
char posicaodetralha = ' ';
char matriz[10][12]; //MATRIX DO JOGO 
int movimentacao[2] = {0, 0};
int posicaoatual[2] = {8, 6};
int posicaoanterior[2] = {0, 0};
int score = 0;

int main(void){
	char tecla;
	barra(); //Chamada da funçao de inicialização 
	imprimir();
	while(d){
		
		usleep(225000);
			if(kbhit()){ // Se eu digitar alguma coisa então a compilação entrará nessa condicional, acionando a movimentação da barra
				tecla = getch();		
				switch(tecla){
					case 119:cima();
						break;
					case 115:baixo();
						break;
					case 97: esquerda();
						break;
					case 100: direita();      
						break;
					case 113: exit(0);
						break;
					default: printf("Teclas Permitidas:\n (A) Esquerda  (D) Direita\n");
						break;
				}
			}
			system("cls");
			movimentacaodabolinha();
			varredura();
	}

	printf("\n\n");
	return 0;
}

void barra(){ //Função para criar a barra do jogador
	int i,j,c;
	
	for(i=0;i<9;i++)
		for(j=0;j<12;j++)
			matriz[i][j] = ' ';
			
	
	for(c = x; c <= y; c++) {
		matriz[z][c] = '*';
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

void esquerda(){//Função que move o '*' para a esquerda

  int i;
  
  if(x>0) { //Adicionando limite para a extremidade esquerda
	  for(i=0;i<5;i++){
		matriz[z][x+i-1] = '*';
		matriz[z][x+i] = ' ';
	  }
	  x -=1;
	  y -=1;
	}
}

void direita(){//Função ques move o '*' para a direita
    int i;
    
	if(y<11){//Adicionanddo limite para a extremidade direita
	
	    for(i=0;i<5;i++){
	 		matriz[z][y-i+1] = '*';
	 		matriz[z][y-i] = ' ';
			
		}
		x +=1;
		y +=1;
	}
}

void valoresbolinha() { // Função que determina os valores que serão somados ou subtraidos nas linhas e colunas de acordo com a posiçao atual
	if (posicaoatual[0] == z-1 && posicaoatual[1] <= y+1 && posicaoatual[1] >= x-1) {
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
void movimentacaodabolinha() { // Funcao de atribuir na 'O' a sua proxima posição; 
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
void gameover() { // Função caso vc perda o jogo
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
void varredura(){
	int p = 0;
	int i,j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 12; j++) {
			if (matriz[i][j] == '#') {
				p++;
			}
		}
	}
	if (p == 0) {
		for(i=0;i<9;i++)
			for(j=0;j<11;j++)
				matriz[i][j] = ' ';
		system("cls");
		matriz[3][1] = 'V';
		matriz[3][2] = 'O';
		matriz[3][3] = 'C';
		matriz[3][4] = 'E';
		
		matriz[3][6] = 'G';
		matriz[3][7] = 'A';
		matriz[3][8] = 'N';
		matriz[3][9] = 'H';
		matriz[3][10] = 'O';
		matriz[3][11] = 'U';
		
		matriz[4][2] = 'P';
		matriz[4][3] = 'A';
		matriz[4][4] = 'R';
		matriz[4][5] = 'A';
		matriz[4][6] = 'B';
		matriz[4][7] = 'E';
		matriz[4][8] = 'N';
		matriz[4][9] = 'S';
		imprimir();
		d = 0;
	}

	
}
void cima() {
	z--;
	int c, j;
	for (j = 0; j < 12; j++) {
		matriz[z+1][j] = ' ';
	}
	for(c = x; c <= y; c++) {
		matriz[z][c] = '*';
	}
}
void baixo() {
	z++;
	int c, j;
	for (j = 0; j < 12; j++) {
		matriz[z-1][j] = ' ';
	}
	for(c = x; c <= y; c++) {
		matriz[z][c] = '*';
	}
}
void tralhas() {
	if (posicaodetralha == '#') { // Verifica se a posicao atual tinha um '#', se sim vai mudar a movimentaçao
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
