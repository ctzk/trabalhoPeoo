#include "biblio.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
	string a,b;
	Pirata pi("Jackes Pardal", pirata, 85, 93.4, 33.8);
	Marinha m("Almirante Smoker", marinha, 100, 100.0, 0);

	if(pi.getTipo() == pirata){
		a = "Pirata";
	}

	if(m.getTipo() == marinha){
		b = "Marinha";
	}

	cout << "Character 2:" << endl;
	cout << "Nome: " << pi.getNome() << endl;
	cout << "Afiliacao: " << a << endl;
	cout << "Peso: " << pi.getPeso() << "Kg." << endl;
	cout << "Peso Total: " << (pi.getPeso() + pi.getPesoAdd()) << "Kg." << endl;
	cout << "Vida restante: " << pi.getHp() << endl;

	cout << endl << endl;

	cout << "Character 3:" << endl;
	cout << "Nome: " << m.getNome() << endl;
	cout << "Afiliacao: " << b << endl;
	cout << "Peso: " << "x" << "Kg." << endl;
	cout << "Peso Total: "<< "x" << "Kg." << endl;
	cout << "Vida restante: " << m.getHp() << endl;
	return 0;
}
