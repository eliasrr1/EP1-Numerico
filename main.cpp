#include <iostream>
#include "Tarefa.h"
#include <limits.h>

void menu();

// Menu visual para recebimento de instrucoes
void menu() {
	int tarefa;
	char item;
	std::cout << std::endl;
	std::cout << "1 - Primeira tarefa" << std::endl;
	std::cout << "2 - Segunda tarefa" << std::endl;
	std::cout << "0 - Sair" << std::endl;
	std::cout << "Escolha a opcao: ";
	std::cin >> tarefa;
	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		throw new std::invalid_argument("Digite um numero");
	}

	if (tarefa == 1) {

		int N, M;
		std::cout << std::endl << "Digite o valor de N: ";
		std::cin >> N;
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			throw new std::invalid_argument("Digite um numero");
		}
		std::cout << "Digite o valor de M: ";
		std::cin >> M;
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			throw new std::invalid_argument("Digite um numero");
		}
		Tarefa tarefa(N, M);
		std::cout << "Valor de lambda = " << std::fixed << tarefa.getLambda() << std::endl;

		std::cout << std::endl << "Digite o item que deseja rodar: ";
		std::cin >> item;
		item = (char)tolower(item);
		if (item == 'a') {
			tarefa.itemUmATeste();
			tarefa.itemUmA();
		}
		else if (item == 'b') {
			tarefa.itemUmB();
		}
		else if (item == 'c') {
			tarefa.itemUmC();
		}
		else {
			throw new std::invalid_argument("Digite apenas uma letra de A a C");
		}
		menu();
	}
	else if (tarefa == 2) {

		int N;
		std::cout << std::endl << "Digite o valor de N = M: ";
		std::cin >> N;
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			throw new std::invalid_argument("Digite um numero");
		}
		Tarefa tarefa(N, N);
		std::cout << "Valor de lambda = " << std::fixed << tarefa.getLambda() << std::endl;

		std::cout << std::endl << "Digite o item que deseja rodar: ";
		std::cin >> item;
		item = (char)tolower(item);
		if (item == 'a') {
			std::cout << std::endl << "Siga as instrucoes do README. Para prosseguir, pressione [Enter]" << std::endl;
			std::cin.ignore();
			while (getchar() != '\n');
			tarefa.itemDoisA();
		}
		else if (item == 'b') {
			tarefa.itemDoisB();
		}
		else if (item == 'c') {
			tarefa.itemDoisC();
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
	std::cout << "====================" << std::endl;
	std::cout << "Exercicio Programa 1" << std::endl;
	std::cout << "====================" << std::endl;
	bool exception = 0;
	do {
		try {
			exception = 0;
			menu();
		}
		catch (std::exception* e) {
			std::cout << std::endl << "** Erro na execucao do programa: " << e->what() << "! **" << std::endl;
			delete e;
			exception = 1;
		}
	} while (exception == 1);
	return 0;
}