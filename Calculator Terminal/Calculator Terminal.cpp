#include <iostream>
#include <cmath>
#include "calculator.h"
#include "rational.h"
#include "calculator.h"
using namespace std;

int main()
{
	char operMain, operA, operB;
	calculator calc1, calc2;
	rational rat1, rat2;
	cout << "Version: 1.0.0		Developed by: Mettagoner" << endl << endl;
	do
	{
		cout << "Press (a) for normal calculation   (b) for fraction calculation   (c) for square root calculation   (q)uit: ";
		cin >> operMain;
		switch (operMain)
		{
		case 'a':
			cout << endl;
			 cout << "NORMAL CALCULATION MODE ENABLED" << endl;
		 clearA:; cout << "Instructions:	[Enter num1 (+,-,*,/) num2]" << endl;
			cout << "Input: ";
			cin >> calc1; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearA;}
			do {
				cin >> operA; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearA;}
				//CLEAR OPERANDS
				if (operA == 'c')
				{
					cout << "OPERANDS CLEARED" << endl;
					goto clearA;
				}
				//QUIT TO ROOT
				if (operA == 'q')
				{
					cout << "NORMAL CALCULATION MODE DISABLED" << endl;
					cout << endl; //format spacing
					break;
				}
				cin >> calc2; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearA;}
				//IF STATEMENTS
				if (operA == '+')
				{
					calc1 = calc1 + calc2;
					cout << calc1;
				}
				if (operA == '-')
				{
					calc1 = calc1 - calc2;
					cout << calc1;
				}
				if (operA == '*')
				{
					calc1 = calc1 * calc2;
					cout << calc1;
				}
				if (operA == '/')
				{
					calc1 = calc1 / calc2;
					cout << calc1;
				}
			} while (operA != 'q');
			break; //break 'a' switch case

		case 'b':
			cout << endl;
		clearB:; cout << "FRACTION CALCULATION MODE ENABLED" << endl;
			cout << "Instructions:   [num1/den1 (+,-,*,/) num2/den2]" << endl;
			cout << "Input: ";
			cin >> rat1; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB;}
			do {
				cin >> operB; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB;}
				//CLEAR OPERANDS
				if (operB == 'c')
				{
					cout << "OPERANDS CLEARED" << endl;
					goto clearB;
				}
				//QUIT TO ROOT
				if (operB == 'q')
				{
					cout << "FRACTION CALCULATION MODE DISABLED" << endl;
					cout << endl; //format spacing
					break;
				}
				cin >> rat2; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB;}
				//IF STATEMENTS
				if (operB == '+')
				{
					rat1 = rat1 + rat2;
					cout << rat1;
				}
				if (operB == '-')
				{
					rat1 = rat1 - rat2;
					cout << rat1;
				}
				if (operB == '*')
				{
					rat1 = rat1 * rat2;
					cout << rat1;
				}
				if (operB == '/')
				{
					rat1 = rat1 / rat2;
					cout << rat1;
				}
			} while (operB != 'q');
			break; //break 'b' switch case

		case 'c':
			float sqroot;
			char operSqroot;
			cout << endl; //format spacing
		retryC:; cout << "SQUARE ROOT MODE ENABLED" << endl;
			cout << "Instructions:   [Enter a value to square root]" << endl;
			do
			{
				cout << "Input: ";
				cin >> sqroot; if (cin.fail()) {std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryC;}
				cout << "Sqrt(" << sqroot << ") " << "Result = " << sqrt(sqroot) << endl;
				cout << "[Press (r) to retry] or [Press (q) to quit to root]: ";
				cin >> operSqroot; if ((operSqroot != 'r') && (operSqroot != 'q')) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryC; }
				if (operSqroot == 'r')
				{
					goto retryC;
				}
			} while (operSqroot != 'q');
			cout << "SQUARE ROOT MODE DISABLED" << endl;
			cout << endl; //format spacing
			break; //break 'c' switch case
		}//break operMain switch case
	} while (operMain != 'q'); 
	return 0;
}