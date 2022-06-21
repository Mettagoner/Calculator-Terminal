#include <iostream>
using namespace std;
#pragma once

class calculator
{
public:
    //Modify constructor declaration to set default values for parameters. See instructions below.
    calculator();
    friend istream& operator >>(istream& ins, calculator& c);
    friend ostream& operator <<(ostream& outs, const calculator& c);
    float getOp();
    friend calculator operator +(const calculator& calc1, const calculator& calc2);
    friend calculator operator -(const calculator& calc1, const calculator& calc2);
    friend calculator operator *(const calculator& calc1, const calculator& calc2);
    friend calculator operator /(const calculator& calc1, const calculator& calc2);
    friend bool operator ==(const calculator& calc1, const calculator& calc2);

private:
	float op;
};

