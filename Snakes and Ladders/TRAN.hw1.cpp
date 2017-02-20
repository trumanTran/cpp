/**************************************************************************************
Title: 			TRAN.hw1.cpp
Author: 		Trung Tran
Created on: 	July 9, 2015
Description: 	Simulates a game of Snakes and Ladders using a
				separate .txt to set the dimensions of the board, the number of 
				players, the number of sides on the die and positions of the snakes
				and ladders. 
Purpose:		Practice with arrays and reading from an external file to use as input
***************************************************************************************/
 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//function declarations
int dieRoll(int sides);
// dieRoll - function that will simulate rolling a die (of specified sides)
// @param sides - the number of sides to the die

using namespace std;
int main()
{
	srand(time(0));
	int n;
		//board dimensions - measured as n X n 
	int numOfPlayers;
		//number of players for this current game
	int dieSides;
		//number of sides to the die being used
	
	ifstream gameSettings;
	
	gameSettings.open("input.txt");
	
	gameSettings >> n >> numOfPlayers >> dieSides ;  
		/* this will set the first three variables 
		from the input.txt as board dimensions, 
		number of players and number of sides to
		the die, respectively */
	
	if ((n < 8 || n > 12)||(numOfPlayers < 2 || numOfPlayers > 5)||(dieSides < 2 || dieSides > 12))
	{
		cerr << endl << "Unacceptable input parameters for one of the following:" << endl << 
		"1) Dimensions(8x8 to 12x12)" << endl << 
		"2) Number of players (2 to 5)" << endl << 
		"3) Number of sides to die (2 to 12)" << endl << 
		"Please correct and try again!" << endl;
		
		exit(1);
		
		/* Setting an error message in case the person who sets the input.txt did not properly set the parameters correctly
		for n, players or dieSides. */
	}
	
	int spaces = n*n;
		//number of spaces on the board
	char snakeOrLadder;
		//used to recognize the 'S' and 'L' within input.txt
	int position, offset; 
		/* first and second number after each char; determines the
		position of the snake/ladder and its offset */
	int snakePosition[(spaces)/2];
		/* array that will have the tile position of each snake.
		please note that I set the array size to spaces/2 because the maximum
		number of snakes possible is half of the spaces on the board since a 
		snake takes up 2 spaces (same goes for ladders) */
	int snakeOffset[(spaces)/2];
		//array that will have the offset number of each snake 
	int ladderPosition[(spaces)/2];
		//array that will have the tile position of each ladder
	int ladderOffset[(spaces)/2];
		//array that will have the offset number of each ladder
	int s = 0;
		//starting index number of each snake array	
	int l = 0;
		//starting index number of each ladder array
	
	while (gameSettings >> snakeOrLadder >> position >> offset) 
		/* used to fill up the previously declared arrays. should the program
		spot an 'S' in the input.txt, it will fill in the arrays for snakePosition
		and snakeOffset. Otherwise, the array for ladderPosition and ladderOffset 
		will be filled */
	{
		if (snakeOrLadder == 'S')
		{
			snakePosition[s] = position;
			snakeOffset[s] = offset;
			s++;
		}
		else 
		{
			ladderPosition[l] = position;
			ladderOffset[l] = offset;
			l++;
		}	
	}
	
	for (int i = 0; i < s; i++)
	{
		if (snakePosition[i]==spaces)
		{
			cerr << endl << "You have placed a snake head on the last tile, " << spaces << endl <<
			"This is not allowed. Please correct before playing!" << endl;
			exit(1);
		}
		/* The person creating the input.txt should not put a snake on the last cell of the board. 
		As such, I created an error message that reminds the user to change the position of that snake. */
	}
	
	for (int i = 0; i < l; i++)
	{
		if (ladderPosition[i]==spaces)
		{
			cerr << endl << "You have placed a ladder on the last tile, " << spaces << endl <<
			"This is not allowed. Please correct before playing!" << endl;
			exit(1);
		}
		// same reasoning as to not put a ladder on the final cell
		
	}
	
	gameSettings.close();
	
	int playerPosition[numOfPlayers];
		//declaring an array to save position of each player after a turn
	int players[numOfPlayers];
		//declaring an array to later use to rank each player at the end of the game 
	for(int i = 0; i< numOfPlayers;i++)
	{
		players[i] = i+ 1;
		//filling out the array for players[] so that it has each player number
	}
	for(int i=0; i < numOfPlayers; i++)
	{
		playerPosition[i] = 1;
			// each player starts at tile 1
	}
	
	bool gameOver = false;
		/* I am setting up a boolean known as gameOver so that when a player reaches the finish, gameOver becomes true
		and ends the while loop */
		
	int round = 0;
		//declaring variable round to keep track of the rounds being played
	while(!gameOver)
		/* The main part of the coding. This entire block of nested loops is where the die roll happens to determine the position of each player.
		Depending on the die roll and the position of the snakes or ladder, the player may move further forward or fall further back. 
		Refer to rules given on the pdf to hw1.  */
	{ 
		round ++;
		cout << "Round " << round << endl;
		int roll;
			// declaring a variable for the current roll for the current player
		int secondRoll;
			//declaring a variable for a second roll, should the player roll a d for the d-sided die
		for (int j = 0; j < numOfPlayers; j++)
		{
			roll = dieRoll(dieSides);
				//utilizes the dieroll function to determine the current roll number
			playerPosition[j] += roll;
				//current player's position gets updated according to the roll
			if (roll != dieSides)
				/* If the roll is anything other than d, the player will just move "roll" amount of spaces. 
				Should that cell not have a snake or ladder, or the player did not land or pass the final cell
				the current player's turn will end and go on to the next player. */
			{
				if(playerPosition[j] >= spaces)
				{
					 cout << "Player " << j + 1 << " rolled a " << roll << " and moved to tile " << spaces << endl << endl;
				}
				else
				{
					cout << "Player " << j + 1 << " rolled a " << roll << " and moved to tile " << playerPosition [j] << endl << endl;
				}
			}
			else if(playerPosition[j] >= spaces)
				{
					 cout << "Player " << j + 1 << " rolled a " << roll << " and moved to tile " << spaces << endl << endl;
				}
			else
				/* If the roll is in fact a d of a d-sided die, the current player gets to roll again once more and only once more. Same rules apply in terms of 
				whether the player passes the final cell or if he/she lands on a snake or ladder. */				
			{
				secondRoll = dieRoll(dieSides);
				playerPosition[j] += secondRoll;
				if(playerPosition[j] >= spaces)
				{
					 cout << "Player " << j + 1 << " rolled a " << dieSides << " and gets another turn! He/she is at tile " <<  playerPosition[j] - secondRoll << endl
					<< "Second roll is a " << secondRoll << " and moves him/her to tile " << spaces << endl << endl;
				}
				else
				{
					cout << "Player " << j + 1 << " rolled a " << dieSides << " and gets another turn! He/she is at tile " <<  playerPosition[j] - secondRoll << endl
					<< "Second roll is a " << secondRoll << " and moves him/her to tile " << playerPosition [j] << endl << endl;  
				}
			}
			
			for(int k = 0; k < s; k++)
				/* This loop is to compare whether the current player's position after the die roll is the same as the position of a snake.
				If it is the same, players will move back a certain amount of spaces based upon the offset of that given snake */
			{
				if (playerPosition [j] == snakePosition[k])
				{
					playerPosition[j] -= snakeOffset[k];
					cout << "Player " << j+1 << " landed on a snake!" << endl <<
					"He/she moves back " << snakeOffset[k] << " spaces and is now at tile " << playerPosition[j] << endl << endl;
					
				}
			}
			for(int k = 0; k < l; k++)
				/* This loop is to compare whether the current player's position after the die roll is the same as the position of a ladder.
				If it is the same, players will move forward a certain amount of spaces based upon the offset of that given ladder */
			{
				if (playerPosition [j] == ladderPosition[k])
				{
					playerPosition[j] += ladderOffset[k];
					if(playerPosition[j] >= spaces)
					{
						cout << "Player " << j+1 << " landed on ladder!" << endl <<
						"He/she moves forward " << ladderOffset[k] << " spaces and is now at tile " << spaces << endl << endl;
					}
					else
					{
						cout << "Player " << j+1 << " landed on ladder!" << endl <<
						"He/she moves forward " << ladderOffset[k] << " spaces and is now at tile " << playerPosition[j] << endl << endl;
					}
				}
			}
		
			gameOver = playerPosition[j] >= spaces;
				//The given criteria for when the game is over. Should the player land on the final cell or move past it, gameOver becomes true and will end the loop
			if (gameOver)
			{
				playerPosition[j] = spaces;
				//change the winning player's position to the final cell, since you technically cannot go past the last cell
				cout << "Player " << j+1 << " wins by reaching " << spaces << " first!" << endl;
				break;
			}
		}
		
	}
	
	/* The next block of code is used to sort two arrays: playerPosition[] and players[]. I am arranging both arrays in descending order so that the winning player is first,
	the next player is the one closest to the finish and so on. */
	
	int temp1, temp2;
		// declared to temp integers to use as placeholders for sorting the rank of each player in descending order. 
	for(int i = 0; i< numOfPlayers;i++)
	{
		for(int j = 0; j < numOfPlayers;j++)
		{
			if(playerPosition[i]>playerPosition[j])
				//We are able to compare one index to the another using this method
			{
				temp1 = playerPosition[i];
				temp2 = players[i];
				playerPosition[i] = playerPosition[j];
				players[i] = players [j]; 
				playerPosition[j] = temp1;
				players[j] = temp2;
			}
		}
	}
	
	cout << endl << "Final standings at the end of the game" << endl << endl << "Player" << "  " << "Cell #" << endl;
	for(int i = 0; i< numOfPlayers;i++)
	{
		cout << players[i] << "        " << playerPosition[i] << endl;
	}
	return 0;
}

//Function Definitions 

int dieRoll(int sides)
{
	int rollOutcome = 1+ (rand()%sides);
	
	return rollOutcome;
}

