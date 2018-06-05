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

	GrandLine cenario_jogo;
	cenario_jogo.inicializar(10);

	cout << endl << "Mapa" << endl;
	cenario_jogo.visualizarCenario();
	cout << endl;

	Movimento ir_para;
	char a;


	while(a != 'k'){
		cin >> a;
		getchar();

		if(a == 'w'){
			ir_para = cima;
		}else if(a == 's'){
			ir_para = baixo;
		}else if(a == 'd'){
			ir_para = direita;
		}else if(a == 'a'){
			ir_para = esquerda;
		}

		//ir_para = Movimento(rand() % 4 + 1);

		player.move(&cenario_jogo, ir_para);
		//boss.move(&cenario_jogo, movimento_realM);
		cenario_jogo.visualizarCenario();
		cout << endl;
	}

	return 0;
}
