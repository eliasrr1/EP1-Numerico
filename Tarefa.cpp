#include "Tarefa.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

Tarefa::Tarefa(int N, int M) : N(N), M(M)
{
	deltaT = 1 / (double)M;
	deltaX = 1 / (double)N;
	lambda = ((double)N * (double)N) / M;
}

Tarefa::~Tarefa()
{
}

// Tarefa 1
void Tarefa::itemUmATeste()
{
	// Vetores para armazenamento de dados
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);
	std::ofstream fileU, fileE; // Arquivos de saida
	double ErroMax = 0;
	fileU.open("Output1ATeste.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;
	fileE.open("Erro1ATeste.txt", std::ios::trunc);
	fileE << std::endl << "Erro" << std::endl;

	// Calculo das celulas por Euler explicito
	printLine(*u, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 't'));
			erro->at(i) = abs(uReal(k + 1, i, 't') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo do teste: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmA()
{
	// Vetores para armazenamento de dados
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);
	std::ofstream fileU, fileE; // Arquivos de saida
	double ErroMax = 0;
	fileU.open("Output1A.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;
	fileE.open("Erro1A.txt", std::ios::trunc);
	fileE << std::endl << "Erro" << std::endl;

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = (x * x * (1 - x) * (1 - x));
	}

	// Calculo das celulas por Euler explicito
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'a'));
			erro->at(i) = abs(uReal(k + 1, i, 'a') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmB()
{
	// Vetores para armazenamento de dados
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);
	std::ofstream fileU, fileE; // Arquivos de saida
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

	// Calculo das celulas por Euler explicito
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		double t = deltaT * (k + 1.0);
		u->at(0) = exp(t); // condicoes de contorno
		u->at(N) = exp(t - 1) * cos(5 * t);
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'b'));
			erro->at(i) = abs(uReal(k + 1, i, 'b') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo: \n" << std::scientific << ErroMax << std::endl;

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemUmC()
{
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::ofstream fileU; // Arquivo de saida
	fileU.open("Output1C.txt", std::ios::trunc);
	fileU << std::endl << "Matriz U calculada" << std::endl;

	// Calculo das celulas por Euler explicito
	printLine(*u, fileU);
	for (int k = 0; k < M; k++) {
		for (int i = 1; i < N; i++) {
			u->at(i) = uAnterior->at(i) + deltaT * ((uAnterior->at(i - 1) - (2.0 * uAnterior->at(i)) + uAnterior->at(i + 1)) / (deltaX * deltaX) + f(k, i, 'c'));
		}
		*uAnterior = *u;
		printLine(*u, fileU);
	}

	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

// Tarefa 2
void Tarefa::itemDoisA()
{
	// Vetores de entrada da matriz A
	std::vector<double>* diag = new std::vector<double>(N - 1, 0);
	std::vector<double>* sub = new std::vector<double>(N - 2, 0);
	std::vector<double>* b = new std::vector<double>(N - 1, 0);
	std::ifstream entrada;
	entrada.open("Entrada.txt");

	std::ofstream saida;
	saida.open("Output2A.txt", std::ios::trunc);

	// Verificar se o arquivo existe
	if (entrada.fail()) {
		entrada.close();
		throw new std::invalid_argument("Arquivo nao encontrado");
	}

	if (entrada.eof()) {
		entrada.close();
		throw new std::invalid_argument("Arquivo vazio");
	}

	// Preencher os vetores
	for (int i = 0; i < N - 1; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao");
		}
		entrada >> diag->at(i);
	}
	for (int i = 0; i < N - 2; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao");
		}
		entrada >> sub->at(i);
	}
	for (int i = 0; i < N - 1; i++) {
		if (!entrada.good()) {
			entrada.close();
			throw new std::invalid_argument("Erro de formatacao");
		}
		entrada >> b->at(i);
	}

	// Imprimir a solucao no arquivo de saida
	printLine(*solveLDLt(diag, sub, b), saida);
	std::cout << "Finalizado. Resultados impressos em arquivo." << std::endl;
}

