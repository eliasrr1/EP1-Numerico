#include "Tarefa.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

Tarefa::Tarefa(int N, int M) : N(N), M(M)
{
	deltaT = 1 / (double)M;
	deltaX = 1 / (double)N;
}

Tarefa::~Tarefa()
{
}

void Tarefa::itemUmA()
{
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);
	std::ofstream fileU, fileE;
	double ErroMax = 0;
	fileU.open("Output1A.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;
	fileE.open("Erro1A.txt", std::ios::trunc);
	fileE << std::endl << "Erro" << std::endl;

	for (int k = 0; k < M; k++) {
		printLine(*uAnterior, fileU);
		printLine(*erro, fileE);
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'a'));
			erro->at(i) = abs(uReal(k + 1, i, 'a') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
	}
	printLine(*uAnterior, fileU);

	std::cout << std::endl << "Erro maximo: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmB()
{

	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);
	std::ofstream fileU, fileE;
	double ErroMax = 0;
	fileU.open("Output1B.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;
	fileE.open("Erro1B.txt", std::ios::trunc);
	fileE << std::endl << "Erro" << std::endl;

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = exp(-x);
	}

	for (int k = 0; k < M; k++) {
		double t = deltaT * (k + 1.0);
		printLine(*uAnterior, fileU);
		printLine(*erro, fileE);
		u->at(0) = exp(t);
		u->at(N) = exp(t - 1) * cos(5 * t);
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'b'));
			erro->at(i) = abs(uReal(k + 1, i, 'b') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
	}
	printLine(*uAnterior, fileU);

	std::cout << std::endl << "Erro maximo: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmC()
{
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::ofstream fileU;
	double ErroMax = 0;
	fileU.open("Output1C.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;

	for (int k = 0; k < M; k++) {
		double t = deltaT * k;
		printLine(*uAnterior, fileU);
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'c'));
		}
		*uAnterior = *u;
	}
	printLine(*uAnterior, fileU);

	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

void Tarefa::itemDoisA()
{
	std::vector<double>* diag = new std::vector<double>(N - 1, 0);
	std::vector<double>* sub = new std::vector<double>(N - 2, 0);
	std::vector<double>* b = new std::vector<double>(N - 1, 0);
	std::ifstream entrada;
	entrada.open("Entrada.txt");

	std::ofstream saida;
	saida.open("Output2A.txt", std::ios::trunc);
	if (entrada.fail()) {
		entrada.close();
		throw new std::invalid_argument("Arquivo nao encontrado.");
	}

	
	if (entrada.eof()) {
		entrada.close();
		throw new std::invalid_argument("Arquivo vazio.");
	}
	
	for (int i = 0; i < N - 1; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao.");
		}
		entrada >> diag->at(i);
	}
	for (int i = 0; i < N - 2; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao.");
		}
		entrada >> sub->at(i);
	}
	for (int i = 0; i < N - 1; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao.");
		}
		entrada >> b->at(i);
	}

	printLine(*solveLDLt(diag, sub, b), saida);
	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

void Tarefa::itemDoisB()
{

}

void Tarefa::itemDoisC()
{

}

double Tarefa::f(int k, int i, char ch)
{
	double t = deltaT * k;
	double x = deltaX * i;
	if (ch == 'a')
		return (10 * x * x * (x - 1) - 60 * x * t + 20 * t);
	else if (ch == 'b')
		return (5 * (exp(t - x)) * (5 * t * t * cos(5 * t * x) - 2 * t * sin(5 * t * x) - x * sin(5 * t * x)));
	else if (x >= (p - deltaX / 2) && x <= (p + deltaX / 2))
		return (10000 * (1 - 2 * t * t) / deltaX);
	else
		return 0;
}

double Tarefa::uReal(int k, int i, char ch)
{
	double t = deltaT * k;
	double x = deltaX * i;
	if (ch == 'a')
		return (10 * x * x * (x - 1) * t);
	else
		return (exp(t - x) * cos(5 * t * x));
}

void Tarefa::printLine(std::vector<double> line, std::ostream& output)
{
	for (int i = 0; i < line.size(); i++) {
		output << std::scientific << line.at(i) << " ";
	}
	output << std::endl;
}

std::vector<double>* Tarefa::solveLDLt(std::vector<double>* diag, std::vector<double>* sub, std::vector<double>* b)
{
	//Determinacao de D e L
	std::vector<double>* d = new std::vector<double>(N - 1, 0);
	std::vector<double>* l = new std::vector<double>(N - 2, 0);

	double somaD = 0;
	for (int i = 0; i < N - 2; i++) {
		d->at(i) = diag->at(i) - somaD;
		l->at(i) = sub->at(i) / d->at(i);
		somaD = l->at(i) * l->at(i) * d->at(i);
	}
	d->at(N - 2) = diag->at(N - 2) - somaD;

	//Resolucao do sistema

	std::vector<double>* x = new std::vector<double>(N - 1, 0);

	double somaX = 0;
	for (int i = 0; i < N - 2; i++) {
		x->at(i) = b->at(i) - somaX;
		somaX = l->at(i) * x->at(i);
	}
	x->at(N - 2) = b->at(N - 2) - somaX;

	for (int i = 0; i < N - 1; i++) {
		x->at(i) = x->at(i) / d->at(i);
	}

	somaX = 0;
	x->at(N - 2) = x->at(N - 2) - somaX;
	for (int i = N - 3; i >= 0; i--) {
		somaX = l->at(i) * x->at(i + 1);
		x->at(i) = x->at(i) - somaX;
	}
	return x;
}
