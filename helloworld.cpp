#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void barra();
void imprimir();
void esquerda();
void direita();
int x=8,y=5;
char matriz[9][11]; //MATRIX DO JOGO

int main(void){
	
	char tecla;
	
	barra(); //Chamada da funçao de inicialização
	
	while(1){
		tecla = getch();
		system("cls");		
		switch(tecla){
			case 97: esquerda();
			
				break;
				
			case 100: direita();
			
				break;
				
			case 113: exit(0);
				
			default: printf("Teclas Permitidas:\n (A) Esquerda  (D) Direita\n");
				break;
		}		
		
		imprimir();	
	}
		
		
	printf("\n\n");
	return 0;
	
	
}


void barra(){ //Função para criar a barra do jogador
	int i,j;
	
	for(i=0;i<9;i++)
		for(j=0;j<11;j++)
			matriz[i][j] = ' ';
	
	for(int c = 3; c <= 7; c++) {
		matriz[8][c] = '*';
		
	}
	
	

	 imprimir(); //Chamada da função imprimir

		
}


void imprimir(){
	int i,j;
	
	for(i=0;i<9;i++){
		printf("|");
		for(j=0;j<11;j++){
			printf("%c",matriz[i][j]);
		}
		
		printf("|\n");
	}
	
	
}

void esquerda(){//Função que move o '*' para a esquerda
    char aux;
    int a = x, b = y-1; //y=5
 if(b>=0 && b<=10) { //Adicionando limite para a extremidade direita
	for(int c = y; c > 0; c--) {
	 aux = matriz[x][c];
     matriz[x][c] = matriz[x][c-1];
     matriz[x][c-1] = aux;    
	}
 }
}


void direita(){//Função que move o '*' para a direita
    char aux;
    int a = x, b = y+1;
 if(b>=0 && b<=10) { //Adicionando limite para a extremidade direita
     aux = matriz[x][y];
     matriz[x][y] = matriz[x][y+1];
     matriz[x][y+1] = aux;
     y +=1;
 }
}
