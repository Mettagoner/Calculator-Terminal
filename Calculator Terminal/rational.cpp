#include "rational.h"
#include <iostream>
#include <string>
using namespace std;

rational::rational()
{
    num = 0;
    den = 1;
}

void rational::input()
{
    char slash;
    cin >> num >> slash >> den;
    if (cin.fail())
    {
        cout << "Error: Illegal input. Exiting program...";
        exit(0);
    }
}

void rational::output() const
{
    cout << "Result = " << num << "/" << den << endl;
}

int rational::getNumerator()
{
    return num;
}

int rational::getDenominator()
{
    return den;
}

void rational::add(rational rat1, rational rat2)
{
    num = ((rat1.getNumerator() * rat2.getDenominator()) + (rat2.getNumerator() * rat1.getDenominator()));
    den = ((rat1.getDenominator() * rat2.getDenominator()));
}

void rational::subtract(rational rat1, rational rat2)
{
    num = ((rat1.getNumerator() * rat2.getDenominator()) - (rat2.getNumerator() * rat1.getDenominator()));
    den = ((rat1.getDenominator() * rat2.getDenominator()));
}

void rational::multiply(rational rat1, rational rat2)
{
    num = (rat1.getNumerator() * rat2.getNumerator());
    den = (rat1.getDenominator() * rat2.getDenominator());
}

void rational::divide(rational rat1, rational rat2)
{
    num = (rat1.getNumerator() * rat2.getDenominator());
    den = (rat1.getDenominator() * rat2.getNumerator());
}

void rational::addG(rational rat1, rational rat2)
{
    rational temp;
    temp.num = ((rat1.getNumerator() * rat2.getDenominator()) + (rat2.getNumerator() * rat1.getDenominator()));
    temp.den = ((rat1.getDenominator() * rat2.getDenominator()));
    temp.simplify();
    num = temp.num;
    den = temp.den;
}

void rational::subtractG(rational rat1, rational rat2)
{
    rational temp;
    temp.num = ((rat1.getNumerator() * rat2.getDenominator()) - (rat2.getNumerator() * rat1.getDenominator()));
    temp.den = ((rat1.getDenominator() * rat2.getDenominator()));
    temp.simplify();
    num = temp.num;
    den = temp.den;
}

void rational::multiplyG(rational rat1, rational rat2)
{
    rational temp;
    temp.num = (rat1.getNumerator() * rat2.getNumerator());
    temp.den = (rat1.getDenominator() * rat2.getDenominator());
    temp.simplify();
    num = temp.num;
    den = temp.den;
}

void rational::divideG(rational rat1, rational rat2)
{
    rational temp;
    temp.num = (rat1.getNumerator() * rat2.getDenominator());
    temp.den = (rat1.getDenominator() * rat2.getNumerator());
    temp.simplify();
    num = temp.num;
    den = temp.den;
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