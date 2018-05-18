#include "biblio.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
	string a,b;
	Pessoa p("Pessonildo", espacoVazio , 100);
	Pirata pi("Jackes Pardal", pirata, 85, 93.4, 33.8);
	Marinha m("Almirante Smoker", marinha, 100, 100.0, 0);

	if(pi.GetTipo() == pirata){
		a = "Pirata";
	}

	if(m.GetTipo() == marinha){
		b = "Marinha";
	}


	cout << "Character 1:" << endl;
	cout << "Nome: " << p.GetNome() << endl;
	cout << "Afiliacao: " << "x" << endl;
	cout << "Peso: " << "x" << "Kg."<< endl;
	cout << "Peso Total: " << "x" << "Kg."<< endl;
	cout << "Vida restante: " << p.GetHp() << endl;

	cout << endl << endl;

	cout << "Character 2:" << endl;
	cout << "Nome: " << pi.GetNome() << endl;
	cout << "Afiliacao: " << a << endl;
	cout << "Peso: " << pi.GetPeso() << "Kg." << endl;
	cout << "Peso Total: " << (pi.GetPeso() + pi.GetPesoAdd()) << "Kg." << endl;
	cout << "Vida restante: " << p.GetHp() << endl;

	cout << endl << endl;

	cout << "Character 3:" << endl;
	cout << "Nome: " << m.GetNome() << endl;
	cout << "Afiliacao: " << b << endl;
	cout << "Peso: " << "x" << "Kg." << endl;
	cout << "Peso Total: "<< "x" << "Kg." << endl;
	cout << "Vida restante: " << p.GetHp() << endl;
	return 0;
}
