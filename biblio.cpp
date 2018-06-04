#include "enum.h"
#include "biblio.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


//##################### ELEMENTO #############################
Elemento::Elemento(){
	nome = " . ";
	tipo = espacoVazio;
}

Elemento::Elemento(string nome, TipoElemento tipo){
	this->nome = nome;
	this->tipo = tipo;
}

void Elemento::setNome(string nome){
	this->nome = nome;
}

string Elemento::getNome(){
	return nome;
}

void Elemento::setTipo(TipoElemento tipo){
	this->tipo = tipo;
}


TipoElemento Elemento::getTipo(){
	return tipo;
}
//##################### PESSOA #############################
Pessoa::Pessoa(string nome, TipoElemento tipo, int hp):Elemento(nome, tipo){
	this->hp = hp;
}

void Pessoa::setHp(int hp){
	this->hp = hp;
}

int Pessoa::getHp(){
	return hp;
}

void Pessoa::procuraPosicao(GrandLine mapa, int *p){
	// int i, j;
	// for(i = 0; i < mapa.getCenario().size(); i++){
	// 	for(j = 0; j < mapa.getCenario()[0].size(); j++){
	// 		if(mapa.getCenario()[i][j].getTipo() == getTipo()){
	// 			p[0] = i;
	// 			p[1] = j;
	// 		}
	// 	}
	// }
}

void Pessoa::move(GrandLine *mapa, Movimento ir_para){
}


//##################### ONEPIECE #############################
OnePiece::OnePiece(float peso):Elemento(" OP", onePiece){	//One piece pode continuar assim
	this->peso = peso;
}

void OnePiece::setPeso(float peso){
	this->peso = peso;
}

float OnePiece::getPeso(){
	return peso;
}

//##################### PIRATA #############################
Pirata::Pirata(string nome, TipoElemento tipo, int hp,
				float peso, float pesoAdd) : Pessoa(nome, tipo, hp){
	this->peso = peso;
	this->pesoAdd = pesoAdd;
}

void Pirata::setPeso(float peso){
	this->peso = peso;
}

float Pirata::getPeso(){
	return peso;
}

void Pirata::setPesoAdd(float pesoAdd){
	this->pesoAdd = pesoAdd;
}

float Pirata::getPesoAdd(){
	return pesoAdd;
}

void Pirata::move(GrandLine *mapa, Movimento ir_para){
	int estava_x, estava_y;
	int i, j;
	for(i = 0; i < mapa->getCenario().size(); i++){
		for(j = 0; j < mapa->getCenario()[0].size(); j++){
			if(mapa->getCenario()[i][j].getTipo() == getTipo()){
				estava_x = i;
				estava_y = j;
			}
		}
	}

	Pirata p(getNome(), getTipo(), getHp(), getPeso(), getPesoAdd());

	if(ir_para == baixo){
		if(estava_x+1 < mapa->getCenario().size()){
			if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == espacoVazio){
				Elemento aux(" . ", espacoVazio);
				mapa->setCenario(aux, estava_x, estava_y);
				mapa->setCenario(p, estava_x+1, estava_y);
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
				mapa->setCenario(p, estava_x-1, estava_y);
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
				mapa->setCenario(p, estava_x, estava_y+1);
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
				mapa->setCenario(p, estava_x, estava_y-1);
			}else{
				cout << "Nao eh possivel ir para esquerda" << endl;
			}
		}else{
			cout << "Nao existe mais cenario a esquerda" << endl;
		}
	}
}

//##################### MARINHA #############################
Marinha::Marinha(std::string nome, TipoElemento tipo, int hp,
									bool estado) : Pessoa(nome, tipo, hp){
	this->estado = estado;
}

void Marinha::setEstado(bool estado){
	this->estado = estado;
}

bool Marinha::getEstado(){
	return estado;
}