void Tarefa::itemDoisB()
{
	// Vetores para armazenar a saida
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);

	// Vetores intermediarios de calculo
	std::vector<double>* diag = new std::vector<double>(N - 1, 1 + 2 * lambda);
	std::vector<double>* sub = new std::vector<double>(N - 2, -lambda);
	std::vector<double>* b = new std::vector<double>(N - 1, 0);
	std::vector<double>* temp = new std::vector<double>(N - 1, 0);
	std::ofstream fileU, fileE;
	double ErroMax = 0;
	fileU.open("Output2B.txt", std::ios::trunc);
	fileU << std::endl << "================ Caso A ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso A" << std::endl;
	fileE.open("Erro2B.txt", std::ios::trunc);
	fileE << std::endl << "================ Caso A ================" << std::endl;
	fileE << std::endl << "Erro do caso A" << std::endl;

	// Item B.a

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = (x * x * (1 - x) * (1 - x));
	}

	// Calculo por metodo de Euler implicito
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		u->at(0) = 0; // Condicao de contorno em x=0
		for (int i = 0; i < N - 1; i++) {
			b->at(i) = uAnterior->at(i + 1) + deltaT * f(k + 1, i + 1, 'a');
		}
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
			erro->at(i) = abs(uReal(k + 1, i, 'a') - u->at(i));
		}
		u->at(N) = 0; // Condicao de contorno em x=1
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo do caso A: \n" << std::scientific << ErroMax << std::endl;

	// Item B.b
	ErroMax = 0;
	std::fill(erro->begin(), erro->end(), 0);

	fileU << std::endl << std::endl << "================ Caso B ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso B" << std::endl;
	fileE << std::endl << std::endl << "================ Caso B ================" << std::endl;
	fileE << std::endl << "Erro do caso B" << std::endl;

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = exp(-x);
	}

	// Calculo por metodo de Euler implicito
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		double t = deltaT * (k + 1.0);
		u->at(0) = exp(t); // Condicoes de contorno
		u->at(N) = exp(t - 1) * cos(5 * t);
		b->at(0) = uAnterior->at(1) + deltaT * f(k + 1, 1, 'b') + lambda * u->at(0);
		for (int i = 1; i < N - 2; i++) {
			b->at(i) = uAnterior->at(i + 1) + deltaT * f(k + 1, i + 1, 'b');
		}
		b->at(N - 2) = uAnterior->at(N - 1) + deltaT * f(k + 1, N - 1, 'b') + lambda * u->at(N);
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
			erro->at(i) = abs(uReal(k + 1, i, 'b') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo do caso B: \n" << std::scientific << ErroMax << std::endl;

	// Item B.c
	fileU << std::endl << std::endl << "================ Caso C ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso C" << std::endl;
	std::fill(uAnterior->begin(), uAnterior->end(), 0);

	// Calculo por metodo de Euler implicito
	printLine(*uAnterior, fileU);
	for (int k = 0; k < M; k++) {
		u->at(0) = 0;
		for (int i = 0; i < N - 1; i++) {
			b->at(i) = uAnterior->at(i + 1) + deltaT * f(k + 1, i + 1, 'c');
		}
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
		}
		u->at(N) = 0;
		*uAnterior = *u;
		printLine(*u, fileU);
	}

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

