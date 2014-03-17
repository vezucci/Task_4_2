#include "functions.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include "evaluation.h"

typedef unsigned char UC;

using namespace std;

void go()
{
	cout << "Enter an arithmetic expression. Please use only 1234567890()+-*/ " << endl;
	bool accept = true;
	char* expression;

	do
	{
		string input;
		getline(cin, input);
		expression = (char*)input.data();

		for (UC i = 0; expression[i] != '\0'; ++i)
		{
			accept = isAcceptable(expression[i]) && isBrCor(expression);
			if (!accept)
			{
				break;
			}
		}

		if (accept)
		{
			cout << "The result is " << EvaluateExpression(expression) << endl;
		}
		else
		{
			cout << "Invalid characters or brackets are set incorrectly. Try again." << endl;
		}
	} while (!accept);


}


bool isAcceptable(char c)
{
	if (((c >= '0') && (c <= '9')) || (c == '+') || (c == '-') ||
		(c == '*') || (c == '/') || (c == ' ') || (c == '(') || (c == ')'))
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool isBrCor(char* str)
{
	Stack<char> st;

	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
		{
					st.push(str[i]);
					break;
		}

		case ')':
		{
					if (st.peek() == '(')
					{
						st.pop();
					}
					else
					{
						st.push('-');
					}
					break;
		}
		default:
			break;
		}
	}


	if (st.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}


void info()
{
	unsigned i;
	for (i = 0; i < 10; ++i)
		printf("-");
	puts("\nConsoleCalc v1.0");
	puts("\nThis genial program evaluates arithmetic expression you enter.");
	puts("\nTsybran Vitalii 2014 All rigths reserved.");
	for (i = 0; i < 10; ++i)
		printf("-");
	printf("\n");
}