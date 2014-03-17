#ifndef EVALUATION_H
#define EVALUATION_H


#include "stack.h"

/*
*@brief	This function evaluates inputed arithmetic expression.
*@param	[in]	char* Expression to evaluate
*@return	int
*/
int EvaluateExpression(char* exp);


/*
Helper functions
*/

void ProcessClosingParenthesis(Stack<int> &vStack, Stack<char> &opStack);
void ProcessInputOperator(char op, Stack<int> &vStack, Stack<char> &opStack);
bool OperatorCausesEvaluation(char op, char prevOp);
void ExecuteOperation(Stack<int> &vStack, Stack<char> &opStack);
int ProcessInputNumber(char* exp, int pos, Stack<int> &vStack);



#endif //EVALUATION_H