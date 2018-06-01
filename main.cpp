#include "biblio.h"
#include<iostream>
#include<vector>
#include <cstdio>
#include <ctime>
using namespace std;

int main(){
	int i, j, tamanhoDoMapa;

	do{
		cout << "Digite o tamanho do mapa: ";
		cin >> tamanhoDoMapa;

		if(tamanhoDoMapa == -1){
			return 0;
		}

		GrandLine cenario_jogo(tamanhoDoMapa);
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
