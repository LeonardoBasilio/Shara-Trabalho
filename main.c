#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void barra();
void imprimir();
void esquerda();
void direita();
int x=3,y=8;
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
			printf("%c",matriz[i][j]);
		}		
		printf("|\n");
	}
}

void esquerda(){//Função que move o '*' para a esquerda

  int i;
  
  if(x>0) { //Adicionando limite para a extremidade direita
	  for(i=0;i<4;i++){
	  	matriz[y][x+i] = ' ';
	    matriz[y][x+i-1] = '*';
	  }
	  x -=1;
	}
}

void direita(){//Função ques move o '*' para a direita
    int i;
    
	if(x<7){
	
	    for(i=0;i<4;i++){
	 
	    	matriz[y][x-i] = ' ';
	    	matriz[y][x+i+1] = '*';
		}
		x +=1;
	}
}
