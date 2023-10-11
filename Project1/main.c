#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

int main() {

    // Initialize the srand() to start the random generator
    srand(1); //Have this a 1 for testing purposes.
	// Initialize the player-1 and player-2 points to 0
    int player1 = 0;
    int player2 = 0;
	// Initialize all other required variables
    int roundCount;
    int currentPlayer;
	// scanf the user for the number of rounds to run the game
    printf("Enter the number of rounds: ");
    scanf("%d", &roundCount);
	// Call printPlayerPoints() function to print the initial player points which will be 0
    printPlayerPoints(player1, player2);
    // Determine the starting player randomly
    //I will be doing a random with a range to 1-2 to quickly decide who goes first.
    int random_start = rand() % 2 + 1; 
    if(random_start == 1)
    {
        currentPlayer = 1; //Player1 goes first
    }
    if(random_start == 2)
    {
        currentPlayer = 2; //Player2 goes first
    }

    // Set up the loop to go through all the rounds one at a time
     for(int i = 1; i <= roundCount; i++){
        		// Call the corresponding functions to get the information for this round - type, dice, points
                ROUNDTYPE type = getRoundType();
                int dice = getRandomNumber(0,6);
                int points = getRoundPoints(type);
                // Print round number
                printf("ROUND %d\n-------- \n",i);
                // Print current player
                if(currentPlayer == 1)
                {
                    printf("Player   : 1\n");
                }
                if(currentPlayer == 2)
                {
                    printf("Player   : 2\n");
                }
                // Call printRoundInfo() to print the round information
                printRoundInfo(type,dice,points);



                // MAIN GAME LOGIC
                // Write code here to get the main game logic using branches
                // Success: Player-1 (odd player) is the current player and the dice rolled is odd
                if((currentPlayer == 1) && (dice % 2 == 1))
                {
                    player1 += points;
                }
                // OR Player-2 (even player) is the current player and the dice rolled is even.
                if((currentPlayer == 2) && (dice % 2 == 0))
                {
                    player2 += points;
                }
                // Current player gains the points, based on the type of the round (see above). The current player’s turn continues in the next round.

                // Failure: Player-1 (odd player) is the current player and the dice rolled is even
                if((currentPlayer == 1) && (dice % 2 == 0))
                {
                    player1 -= points;
                }
                // OR Player-2 (even player) is the current player and the dice rolled is odd.
                if((currentPlayer == 2) && (dice % 2 == 1))
                {
                    player2 -= points;
                }
                // Current player incurs penalty of the same number of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
                if(currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else if(currentPlayer == 2)
                {
                    currentPlayer = 1;
                }
                // Call printPlayerPoints() to print the player information at the end of the round
                printPlayerPoints(player1,player2);

     }


    printf("\nGame Over!\n");

    // Print the winner as the one with higher points
    if(player1 > player2)
    {
        printf("P1 Won\n");
    }
    else if(player2 > player1)
    {
        printf("P2 Won\n");
    }
    else
    {
        printf("Either a Tie or a mistake\n");
    }

	// Return from the main() function to end the program successfully
    return 0;
}
