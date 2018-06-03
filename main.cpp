#include "biblio.h"
#include<iostream>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;


void procuraPirata(GrandLine mapa, int *p){
	int i, j;
	for(i = 0; i < mapa.getCenario().size(); i++){
		for(j = 0; j < mapa.getCenario()[0].size(); j++){
			if(mapa.getCenario()[i][j].getTipo() == pirata){
				p[0] = i;
				p[1] = j;
			}
		}
	}
}

void move(GrandLine *mapa, Pirata *p, int estava_x, int estava_y, Movimento ir_para){
	if(ir_para == baixo){
		if(estava_x+1 < mapa->getCenario().size()){
			if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == espacoVazio || mapa->getCenario()[estava_x+1][estava_y].getTipo() == onePiece){
				Elemento aux(" . ", espacoVazio);
				mapa->setCenario(aux, estava_x, estava_y);
				mapa->setCenario(*p, estava_x+1, estava_y);
			}else{
				cout << "Nao eh possivel ir para baixo" << endl;
			}
		}else{
			cout << "Nao existe mais cenario a baixo" << endl;
		}
	}else if(ir_para == cima){
		if(estava_x-1 >= 0){
			if(mapa->getCenario()[estava_x-1][estava_y].getTipo() == espacoVazio || mapa->getCenario()[estava_x+1][estava_y].getTipo() == onePiece){
				Elemento aux(" . ", espacoVazio);
				mapa->setCenario(aux, estava_x, estava_y);
				mapa->setCenario(*p, estava_x-1, estava_y);
			}else{
				cout << "Nao eh possivel ir para cima" << endl;
			}
		}else{
			cout << "Nao existe mais cenario a cima" << endl;
		}
	}else if(ir_para == direita){
		if(estava_y+1 < mapa->getCenario()[0].size()){
			if(mapa->getCenario()[estava_x][estava_y+1].getTipo() == espacoVazio || mapa->getCenario()[estava_x+1][estava_y].getTipo() == onePiece){
				Elemento aux(" . ", espacoVazio);
				mapa->setCenario(aux, estava_x, estava_y);
				mapa->setCenario(*p, estava_x, estava_y+1);
			}else{
				cout << "Nao eh possivel ir para direita" << endl;
			}
		}else{
			cout << "Nao existe mais cenario a direita" << endl;
		}
	}else {
		if(estava_y-1 >= 0){
			if(mapa->getCenario()[estava_x][estava_y-1].getTipo() == espacoVazio || mapa->getCenario()[estava_x+1][estava_y].getTipo() == onePiece){
				Elemento aux(" . ", espacoVazio);
				mapa->setCenario(aux, estava_x, estava_y);
				mapa->setCenario(*p, estava_x, estava_y-1);
			}else{
				cout << "Nao eh possivel ir para esquerda" << endl;
			}
		}else{
			cout << "Nao existe mais cenario a esquerda" << endl;
		}
	}
}


int main(){
	int i, j, tamanhoDoMapa;
	srand(time(NULL));

	Pirata player(" P ", pirata, 100, 70.0, 0.0);
	int posiP[2];	//guarda a posição anterior do pirata
	cout << "Digite o tamanho do mapa: ";
	cin >> tamanhoDoMapa;

	GrandLine cenario_jogo;
	cenario_jogo.inicializar(tamanhoDoMapa);

	cout << endl;
	cout << "'k' p/ sair" << endl;
	cout << "Legendas: "<< endl;
	cout << "P = Pirata" << endl;
	cout << "M = Marinha" << endl;
	cout << "OP = One Piece" << endl;

	cenario_jogo.visualizarCenario();
	cenario_jogo.mostraMapa();

//Variáveis para movimentação
	int movimento_int;
	Movimento movimento_real;
	char a = 'b';


	while(a != 'k'){
		a = getchar();
		movimento_int = rand() % 4 + 1;

//traduz o random para tipo MOVIMENTO
		if(movimento_int == 1){
			movimento_real = cima;
		}else if(movimento_int == 2){
			movimento_real = baixo;
		}else if(movimento_int == 3){
			movimento_real = esquerda;
		}else{
			movimento_real = direita;
		}

		procuraPirata(cenario_jogo, posiP);	//busca a última posição do pirata
		move(&cenario_jogo, &player, posiP[0], posiP[1], movimento_real);
		cenario_jogo.mostraMapa();
	}

	return 0;
}