void Marinha::move(GrandLine *mapa, Movimento ir_para){
	int estava_x, estava_y;
	int i, j;
	for(i = 0; i < mapa->getCenario().size(); i++){
		for(j = 0; j < mapa->getCenario()[0].size(); j++){
			if(mapa->getCenario()[i][j].getTipo() == getTipo()){
				estava_x = i;
				estava_y = j;
			}
		}
	}

//define o momento que a marinha deve acordar e impede a verificação em lugares fora do mapa
	if(estava_x+1 < mapa->getCenario().size()){
		if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == pirata){
			setEstado(true);
		}
	}
	if(estava_x-1 >= 0){
		if(mapa->getCenario()[estava_x-1][estava_y].getTipo() == pirata){
			setEstado(true);
		}
	}
	if(estava_y+1 < mapa->getCenario()[0].size()){
		if(mapa->getCenario()[estava_x][estava_y+1].getTipo() == pirata){
			setEstado(true);
		}
	}
	if(estava_y-1 >= 0){
		if(mapa->getCenario()[estava_x][estava_y-1].getTipo() == pirata){
			setEstado(true);
		}
	}

	Marinha p(getNome(), getTipo(), getHp(), getEstado());

	if(getEstado() == true){
		if(ir_para == baixo){
			if(estava_x+1 < mapa->getCenario().size()){
				if(mapa->getCenario()[estava_x+1][estava_y].getTipo() == espacoVazio){
					Elemento aux(" . ", espacoVazio);
					mapa->setCenario(aux, estava_x, estava_y);
					mapa->setCenario(p, estava_x+1, estava_y);
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
					mapa->setCenario(p, estava_x-1, estava_y);
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
					mapa->setCenario(p, estava_x, estava_y+1);
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
					mapa->setCenario(p, estava_x, estava_y-1);
				}else{
					cout << "Nao eh possivel ir para esquerda" << endl;
				}
			}else{
				cout << "Nao existe mais cenario a esquerda" << endl;
			}
		}
	}
}

//##################### GrandLine #############################
GrandLine::GrandLine(){
}

void GrandLine::inicializar(int tam){
	int i;
	cenario.resize(tam);
	for(i = 0; i < tam; i++){
		cenario[i].resize(tam);
	}

	srand(time(NULL));
	Elemento obs(" O ", obstaculo);
	Marinha mar(" M ", marinha, 0, false);	//HP, estado
	Pirata player(" P ", pirata, 0, 0, 0);	//HP, peso, peso adicional
	OnePiece tesouro(300); //Peso
	int r_linha, r_coluna;

	cenario[0][0] = player;
	cenario[cenario.size()-1][cenario.size()-1] = tesouro;

//coloca obstaculos em uma posição aleatória entre 1,1 e n-1,n-1 em uma posição que não esteja ocupada
	for(i = 0; i < (cenario.size()/2); i++){
		do{
			r_linha = rand() % (cenario.size()-1) + 1;
			r_coluna = rand() % (cenario.size()-1) + 1;

			if(cenario[cenario.size()-1][cenario.size()-2].getTipo() == obstaculo ||
				 cenario[cenario.size()-2][cenario.size()-1].getTipo() == obstaculo ||
				 cenario[0][1].getTipo() == obstaculo || cenario[1][0].getTipo() == obstaculo){
					 r_linha = rand() % (cenario.size()-1) + 1;
					 r_coluna = rand() % (cenario.size()-1) + 1;
				 }
		}while(cenario[r_linha][r_coluna].getTipo() != espacoVazio);

		cenario[r_linha][r_coluna] = obs;
	}

//coloca marinha em uma posição aleatória entre 1,1 e n-1,n-1 em uma posição que não esteja ocupada
	do{
		r_linha = rand() % (cenario.size()-1) + 1;
		r_coluna = rand() % (cenario.size()-1) + 1;

		if((r_linha == 1 && r_coluna == 0 && cenario[0][1].getTipo() == obstaculo) ||
			 (r_linha == 0 && r_coluna == 1 && cenario[1][0].getTipo() == obstaculo)){
				 r_linha = rand() % (cenario.size()-1) + 1;
				 r_coluna = rand() % (cenario.size()-1) + 1;
			 }
	}while(cenario[r_linha][r_coluna].getTipo() != espacoVazio);

	cenario[r_linha][r_coluna] = mar;
}

vector < vector<Elemento> > GrandLine::getCenario(){
	return cenario;
}

void GrandLine::setCenario(Elemento n, int x, int y){
	cenario[x][y] = n;
}

void GrandLine::setCenario(Pirata n, int x, int y){
	cenario[x][y] = n;
}

void GrandLine::setCenario(Marinha n, int x, int y){
	cenario[x][y] = n;
}

void GrandLine::visualizarCenario(){
	int i, j;
	bool temObjetos = true;

	for(i = 0; i < cenario.size(); i++){
		for(j = 0; j < cenario[0].size(); j++){
			cout << getCenario()[i][j].getNome();
		}
		cout << endl;
	}

//remove linhas com apenas espaços vazios
	for(i = 0; i < cenario.size(); i++){
		for(j = 0; j < cenario[0].size(); j++){
			if(cenario[i][j].getTipo() != espacoVazio){
				j = cenario[0].size();
			}else if((j == cenario[0].size()-1) && cenario[i][j].getTipo() == espacoVazio){
				cenario[i].clear();	//esvazia o vetor
				cenario.erase(cenario.begin()+i);	//remove o vetor "da conta"
				i--;
			}
		}
	}
}

void GrandLine::mostraMapa(){
	int i, j;

	for(i = 0; i < cenario.size(); i++){
		for(j = 0; j < cenario[0].size(); j++){
			cout << getCenario()[i][j].getNome();
		}
		cout << endl;
	}
}
