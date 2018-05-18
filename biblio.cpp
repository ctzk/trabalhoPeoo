#include "enum.h"
#include "biblio.h"
#include <iostream>
using namespace std;

//##################### ELEMENTO #############################
Elemento::Elemento(string nome, TipoElemento tipo){
	this->nome = nome;
	this->tipo = tipo;
}

void Elemento::SetNome(string nome){
	this->nome = nome;
}

string Elemento::GetNome(){
	return nome;
}

void Elemento::SetTipo(TipoElemento tipo){
	this->tipo = tipo;
}

//##################### PESSOA #############################
Pessoa::Pessoa(string nome, TipoElemento tipo, int hp):Elemento(nome, tipo){
	this->hp = hp;
}

void Pessoa::SetHp(int hp){
	this->hp = hp;
}

int Pessoa::GetHp(){
	return hp;
}

TipoElemento Pessoa::GetTipo(){
	return espacoVazio;
}

//##################### ONEPIECE #############################
OnePiece::OnePiece(float peso):Elemento("One Piece", onePiece){	//One piece pode continuar assim
	this->peso = peso;
}

TipoElemento OnePiece::GetTipo(){
	return onePiece;
}

void OnePiece::SetPeso(float peso){
	this->peso = peso;
}

float OnePiece::GetPeso(){
	return peso;
}

//##################### PIRATA #############################
Pirata::Pirata(string nome, TipoElemento tipo, int hp,
							float peso, float pesoadd) : Pessoa(nome, tipo, hp){
	this->peso = peso;
	this->pesoadd = pesoadd;
}

void Pirata::SetPeso(float peso){
	this->peso = peso;
}

float Pirata::GetPeso(){
	return peso;
}

void Pirata::SetPesoAdd(float pesoadd){
	this->pesoadd = pesoadd;
}

float Pirata::GetPesoAdd(){
	return pesoadd;
}

TipoElemento Pirata::GetTipo(){
	return pirata;
}

//##################### MARINHA #############################
Marinha::Marinha(std::string nome, TipoElemento tipo, int hp,
									float peso, bool estado) : Pessoa(nome, tipo, hp){
	this->estado = estado;
}

void Marinha::SetEstado(bool estado){
	this->estado = estado;
}

bool Marinha::GetEstado(){
	return estado;
}

TipoElemento Marinha::GetTipo(){
	return marinha;
}
