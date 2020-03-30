#include <iostream>
#include <stdexcept>
#include "Tarefa.h"

void menu();

void menu() {
	int tarefa;
	char item;
	std::cout << std::endl;
	std::cout << "1 - Primeira tarefa" << std::endl;
	std::cout << "2 - Segunda tarefa" << std::endl;
	std::cout << "0 - Sair" << std::endl;
	std::cout << "Escolha a opcao: ";
	std::cin >> tarefa;

	if (tarefa == 1) {
		int N, M;
		std::cout << std::endl << "Digite o valor de N: ";
		std::cin >> N;
		std::cout << "Digite o valor de M: ";
		std::cin >> M;
		std::cout << "Valor de lambda = " << ((double)N*(double)N) / M << std::endl;

		Tarefa tarefa(N, M);

		std::cout << std::endl << "Digite o item que deseja rodar: ";
		std::cin >> item;
		item = (char)tolower(item);
		if (item == 'a') {
			tarefa.itemUmA();
		}
		else if (item == 'b') {
			tarefa.itemUmB();
		}
		else if (item == 'c') {
			//tarefa.itemUmC();
		}
		else {
			throw new std::invalid_argument("Digite apenas uma letra de A a C");
		}
		menu();
	}
	else if (tarefa == 2) {
		std::cout << std::endl << "Digite o item que deseja rodar: ";
		std::cin >> item;
		item = (char)tolower(item);
		if (item == 'a') {
			//item_2a();
		}
		else if (item == 'b') {
			//item_2b();
		}
		else if (item == 'c') {
			//item_2c();
		}
		else {
			throw new std::invalid_argument("Digite apenas uma letra de A a C");
		}
		menu();
	}
	else if (tarefa == 0) {
		return;
	}
	else {
		throw new std::invalid_argument("Selecao invalida");
	}
}

int main()
{
	// INICIO
	std::cout << "Exercicio Programa 1" << std::endl;
	bool exception = 0;
	do {
		try {
			exception = 0;
			menu();
		}
		catch (std::exception* e) {
			std::cout << std::endl << "Erro na execucao do programa: " << e->what() << std::endl;
			delete e;
			exception = 1;
		}
	} while (exception == 1);
	return 0;
}