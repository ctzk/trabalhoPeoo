#include "enum.h"
#include "biblio.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

//##################### ELEMENTO #############################
Elemento::Elemento(){
	nome = "";
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

void Pessoa::move(GrandLine *mapa, Movimento ir_para){
}

//##################### PIRATA #############################
Pirata::Pirata():Pessoa("", pirata, 0){
	peso = 0;
	pesoAdd = 0;
}

Pirata::Pirata(string nome, TipoElemento tipo, int hp, float peso, float pesoAdd) : Pessoa(nome, tipo, hp){
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
	int esta_x, esta_y, vai_x, vai_y;
	int i, j;
	for(i = 0; i < mapa->cenario.size(); i++){
		for(j = 0; j < mapa->cenario.size(); j++){
			if(mapa->cenario[i][j].getTipo() == getTipo()){
				esta_x = i;
				esta_y = j;
			}
		}
	}

	if(ir_para == baixo){
		vai_x = esta_x+1;
		vai_y = esta_y;
	}
	else if(ir_para == cima){
		vai_x = esta_x-1;
		vai_y = esta_y;
	}
	else if(ir_para == esquerda){
		vai_x = esta_x;
		vai_y = esta_y-1;
	}
	else if(ir_para == direita){
		vai_x = esta_x;
		vai_y = esta_y+1;
	}

	if(mapa->cenario[0][0].getTipo() == pirata){
		descarregar();
	}

	//o pirata continua a carregar o One Piece até que seu peso adicioal chegue ao máximo
	if(AchouOnePiece(*mapa)){
		if(getPesoAdd() < getPeso() && mapa->tesouro.getPeso() > 0){
			carregar();
			mapa->tesouro.setPeso(mapa->tesouro.getPeso()-10);
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-1].setTipo(pirata);
			return;
		}
	}

	//movimentos especiais do pirata nas duas casas proximas de One Piece
	if(mapa->cenario[mapa->cenario.size()-3][mapa->cenario.size()-1].getTipo() == pirata &&
			mapa->cenario[mapa->cenario.size()-2][mapa->cenario.size()-1].getTipo() == espacoVazio && getPesoAdd() == 0){
			mapa->cenario[mapa->cenario.size()-3][mapa->cenario.size()-1].setTipo(espacoVazio);
			mapa->cenario[mapa->cenario.size()-2][mapa->cenario.size()-1].setTipo(pirata);
			return;
	}

	else if(mapa->cenario[mapa->cenario.size()-2][mapa->cenario.size()-1].getTipo() == pirata && getPesoAdd() == 0){
			mapa->cenario[mapa->cenario.size()-2][mapa->cenario.size()-1].setTipo(espacoVazio);
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-1].setTipo(pirata);
			return;
	}

	else if(mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-3].getTipo() == pirata &&
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-2].getTipo() == espacoVazio && getPesoAdd() == 0){
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-3].setTipo(espacoVazio);
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-2].setTipo(pirata);
			return;
	}

	else if(mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-2].getTipo() == pirata && getPesoAdd() == 0){
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-2].setTipo(espacoVazio);
			mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-1].setTipo(pirata);
			return;
	}


	if(ir_para == baixo){

		if(vai_x < mapa->cenario.size()){
			if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == onePiece){
				mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
				mapa->cenario[vai_x][vai_y].setTipo(pirata);
			}
			else{
				//para fugir da marinha
				if(mapa->cenario[vai_x][vai_y].getTipo() == marinha){
					Movimento movimento_de_fulga;
					do{
						movimento_de_fulga = Movimento(rand() % 4 + 1);
					}while(movimento_de_fulga == ir_para);

					cout << endl << "*" << getNome() << " percebeu que a marinha esta proxima*" << endl << endl;
					move(&(*mapa), movimento_de_fulga);
					return;
				}
				cout << endl << "*Um obstaculo bloqueou a passagem de " << getNome() << ".*" << endl << endl;
				mapa->marinheiro.setEstado(true);
			}
		}
		else{
			cout << endl << "*" << getNome() << " quase saiu da Grand Line BAIXO.*" << endl << endl;
		}
	}
	else if(ir_para == cima){

		if(vai_x >= 0){
			if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio){

				//checa se está no One Piece
				if(AchouOnePiece(*mapa)){
					if(mapa->tesouro.getPeso() == 0){	//quando o tesouro acaba remove onePiece do mapa
						mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					}else{
						mapa->cenario[esta_x][esta_y].setTipo(onePiece);
					}

					mapa->cenario[vai_x][vai_y].setTipo(pirata);
					return;
				}

				//deixa uma espaço vazio por onde passou
				mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
				mapa->cenario[vai_x][vai_y].setTipo(pirata);
			}
			else{
				//para fugir da marinha
				if(mapa->cenario[vai_x][vai_y].getTipo() == marinha){
					Movimento movimento_de_fulga;
					do{
						movimento_de_fulga = Movimento(rand() % 4 + 1);
					}while(movimento_de_fulga == ir_para);

					cout << endl << "*" << getNome() << " percebeu que a marinha esta proxima*" << endl << endl;
					move(&(*mapa), movimento_de_fulga);
					return;
				}

				cout << endl << "*Um obstaculo bloqueou a passagem de " << getNome() << ".*" << endl << endl;
				mapa->marinheiro.setEstado(true);
			}
		}
		else{
			cout << endl << "*" << getNome() << " quase saiu da Grand Line CIMA.*" << endl << endl;
		}
	}

	else if(ir_para == direita){

		if(vai_y < mapa->cenario[0].size()){
			if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == onePiece){
				mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
				mapa->cenario[vai_x][vai_y].setTipo(pirata);
			}
			else{
				//para fugir da marinha
				if(mapa->cenario[vai_x][vai_y].getTipo() == marinha){
					Movimento movimento_de_fulga;
					do{
						movimento_de_fulga = Movimento(rand() % 4 + 1);
					}while(movimento_de_fulga == ir_para);

					cout << endl << "*" << getNome() << " percebeu que a marinha esta proxima*" << endl << endl;
					move(&(*mapa), movimento_de_fulga);
					return;
				}

				cout << endl << "*Um obstaculo bloqueou a passagem de " << getNome() << ".*" << endl << endl;
				mapa->marinheiro.setEstado(true);
			}
		}
		else{
			cout << endl << "*" << getNome() << " quase saiu da Grand Line DIREITA.*" << endl << endl;
		}
	}

	else if(ir_para == esquerda){

		if(vai_y >= 0){
			if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio){
				if(AchouOnePiece(*mapa)){
					if(mapa->tesouro.getPeso() == 0){		//quando o tesouro acaba remove onePiece do mapa
						mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					}else{
						mapa->cenario[esta_x][esta_y].setTipo(onePiece);
					}

					mapa->cenario[vai_x][vai_y].setTipo(pirata);
					return;
				}

				mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
				mapa->cenario[vai_x][vai_y].setTipo(pirata);
			}
			else{
				//para fugir da marinha
				if(mapa->cenario[vai_x][vai_y].getTipo() == marinha){
					Movimento movimento_de_fulga;
					do{
						movimento_de_fulga = Movimento(rand() % 4 + 1);
					}while(movimento_de_fulga == ir_para);

					cout << endl << "*" << getNome() << " percebeu que a marinha esta proxima*" << endl << endl;
					move(&(*mapa), movimento_de_fulga);
					return;
				}

				cout << endl << "*Um obstaculo bloqueou a passagem de " << getNome() << ".*" << endl << endl;
				mapa->marinheiro.setEstado(true);
			}
		}
		else{
			cout << endl << "*" << getNome() << " quase saiu da Grand Line ESQUERDA.*" << endl << endl;
		}
	}
}

