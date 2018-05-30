#include "biblio.h"
#include<iostream>
#include<vector>
#include <cstdio>
#include <ctime>
using namespace std;

void colocaObstaculo(GrandLine *cenario, int tamanhoDoMapa);


int main(){
	int i, j, tamanhoDoMapa;
	//testre, no Labcomp deu certo
	// int cont = 15;
	// Elemento test(" O ", obstaculo);
	// Pirata vrau(" P ", pirata, 100, 70, 0);
	// Marinha poli(" M ", marinha, 100, 60, false);

	cout << "Digite o tamanho do mapa: ";
	cin >> tamanhoDoMapa;
	GrandLine cenario_jogo(tamanhoDoMapa);
	colocaObstaculo(&cenario_jogo, tamanhoDoMapa);

	//teste, Labcomp deu certo
	//cout << cenario_jogo.getCenario()[0][0].getNome() << endl;
	// cenario_jogo.setCenario(vrau, 0, 0);
	// cenario_jogo.setCenario(poli, 10, 4);
	// cenario_jogo.setCenario(poli, 4, 9);
	// cenario_jogo.setCenario(test, 5, 0);
	// cenario_jogo.setCenario(test, 9, 8);
	// cenario_jogo.setCenario(test, 2, 10);

	cout << "Legendas: "<< endl;
	cout << "P = Pirata" << endl;
	cout << "M = Marinha" << endl;
	cout << "OP = One Piece" << endl << endl;


	//imprime o mapa
	for(i = 0; i < tamanhoDoMapa; i++){
		for(j = 0; j < tamanhoDoMapa; j++){
			cout << cenario_jogo.getCenario()[i][j].getNome();
		}
		cout << endl;
	}

	return 0;
}

void colocaObstaculo(GrandLine *cenario, int tamanhoDoMapa){
	int i;
	srand(time(NULL));
	Elemento obs(" O ", obstaculo);
	Marinha mar(" M ", marinha, 100, false);	//HP, estado
	Pirata player(" P ", pirata, 100, 70.0, 0.0);	//HP, peso, peso adicional
	OnePiece op(300); //300 Kg, Tn?
	int r_linha;
	int r_coluna;

	for(i = 0; i < (tamanhoDoMapa/2); i++){
		r_linha = rand() % (tamanhoDoMapa-1) + 1;
		r_coluna = rand() % (tamanhoDoMapa-1) + 1;
		cenario->setCenario(obs, r_linha, r_coluna);
	}

	//coloca marinha em uma posição aleatória entre 1,1 e n-1,n-1
	r_linha = rand() % (tamanhoDoMapa-1) + 1;
	r_coluna = rand() % (tamanhoDoMapa-1) + 1;
	cenario->setCenario(mar, r_linha, r_coluna);

	//o pirata parte de 0,0
	cenario->setCenario(player, 0, 0);
	cenario->setCenario(op, (tamanhoDoMapa-1), (tamanhoDoMapa-1));
}
