#include "biblio.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int i, j, cont = 15;
	Elemento test("^^^ ", obstaculo);
	Pirata vrau("PRT ", pirata, 100, 70, 0);
	Marinha poli("MRN ", marinha, 100, 60, false);
	GrandLine cenario_jogo(cont);

//	cout << cenario_jogo.getCenario()[0][0].getNome() << endl;

	cenario_jogo.setCenario(vrau, 0, 0);
	cenario_jogo.setCenario(poli, 10, 4);
	cenario_jogo.setCenario(poli, 4, 9);
	cenario_jogo.setCenario(test, 5, 0);
	cenario_jogo.setCenario(test, 9, 8);
	cenario_jogo.setCenario(test, 2, 10);
	for(i = 0; i < cont; i++){
		for(j = 0; j < cont; j++){
			cout << cenario_jogo.getCenario()[i][j].getNome();
		}
		cout << endl;
	}

	return 0;
}
