/*********************************************************************************************
Title: 			TRAN.assignment1 (main.cpp)
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
#include <fstream>

#include "evaluator.h"

using namespace std;

int main()
{
	//open up stream for the input and output files
	ifstream inputFile("data.txt");
	ofstream outputFile("results.txt");
	
    if(inputFile)
	{
		string expression;
			// declare string variable to stream each line into
		
		while(inputFile >> expression)
		{
			
			evaluator expressionToParse(expression);
			
			if (expressionToParse.evaluate() == 1)
				//should bool validExpression remain true, evaluated expression will be written into the results.txt
			{
				outputFile << expressionToParse.getFinalResult() << endl;
			}
			else
				//should bool validExpression, but set to false, error message will be written for the given line
				outputFile << "Incorrect input. Please fix." << endl;
		}
		
		inputFile.close();
		outputFile.close();
	}
	else
	{
		cerr << endl << "Input file could not be opened or found! Please resolve...\n";
			//should input file not be found
		return 1;
	}
    return 0;
}