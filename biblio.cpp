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

TipoElemento Pessoa::getTipo(){
	return espacoVazio;
}

//##################### ONEPIECE #############################
OnePiece::OnePiece(float peso):Elemento(" OP", onePiece){	//One piece pode continuar assim
	this->peso = peso;
}

TipoElemento OnePiece::getTipo(){
	return onePiece;
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

TipoElemento Pirata::getTipo(){
	return pirata;
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

TipoElemento Marinha::getTipo(){
	return marinha;
}

//##################### GrandLine #############################
GrandLine::GrandLine(int tam){
	int i;
	cenario.resize(tam);
	for(i = 0; i < tam; i++){
		cenario[i].resize(tam);
	}

	srand(time(NULL));
	Elemento obs(" O ", obstaculo);
	Marinha mar(" M ", marinha, 100, false);	//HP, estado
	Pirata player(" P ", pirata, 100, 70.0, 0.0);	//HP, peso, peso adicional
	OnePiece op(300); //300 Kg
	int r_linha;
	int r_coluna;

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
		}while(cenario[r_coluna][r_linha].getTipo() != espacoVazio);

		setCenario(obs, r_linha, r_coluna);
	}

//coloca marinha em uma posição aleatória entre 1,1 e n-1,n-1 em uma posição que não esteja ocupada
	do{
		r_linha = rand() % (cenario.size()-1) + 1;
		r_coluna = rand() % (cenario.size()-1) + 1;

//garante que a marinha nao tranque o caminho com uma pedra APENAS na origem
		if((r_linha == 1 && r_coluna == 0 && cenario[0][1].getTipo() == obstaculo) ||
			 (r_linha == 0 && r_coluna == 1 && cenario[1][0].getTipo() == obstaculo)){
				 r_linha = rand() % (cenario.size()-1) + 1;
				 r_coluna = rand() % (cenario.size()-1) + 1;
			 }
	}while(cenario[r_coluna][r_linha].getTipo() != espacoVazio);
	setCenario(mar, r_linha, r_coluna);

//o pirata parte de 0,0
	setCenario(player, 0, 0);
	setCenario(op, (cenario.size()-1), (cenario.size()-1));
}

vector < vector<Elemento> > GrandLine::getCenario(){
	return cenario;
}

void GrandLine::setCenario(Elemento n, int x, int y){
	cenario[y][x] = n;
}

void GrandLine::setCenario(Pirata n, int x, int y){
	cenario[y][x] = n;
}

void GrandLine::setCenario(Marinha n, int x, int y){
	cenario[y][x] = n;
}
