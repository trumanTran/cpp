/*********************************************************************************************
Title: 			TRAN.hw3 (dnaAnalysis.cpp)
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

#include "dnaAnalysis.h"

dnaAnalysis::dnaAnalysis()
{
	
}

dnaAnalysis::dnaAnalysis(string sequence)
{
	newSequence = sequence;
}

dnaAnalysis::~dnaAnalysis()
{
	
}

void dnaAnalysis::setSequence(string sequence)
{
	newSequence = sequence;
}

void dnaAnalysis::isDnaValid() 
{
	for(unsigned int i = 0; i < newSequence.length(); i++)
	{
		if(newSequence[i] == 'A'||newSequence[i] == 'T'||newSequence[i] == 'G'||newSequence[i] == 'C')
			//as long as each char in the rna string is A T G C, for loop will continue
		{
			continue;
		}
		else
			//otherwise, it will prompt error message and exit
		{
			cerr << "Your input file contains sequence(s) that have invalid character(s).\n" <<
			"Please ensure the strands all have proper bases (A,T,G,C)\n";
			
			exit(1);
		}
	}
}

double dnaAnalysis::gcContent()
{
	double gc = 0;
		//declare gc to hold count of number of C or G in DNA strand
	
	for(unsigned int i = 0; i < newSequence.length(); i++)
	{
		if(newSequence[i] == 'G' || newSequence[i] == 'C' )
		{
			gc += 1;
				//should loop find in G or C in string, it'll add one to count
		}
	}
	
	double gcPercentage = (gc/newSequence.length()) * 100;
		//percentage determined by number of G or C divided by total number of char
	
	return gcPercentage;
}

string dnaAnalysis::cpgIslands()
{
	string CG("CG");
		//create a string CG to use as a search parameter
	string cgLocations = "Found 'CG' at ";
		//declared string that will give the location of each CpG island
	string location;
		//declared a string to use to convert int(CG location) into string to concatenate wiht cgLocations
	
	size_t index = 0;
	while ((index = newSequence.find(CG, index)) != string::npos)
	{
		stringstream convertInt;
		convertInt << index; 
		location = convertInt.str();
		cgLocations += location + " ";
			//concatenate location with cgLocations string
		index += CG.length();
	}
	
	return cgLocations;
	
}

string dnaAnalysis::dnaComplement()
{
	string copyNewSequence(newSequence);
		//create a copy of the original DNA sequence to use for creating complement 
		
	for(unsigned int i = 0; i < copyNewSequence.length(); i++)
	{
		if(copyNewSequence[i] == 'A')
		{
			copyNewSequence[i] = 'T';
		}
		else if (copyNewSequence[i] == 'T')
		{
			copyNewSequence[i] = 'A';
		}
		else if (copyNewSequence[i] == 'G')
		{
			copyNewSequence[i] = 'C';
		}
		else 
		{
			copyNewSequence[i] = 'G';
		}
	}
	
	string complement= "";
		//declare complement string to concatenate all complement bases
	
	for(int j = copyNewSequence.length()- 1; j >= 0; j--)
			//this for loop is counting down from copyNewSequence.length in order to have the sequence be in 5' to 3' format
	{
		complement += copyNewSequence[j];
	}
	
	return complement;
}



