#include "enum.h"
#include "biblio.h"
#include <iostream>

using namespace std;

//##################### ELEMENTO #############################
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
OnePiece::OnePiece(float peso):Elemento("One Piece", onePiece){	//One piece pode continuar assim
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
				float peso, bool estado) : Pessoa(nome, tipo, hp){
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
GrandLine::GrandLine(int tamanho_cenario){
	setCenario(tamanho_cenario);
}

void GrandLine::setCenario(int tamanho_cenario){
	cenario.resize(tamanho_cenario);	//aloca uma coluna de tamanho "tamanho_cenario"
	for(int i = 0; i < tamanho_cenario; i++){
		cenario[i].resize(tamanho_cenario);	//aloca em cada coluna uma linha de tamanho "tamanho_cenario"
	}
}
