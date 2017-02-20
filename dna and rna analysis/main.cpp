/*********************************************************************************************
Title: 			TRAN.hw3 (main.cpp)
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
#include <fstream>
#include <iomanip>

#include "dnaAnalysis.h"
#include "rnaAnalysis.h"

using namespace std;

int main(int argc, char* argv[])
{
	 //check the number of parameters
    if (argc != 4) 
	{
        //error message to tell the user how to run the program
        cerr << "Incorrect input!" 
		<< endl << "Please include: " << argv[0] << " rna/dna input(.txt) output(.txt)" << endl;
        
        return 1;
    }
	else
	{
		ifstream inputFile(argv[2]);
		ofstream outputFile(argv[3]);
		
		//check to make sure input file actually loads 
		if(inputFile)
		{	
			string type(argv[1]);
				/* create a string for first parameter run through command line to determine 
				whether user wants to analyze DNA or RNA  */ 
			
			for(unsigned int i = 0; i < type.length(); ++i) 
			{
				type[i] = tolower(type[i]);
				/* making sure that even if user inputs capital letters,
				it would recognize the dna/DNA by making everything lower 
				case */
			}
			
			int numOfSequence = 0;
				//declared and initialized a integer to keep count of number of sequences processed for either RNA or DNA
			
			if (type == "dna") //should the user choose DNA in cmd line
			{
				string dnaSequence;
					//declaring a string dnaSequence to stream string from the input.txt
			
				while (inputFile >> dnaSequence)
					/* the program is to go through each sequence (line in the .txt file) one by one
					and process each separately */
				{
					dnaAnalysis dna(dnaSequence);
						//create class for DNA sequences 
					dna.isDnaValid(); //check to see if each sequence from the .txt file valid. If invalid, program exits automatically.
					
					outputFile << "GC content(percent): " << fixed << setprecision(2) << dna.gcContent() << " | " << 
					dna.cpgIslands() << " |" << " Inverse complement: " << dna.dnaComplement() << "\n"; 
						/* as long as sequence is valid, the GC content is found along with location of CpG islands.
						Finally, the inverse complement of original sequence is determined. All 3 of those are streamed out
						onto a separate output.txt file */
					
					numOfSequence++;
						//increase after each sequence processed 
				}
				inputFile.close();
				outputFile.close();
				
				cout << "Number of sequences processed: " << numOfSequence << endl; 
			}
			
			else if (type == "rna") //should the user choose RNA in cmd line
			{
				string rnaSequence;
					//declaring a string rnaSequence to stream string from the input.txt
				while(inputFile >> rnaSequence)
					/* the program is to go through each sequence (line in the .txt file) one by one
					and process each separately */
				{
					rnaAnalysis rna(rnaSequence);
						//create class for RNA sequences
					rna.isRnaValid();
						//determines whether each RNA sequence is valid
					outputFile << rna.translateRna() << "\n"; 
						//each RNA strand is translated into a sequence of amino acids that represents a protein
					
					numOfSequence++;
						//increase after each sequence processed
				}
				inputFile.close();
				outputFile.close();
				
				cout << "Number of sequences processed: " << numOfSequence << endl;
			}
			
			else
			{
				cerr << "Error: Please ensure that your first parameter is dna or rna\n";
					//should user typed into something out side of dna/rna(case insensitive) for argv[1]
				
				return 1;
			}
			
		}
		
		else
		{
			cerr << endl << "Input file could not be opened or found! Please resolve...\n";
			return 1;
		}
		
		
	}

    return 0;
}