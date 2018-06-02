#include "biblio.h"
#include<iostream>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;

int main(){
	int i, j, tamanhoDoMapa;
	GrandLine cenario_jogo;
	srand(time(NULL));

//personagens do jogo
	Pirata player(" P ", pirata, 100, 70.0, 0.0);
	Marinha boss(" M ", marinha, 100, false);
	int posiP[2];	//guarda a posição anterior do pirata
	int posiM[2];	//guarda a posição anterior da marinha

	cout << "Digite o tamanho do mapa: ";
	cin >> tamanhoDoMapa;

	cenario_jogo.inicializar(tamanhoDoMapa);

	cout << endl;
	cout << "'k' p/ sair" << endl;
	cout << "Legendas: "<< endl;
	cout << "P = Pirata" << endl;
	cout << "M = Marinha" << endl;
	cout << "OP = One Piece" << endl;

	cout << endl << "Mapa Original" << endl;
	cenario_jogo.visualizarCenario();	//cenario que foi gerado originalmente
	cout << endl << "Mapa com linhas removidas" << endl;
	cenario_jogo.mostraMapa();	//cenário após a remoção das linhas vazias
	cout << endl << endl;

//Variáveis para movimentação
	int movimento_int;
	Movimento movimento_realP;
	Movimento movimento_realM;
	char a = 'b';


	while(a != 'e'){
		a = getchar();
		movimento_int = rand() % 4 + 1;	//gera o próximo movimento

//traduz o random para tipo MOVIMENTO
//pirata
		if(movimento_int == 1){
			movimento_realP = cima;
		}else if(movimento_int == 2){
			movimento_realP = baixo;
		}else if(movimento_int == 3){
			movimento_realP = esquerda;
		}else{
			movimento_realP = direita;
		}

		movimento_int = rand() % 4 + 1;	//gera o próximo movimento

//marinha
		if(movimento_int == 1){
			movimento_realM = cima;
		}else if(movimento_int == 2){
			movimento_realM = baixo;
		}else if(movimento_int == 3){
			movimento_realM = esquerda;
		}else{
			movimento_realM = direita;
		}

		procuraPirata(cenario_jogo, posiP);	//busca a última posição do pirata
		procuraMarinha(cenario_jogo, posiM);	//busca a última posição da marinha
		player.move(&cenario_jogo, &player, posiP[0], posiP[1], movimento_realP);
		boss.move(&cenario_jogo, &boss, posiM[0], posiM[1], movimento_realM);
		cenario_jogo.mostraMapa();
		cout << endl;
	}

	return 0;
}
