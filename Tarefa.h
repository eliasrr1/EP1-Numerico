#pragma once
#include <cmath>
#include <vector>
#include <ostream>

class Tarefa
{
public:
	Tarefa(int N, int M);
	~Tarefa();

	void itemUmA();
	void itemUmB();
	void itemUmC();

	void itemDoisA();
	void itemDoisB();
	void itemDoisC();

private:
	int N = 0;
	int M = 0;
	double deltaT = 0; 
	double deltaX = 0;
	double p = 0.25;
	std::vector<std::vector<double> > *u;
	double f(int k, int i, char ch);
	double uReal(int k, int i, char ch);
	void printMatrix(std::vector<std::vector<double> > mat, std::ostream& output, std::string message);
};