void Tarefa::itemDoisC()
{
	// Vetores para armazenar a saida
	std::vector<double>* u = new std::vector<double>(N + 1, 0);
	std::vector<double>* uAnterior = new std::vector<double>(N + 1, 0);
	std::vector<double>* erro = new std::vector<double>(N + 1, 0);

	// Vetores intermediarios de calculo
	std::vector<double>* diag = new std::vector<double>(N - 1, 1 + lambda);
	std::vector<double>* sub = new std::vector<double>(N - 2, -lambda / 2);
	std::vector<double>* b = new std::vector<double>(N - 1, 0);
	std::vector<double>* temp = new std::vector<double>(N - 1, 0);
	std::ofstream fileU, fileE;
	double ErroMax = 0;
	fileU.open("Output2C.txt", std::ios::trunc);
	fileU << std::endl << "================ Caso A ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso A" << std::endl;
	fileE.open("Erro2C.txt", std::ios::trunc);
	fileE << std::endl << "================ Caso A ================" << std::endl;
	fileE << std::endl << "Erro do caso A" << std::endl;

	// Item C.a

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = (x * x * (1 - x) * (1 - x));
	}

	// Calculo por metodo de Crank-Nicolson
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		u->at(0) = 0; // Condicao de contorno em x=0
		for (int i = 0; i < N - 1; i++) {
			b->at(i) = (1 - lambda) * uAnterior->at(i + 1) + (lambda / 2) * uAnterior->at(i) + (lambda / 2) * uAnterior->at(i + 2) + (deltaT / 2) * (f(k, i + 1, 'a') + f(k + 1, i + 1, 'a'));
		}
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
			erro->at(i) = abs(uReal(k + 1, i, 'a') - u->at(i));
		}
		u->at(N) = 0; // Condicao de contorno em x=1
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo do caso A: \n" << std::scientific << ErroMax << std::endl;

	// Item C.b
	ErroMax = 0;
	std::fill(erro->begin(), erro->end(), 0);

	fileU << std::endl << std::endl << "================ Caso B ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso B" << std::endl;
	fileE << std::endl << std::endl << "================ Caso B ================" << std::endl;
	fileE << std::endl << "Erro do caso B" << std::endl;

	// definição das condições de fronteira
	// coloca u0 em u(0,:)
	for (int i = 0; i <= N; i++) {
		double x = deltaX * i;
		uAnterior->at(i) = exp(-x);
	}

	// Calculo por metodo de Crank-Nicolson
	printLine(*uAnterior, fileU);
	printLine(*erro, fileE);
	for (int k = 0; k < M; k++) {
		double t = deltaT * (k + 1.0);
		u->at(0) = exp(t); // Condicoes de contorno
		u->at(N) = exp(t - 1) * cos(5 * t);
		b->at(0) = (1 - lambda) * uAnterior->at(1) + (lambda / 2) * uAnterior->at(0) + (lambda / 2) * uAnterior->at(2) + (deltaT / 2) * (f(k, 1, 'b') + f(k + 1, 1, 'b')) + (lambda / 2) * u->at(0);
		for (int i = 1; i < N - 2; i++) {
			b->at(i) = (1 - lambda) * uAnterior->at(i + 1) + (lambda / 2) * uAnterior->at(i) + (lambda / 2) * uAnterior->at(i + 2) + (deltaT / 2) * (f(k, i + 1, 'b') + f(k + 1, i + 1, 'b'));
		}
		b->at(N - 2) = (1 - lambda) * uAnterior->at(N - 1) + (lambda / 2) * uAnterior->at(N - 2) + (lambda / 2) * uAnterior->at(N) + (deltaT / 2) * (f(k, N - 1, 'b') + f(k + 1, N - 1, 'b')) + (lambda / 2) * u->at(N);
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
			erro->at(i) = abs(uReal(k + 1, i, 'b') - u->at(i));
		}
		*uAnterior = *u;
		if (*std::max_element(erro->begin(), erro->end()) > ErroMax)
			ErroMax = *std::max_element(erro->begin(), erro->end());
		printLine(*u, fileU);
		printLine(*erro, fileE);
	}

	std::cout << std::endl << "Erro maximo do caso B: \n" << std::scientific << ErroMax << std::endl;

	// Item C.c
	fileU << std::endl << std::endl << "================ Caso C ================" << std::endl;
	fileU << std::endl << "Matriz U calculada do caso C" << std::endl;
	std::fill(uAnterior->begin(), uAnterior->end(), 0);

	// Calculo por metodo de Crank-Nicolson
	printLine(*uAnterior, fileU);
	for (int k = 0; k < M; k++) {
		u->at(0) = 0;
		for (int i = 0; i < N - 1; i++) {
			b->at(i) = (1 - lambda) * uAnterior->at(i + 1) + (lambda / 2) * uAnterior->at(i) + (lambda / 2) * uAnterior->at(i + 2) + (deltaT / 2) * (f(k, i + 1, 'c') + f(k + 1, i + 1, 'c'));
		}
		temp = solveLDLt(diag, sub, b);
		for (int i = 1; i < N; i++) {
			u->at(i) = temp->at(i - 1);
		}
		u->at(N) = 0;
		*uAnterior = *u;
		printLine(*u, fileU);
	}

	std::cout << "Finalizado. Resultados impressos em arquivos." << std::endl;
}

double Tarefa::getLambda()
{
	return this->lambda;
}

double Tarefa::f(int k, int i, char ch)
{
	double t = deltaT * k;
	double x = deltaX * i;
	if (ch == 't')
		return (10 * x * x * (x - 1) - 60 * x * t + 20 * t);
	else if (ch == 'a')
		return (10 * cos(10 * t) * x * x * (1 - x) * (1 - x) - (1 + sin(10 * t)) * (12 * x * x - 12 * x + 2));
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
	if (ch == 't')
		return (10 * x * x * (x - 1) * t);
	else if (ch == 'a')
		return ((1 + sin(10 * t)) * x * x * (1 - x) * (1 - x));
	else
		return (exp(t - x) * cos(5 * t * x));
}

void Tarefa::printLine(std::vector<double> line, std::ostream& output)
{
	for (unsigned int i = 0; i < line.size(); i++) {
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
