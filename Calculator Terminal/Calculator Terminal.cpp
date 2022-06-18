#include <iostream>
#include <cmath>
#include <Windows.h>
#include "Calculator.h"
#include "rational.h"

using namespace std;

int main()
{
    bool run = true;
    bool quit = false;
    bool a = false;
    bool b = false;
    bool c = false;
    Calculator op1, op2;
    rational rat1, rat2;
    char operN, operFrac, operMain;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Version: 1.0   Created by: Dan F" << endl;

    while (run == true) {
    start:;
        cout << "Select: ";
        SetConsoleTextAttribute(h, 13);
        cout << "(a)Normal Calculation ";
        SetConsoleTextAttribute(h, 11);
        cout << "(b)Fraction Calculation ";
        SetConsoleTextAttribute(h, 9);
        cout << "(c)Square Root Mode ";
        SetConsoleTextAttribute(h, 4);
        cout << "(q)Quit: ";
        SetConsoleTextAttribute(h, 7);
        cin >> operMain;
        if ((operMain != 'a') && (operMain != 'b') && (operMain != 'c') && (operMain != 'q') || (cin.fail()))
        {
            cout << "Invalid input..." << endl;
            goto start;
        }
        if ((operMain == 'a') || (operMain == 'A'))
        {
            a = true;
            SetConsoleTextAttribute(h, 13);
            cout << "NORMAL CALCULATION MODE ENABELD" << endl;
            cout << "Enter the first operand: ";
            op1.input();
            while (a == true) {
                cout << "Enter operator [+, -, /, *, q(rtn to root menu)]: ";
                cin >> operN;
                while ((operN != '+') && (operN != '-') && (operN != '*') && (operN != '/') && (operN != 'q'))
                {
                    cout << "Error: Illegal input..." << endl;
                    cout << "Enter operator [+, -, /, *, q(rtn to root menu)]: ";
                    cin >> operN;
                }
                switch (operN)
                {
                case '+':
                    cout << "Enter second operand: ";
                    op2.input();
                    op1.add(op1, op2);
                    op1.output();
                    continue;

                case '-':
                    cout << "Enter second operand: ";
                    op2.input();
                    op1.subtract(op1, op2);
                    op1.output();
                    continue;

                case '*':
                    cout << "Enter second operand: ";
                    op2.input();
                    op1.multiply(op1, op2);
                    op1.output();
                    continue;

                case '/':
                    cout << "Enter second operand: ";
                    op2.input();
                    op1.divide(op1, op2);
                    op1.output();
                    continue;

                case 'q':
                    cout << "NORMAL CALCULATION MODE DISABLED" << endl;
                    a = false;
                    break;
                }
                if (a == false)
                {
                    break;
                }
            }
        }

        if ((operMain == 'b') || (operMain == 'B'))
        {
            b = true;
            SetConsoleTextAttribute(h, 11);
            bool gcd = true;
            int counter = 0;
            cout << "FRACTION MODE ENABLED" << endl;
            cout << "Enter the first operand (in the format of num/den): ";
            rat1.input();
            while (b == true) {
                cout << "Enter operator [+, -, /, *, d(disable GCD), q(rtn to root menu)]: ";
                cin >> operFrac;
                while ((operFrac != '+') && (operFrac != '-') && (operFrac != '*') && (operFrac != '/') && (operFrac != 'd') && (operFrac != 'q'))
                {
                    cout << "Error: Illegal input..." << endl;
                    cout << "Enter operator [+, -, /, *, d(disable GCD), q(rtn to root menu)]: ";
                    cin >> operFrac;
                }

                switch (operFrac)
                {
                case '+':
                    cout << "Enter the second operand (in the format of num/den): ";
                    rat2.input();
                    rat1.addG(rat1, rat2);
                    if (gcd == false)
                    {
                        rat1.add(rat1, rat2);
                    }
                    rat1.output();
                    continue;

                case '-':
                    cout << "Enter the second operand (in the format of num/den): ";
                    rat2.input();
                    rat1.subtractG(rat1, rat2);
                    if (gcd == false)
                    {
                        rat1.subtract(rat1, rat2);
                    }
                    rat1.output();
                    continue;

                case '*':
                    cout << "Enter the second operand (in the format of num/den): ";
                    rat2.input();
                    rat1.multiplyG(rat1, rat2);
                    if (gcd == false)
                    {
                        rat1.multiply(rat1, rat2);
                    }
                    rat1.output();
                    continue;

                case '/':
                    cout << "Enter the second operand (in the format of num/den): ";
                    rat2.input();
                    rat1.divideG(rat1, rat2);
                    if (gcd == false)
                    {
                        rat1.divide(rat1, rat2);
                    }
                    rat1.output();
                    continue;

                case 'd':
                    counter++;
                    if (counter % 2 == 0)
                    {
                        gcd = true;
                        cout << "GCD FEATURE ENABLED" << endl;
                    }
                    else {
                        gcd = false;
                        cout << "GCD FEATURE DISABLED" << endl;
                    }
                    continue;

                case 'q':
                    cout << "FRACTION MODE DISABLED" << endl;
                    b = false;
                    break;
                }
                if (b == false)
                {
                    break;
                }
            }
        }

        if ((operMain == 'c') || (operMain == 'C'))
        {
            c = true;
            SetConsoleTextAttribute(h, 9);
            float sqroot;
            char operSqrt;
            cout << "SQUARE ROOT MODE ENABLED" << endl;
            while (c == true) {
                cout << "Enter a value: ";
                cin >> sqroot;
                if (cin.fail())
                {
                    cout << "Error: Illegal input. Exiting program...";
                    exit(0);
                }
                cout << "Sqrt(" << sqroot << ") " << "Result = " << sqrt(sqroot) << endl;
                cout << "Enter either r(etry) or q(rtn to root menu): ";
                cin >> operSqrt;
                if (operSqrt == 'r')
                {
                    continue;
                }
                if (operSqrt == 'q') {
                    cout << "SQUARE ROOT MODE DISABLED" << endl;
                    c = false;
                    break;
                }
                while ((operSqrt != 'r') && (operSqrt != 'q'))
                {
                    cout << "Error: Illegal input..." << endl;
                    cout << "Enter either r(etry) or q(rtn to root menu): ";
                    cin >> operSqrt;
                }
            }
        }
        if ((operMain == 'q') || (operMain == 'Q'))
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Quitting... goodbye!";
            quit = true;
            break;
        }
    }
    if (quit == true)
    {
        exit(0);
    }
    return 0;
} //close main