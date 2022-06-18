#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
#pragma once

class Calculator
{
public:
	Calculator();
	void input();
	void output();
	float getInput();
	void add(Calculator op1, Calculator op2);
	void subtract(Calculator op1, Calculator op2);
	void multiply(Calculator op1, Calculator op2);
	void divide(Calculator op1, Calculator op2);

private:
	string str;
	float op;
};

