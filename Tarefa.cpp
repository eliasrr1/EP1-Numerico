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
		std::fill(u->begin(), u->end(), 0);
		std::cout << "Progresso: " << std::defaultfloat << (100 * (double)k) / (double)M << "%" << std::endl;
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
	fileU.open("Output1A.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;
	fileE.open("Erro1A.txt", std::ios::trunc);
	fileE << std::endl << "Erro" << std::endl;

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = exp(-x);
	}

	for (int k = 0; k < M; k++) {
		double t = deltaT * k;
		printLine(*uAnterior, fileU);
		printLine(*erro, fileE);
		u->at(0) = exp(-t);
		u->at(N) = exp(t - 1) * cos(5 * t);
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'b'));
			erro->at(i) = abs(uReal(k + 1, i, 'a') - u->at(i));
		}
		uAnterior = u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
	}
	printLine(*u, fileU);

	std::cout << std::endl << "Erro maximo: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmC()
{
	/*
	std::vector<std::vector<double> > erro(M + 1, std::vector<double>(N + 1, 0));
	std::ofstream file;
	file.open("Output1C.txt", std::ios::trunc);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(k + 1).at(i) = u->at(k).at(i) + deltaT * ((u->at(k).at(i - 1) - (2.0 * u->at(k).at(i)) + u->at(k).at(i + 1)) / (deltaX * deltaX) + f(k, i, 'c'));
		}
	}

	file << std::endl << "Matriz U calculada" << std::endl;
	printLine(*u, file);
	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
	*/
}

void Tarefa::itemDoisA()
{
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
	for (int i = 0; i <= N; i++) {
		output << std::fixed << line.at(i) << " ";
	}
	output << std::endl;
}