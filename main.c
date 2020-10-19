
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main()
{
srand(time(NULL));
int rounds, die1, die2, user_choice, i;
int flag = 1, total_points = 0;
// input the number of rounds
printf("Enter the number of rounds you want to play (2-12): ");
scanf("%d",&rounds);
// validate rounds and re-prompt until valid
while(rounds < 2 || rounds > 12)
{
printf("Invalid. Enter the number of rounds you want to play (2-12): ");
scanf("%d",&rounds);
}
// create dynamic array of Guess objects
Guess *guesses = (Guess*)malloc(sizeof(Guess)*rounds);

// populate the guess objects
fillGuesses(guesses, rounds);
// get the initial roll value of two dice for the player to start guess:
getDice(&die1,&die2);

printf("\nThe game starts now.");
i = 0;
// loop continues till rounds have been finished or user has lost an elimination round
while((flag == 1) && (i < rounds))
{
// display the round number and type
printf("\n----- Round %d: Type = ",(i+1));
if(guesses[i].type == REGULAR)
printf("Regular -----");
else if(guesses[i].type == BONUS)
printf("Bonus -----");
else
printf("Elimination -----");
// display the current points
printf("\nPoints: %d",total_points);
// display the previous roll
printf("\nPrevious roll is %d (%d,%d)",die1+die2, die1,die2);
// input of whether the next roll will be lower or higher
printf("\nIs the next roll: 1) LOWER or 2) HIGHER? ");
scanf("%d",&user_choice);
// validate input choice and re-prompt until valid
while(user_choice < 1 || user_choice > 2)
{
printf("Invalid choice. Is the next roll: 1) LOWER or 2) HIGHER? ");
scanf("%d",&user_choice);
}

printGuess(guesses[i]); // display the current guess object result

// display the current result and update total_points
if((guesses[i].die1+guesses[i].die2) == (die1+die2))
printf("\nThe roll was a TIE. This round is a PUSH.");
else if(user_choice == 1)
{
if((guesses[i].die1+guesses[i].die2) < (die1+die2))
{

printf("\nCORRECT!");
if(guesses[i].type == REGULAR || guesses[i].type == ELIMINATION)
total_points += guesses[i].points;
else
total_points += (2*guesses[i].points);
}else
{
printf("\nINCORRECT!");
total_points -= guesses[i].points;
if(guesses[i].type == ELIMINATION) // incorrect guess and elimination round, set flag to 0 to end the loop
flag = 0;
}
}
else if(user_choice == 2)
{
if((guesses[i].die1+guesses[i].die2) > (die1+die2))
{

printf("\nCORRECT!");
if(guesses[i].type == REGULAR || guesses[i].type == ELIMINATION)
total_points += guesses[i].points;
else
total_points += (2*guesses[i].points);
}else
{
printf("\nINCORRECT!");
total_points -= guesses[i].points;
if(guesses[i].type == ELIMINATION) // incorrect guess and elimination round, set flag to 0 to end the loop
flag = 0;
}
}
// update the previous dice
die1 = guesses[i].die1;
die2 = guesses[i].die2;
i++;

printf("\n");
}

if(i > rounds) // check if all rounds were completed
i = rounds;
double completion_percent = (((double)(i*100))/rounds);
// display the summary data
printf("\nGAME OVER");
printf("\nPoints: %d, Percentage Complete %.2f%s",total_points,completion_percent,"%");

return 0;
}
//end of main.c