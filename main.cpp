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

	do{
		cout << "Digite o tamanho do mapa: ";
		cin >> tamanhoDoMapa;

		if(tamanhoDoMapa == -1){
			return 0;
		}

		GrandLine cenario_jogo(tamanhoDoMapa);
		colocaObstaculo(&cenario_jogo, tamanhoDoMapa);
		//cout << cenario_jogo.getCenario()[0][0].getNome() << endl;

		cout << "-1 p/ sair" << endl;
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
	}while(true);

	return 0;
}

void colocaObstaculo(GrandLine *cenario, int tamanhoDoMapa){
	int i;
	srand(time(NULL));
	Elemento obs(" O ", obstaculo);
	Marinha mar(" M ", marinha, 100, false);	//HP, estado
	Pirata player(" P ", pirata, 100, 70.0, 0.0);	//HP, peso, peso adicional
	OnePiece op(300); //300 Kg
	int r_linha;
	int r_coluna;

//coloca obstaculos em uma posição aleatória entre 1,1 e n-1,n-1 em uma posição que não esteja ocupada
	for(i = 0; i < (tamanhoDoMapa/2); i++){
		do{
			r_linha = rand() % (tamanhoDoMapa-1) + 1;
			r_coluna = rand() % (tamanhoDoMapa-1) + 1;

			if(cenario->getCenario()[tamanhoDoMapa-1][tamanhoDoMapa-2].getTipo() == obstaculo ||
				 cenario->getCenario()[tamanhoDoMapa-2][tamanhoDoMapa-1].getTipo() == obstaculo ||
				 cenario->getCenario()[0][1].getTipo() == obstaculo || cenario->getCenario()[1][0].getTipo() == obstaculo){
					 r_linha = rand() % (tamanhoDoMapa-1) + 1;
					 r_coluna = rand() % (tamanhoDoMapa-1) + 1;
				 }
		}while(cenario->getCenario()[r_coluna][r_linha].getTipo() != espacoVazio);

		cenario->setCenario(obs, r_linha, r_coluna);
	}

//coloca marinha em uma posição aleatória entre 1,1 e n-1,n-1 em uma posição que não esteja ocupada
	do{
		r_linha = rand() % (tamanhoDoMapa-1) + 1;
		r_coluna = rand() % (tamanhoDoMapa-1) + 1;

//garante que a marinha nao tranque o caminho com uma pedra APENAS na origem
		if((r_linha == 1 && r_coluna == 0 && cenario->getCenario()[0][1].getTipo() == obstaculo) ||
			 (r_linha == 0 && r_coluna == 1 && cenario->getCenario()[1][0].getTipo() == obstaculo)){
				 r_linha = rand() % (tamanhoDoMapa-1) + 1;
				 r_coluna = rand() % (tamanhoDoMapa-1) + 1;
			 }
	}while(cenario->getCenario()[r_coluna][r_linha].getTipo() != espacoVazio);
	cenario->setCenario(mar, r_linha, r_coluna);

//o pirata parte de 0,0
	cenario->setCenario(player, 0, 0);
	cenario->setCenario(op, (tamanhoDoMapa-1), (tamanhoDoMapa-1));
}
