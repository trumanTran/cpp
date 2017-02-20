/*********************************************************************************************
Title: 			TRAN.hw3 (rnaAnalysis.h)
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
using namespace std;

#ifndef rnaAnalysis_H
#define rnaAnalysis_H

class rnaAnalysis
{
	public:
		//default constructor
		rnaAnalysis();
		
		//overload constructor
		rnaAnalysis(string);
			//dnaAnaysis - constructor for creating DNA object
			//@param string - current DNA sequence 
			
		//destructor
		~rnaAnalysis();
			
		//setters
		void setSequence(string);
			//setSequence - sets current sequence of DNA strand
			//@param string- current sequence of DNA
		
		//other functions
		void isRnaValid();
			//isDnaValid - determines whether given sequence of DNA is valid
		
		string translateRna();
			//translateRna - reads current strand of RNA and returns sequence of amino acids
			//@param string - sequence of amino acids that makes protein
		
			
		
	private:
	//member variables
	string newSequence;
	
	//functions
	int baseIndex(char);
		//baseIndex - returns numerical representation of the bases A,C,G,U
		//@param int - number representation of bases A,C,G,U
		//@param base - base taken from current RNA sequence
};

#endif