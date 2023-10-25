#include "dicegame.h"

int getRandomNumber(int min, int max) {
    //Gets a range inbetween and including min and max.
    return rand() % (max - min + 1) + min; 
    printf("deg");
}

ROUNDTYPE getRoundType() {
    //Simulating % odds of having each type through setting up if else statement and getRandomNumber.
    int randomNumber = getRandomNumber(0,9);
    if(randomNumber < 2)
    {
        return BONUS;
    }
    else if(randomNumber < 5)
    {
        return DOUBLE;
    }
    else
    {
        return REGULAR;
    }
}
//Returns amount of points according to roundType.
int getRoundPoints(ROUNDTYPE roundType) {
    if(roundType == BONUS)
    {
        return 200;
    }
    if(roundType == DOUBLE)
    {
        return 2 * (10 * getRandomNumber(1,10));
    }
    if(roundType == REGULAR)
    {
        return 10 * getRandomNumber(1,10);
    }
    return 0;
}
//Prints player points.
void printPlayerPoints(int p1, int p2) {
    printf("P1\t: %d\n",p1);
    printf("P2\t: %d\n\n",p2);
}
//Prints other round info such as type, dice and points
void printRoundInfo(ROUNDTYPE t, int dice, int points) {
    if(t == BONUS)
    {
        printf("Type\t: BONUS\n");
    }
    else if(t == DOUBLE)
    {
        printf("Type\t: DOUBLE\n");
    }
    else if(t == REGULAR)
    {
        printf("Type\t: REGULAR\n");
    }
    else
    {
        printf("something went wrong\n");
    }
    printf("DICE\t: %d\n",dice);
    printf("POINTS\t: %d\n",points);
}
