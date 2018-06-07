/*############################################################//

				Univercidade Estadual do Ceará - UECE
				Equipe: Vinicius Eduardo, Lucas Araújo, Lucas Almeida
				Docente: Matheus Magalhaes de Carvalho

//###########################################################*/
#include "biblio.h"
#include<iostream>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;

int main(){
	string vida_restante;
	srand(time(NULL));

	Pirata player("Luffy", pirata, 100, 70.0, 0.0);
	Marinha boss("Smoke", marinha, 100, false);

	GrandLine cenario_jogo;
	cenario_jogo.inicializar(7);
	cenario_jogo.set_Tesouro(100);

	cout << endl << "\tMapa" << endl;
	cenario_jogo.visualizarCenario();
	cout << endl;

	Movimento ir_para;
	char a;

	while(a != 'k'){
		cout << "---------------------"<< endl;
		cenario_jogo.visualizarCenario();

		if(cenario_jogo.get_Tesouro().getPeso() <= 0 && cenario_jogo.getCenario()[0][0].getTipo() == pirata){
			cout << endl << "\tParabens! Voce eh o novo Rei dos Piratas!" << endl;
			break;
		}
		if(cenario_jogo.get_Pirata_Aux().getHp() == 0){
			cout << player.getNome() << " morreu, mais sorte na proxima!" << endl;
			break;
		}

		cout << "movimento: "; cin >> a;
		getchar();
		if(a == 'w'){
			ir_para = cima;
		}else if(a == 's'){
			ir_para = baixo;
		}else if(a == 'd'){
			ir_para = direita;
		}else if(a == 'a'){
			ir_para = esquerda;
		}

		// a = getchar();
		// ir_para = Movimento(rand() % 4 + 1);

		player.move(&cenario_jogo, ir_para);
		boss.move(&cenario_jogo, ir_para);

		if(cenario_jogo.get_Pirata_Aux().getHp() == 100){
			vida_restante.clear();
			vida_restante = "[ ][ ]";
		}
		else if(cenario_jogo.get_Pirata_Aux().getHp() == 50){
			vida_restante.clear();
			vida_restante = "[X][ ]";
		}
		else if(cenario_jogo.get_Pirata_Aux().getHp() == 0){
			vida_restante.clear();
			vida_restante = "[X][X]";
		}

		cout << endl << "Tesouro restante: " << cenario_jogo.get_Tesouro().getPeso() << endl;
		cout << "Vida: " << vida_restante << endl;
		cout << "Peso adicional: " << player.getPesoAdd() << endl;
		cout << "---------------------"<< endl;
	}

	getchar();
	return 0;
}
