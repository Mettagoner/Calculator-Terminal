#include <iostream>
#include "rational.h"
using namespace std;

//default constructor
rational::rational(int numer, int denom) //initialize to 0 and 1
{
	num = numer;
	den = denom;

	//invalid parameters: if num and den arent equal to default values
	if ((numer != 0) || (denom != 1)) 
	{
		cout << "Error: Invalid parameters" << endl;
		exit(1);
	}
}

//input function
istream& operator >>(istream& ins, rational& r)
{
	char slash;
	ins >> r.num >> slash >> r.den;
	return ins;
}

//output function
ostream& operator <<(ostream& outs, const rational& r)
{
	outs << "Result = " << r.num << "/" << r.den << "		[Enter (+,-,*,/) num2/den2] or [Press (c) to clear operands] or [Press (q) to quit to root]" << endl;
	outs << "Input: ";
	return outs;
}

//getNumerator Accessor
int rational::getNumerator()
{
	return num;
}

//getDenominator Accessor
int rational::getDenominator()
{
	return den;
}

rational operator +(const rational& rat1, const rational& rat2)
{
	rational temp;
	temp.num = (rat1.num * rat2.den + rat2.num * rat1.den);
	temp.den = (rat1.den * rat2.den);
	temp.simplify();
	return temp;
}

rational operator -(const rational& rat1, const rational& rat2)
{
	rational temp;
	temp.num = (rat1.num * rat2.den - rat2.num * rat1.den);
	temp.den = (rat1.den * rat2.den);
	temp.simplify();
	return temp;
}

rational operator *(const rational& rat1, const rational& rat2)
{
	//cross multiply
	rational temp;
	temp.num = (rat1.num * rat2.num);
	temp.den = (rat1.den * rat2.den);
	temp.simplify();
	return temp;
}

rational operator /(const rational& rat1, const rational& rat2)
{
	rational temp;
	temp.num = (rat1.num * rat2.den);
	temp.den = (rat1.den * rat2.num);
	temp.simplify();
	return temp;
}

void rational::simplify()
{
	int commonD = gcd(num, den); //use gcd function
	num = num / commonD;
	den = den / commonD;
}

int rational::gcd(int a, int b)
{
	while (a != 0 && b != 0)
	{
		a = a % b;
		if (a != 0)
			b = b % a;
	}

	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return 1;
}
