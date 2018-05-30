#include "enum.h"
#ifndef BIBLIO_H
#define BIBLIO_H
#include<string>
#include<vector>

//##################### ELEMENTO #############################
class Elemento{
private:
	std::string nome;
	TipoElemento tipo;
public:
	Elemento(std::string nome, TipoElemento tipo);
	void setNome(std::string nome);
	std::string getNome();
	void setTipo(TipoElemento tipo);
	virtual TipoElemento getTipo() = 0;
};

//##################### PESSOA #############################
class Pessoa: public Elemento{
private:
	int hp;
public:
	Pessoa(std::string nome, TipoElemento tipo, int hp);
	void setHp(int hp);
	int getHp();
	virtual TipoElemento getTipo();
};

//##################### PIRATA #############################
class Pirata: public Pessoa{
private:
	float peso;
	float pesoAdd;
public:
	Pirata(std::string nome, TipoElemento tipo, int hp,
					float peso, float pesoAdd);
	void setPeso(float peso);
	float getPeso();
	void setPesoAdd(float pesoAdd);
	float getPesoAdd();
	TipoElemento getTipo();
};

//##################### MARINHA #############################
class Marinha: public Pessoa{
private:
	bool estado;
public:
	Marinha(std::string nome, TipoElemento tipo, int hp,
					float peso, bool estado);
	void setEstado(bool estado);
	bool getEstado();
	TipoElemento getTipo();
};

//##################### ONEPIECE #############################
class OnePiece: public Elemento{
private:
	float peso;
public:
	OnePiece(float peso);
	void setPeso(float peso);
	float getPeso();
	TipoElemento getTipo();
};

//##################### GRANDLINE #############################

class GrandLine{
private:
	std::vector< std::vector < Elemento > > cenario;
public:
	GrandLine();
	void setCenario(std::vector< std::vector < Elemento > > cenario);
	std::vector< std::vector < Elemento > > getCenario();
};

#endif
