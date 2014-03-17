#include "stack.h"
#include "evaluation.h"
#include "string.h"


int EvaluateExpression(char* exp)
{
	Stack<int> vStack;
	Stack<char> opStack;

	opStack.push('(');

	int pos = 0;
	while (pos <= strlen(exp))
	{
		if (exp[pos] == ' ')
		{
			pos++;
		}
		else if (pos == strlen(exp) || exp[pos] == ')')
		{
			ProcessClosingParenthesis(vStack, opStack);
			pos++;
		}
		else if (exp[pos] >= '0' && exp[pos] <= '9')
		{
			pos = ProcessInputNumber(exp, pos, vStack);
		}
		else
		{
			ProcessInputOperator(exp[pos], vStack, opStack);
			pos++;
		}
	}
	return vStack.pop();
}





void ProcessClosingParenthesis(Stack<int> &vStack, Stack<char> &opStack)
{

	while (opStack.peek() != '(')
	{
		ExecuteOperation(vStack, opStack);
	}

	opStack.pop(); // Remove the opening parenthesis

}



int ProcessInputNumber(char* exp, int pos, Stack<int> &vStack)
{

	int value = 0;
	while (pos < strlen(exp) && exp[pos] >= '0' && exp[pos] <= '9')
	{
		value = 10 * value + (int)(exp[pos++] - '0');
	}
		

	vStack.push(value);

	return pos;

}






void ProcessInputOperator(char op, Stack<int> &vStack, Stack<char> &opStack)
{

	while (!opStack.isEmpty() && OperatorCausesEvaluation(op, opStack.peek()))
	{
		ExecuteOperation(vStack, opStack);
	}

	opStack.push(op);

}




bool OperatorCausesEvaluation(char op, char prevOp)
{

	bool evaluate = false;

	switch (op)
	{
	case '+':
	case '-':
		evaluate = (prevOp != '(');
		break;
	case '*':
	case '/':
		evaluate = (prevOp == '*' || prevOp == '/');
		break;
	case ')':
		evaluate = true;
		break;
	}

	return evaluate;

}




void ExecuteOperation(Stack<int> &vStack, Stack<char> &opStack)
{

	int rightOperand = vStack.pop();
	int leftOperand = vStack.pop();
	char op = opStack.pop();

	int result = 0;
	switch (op)
	{
	case '+':
		result = leftOperand + rightOperand;
		break;
	case '-':
		result = leftOperand - rightOperand;
		break;
	case '*':
		result = leftOperand * rightOperand;
		break;
	case '/':
		result = leftOperand / rightOperand;
		break;
	}

	vStack.push(result);

}