void Pirata::carregar(){
	pesoAdd += 10;
}

void Pirata::descarregar(){
	pesoAdd = 0;
}

bool Pirata::AchouOnePiece(GrandLine mapa){
	if(mapa.cenario[mapa.cenario.size()-1][mapa.cenario.size()-1].getTipo() == pirata){
		return true;
	}
	return false;
}

//##################### MARINHA #############################
Marinha::Marinha():Pessoa("", marinha, 0){
	estado = false;
	tempoAcordado = 0;
}
Marinha::Marinha(std::string nome, TipoElemento tipo, int hp,
									bool estado) : Pessoa(nome, tipo, hp){
	this->estado = estado;
	tempoAcordado = 0;
}

void Marinha::setEstado(bool estado){
	this->estado = estado;
}

bool Marinha::getEstado(){
	return estado;
}

void Marinha::move(GrandLine *mapa, Movimento ir_para){
	int esta_x, esta_y, vai_x, vai_y;
	int i, j;
	for(i = 0; i < mapa->cenario.size(); i++){
		for(j = 0; j < mapa->cenario.size(); j++){
			if(mapa->cenario[i][j].getTipo() == getTipo()){
				esta_x = i;
				esta_y = j;
			}
		}
	}

	//movimento contrário ao do pirata
	if(ir_para == cima){
		ir_para = baixo;
	}else if(ir_para == baixo){
		ir_para = cima;
	}else if(ir_para == esquerda){
		ir_para = direita;
	}else if(ir_para == direita){
		ir_para = esquerda;
	}

	if(ir_para == baixo){
		vai_x = esta_x+1;
		vai_y = esta_y;
	}
	else if(ir_para == cima){
		vai_x = esta_x-1;
		vai_y = esta_y;
	}
	else if(ir_para == esquerda){
		vai_x = esta_x;
		vai_y = esta_y-1;
	}
	else if(ir_para == direita){
		vai_x = esta_x;
		vai_y = esta_y+1;
	}

	if(mapa->marinheiro.getEstado() == true && mapa->marinheiro.getTempoAcordado() >= 0 && mapa->marinheiro.getTempoAcordado() < 3){
		mapa->marinheiro.addTempoAcordado();
		//gera a movimentação aleatória da marinha caso o pirata esteja carregando ou descarregando
		if(mapa->cenario[0][0].getTipo() == pirata || mapa->cenario[mapa->cenario.size()-1][mapa->cenario.size()-1].getTipo() == pirata){
			Movimento movimentacao_especial = Movimento(rand() % 4 + 1);
			move(&(*mapa), movimentacao_especial);
		}

		//A marinha nunca ira capturar o pirata se ele estiver no One Piece
		if(vai_x == mapa->cenario.size()-1 && vai_x == mapa->cenario.size()-1){
			Movimento movimentacao_especial = Movimento(rand() % 4 + 1);
			move(&(*mapa), movimentacao_especial);
		}
	}else{
		mapa->marinheiro.setEstado(false);
		mapa->marinheiro.setTempoAcordado(0);
	}


	if(mapa->marinheiro.getEstado()){
		if(ir_para == baixo){

			if(vai_x < mapa->cenario.size()){
				if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == pirata){

					//remove 50 de HP ao encontrar o pirata
					if(mapa->cenario[vai_x][vai_y].getTipo() == pirata){
						mapa->pirata_Aux.setHp(mapa->pirata_Aux.getHp()-50);
						mapa->cenario[0][0].setTipo(pirata);	//pirata volta para o inicio do mapa
					}

					mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					mapa->cenario[vai_x][vai_y].setTipo(marinha);
				}
				else{
					cout << "MARINHA *Nao pode se mover para BAIXO.*" << endl << endl;
				}
			}
			else{
				cout << "MARINHA *Acabou o cenario para BAIXO.*" << endl << endl;
			}
		}
		else if(ir_para == cima){

			if(vai_x >= 0){
				if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == pirata){

					if(mapa->cenario[vai_x][vai_y].getTipo() == pirata){
						mapa->pirata_Aux.setHp(mapa->pirata_Aux.getHp()-50);
						mapa->cenario[0][0].setTipo(pirata);	//pirata volta para o inicio do mapa
					}

					mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					mapa->cenario[vai_x][vai_y].setTipo(marinha);
				}
				else{
					cout << "MARINHA *Nao pode se mover para CIMA.*" << endl << endl;
				}
			}
			else{
				cout << "MARINHA *Acabou o cenario para CIMA.*" << endl << endl;
			}
		}

		else if(ir_para == direita){

			if(vai_y < mapa->cenario[0].size()){
				if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == pirata){

					if(mapa->cenario[vai_x][vai_y].getTipo() == pirata){
						mapa->pirata_Aux.setHp(mapa->pirata_Aux.getHp()-50);
						mapa->cenario[0][0].setTipo(pirata);	//pirata volta para o inicio do mapa
					}

					mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					mapa->cenario[vai_x][vai_y].setTipo(marinha);
				}
				else{
					cout << "MARINHA *Nao pode se mover para DIREITA.*" << endl << endl;
				}
			}
			else{
				cout << "MARINHA *Acabou o cenario para DIREITA.*" << endl << endl;
			}
		}

		else if(ir_para == esquerda){

			if(vai_y >= 0){
				if(mapa->cenario[vai_x][vai_y].getTipo() == espacoVazio || mapa->cenario[vai_x][vai_y].getTipo() == pirata){

					if(mapa->cenario[vai_x][vai_y].getTipo() == pirata){
						mapa->pirata_Aux.setHp(mapa->pirata_Aux.getHp()-50);
						mapa->cenario[0][0].setTipo(pirata);	//pirata volta para o inicio do mapa
					}

					mapa->cenario[esta_x][esta_y].setTipo(espacoVazio);
					mapa->cenario[vai_x][vai_y].setTipo(marinha);
				}
				else{
					cout << "MARINHA *Nao pode ser mover para ESQUERDA.*" << endl << endl;
				}
			}
			else{
				cout << "MARINHA *Acabou o cenario para a ESQUERDA.*" << endl << endl;
			}
		}
	}
}

