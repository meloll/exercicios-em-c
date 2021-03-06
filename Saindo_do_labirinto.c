#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX 15




int gera(int m[MAX][MAX]){

	
	for( int y=0;y<MAX;y++){
		for(int x=0;x<MAX;x++){
			
			
			if(y != 0 && y != MAX-1 && x != 0 && x != MAX-1){
				m[y][x]= (int)rand()/(int)RAND_MAX;
				if(rand()%100 <=25){m[y][x]=1;}
			}

			
			else{m[y][x]=1;}
				
		}
	}
	m[1][0]=0;
	m[13][14]=0;

}

void exibe(int m[MAX][MAX]){

	for(int y=0; y<MAX; y++){
		for(int x=0; x<MAX; x++)
			printf("%s",m[y][x] ? "\xDB\xDB": "  ");
		puts("");
	}
}

void mostra(char c, int i, int j){
	_gotoxy(2*j+1,i+1);
	printf("%c%c\b",c,c);
	_sleep(1);
}

int sai(int m[MAX][MAX], int i, int j){
	m[i][j] = 2;
	mostra('\xB0',i,j);
	if( i==MAX-2 && j==MAX-1) return 1;
	if( m[i+1][j] == 0 && sai(m,i+1,j)) return 1;
	if( m[i][j+1] == 0 && sai(m,i,j+1)) return 1;
	if( m[i-1][j]==0 && sai(m,i-1,j)) return 1;
	if( j>0 && m[i][j-1]==0 && sai(m,i,j-1)) return 1;
	mostra(' ',i,j);
	return 0;
}

int main(void){
	int m[MAX][MAX];
	srand(time(NULL));
    gera(m);
    exibe(m);
    _textcolor(15);
    sai(m,1,0);
    printf("\n");
    return 0;


}




