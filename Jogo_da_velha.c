#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define iguais(a,b,c) (a!=' ' && a==b && b==c)

//Para jogar, insira a posicao do vetor (EX:2,2)


void exibe(char  m[3][3]){
	for(int i=0; i<3; i++){
		printf(" %c | %c | %c \n",m[i][0],m[i][1],m[i][2]);
		if( i<2 ) puts("---+---+---");
	}
	printf("\n");

}

int vencedor(char m[3][3]){
	for(int i=0; i<3;i++){
		if( iguais(m[i][0], m[i][1],m[i][2])) return m[i][0];
		if( iguais(m[0][i], m[1][i],m[2][i])) return m[0][i];
	}
	if( iguais(m[0][0], m[1][1],m[2][2])) return m[0][0];
	if( iguais(m[0][2], m[1][1],m[2][0])) return m[0][2];
	return ' ';
}

void usuario(char m[3][3]){
	int x,y;
	char es;

	do{
		printf("Posicao? ");
		scanf("%d %c %d",&y,&es,&x);


	}while(m[y][x] != ' ');
	m[y][x] = 'x';
	//exibe(m);

}

void computador(char m[3][3]){
	int x,y=0;
	char es[2];

	do{
		x = rand() % 3;
		y = rand() % 3;
		//printf("%d %d\n",x,y);

	}while(m[y][x] != ' ');
	m[y][x] = 'o';
	//exibe(m);


}



int main(void){
	char m[3][3] = {{' ',' ',' '},
					{' ',' ',' '},
					{' ',' ',' '}};
	int j=0,e,s;
	char v;
	printf("Par (0) ou impar (1)? ");
	scanf("%d", &e);
	srand(time(NULL));
	s = rand()%2;
	printf("Sorteando: %d\n",s);
	if( e==s ) puts("Voce comeca!");
	else puts("Eu comeco!");
	printf("Pressione enter...\n");
	_getch();
	do{
		exibe(m);
		if( e==s ) usuario(m);
		else computador(m);
		v = vencedor(m);
		s = !s;
	} while( ++j<9 && v==' ');
	exibe(m);
	switch(v){
		case ' ': puts("\nEmpate!\n"); break;
		case 'x': puts("\nVoce venceu!\n"); break;
		case 'o': puts("\nEu venci!\n");break;
	}
	return 0;
}
