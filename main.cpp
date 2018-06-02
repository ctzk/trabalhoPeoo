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

		GrandLine cenario_jogo;
		cenario_jogo.inicializar(tamanhoDoMapa);
		//cout << cenario_jogo.getCenario()[0][0].getNome() << endl;

		cout << endl;
		cout << "-1 p/ sair" << endl;
		cout << "Legendas: "<< endl;
		cout << "P = Pirata" << endl;
		cout << "M = Marinha" << endl;
		cout << "OP = One Piece" << endl << endl;

		cenario_jogo.visualizarCenario();

	}while(true);

	return 0;
}
