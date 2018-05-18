#include "enum.h"
#ifndef BIBLIO_H
#define BIBLIO_H
#include<string>

//##################### ELEMENTO #############################
class Elemento{
public:
	Elemento(std::string nome, TipoElemento tipo);
	void SetNome(std::string nome);
	std::string GetNome();
	void SetTipo(TipoElemento tipo);
	virtual TipoElemento GetTipo() = 0;
private:
  std::string nome;
  TipoElemento tipo;
};

//##################### PESSOA #############################
class Pessoa: public Elemento{
public:
  Pessoa(std::string nome, TipoElemento tipo, int hp);
  void SetHp(int hp);
  int GetHp();
  TipoElemento GetTipo();
private:
  int hp;
};

//##################### ONEPIECE #############################
class OnePiece: public Elemento{
public:
	OnePiece(float peso);
	void SetPeso(float peso);
	float GetPeso();
  TipoElemento GetTipo();
private:
	float peso;
};

//##################### PIRATA #############################
class Pirata: public Pessoa{
public:
	Pirata(std::string nome, TipoElemento tipo, int hp,
					float peso, float pesoadd);
	void SetPeso(float peso);
	float GetPeso();
	void SetPesoAdd(float pesoadd);
	float GetPesoAdd();
	TipoElemento GetTipo();
private:
	float peso;
	float pesoadd;
};

//##################### MARINHA #############################
class Marinha: public Pessoa{
public:
	Marinha(std::string nome, TipoElemento tipo, int hp,
					float peso, bool estado);
	void SetEstado(bool estado);
	bool GetEstado();
	TipoElemento GetTipo();
private:
	bool estado;
};


#endif