void Marinha::setTempoAcordado(int tempoAcordado){
	this->tempoAcordado = tempoAcordado;
}

int Marinha::getTempoAcordado(){
	return tempoAcordado;
}

void Marinha::addTempoAcordado(){
	tempoAcordado += 1;
}

//##################### ONEPIECE #############################
OnePiece::OnePiece():Elemento("", onePiece){
	peso = 0;
}

OnePiece::OnePiece(string nome, TipoElemento tipo, float peso):Elemento(nome, tipo){
	this->peso = peso;
}

void OnePiece::setPeso(float peso){
	this->peso = peso;
}

float OnePiece::getPeso(){
	return peso;
}

//##################### GrandLine #############################
GrandLine::GrandLine(){
	pirata_Aux.setHp(100);
}

void GrandLine::inicializar(int tam){
	int i;
	cenario.resize(tam);
	for(i = 0; i < tam; i++){
		cenario[i].resize(tam);
	}

	srand(time(NULL));
	int r_linha, r_coluna;

	cenario[0][0].setTipo(pirata);
	cenario[cenario.size()-1][cenario.size()-1].setTipo(onePiece);

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

		cenario[r_linha][r_coluna].setTipo(obstaculo);
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

	cenario[r_linha][r_coluna].setTipo(marinha);
}

vector < vector<Elemento> > GrandLine::getCenario(){
	return cenario;
}

void GrandLine::setCenario(vector< vector<Elemento> > cenario){
	this->cenario = cenario;
}


void GrandLine::visualizarCenario(){
	int i, j;
	bool temObjetos = true;

	for(i = 0; i < cenario.size(); i++){
		for(j = 0; j < cenario[0].size(); j++){
			if(cenario[i][j].getTipo() == obstaculo){
				cout << " O ";
			}
			else if(cenario[i][j].getTipo() == pirata){
				cout << " P ";
			}
			else if(cenario[i][j].getTipo() == marinha){
				cout << " M ";
			}
			else if(cenario[i][j].getTipo() == espacoVazio){
				cout << " . ";
			}
			else if(cenario[i][j].getTipo() == onePiece){
				cout << " T ";
			}
		}
		cout << endl;
	}

}

void GrandLine::set_Tesouro(float peso){
	tesouro.setPeso(peso);
}

OnePiece GrandLine::get_Tesouro(){
	return tesouro;
}

Pirata GrandLine::get_Pirata_Aux(){
	return pirata_Aux;
}
