#include "Calculator.h"
#include <string>
using namespace std;

Calculator::Calculator()
{
	op = 0;
}

void Calculator::input()
{
	cin >> op;
	if (cin.fail())
	{
		cout << "Error: Illegal input. Exiting program...";
		exit(0);
	}
}

void Calculator::output()
{
	cout << "Result: " << op << endl;
}

float Calculator::getInput()
{
	return op;
}

void Calculator::add(Calculator op1, Calculator op2)
{
	op = (op1.getInput() + op2.getInput());
}

void Calculator::subtract(Calculator op1, Calculator op2)
{
	op = (op1.getInput() - op2.getInput());
}

void Calculator::multiply(Calculator op1, Calculator op2)
{
	op = (op1.getInput() * op2.getInput());
}

void Calculator::divide(Calculator op1, Calculator op2)
{
	op = (op1.getInput() / op2.getInput());
}


