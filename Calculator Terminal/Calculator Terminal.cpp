#include <iostream>
#include <cmath>
#include <math.h>
#include "calculator.h"
#include "rational.h"
#include "calculator.h"
using namespace std;

int main()
{
	char operMain, operA, operB, operD;
	calculator calc1, calc2;
	rational rat1, rat2;
	cout << "Version: 1.1.1		Developed by: Mettagoner" << endl << endl;
	do
	{
	clearMain:;
		cout << "Press (a) for normal calculation   (b) for fraction calculation   (c) for square root calculation" << endl; 
		cout << "(d) for trigonometric functions   (e) for exponent mode   (q)uit:" << endl;
		cout << "Input: ";  cin >> operMain; if ((operMain != 'a') && (operMain != 'b') && (operMain != 'c') && (operMain != 'd') && (operMain != 'e') && (operMain != 'q')) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearMain; }
		switch (operMain)
		{
		case 'a':
			cout << endl << endl;
			cout << "NORMAL CALCULATION MODE ENABLED" << endl;
		clearA:; cout << "Instructions:	[Enter num1 (+,-,*,/) num2]" << endl;
			cout << "Input: ";
			cin >> calc1; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearA; }
			do {
				cin >> operA; if ((operA != '+') && (operA != '-') && (operA != '*') && (operA != '/') && (operA != 'q') || (cin.fail())) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearA; }
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
					cout << endl << endl; //format spacing
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
			cout << endl << endl;
			cout << "FRACTION CALCULATION MODE ENABLED" << endl;
		clearB:; cout << "Instructions:   [num1/den1 (+,-,*,/) num2/den2]" << endl;
			cout << "Input: ";
			cin >> rat1; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB; }
			do {
				cin >> operB; if ((operB != '+') && (operB != '-') && (operB != '*') && (operB != '/') && (operB != 'q') || (cin.fail())) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB; }
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
					cout << endl << endl; //format spacing
					break;
				}
				cin >> rat2; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto clearB; }
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
			cout << endl << endl; //format spacing
			cout << "SQUARE ROOT MODE ENABLED" << endl;
		retryC:; cout << "Instructions:   [Enter a value to square root]" << endl;
			do
			{
				cout << "Input: ";
				cin >> sqroot; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryC; }
				cout << "Sqrt(" << sqroot << ") " << "Result = " << sqrt(sqroot) << endl;
				cout << "[Press (r) to retry] or [Press (q) to quit to root]: ";
				cin >> operSqroot; if ((operSqroot != 'r') && (operSqroot != 'q')) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryC; }
				if (operSqroot == 'r')
				{
					goto retryC;
				}
			} while (operSqroot != 'q');
			cout << "SQUARE ROOT MODE DISABLED" << endl;
			cout << endl << endl; //format spacing
			break; //break 'c' switch case

		case 'd':
			float inputD;
			float aTan;
			cout << endl << endl; //format spacing
			cout << "TRIGONOMETRIC FUNCTION MODE ENABLED" << endl;
		retryD:; cout << "NOTE: all functions take input in radians NOT degrees" << endl;
			do {
				cout << "Enter:" << endl;
				cout << "(a) for SINE" << endl;
				cout << "(b) for COSINE" << endl;
				cout << "(c) for TANGENT" << endl;
				cout << "(d) for ARC SINE" << endl;
				cout << "(e) for ARC COSINE" << endl;
				cout << "(f) for ARC TANGENT" << endl;
				cout << "(g) for ARC TANGENT of a/b" << endl;
				cout << "(h) for HYPERBOLIC COSINE" << endl;
				cout << "(i) for HYPERBOLIC TANGENT" << endl;
				cout << "(q) to return to root menu" << endl;
				cout << "Input: ";  cin >> operD; if ((operD != 'a') && (operD != 'b') && (operD != 'c') && (operD != 'd') && (operD != 'e') && (operD != 'f') && (operD != 'g') && (operD != 'h') && (operD != 'i') && (operD != 'q')) { cout << "Illegal input. Resetting..." << endl; goto retryD; }
				//QUIT TO ROOT
				if (operD == 'q')
				{
					cout << "TRIGONOMETRIC FUNCTION MODE DISABLED" << endl;
					cout << endl << endl; //format spacing
					break;
				}
				//BEGIN SWITCH STATEMENT
				switch (operD)
				{
				case 'a':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "SINE value of " << inputD << " = " << sin(inputD) << endl << endl;
					continue;
				case 'b':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "COSINE value of " << inputD << " = " << cos(inputD) << endl << endl;
					continue;
				case 'c':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "TANGENT value of " << inputD << " = " << tan(inputD) << endl << endl;
					continue;
				case 'd':
					cout << "Argument must be in the range -1 to 1 otherwise an ERROR will occur" << endl;
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "ARC SINE value of " << inputD << " = " << asin(inputD) << endl << endl;
					continue;
				case 'e':
					cout << "Argument must be in the range -1 to 1 otherwise an ERROR will occur" << endl;
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "ARC COSINE value of " << inputD << " = " << acos(inputD) << endl << endl;
					continue;
				case 'f':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "ARC TANGENT value of " << inputD << " = " << atan(inputD) << endl << endl;
					continue;
				case 'g':
					cout << "Enter two values: ";
					cin >> inputD; cin >> aTan; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "ARC TANGENT value of " << inputD << " and " << aTan << " = " << atan2(inputD, aTan) << endl << endl;
					continue;
				case 'h':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "HYPERBOLIC COSINE of " << inputD << " = " << cosh(inputD) << endl << endl;
					continue;
				case 'i':
					cout << "Enter value: ";
					cin >> inputD; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryD; }
					cout << "HYPERBOLIC TANGENT of " << inputD << " = " << tanh(inputD) << endl << endl;
					continue;
				}
			} while (operD != 'q');
			break; //break 'd' switch case

		case 'e':
			char operE;
			float numE, expE;
			cout << endl << endl;
			cout << "EXPONENT MODE ENABLED" << endl;
		retryE:; cout << "Instructions:	[Enter a number then an exponent]" << endl;
			do {
				cout << "Enter a number: "; 
				cin >> numE; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryE; }
				cout << "Enter an exponent: " << endl;
				cin >> expE; if (cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryE; }
				cout << "Result: " << pow(numE, expE) << endl;
				cout << "[Press (r) to retry] or [Press (q) to quit to root]: ";
				cin >> operE; if ((operE != 'r') && (operE != 'q')) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cout << "Illegal input. Resetting..." << endl; goto retryE; }
				if (operSqroot == 'r')
				{
					goto retryC;
				}
			} while (operE != 'q');
			cout << "EXPONENT MODE DISABLED" << endl;
			cout << endl << endl; //format spacing
			break; //case 'e' switch case
		}//break operMain switch case
	} while (operMain != 'q');
	return 0;
}