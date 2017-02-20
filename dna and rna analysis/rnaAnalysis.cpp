/*********************************************************************************************
Title: 			TRAN.hw3 (rnaAnalysis.cpp)
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

#include "rnaAnalysis.h"

rnaAnalysis::rnaAnalysis()
{
	
}

rnaAnalysis::rnaAnalysis(string sequence)
{
	newSequence = sequence;
}

rnaAnalysis::~rnaAnalysis()
{
	
}

void rnaAnalysis::setSequence(string sequence)
{
	newSequence = sequence;
}

void  rnaAnalysis::isRnaValid()
{
	if(newSequence.length()%3 != 0)
		//RNA sequences must be composed of codons (groups of 3). Should the sequence not be divisible by 3, an error will appear and exit the program
	{
		cerr << "Input file contains sequence(s) that do not have the proper amount of bases.\n" <<
		"Please ensure all RNA strands are properly grouped into codons(3 bases)\n";
		
		exit(1);
	}
	
	for(unsigned int i = 0; i < newSequence.length(); i++)
		//ensures that each base in the RNA sequence is A U G C. any other input will prompt an error
	{
		if(newSequence[i] == 'A'||newSequence[i] == 'U'||newSequence[i] == 'G'||newSequence[i] == 'C')
		{
			continue;
		}
		else
		{
			cerr << "Your input file contains sequence(s) that have invalid character(s).\n" <<
			"Please ensure the strands all have proper bases (A,U,G,C)\n";
			
			exit(1);
		}
	}
	
	string firstCodon = newSequence.substr(0,3);
		//declare firstCodon to be substring (first codon) of the original RNA sequence
	string lastCodon = newSequence.substr(newSequence.length() - 3);
		//declare lastCodon to be substring (last codon) of the original RNA sequence
	
	if(firstCodon != "AUG")
		//first codon must be a start codon
	{
		cerr << "At least one RNA sequence does not begin with a start codon(AUG).\n" <<
		"Please ensure all RNA strands begin with AUG.\n";
		
		exit(1);
	}
	
	
	if((lastCodon != "UAA") && (lastCodon != "UAG") && (lastCodon != "UGA"))
		//last codon must be a stop codon
	{
		cerr << "At least one RNA sequence does not end with a stop codon(UAA/UAG/UGA).\n" <<
		"Please ensure all RNA strands end with a proper stop codon.\n";
		
		exit(1);
	}
	
}

string rnaAnalysis::translateRna()
{
	//RNA codon to amino acid mapping
	char aminoAcid[4][4][4];
		//3-d array to represent an amino acid. each index is a base
		//A = 0, C = 1, G = 2, U = 3
		
		//phenylalanine - F
			aminoAcid[3][3][3] = 'F';
			aminoAcid[3][3][1] = 'F';
		//Leucine - L
			aminoAcid[3][3][0] = 'L';
			aminoAcid[3][3][2] = 'L';
		//Serine - S
			aminoAcid[3][1][3] = 'S';
			aminoAcid[3][1][1] = 'S';
			aminoAcid[3][1][0] = 'S';
			aminoAcid[3][1][2] = 'S';
		//tyrosine - Y
			aminoAcid[3][0][3] = 'Y';
			aminoAcid[3][0][1] = 'Y';
		//stop codon
			aminoAcid[3][0][0] = '-';
			aminoAcid[3][0][2] = '-';
		//cysteine - C
			aminoAcid[3][2][3] = 'C';
			aminoAcid[3][2][1] = 'C';
		//stop codon
			aminoAcid[3][2][0] = '-';
		//tryptophan - W
			aminoAcid[3][2][2] = 'W';
		//leucine - L
			aminoAcid[1][3][3] = 'L';
			aminoAcid[1][3][1] = 'L';
			aminoAcid[1][3][0] = 'L';
			aminoAcid[1][3][2] = 'L';
		//proline - P
			aminoAcid[1][1][3] = 'P';
			aminoAcid[1][1][1] = 'P';
			aminoAcid[1][1][0] = 'P';
			aminoAcid[1][1][2] = 'P';
		//histidine - H
			aminoAcid[1][0][3] = 'H';
			aminoAcid[1][0][1] = 'H';
		//glutamine - Q
			aminoAcid[1][0][0] = 'Q';
			aminoAcid[1][0][2] = 'Q';
		//arginine - R 
			aminoAcid[1][2][3] = 'R';
			aminoAcid[1][2][1] = 'R';
			aminoAcid[1][2][0] = 'R';
			aminoAcid[1][2][2] = 'R';
		//isoleucine - I
			aminoAcid[0][3][3] = 'I';
			aminoAcid[0][3][1] = 'I';
			aminoAcid[0][3][0] = 'I';
		//methionine(start codon) - M
			aminoAcid[0][3][2] = 'M';
		//threonine - T
			aminoAcid[0][1][3] = 'T';
			aminoAcid[0][1][1] = 'T';
			aminoAcid[0][1][0] = 'T';
			aminoAcid[0][1][2] = 'T';
		//asparagine - N
			aminoAcid[0][0][3] = 'N';
			aminoAcid[0][0][1] = 'N';
		//lysine - K
			aminoAcid[0][0][0] = 'K';
			aminoAcid[0][0][2] = 'K';
		//serine - S
			aminoAcid[0][2][3] = 'S';
			aminoAcid[0][2][1] = 'S';
		//arginine - R
			aminoAcid[0][2][0] = 'R';
			aminoAcid[0][2][2] = 'R';
		//valine - V
			aminoAcid[2][3][3] = 'V';
			aminoAcid[2][3][1] = 'V';
			aminoAcid[2][3][0] = 'V';
			aminoAcid[2][3][2] = 'V';
		//alanine - A
			aminoAcid[2][1][3] = 'A';
			aminoAcid[2][1][1] = 'A';
			aminoAcid[2][1][0] = 'A';
			aminoAcid[2][1][2] = 'A';
		//aspartic acid - D
			aminoAcid[2][0][3] = 'D';
			aminoAcid[2][0][1] = 'D';
		//glutamic acid - E
			aminoAcid[2][0][0] = 'E';
			aminoAcid[2][0][2] = 'E';
		//glycine - G
			aminoAcid[2][2][3] = 'G';
			aminoAcid[2][2][1] = 'G';
			aminoAcid[2][2][0] = 'G';
			aminoAcid[2][2][2] = 'G';
	
	string protein = "";
		//declare protein string as value to return. Each time a codon is converted to a amino acid, it will concatenate to this string
	int firstBase, secondBase, thirdBase;
		/* declaring the first, second and third base in order to convert each base in the RNA (which is a char) into an 
		integer to use as an index of the aminoAcid 3-d array */
	bool readSequence = true;
		/* declared a boolean readSequence. As long as it remains true, the codons read will be translated into an amino acid
		and then be concatenated into string protein. Stop codons will set readSequence to false. Should it be false, the codons 
		will be read over but not recorded until it hits another start codon*/
	
	for(unsigned int i = 0; i < newSequence.length() - 2; i += 3)
	{
		firstBase = baseIndex(newSequence[i]);
		secondBase = baseIndex(newSequence[i + 1]);
		thirdBase = baseIndex(newSequence[i + 2]);
		
		if (aminoAcid[firstBase][secondBase][thirdBase] == aminoAcid[0][3][2])
			//should the loop find a start codon in the sequence, readSequence is set to true
		{
			readSequence = true;
		}
		else if ((aminoAcid[firstBase][secondBase][thirdBase] == aminoAcid[3][0][0]) || 
		(aminoAcid[firstBase][secondBase][thirdBase] == aminoAcid[3][0][2]) || 
		(aminoAcid[firstBase][secondBase][thirdBase] == aminoAcid[3][2][0]))
			//should the loop find a stop codon in the sequence, readSequence is set to false
		{
			readSequence = false;
		}
		
		if(readSequence == true)
		{
			protein = protein + aminoAcid[firstBase][secondBase][thirdBase] + " ";
		}
		else 
		{
			continue;
		}
	}
	
	return protein;
}

int rnaAnalysis::baseIndex(char base)
{
	int index; 
	if(base == 'A')
	{
		index = 0;
	}
	else if(base == 'C')
	{
		index = 1;
	}
	else if(base == 'G')
	{
		index = 2;
	}
	else if(base == 'U')
	{
		index = 3;
	}
	
	return index;
}