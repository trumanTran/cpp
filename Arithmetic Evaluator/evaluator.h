/*********************************************************************************************
Title: 			TRAN.assignment1 (evaluator.h)
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

#include <iostream>
using namespace std;

#ifndef evaluator_H
#define evaluator_H

class evaluator
{
	public:
		//default constructor
		evaluator();
		
		//overload constructor
		evaluator(string);
			//evaluator- constructor for creating expression object
			//@param string - current expression being evaluated 
			
		//destructor
		~evaluator();
		
		//other function
		int evaluate(); 
			//evaluate- returns the evaluated expression 
			
		int getFinalResult();
			//getFinalResult - returns the final result of expression should expression is valid
			//@param int - final result of valid expression
			
	private:
		//member variables 
		const char *newExpression; 
		int finalResult;
		bool validExpression;
			//boolean (set to true by default). Should there be an invalid character or order of character, bool will be set to false
		
		//class functions
		
		void firstChar();
			//firstChar - evaluates the first character in expression to determine whether it's valid or not
		char current();
			//current - returns the current character within the expression
			//@param char - current character within expression being evaluated
		char next();
			//next - returns the current character within the expression and then moves to next character 
			//@param char - current character within expression being evaluated
		int number();
			//number - returns number should current character be a number. Note that this function concatentates digits 
			//@param int - the current number
		int factor();
			//factor - returns and calculates factor should current character be part of a factor
			//@param int - current result of factor
		int term();
			//factor - returns and calculates term should current character be part of a term
			//@param int - current result of term
		int expression();
			//expression - returns and calculates expression should current character be part of an expression
			//@param int - current result of expression
	
	
};

#endif