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

void procuraMarinha(GrandLine mapa, int *m){
	int i, j;
	for(i = 0; i < mapa.getCenario().size(); i++){
		for(j = 0; j < mapa.getCenario()[0].size(); j++){
			if(mapa.getCenario()[i][j].getTipo() == marinha){
				m[0] = i;
				m[1] = j;
			}
		}
	}
}

void moveP(GrandLine *mapa, Pirata *p, int estava_x, int estava_y, Movimento ir_para){
	if(ir_para == baixo){
		if(estava_x+1 < mapa->getCenario().size()){
			if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == espacoVazio){
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
			if(mapa->getCenario()[estava_x-1][estava_y].getTipo() == espacoVazio){
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
			if(mapa->getCenario()[estava_x][estava_y+1].getTipo() == espacoVazio){
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
			if(mapa->getCenario()[estava_x][estava_y-1].getTipo() == espacoVazio){
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

void moveM(GrandLine *mapa, Marinha *m, int estava_x, int estava_y, Movimento ir_para){
//define o momento que a marinha deve acordar e impede a verificação em lugares fora do mapa
	if(estava_x+1 < mapa->getCenario().size()){
		if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == pirata){
			m->setEstado(true);
		}
	}
	if(estava_x-1 >= 0){
		if(mapa->getCenario()[estava_x-1][estava_y].getTipo() == pirata){
			m->setEstado(true);
		}
	}
	if(estava_y+1 < mapa->getCenario()[0].size()){
		if(mapa->getCenario()[estava_x][estava_y+1].getTipo() == pirata){
			m->setEstado(true);
		}
	}
	if(estava_y-1 >= 0){
		if(mapa->getCenario()[estava_x][estava_y-1].getTipo() == pirata){
			m->setEstado(true);
		}
	}

//inicia o movimento da marinha se ela estiver acordada
	if(m->getEstado() == true){
		if(ir_para == baixo){
			if(estava_x+1 < mapa->getCenario().size()){
				if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == espacoVazio){
					Elemento aux(" . ", espacoVazio);
					mapa->setCenario(aux, estava_x, estava_y);
					mapa->setCenario(*m, estava_x+1, estava_y);
				}else{
					cout << "MARINHA - Nao eh possivel ir para baixo" << endl;
				}
			}else{
				cout << "MARINHA - Nao existe mais cenario a baixo" << endl;
			}
		}else if(ir_para == cima){
			if(estava_x-1 >= 0){
				if(mapa->getCenario()[estava_x-1][estava_y].getTipo() == espacoVazio){
					Elemento aux(" . ", espacoVazio);
					mapa->setCenario(aux, estava_x, estava_y);
					mapa->setCenario(*m, estava_x-1, estava_y);
				}else{
					cout << "MARINHA - Nao eh possivel ir para cima" << endl;
				}
			}else{
				cout << "MARINHA - Nao existe mais cenario a cima" << endl;
			}
		}else if(ir_para == direita){
			if(estava_y+1 < mapa->getCenario()[0].size()){
				if(mapa->getCenario()[estava_x][estava_y+1].getTipo() == espacoVazio){
					Elemento aux(" . ", espacoVazio);
					mapa->setCenario(aux, estava_x, estava_y);
					mapa->setCenario(*m, estava_x, estava_y+1);
				}else{
					cout << "MARINHA - Nao eh possivel ir para direita" << endl;
				}
			}else{
				cout << "MARINHA - Nao existe mais cenario a direita" << endl;
			}
		}else {
			if(estava_y-1 >= 0){
				if(mapa->getCenario()[estava_x][estava_y-1].getTipo() == espacoVazio){
					Elemento aux(" . ", espacoVazio);
					mapa->setCenario(aux, estava_x, estava_y);
					mapa->setCenario(*m, estava_x, estava_y-1);
				}else{
					cout << "MARINHA - Nao eh possivel ir para esquerda" << endl;
				}
			}else{
				cout << "MARINHA - Nao existe mais cenario a esquerda" << endl;
			}
		}
	}
}



int main(){
	int i, j, tamanhoDoMapa;
	srand(time(NULL));

	Pirata player(" P ", pirata, 100, 70.0, 0.0);
	Marinha boss(" M ", marinha, 100, false);
	int posiP[2];	//guarda a posição anterior do pirata
	int posiM[2];
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

		procuraPirata(cenario_jogo, posiP);	//busca a última posição do pirata
		procuraMarinha(cenario_jogo, posiM);
		moveP(&cenario_jogo, &player, posiP[0], posiP[1], movimento_realP);
		moveM(&cenario_jogo, &boss, posiM[0], posiM[1], movimento_realM);
		cenario_jogo.mostraMapa();
		cout << endl;
	}

	return 0;
}
