#pragma once
#include <string>
#include <iostream>
#include "AlgebraicExpression.h"
//#include "Stackint.h"

using namespace std;

AlgebraicExpression::AlgebraicExpression() {

}

AlgebraicExpression::~AlgebraicExpression() {

}

double AlgebraicExpression::evaluateInfix(const string exp) {
	double output = 0;
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i+1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')' ) {

		}
		else {
			if (ch != ' ') {

				if (ch == '+') {
					stack.push(ch);
				}
				else if (ch == '-') {
					stack.push(ch);
				}
				else if (ch == '*') {
					stack.push(ch);
				}
				else if (ch == '/') {
					stack.push(ch);
				}
				else {

					if (nextspace == 0) {
						temp += ch;
					}
					else {

						temp += ch;
						if (stack.isEmpty()) {
							int tempint = stoi(temp);
							output += tempint;
						}
						else {
							int tempint = stoi(temp);
							if (stack.getTop() == '+') {
								output += tempint;
								
							}
							else if (stack.getTop() == '-') {
								output -= tempint;
								
							}
							else if (stack.getTop() == '*') {
								output *= tempint;
								
							}
							else if (stack.getTop() == '/') {
								output /= tempint;
								
							}
							stack.pop();
						}
						temp = "";
					}
					
				}
			}
		}	

	}	
	return output;
}


double AlgebraicExpression::evaluatePrefix(const string exp) {
	double output = 1;
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i + 1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')') {

		}
		else {
			if (ch != ' ') {

				if (ch == '+') {
					stack.push(ch);
				}
				else if (ch == '-') {
					stack.push(ch);
				}
				else if (ch == '*') {
					stack.push(ch);
				}
				else if (ch == '/') {
					stack.push(ch);
				}
				else {

					if (nextspace == 0) {
						temp += ch;
					}
					else {

						temp += ch;
						if (output==1) {
							int tempint = stoi(temp);
							output += tempint-1;
						}
						else {
							int tempint = stoi(temp);
							if (stack.getTop() == '+') {
								output += tempint;

							}
							else if (stack.getTop() == '-') {
								output -= tempint;

							}
							else if (stack.getTop() == '*') {
								output *= tempint;

							}
							else if (stack.getTop() == '/') {
								output /= tempint;

							}
							stack.pop();
						}
						temp = "";
					}

				}
			}
		}

	}
	return output;
}


double AlgebraicExpression::evaluatePostfix(const string exp) {
	double output = 1;
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i + 1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')') {

		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ' && ch != '(' && ch != ')') {
			if (!nextspace) {
				temp += ch;
			}
			else {
				temp += ch;
				int stackelement = stoi(temp);
				stackint.push(stackelement);
				temp = "";
			}
		}
		else if (ch == '+') {
			int int1 = stackint.getTop();
			stackint.pop();
			int int2 = stackint.getTop();
			stackint.pop();
			int int3 = int1 + int2;
			stackint.push(int3);
		}
		else if (ch == '-') {
			int int1 = stackint.getTop();
			stackint.pop();
			int int2 = stackint.getTop();
			stackint.pop();
			int int3 = int1 + int2;
			stackint.push(int3);

		}
		else if (ch == '*') {
			int int1 = stackint.getTop();
			stackint.pop();
			int int2 = stackint.getTop();
			stackint.pop();
			int int3 = int1 + int2;
			stackint.push(int3);
		}
		else if (ch == '/') {
			int int1 = stackint.getTop();
			stackint.pop();
			int int2 = stackint.getTop();
			stackint.pop();
			int int3 = int1 + int2;
			stackint.push(int3);
		}
		if (i + 1 == exp.length()) {
			output = stackint.getTop();
			stackint.pop();
			return output;
		}
	}

}

Stackint AlgebraicExpression::reverseIntStack(Stackint& stackint) {
	Stackint temp;
	while (!stackint.isEmpty()) {
		int int1 = stackint.getTop();
		temp.push(int1);
		stackint.pop();
	}
	return temp;
}



string AlgebraicExpression::toprefix(const string exp) {
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i + 1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')') {

		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ' && ch != '(' && ch != ')') {
			if (!nextspace) {
				temp += ch;
			}
			else {
				temp += ch;
				int stackelement = stoi(temp);
				stackint.push(stackelement);
				temp = "";
			}
		}
		else {
			stack.push(ch);
		}
	}
	Stackint tempstack(reverseIntStack(stackint));
	
	while (!stack.isEmpty()) {
		temp += stack.getTop();
		temp += ' ';
		stack.pop();
	}
	while (!tempstack.isEmpty()) {
		temp += to_string(tempstack.getTop());
		temp += ' ';
		tempstack.pop();
	}
	return temp;
}


string AlgebraicExpression::topostfix(const string exp) {
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i + 1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')') {

		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ' && ch != '(' && ch != ')') {
			if (!nextspace) {
				temp += ch;
			}
			else {
				temp += ch;
				int stackelement = stoi(temp);
				stackint.push(stackelement);
				temp = "";
			}
		}
		else {
			stack.push(ch);
		}
	}
	Stackint tempstack(reverseIntStack(stackint));
	
	while (!tempstack.isEmpty()) {
		temp += to_string(tempstack.getTop());
		temp += ' ';
		tempstack.pop();
	}

	while (!stack.isEmpty()) {
		temp += stack.getTop();
		temp += ' ';
		stack.pop();
	}
	
	return temp;
}


string AlgebraicExpression::toinfix(const string exp) {
	string temp;
	for (int i = 0; i < exp.length(); i++) {
		int j = i + 1;
		bool nextspace = 1;
		char ch = exp.at(i);
		if (j < exp.length()) {
			char chcheck = exp.at(j);
			if (chcheck != ' ') {
				nextspace = 0;
			}
		}
		if (ch == ' ' || ch == '(' || ch == ')') {

		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != ' ' && ch != '(' && ch != ')') {
			if (!nextspace) {
				temp += ch;
			}
			else {
				temp += ch;
				int stackelement = stoi(temp);
				stackint.push(stackelement);
				temp = "";
			}
		}
		else {
			stack.push(ch);
		}
	}
	Stackint tempstack(reverseIntStack(stackint));
	while (!tempstack.isEmpty() && !stack.isEmpty()) {
		temp += to_string(tempstack.getTop());
		temp += ' ';
		tempstack.pop();
		temp += stack.getTop();
		temp += ' ';
		stack.pop();
	}
	return temp;
}


