#include "Tarefa.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

Tarefa::Tarefa(int N, int M) : N(N), M(M)
{
	deltaT = 1 / (double)M;
	deltaX = 1 / (double)N;
	u = new std::vector<std::vector<double> >(M + 1, std::vector<double>(N + 1, 0));
}

Tarefa::~Tarefa()
{
}

void Tarefa::itemUmA()
{
	std::vector<std::vector<double> > erro(M + 1, std::vector<double>(N + 1, 0));
	std::ofstream file;
	file.open("Output1A.txt", std::ios::trunc);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(k + 1).at(i) = u->at(k).at(i) + deltaT * ((u->at(k).at(i - 1) - (2.0 * u->at(k).at(i)) + u->at(k).at(i + 1)) / (deltaX * deltaX) + f(k, i, 'a'));
			erro.at(k + 1).at(i) = abs(uReal(k + 1, i, 'a') - u->at(k + 1).at(i));
		}
	}

	std::vector<double> erroMax(M + 1, 0);
	for (int k = 0; k <= M; k++) {
		erroMax[k] = *std::max_element(erro.at(k).begin(), erro.at(k).end());
	}
	std::cout << std::endl << "Erro maximo: \n" << std::scientific << *std::max_element(erroMax.begin(), erroMax.end()) << std::endl;

	printMatrix(*u, file, "Matriz U calculada");
	printMatrix(erro, file, "Erro");

	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

void Tarefa::itemUmB()
{
	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		u->at(0).at(i) = exp(-x);
	}
	// coloca g1 em u(:,0)
	for (int k = 0; k <= M; k++) {
		double t = deltaT * k;
		u->at(k).at(0) = exp(t);
	}
	// coloca g2 em u(:,N)
	for (int k = 0; k <= M; k++) {
		double t = deltaT * k;
		u->at(k).at(N) = exp(t - 1) * cos(5 * t);
	}

	std::vector<std::vector<double> > erro(M + 1, std::vector<double>(N + 1, 0));
	std::ofstream file;
	file.open("Output1B.txt", std::ios::trunc);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(k + 1).at(i) = u->at(k).at(i) + deltaT * ((u->at(k).at(i - 1) - (2.0 * u->at(k).at(i)) + u->at(k).at(i + 1)) / (deltaX * deltaX) + f(k, i, 'b'));
			erro.at(k + 1).at(i) = abs(uReal(k + 1, i, 'b') - u->at(k + 1).at(i));
		}
	}

	std::vector<double> erroMax(M + 1, 0);
	for (int k = 0; k <= M; k++) {
		erroMax[k] = *std::max_element(erro.at(k).begin(), erro.at(k).end());
	}
	std::cout << std::endl << "Erro maximo: \n" << std::scientific << *std::max_element(erroMax.begin(), erroMax.end()) << std::endl;

	printMatrix(*u, file, "Matriz U calculada");
	printMatrix(erro, file, "Erro");

	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

void Tarefa::itemUmC()
{
	std::vector<std::vector<double> > erro(M + 1, std::vector<double>(N + 1, 0));
	std::ofstream file;
	file.open("Output1C.txt", std::ios::trunc);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(k + 1).at(i) = u->at(k).at(i) + deltaT * ((u->at(k).at(i - 1) - (2.0 * u->at(k).at(i)) + u->at(k).at(i + 1)) / (deltaX * deltaX) + f(k, i, 'c'));
		}
	}

	printMatrix(*u, file, "Matriz U calculada");
	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
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

void Tarefa::printMatrix(std::vector<std::vector<double> > mat, std::ostream& output, std::string message)
{
	output << std::endl << message << std::endl;
	for (int k = 0; k <= M; k++) {
		for (int i = 0; i <= N; i++) {
			output << std::fixed << mat.at(k).at(i) << " ";
		}
		output << std::endl;
	}
	output << std::endl;
}