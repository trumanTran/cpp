/*********************************************************************************************
Title: 			TRAN.hw3 (dnaAnalysis.h)
Author: 		Trung Tran
Created on: 	August 04, 2015
Description: 	Biological Analysis Program. Does the following:
				1)DNA sequence analysis- reads single strand sequences of DNA (5' to 3')
				from a .txt file and return the complement (also in 5' to 3'). In addition, 
				program will calculate GC content and provide locations of CpG islands
				2)Protein sequence prediction. Reads RNA sequences and provide corresponding
				sequences of amino acid. 
Build with:		Make
Usage:			Along with calling ./hw3, user must include "dna" or "rna" as the first
				parameter, the input file as the second parameter and output file as the third
				parameter.
Purpose:		Practice with classes, arrays, string manipulation, reading from input files 
				and creating separate output file for results. 
**********************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

#ifndef dnaAnalysis_H
#define dnaAnalysis_H

class dnaAnalysis
{
	public:
		//default constructor
		dnaAnalysis();
		
		//overload constructor
		dnaAnalysis(string);
			//dnaAnaysis - constructor for creating DNA object
			//@param string - current DNA sequence 
			
		//destructor
		~dnaAnalysis();
			
		//setters
		void setSequence(string);
			//setSequence - sets current sequence of DNA strand
			//@param string- current sequence of DNA
		
		//other functions
		void isDnaValid();
			//isDnaValid - determines whether given sequence of DNA is valid
		
		double gcContent();
			//gcContent - returns the percentage of bases in the current DNA sequence that are either G or C
			//@param double - the percentage of G and C within given DNA sequence 
			
		string cpgIslands();
			//cpgIslands - gives position within sequence where "CG" (in that given order) is located
			//@param string - all given positions of "CG" within the DNA strand
			
		string dnaComplement();
			/* dnaComplement - takes current sequence (5' to 3') and finds its complement(3' to 5').
			Note that function returns the inverse complement (5' to 3') */
			//@param string - the inverse complement of original DNA sequence
			
		
	private:
	//member variables
	string newSequence;
};

#endif