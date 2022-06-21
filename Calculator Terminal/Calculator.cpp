#include <iostream>
#include "calculator.h"
using namespace std;

calculator::calculator()
{
	op = 0;
}

istream& operator >>(istream& ins, calculator& c)
{
	ins >> c.op;
	return ins;
}

ostream& operator <<(ostream& outs, const calculator& c)
{
	outs << "Result = " << c.op << "		[Enter (+,-,*,/) num2] or [Press(c) to clear operands] or [Press(q) to quit to root]" << endl;
	outs << "Input: ";
	return outs;
}

float calculator::getOp()
{
	return op;
}

calculator operator +(const calculator& calc1, const calculator& calc2)
{
	calculator temp;
	temp.op = calc1.op + calc2.op;
	return temp;
}

calculator operator -(const calculator& calc1, const calculator& calc2)
{
	calculator temp;
	temp.op = calc1.op - calc2.op;
	return temp;
}

calculator operator *(const calculator& calc1, const calculator& calc2)
{
	calculator temp;
	temp.op = calc1.op * calc2.op;
	return temp;
}

calculator operator /(const calculator& calc1, const calculator& calc2)
{
	calculator temp;
	temp.op = calc1.op / calc2.op;
	return temp;
}