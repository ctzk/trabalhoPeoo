#include "biblio.h"
#include<iostream>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;






int main(){
	int i, j, tamanhoDoMapa;
	srand(time(NULL));

	Pirata player(" P ", pirata, 100, 70.0, 0.0);
	Marinha boss(" M ", marinha, 100, false);
	int posiP[2];	//guarda a posição anterior do pirata
	int posiM[2];

	GrandLine cenario_jogo;
	cenario_jogo.inicializar(10);

	cout << endl;
	cout << "'k' p/ sair" << endl;
	cout << "Legendas: "<< endl;
	cout << "P = Pirata" << endl;
	cout << "M = Marinha" << endl;
	cout << "OP = One Piece" << endl;

	cout << endl << "Mapa Original" << endl;
	cenario_jogo.visualizarCenario();
	cout << endl << "Mapa com linhas removidas" << endl;
	cenario_jogo.mostraMapa();
	cout << endl << endl;

//Variáveis para movimentação
	int movimento_int;
	Movimento movimento_realP;
	Movimento movimento_realM;
	char a = 'b';


	while(a != 'k'){
		a = getchar();
		movimento_int = rand() % 4 + 1;

//traduz o random para tipo MOVIMENTO
//Pirata
		if(movimento_int == 1){
			movimento_realP = cima;
		}else if(movimento_int == 2){
			movimento_realP = baixo;
		}else if(movimento_int == 3){
			movimento_realP = esquerda;
		}else{
			movimento_realP = direita;
		}

		movimento_int = rand() % 4 + 1;

//Marinha
		if(movimento_int == 1){
			movimento_realM = cima;
		}else if(movimento_int == 2){
			movimento_realM = baixo;
		}else if(movimento_int == 3){
			movimento_realM = esquerda;
		}else{
			movimento_realM = direita;
		}

		player.procuraPosicao(cenario_jogo, posiP);	//busca a última posição do pirata
		boss.procuraPosicao(cenario_jogo, posiM);
		player.move(&cenario_jogo, movimento_realP);
		boss.move(&cenario_jogo, movimento_realM);
		cenario_jogo.mostraMapa();
		cout << endl;
	}

	return 0;
}
