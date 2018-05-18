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
Pessoa::Pessoa():Elemento("Nome_padrao", espacoVazio){
	this->hp = 100;
}

void Pessoa::SetHp(int hp){
	this->hp = hp;
}

int Pessoa::GetHp(){
	return hp;
}

TipoElemento Pessoa::GetTipo(){
	return tipo;
}

//##################### ONEPIECE #############################
OnePiece::OnePiece(float peso):Elemento("One Piece", onePiece){
	this->peso = peso;
}

TipoElemento OnePiece::GetTipo(){
	return tipo;
}

void OnePiece::SetPeso(float peso){
	this->peso = peso;
}

float OnePiece::GetPeso(){
	return peso;
}

//##################### PIRATA #############################
Pirata::Pirata(float peso, float pesoadd) : Pessoa(){
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

//##################### MARINHA #############################
Marinha::Marinha(bool estado) : Pessoa(){
	this->estado = estado;
}

void Marinha::SetEstado(bool estado){
	this->estado = estado;
}

bool Marinha::GetEstado(){
	return estado;
}
