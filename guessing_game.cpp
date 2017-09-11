/*
 * author: Raveen Karnik
 * date: 9-7-17
 * This program creates a guessing game for the player to guess the game
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	bool playing = true;
	while (playing)
	{
		srand(time(NULL));
		int randNum = rand() % 101;
		cout << "The computer has chosen a number. Try to guess it." << endl;
		int guess = -5;
 		cin >> guess;
		int guesses = 1;
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
		cout << "Congratulations! The computer's number was " << randNum << "!" << endl;
		cout << "It took you " << guesses << " guesses. Play again? (y/n)" << endl;
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
