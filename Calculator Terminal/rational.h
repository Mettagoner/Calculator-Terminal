#include <iostream>
using namespace std;

#pragma once
class rational
{
public:
    //Modify constructor declaration to set default values for parameters. See instructions below.
    rational(int numer = 0, int denom = 1);
    friend istream& operator >>(istream& ins, rational& r);
    friend ostream& operator <<(ostream& outs, const rational& r);
    int getNumerator();
    int getDenominator();
    friend rational operator +(const rational& rat1, const rational& rat2);
    friend rational operator -(const rational& rat1, const rational& rat2);
    friend rational operator *(const rational& rat1, const rational& rat2);
    friend rational operator /(const rational& rat1, const rational& rat2);
private:
    //declare data members for rational object
    int num, den;
    //Declare simplify() member that sets the invoking object to be a simplified rational
    void simplify(); // same syntax as setter
    //Implement the gcd function to return the greatest common denominator, use it in simplify above.
    int gcd(int a, int b);
};

