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
	Movimento ir_para;
	char a, escolha;
	srand(time(NULL));

	Pirata player("Luffy", pirata, 100, 70.0, 0.0);
	Marinha boss("Smoke", marinha, 100, false);

	GrandLine cenario_jogo;
	cenario_jogo.inicializar(7);
	cenario_jogo.set_Peso_Tesouro(300);

	cout << endl << "\t\t===================" << endl;
	cout << "\t\t= Mundo de Wumpus =" << endl;
	cout << "\t\t= Edicao OnePiece =" << endl;
	cout << "\t\t===================" << endl << endl;
	cout << "(digite 'e' pra sair)" << endl;
	cout << "1. Voce controla o pirata com WASD." << endl;
	cout << "2. O pirata se move sozinho, porem vc precisara' apertar ENTER para atualizar o cenario." << endl;
	cout << "3. O jogo rodara sozinho e ira parar caso o pirata venca ou morra." << endl;
	cout << "Escolha como o jogo sera' exibido ( 1|2|3 ): ";
	cin >> escolha;


	cout << "\tMapa" << endl;
	cout << endl;

	while(a != 'e'){
		cout << "---------------------"<< endl;
		cenario_jogo.visualizarCenario();

		//o jogo acaba se o pirata estiver em 0,0 e tiver pego todo o one piece
		if(cenario_jogo.get_Tesouro().getPeso() <= 0 && cenario_jogo.getCenario()[0][0].getTipo() == pirata){
			cout << endl << "\tParabens! Voce eh o novo Rei dos Piratas!" << endl;
			break;
		}
		//o jogo também acaba se o pirata morrer
		if(cenario_jogo.get_Pirata_Aux().getHp() == 0){
			cout << endl << player.getNome() << " foi preso, mais sorte na proxima!" << endl;
			break;
		}

		if(escolha == '1'){
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
		}
		else if(escolha == '2'){
			a = getchar();
			ir_para = Movimento(rand() % 4 + 1);
		}
		else if(escolha == 'e'){
			break;
		}
		else{
			ir_para = Movimento(rand() % 4 + 1);
		}



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

		cout << endl << "Vida: " << vida_restante << endl;
		cout << "Peso adicional: " << player.getPesoAdd() << " Kg." << endl;
		cout << "Tesouro restante: " << cenario_jogo.get_Tesouro().getPeso() << " Kg." << endl;
		cout << "---------------------"<< endl;
	}

	getchar();
	return 0;
}
