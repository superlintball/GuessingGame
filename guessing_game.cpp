/*
 * Author: Raveen Karnik
 * date: 9-7-17
 * This program creates a guessing game for the player to guess a number  
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//main function to run program
int main()
{
	//variable to keep track of if the user wants to keep playing
	bool playing = true;
	while (playing)
	{
		//initialize random number function to current timestamp
		srand(time(NULL));
		int randNum = rand() % 101;
		cout << "The computer has chosen a number. Try to guess it." << endl;
		//initialize the first guess to an impossible option
		int guess = -5;
		cin >> guess;
		while (guess < 0 || guess > 100)
		{
			cout << "Your guess must be between 0 and 100, inclusive. Guess again." << endl;
			cin >> guess;
		}
		//initialize a variable to keep track of the number of guesses
		int guesses = 1;
		//have the user guess the random number, telling them if it's too high or too low every time
		while (guess != randNum)
		{
			guesses++;
			if (guess > randNum)
			{
				cout << "Your guess was too high. Guess again." << endl;
			}
			else if (guess < randNum)
			{
				cout << "Your guess was too low. Guess again." << endl;
			}
			cin >> guess;
		}
		//announce to the user that they succeeded and what the number was. Tell them how many guesses it took then ask if they want to play again
		cout << "Congratulations! The computer's number was " << randNum << "!" << endl;
		cout << "It took you " << guesses << " guesses. Play again? (y/n)" << endl;
		//ask the user if they want to keep playing. Switch the playing variable to false if they say no
		char keepPlaying = 'w';
		cin >> keepPlaying;
		while (!(keepPlaying == 'y' || keepPlaying == 'n' || keepPlaying  == 'Y' || keepPlaying == 'N'))
		{
			cout << "Sorry, I couldn't understand that. Play again? (y/n)" << endl;
			cin >> keepPlaying;
		}
		if(keepPlaying == 'n' || keepPlaying == 'N')
		{
			playing = false;
		}
	}
	return 0;
}
