#include <stdio.h>
#include "bibliotecaPilhaEncadeada.h"
#include <stdlib.h>
#define MAX 20

void criaLabirinto(char labirinto[MAX][MAX]){
     int i,j,x,y,z;
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             labirinto[i][j]='|';
             else
              labirinto[i][j]='.';
          }
     for(i=0;i<MAX;i++){
           labirinto[0][i]='*';
           labirinto[MAX-1][i]='*';
           labirinto[i][0]='*';
           labirinto[i][MAX-1]='*';
           }// fim for
        x=  (rand() % MAX-2) +1;
        labirinto[x][19]='S';
     }// fim funcao cria
//-------------------------------------------     
void printLabirinto(char labirinto[MAX][MAX]){
    int i,j;
     for ( i = 0; i < MAX; i++)
    {
     printf("\n");
          for ( j = 0; j < MAX; j++)
			printf (" %c ",labirinto[i][j] );
     	}

} // fim funcao
//-------------------------------------------
     
 int buscaSaida(char lab[MAX][MAX],int i, int j){
        tPilha p1;
        inicializa(&p1);
        tdado atual;
        
       do{
			lab[i][j] = 1;
			   
        	// ANDAR E CONFERIR SE É UMA SAIDA
        	if(lab[i][j+1] == 'S' || lab[i][j+1] == '.'){ //DIREITA
        		if(lab[i][j+1] == 'S'){
					atual.x = i;
					atual.y = j+1;
					lab[i][j] = 1;
					break;
				}else {
					atual.x = i;
		        	atual.y = j;
		        	push(&p1, atual);
		        	j++;
				}     		
			}else if(lab[i+1][j] == 'S' || lab[i+1][j] == '.'){ // BAIXO
				
				if(lab[i+1][j] == 'S'){
		    		atual.x = i+1;
		    		atual.y = j;
		    		lab[i][j] = 1;
			    	break;
				}else {
					atual.x = i;
	        		atual.y = j;
	        		push(&p1, atual);
	        		i++;
				}
				
			}else if(lab[i][j-1] == 'S' || lab[i][j-1] == '.'){ // ESQUERDA
			
				if(lab[i][j-1] == 'S'){
		    		atual.x = i;
		    		atual.y = j-1;
		    		lab[i][j] = 1;
		    		break;
				}else{
					atual.x = i;
	        		atual.y = j;
	        		push(&p1, atual);
	        		j--;
				}
				
			}else if(lab[i-1][j] == 'S' || lab[i-1][j] == '.'){// CIMA
			
				if(lab[i-1][j] == 'S'){
		    		atual.x = i-1;
		    		atual.y = j;
		    		lab[i][j] = 1;
		    		break;
				}else{
					atual.x = i;
	        		atual.y = j;
	        		push(&p1, atual);
	        		i--;	
				}
					
			}else if(!isEmpty(p1)){
				lab[i][j] = 4;
				atual = pop(&p1);
				i = atual.x;
				j = atual.y;
			}else{
				printf("\nNao existe Saida!");
				break;
			}
		
			Sleep(0);
			system("cls");
			printLabirinto(lab);
		}while(1);
		
		system("cls");
		printLabirinto(lab);
		printf("\nA Saida foi encontrada! \nPosicao da saida: [%d][%d]",atual.x,atual.y);

        return 1;
 }// fim funcao

//-------------------------------------------
int main(){
    char meuLabirinto[MAX][MAX];
    int x,y;
    criaLabirinto(meuLabirinto);
    printLabirinto(meuLabirinto);
    printf("\nEntre com a posicao inicial do robo:");
    scanf("%d %d",&x,&y);
    buscaSaida(meuLabirinto,x,y);
    getch();
    return 0;
    }

