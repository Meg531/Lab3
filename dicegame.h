#ifndef DICEGAME_H
#define DICEGAME_H

typedef enum GuessType { REGULAR, BONUS, ELIMINATION } GuessType;

typedef struct Guess
{
int points;
int die1;
int die2;
GuessType type;

} Guess;

void printGuess( Guess g );
void getDice( int* d1, int* d2 );
void fillGuesses( Guess* guesses, int length ) ;


#endif