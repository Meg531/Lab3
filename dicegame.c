#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

/* function prints out the data members for this guess round.
It will print out the total of the two dice, each die value, and possible points for that round.
*/
void printGuess( Guess g )
{
printf("Roll = %d (%d, %d), Possible Points = %d",g.die1+g.die2,g.die1,g.die2,g.points);
}

/* function generates two random numbers between 1 and 6 inclusive (to represent a role of a die).
It will then assign those values to the dereferenced values of the two pointers.
*/
void getDice( int* d1, int* d2 )
{
// rand()%6 generates a random integer between 0 and 5 (inclusive)
*d1 = (rand()%6)+1;
*d2 = (rand()%6)+1;
}

// function traverses and initializes the array.
void fillGuesses( Guess* guesses, int length )
{
int i;
// loop length number of times
for(i=0;i<length;i++)
{
// populate the dice for ith guess
getDice(&guesses[i].die1,&guesses[i].die2);
guesses[i].points = (i+1)*10; // populate the points for (i+1)th round
// populate the game type for the round
int n = rand()%100; // generate a random integer between 0 and 99 (inclusive)
// populate the type based on probability
if(n < 20)
guesses[i].type = ELIMINATION;
else if(n < 40)
guesses[i].type = BONUS;
else
guesses[i].type = REGULAR;
}
}
 
 
 