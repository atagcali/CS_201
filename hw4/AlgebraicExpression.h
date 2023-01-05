#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
//#include "Stackint.h"

using namespace std;


class AlgebraicExpression
{
public:
	AlgebraicExpression();
	~AlgebraicExpression();
	double evaluateInfix(const string exp);
	double evaluatePrefix(const string exp);
	double evaluatePostfix(const string exp);
	Stackint reverseIntStack(Stackint& stackint);
	string toprefix(const string exp);
	string topostfix(const string exp);
	string toinfix(const string exp);
	
private:
	Stack stack;
	Stackint stackint;
};

