#pragma once
class rational
{
public:
    rational();
    void input();
    void output() const;
    int getNumerator();
    int getDenominator();
    void add(rational rat1, rational rat2);
    void subtract(rational rat1, rational rat2);
    void multiply(rational rat1, rational rat2);
    void divide(rational rat1, rational rat2);
    void addG(rational rat1, rational rat2);
    void subtractG(rational rat1, rational rat2);
    void multiplyG(rational rat1, rational rat2);
    void divideG(rational rat1, rational rat2);
    int gcd(int a, int b);
    void simplify();

private:
    int num, den;
};

