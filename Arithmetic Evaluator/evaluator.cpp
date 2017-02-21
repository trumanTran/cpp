/*********************************************************************************************
Title: 			TRAN.assignment1 (evaluator.cpp)
Author: 		Trung Tran
Created on: 	September 28, 2015
Description: 	Simple Arithmetic Expression Evaluator. Does the following:
					1) Reads input strings of arithmetic expressions (one per line) from a
					separate "data.txt" file. 
					2) Parses expressions to determine whether input is valid 
					3) If valid, said expression is evaluated following BNF grammar 
Build with:		Make
Usage:			Be sure to include a data.txt file that contains strings of expressions for 
				program to read and evaluate. 
Purpose:		Practice with parsing, recursion and algorithms  
**********************************************************************************************/

#include "evaluator.h"

evaluator::evaluator()
{
	
}

evaluator::evaluator(string expression)
{
	newExpression = expression.c_str();
		//assigning current string that is being streamed as a char *
}

evaluator::~evaluator()
{
	
}

/* Please note that the following functions work together as a recursive decent parser.
Working top down, each function calls upon one another in a way that works in accordance to 
the BNF grammar. */

//returns character at current position
char evaluator::current()
{
    return *newExpression;
}

//returns character at current position and then moves on to character at next position
char evaluator::next()
{
    return *newExpression++;
}

int evaluator::number()
{
    int result = next() - '0';
		//this converts current character into int variable should it be a digit between 0 and 9
    while (current() >= '0' && current() <= '9')
		//should the character be a digit followed by another digit, this will concatenate the digits together to form a number 
    {
        result = 10 * result + next() - '0';
		
    }
	
	if ((current() >= '0' && current() <= '9') || (current() == ')')|| (current() == '+')|| (current() == '*') || (current() == '\0'))
		//current digit must be followed by a digit, operator or closed parenthesis 
	{
		validExpression = true;
	}
	else
		validExpression = false;
	
    return result;
}

int evaluator::factor()
{
    if (current() >= '0' && current() <= '9')
        return number();
    else if (current() == '(')
    {
        next();
		
		if ((current() >= '0' && current() <= '9') || (current() == '('))
			//open paranthesis must be followed by a digit or another open paranthesis
		{
			int result = expression();
			next(); 
			return result;
		}
		else
			validExpression = false;
    }
	else
			validExpression = false;
		
    return 0; 
}

int evaluator::term()
{
    int result = factor();
    while (current() == '*')
        if (next() == '*')
			if ((current() >= '0' && current() <= '9') || (current() == '('))
				// '*' operator must be followed by a digit or '('
			{
				result *= factor();
			}
			else
				validExpression = false;
    return result;
}

int evaluator::expression()
{
    int result = term();
    while (current() == '+')
        if (next() == '+')
			if ((current() >= '0' && current() <= '9') || (current() == '('))
				// '+' operator must be followed by a digit or '('
			{
				result += term();
			}
			else
				validExpression = false;
    return result;
}

void evaluator::firstChar()
{
	if ((current() >= '0' && current() <= '9') || (current() == '('))
		//first character must be a digit or '('
	{
		validExpression = true;
	}
	else
		validExpression = false;
}

int evaluator::evaluate()
{
	firstChar();
	
	if(validExpression)
	{
		finalResult = expression();
	}
	return validExpression;
}

int evaluator::getFinalResult()
{
	return finalResult;
}