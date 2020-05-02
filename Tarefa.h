#pragma once
#include <math.h>
#include <vector>
#include <ostream>
#include <stdexcept>

class Tarefa
{
public:
	Tarefa(int N, int M);
	~Tarefa();

	void itemUmATeste();
	void itemUmA();
	void itemUmB();
	void itemUmC();

	void itemDoisA();
	void itemDoisB();
	void itemDoisC();

	double getLambda();

private:
	int N = 0;
	int M = 0;
	double lambda = 0;
	double deltaT = 0; 
	double deltaX = 0;
	double p = 0.25;
	double f(int k, int i, char ch);
	double uReal(int k, int i, char ch);
	void printLine(std::vector<double> line, std::ostream& output);
	std::vector<double>* solveLDLt(std::vector<double>* diag, std::vector<double>* sub, std::vector<double>* b);
};