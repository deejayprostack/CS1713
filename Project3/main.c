#include "champion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the winner of a battle and apply rewards/punishments
void battleOutcome(Champion** player1, Champion** player2) {
    // *player1 = removeChampion(*player1);
    // *player2 = removeChampion(*player2);
    // printf("BATTLE OUTCOME\n");
    // return;
    if ((*player1)->role == MAGE) {
        if ((*player2)->role == MAGE) {
            printf("Player 1 is a MAGE and PLAYER 2 is a MAGE\n");
            if ((*player1)->level > (*player2)->level) {
  
                // Player 1 wins
                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                printf("Player 2 (MAGE) loses one champion.\n");

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = addChampion((*player1), createChampion());
                *player2 = removeChampion(*player2);

            } else if ((*player1)->level < (*player2)->level) {

                // Player 2 wins
                printf("Player 2 (MAGE) wins and gains a new champion.\n");
                printf("Player 1 (MAGE) losses one champion.\n");

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player2 = addChampion((*player2), createChampion());
                *player1 = removeChampion(*player1);

            }
              if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 
        } else if ((*player2)->role == FIGHTER) {
            printf("Player 1 is a MAGE and PLAYER 2 is a FIGHTER\n");
            if ((*player1)->level > (*player2)->level) {

                // Player 1 wins
                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                printf("Player 2 (FIGHTER) losses but with no penalty.\n");

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = addChampion((*player1), createChampion());
            } else if ((*player1)->level < (*player2)->level) {

                // Player 2 wins
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins but with no reward.\n");  

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = removeChampion(*player1);
            }
            if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 

        } else if ((*player2)->role == SUPPORT) {
            printf("Player 1 is a MAGE and PLAYER 2 is a SUPPORT\n");
            if ((*player1)->level > (*player2)->level) {

                // Player 1 wins
                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                printf("Player 2 (SUPPORT) loses two champion.\n");  

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = addChampion((*player1), createChampion());
                *player2 = removeChampion(*player2);
                *player2 = removeChampion(*player2);

            } else if ((*player1)->level < (*player2)->level) {

                // Player 2 wins  
                printf("Player 1 (MAGE) loses the next champion.\n");
                printf("Player 2 (SUPPORT) wins and gains two champions.\n");   

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = removeChampion(*player1);
                *player1 = removeChampion(*player1);
                *player2 = addChampion((*player2), createChampion());
            }
              if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 
            
        } else if ((*player2)->role == TANK) {
            printf("Player 1 is a MAGE and PLAYER 2 is a TANK\n");
            printf("Player 1 (MAGE) wins and gains a new champion.\n");
            printf("Player 2 (TANK) loses the next champion.\n");   

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            //Reward/Punishment
            *player2 = removeChampion(*player2);
            *player1 = addChampion((*player1), createChampion());
        }

    } else if ((*player1)->role == FIGHTER) {
        if ((*player2)->role == FIGHTER) {
            printf("Player 1 is a FIGHTER and PLAYER 2 is a FIGHTER\n");
            printf("Both players gain a new champion.\n");            
            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            //Reward/Punishment
            *player1 = addChampion(*player1, createChampion());
            *player2 = addChampion(*player2, createChampion());

        } else if ((*player2)->role == SUPPORT) {
            printf("Player 1 is a FIGHTER and PLAYER 2 is a SUPPORT\n");
            if ((*player1)->level > (*player2)->level) {
                
                // Player 1 wins
                printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                printf("Player 2 (SUPPORT) loses the next champion.\n");   

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player2 = removeChampion(*player2);

            } else if ((*player1)->level < (*player2)->level) {
                // Player 2 wins
                printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                printf("Player 2 (SUPPORT) wins and gains one new champion.\n"); 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player2 = addChampion((*player2), createChampion());
            }
              if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 

        } else if ((*player2)->role == TANK) {
            printf("Player 1 is a FIGHTER and PLAYER 2 is a TANK\n");
            printf("Player 1 (FIGHTER) wins and gains one new champion.\n");
            printf("Player 2 (TANK) loses but with no penalty.\n"); 

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            //Reward/Punishment
            *player1 = addChampion((*player1), createChampion());
        } else if ((*player2)->role == MAGE){
            printf("Player 1 is FIGHTER and Player 2 is MAGE\n");
             if ((*player1)->level > (*player2)->level) {
                // Player 1 wins
            printf("Player 1 (FIGHTER) wins but with no reward.\n");
            printf("Player 2 (MAGE) loses one champion.\n"); 

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player2 = removeChampion(*player2);
            } else if ((*player1)->level < (*player2)->level) {
                // Player 2 wins
             printf("Player 1 (FIGHTER) losses but with no penalty.\n");
             printf("Player 2 (MAGE) wins and gains a new champion.\n");                                
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player2 = addChampion((*player2), createChampion());
            }
              if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward\n");  
              } 

        }

    } else if ((*player1)->role == SUPPORT) {
        if ((*player2)->role == SUPPORT) {
            printf("Player 1 is a SUPPORT and PLAYER 2 is a SUPPORT\n");
            
            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            // Both players lose one champion
            printf("Both players lose one champion\n");
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

        } else if ((*player2)->role == TANK) {
            printf("Player 1 is a SUPPORT and PLAYER 2 is a TANK\n");
            
            printf("Player 1 (SUPPORT) losses but with no penalty.\n");
            printf("Player 2 (TANK) wins and gains a new champion.\n");   

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);
            //Reward/Punishment
            *player2 = addChampion((*player2), createChampion());

        } else if((*player2)->role == MAGE){
            printf("Player 1 is a SUPPORT and PLAYER 2 is a MAGE\n");
            if ((*player1)->level > (*player2)->level) {

                // Player 1 wins
                printf("Player 1 (SUPPORT) wins and gains two champions.\n");
                printf("Player 2 (MAGE) loses one champion.\n");                                   
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = addChampion((*player1), createChampion());
                *player1 = addChampion((*player1), createChampion());
                *player2 = removeChampion(*player2);
    
            } else if ((*player1)->level < (*player2)->level) {
                // Player 2 wins  
                printf("Player 1 (SUPPORT) loses two champions.\n");
                printf("Player 2 (MAGE) wins and gains one champion.\n");  

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = removeChampion(*player1);
                *player1 = removeChampion(*player1); // Remove one champion from MAGE
                *player2 = addChampion(*player2, createChampion());
            }
            if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 
        } else if((*player2)->role == FIGHTER){
            printf("Player 1 is a SUPPORT and PLAYER 2 is a FIGHTER\n");
            if ((*player1)->level > (*player2)->level) {

                // Player 1 wins
                printf("Player 1 (SUPPORT) wins and gains one champion.\n");
                printf("Player 2 (FIGHTER) loses but with no penalty.\n");                                   
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = addChampion((*player1), createChampion());
    
            } else if ((*player1)->level < (*player2)->level) {
                // Player 2 wins  
                printf("Player 1 (SUPPORT) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins but gains no reward.\n");  

                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);

                //Reward/Punishment
                *player1 = removeChampion(*player1);
            }
              if ((*player1)->level == (*player2)->level) { 
                // Remove deployed champions from the players' lists
                *player1 = removeChampion(*player1);
                *player2 = removeChampion(*player2);  
                printf("Nothing happens - no penalty or reward");  
              } 
        }

    } else if ((*player1)->role == TANK) {
        if ((*player2)->role == TANK) {
        printf("Player 1 is TANK and Player 2 is TANK\n");
        printf("Nothing happens - no penalty or reward");
            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);   
        } else if((*player2)->role == FIGHTER){
            printf("Player 1 is a TANK and PLAYER 2 is a FIGHTER\n");
            printf("Player 1 (TANK) loses but with no penalty \n");
            printf("Player 2 (FIGHTER) wins and gains one new champion.\n"); 

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

             //Reward/Punishment
            *player2 = addChampion(*player2, createChampion());           
        } else if ((*player2)->role == SUPPORT){
             printf("Player 1 is a TANK and PLAYER 2 is a SUPPORT\n");

            printf("Player 1 (TANK) wins and gains a new champion.\n");
            printf("Player 2 (SUPPORT) losses but with no penalty.\n");

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            //Reward/Punishment
            *player1 = addChampion((*player1), createChampion());

        }else if((*player2)->role == MAGE){
            printf("Player 1 is a TANK and PLAYER 2 is a MAGE\n");
            printf("Player 1 (TANK) loses the next champion.\n");
            printf("Player 2 (MAGE) wins and gains a new champion.\n");    

            // Remove deployed champions from the players' lists
            *player1 = removeChampion(*player1);
            *player2 = removeChampion(*player2);

            //Reward/Punishment
            *player1 = removeChampion(*player2);
            *player2 = addChampion((*player2), createChampion());

        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of champions>\n", argv[0]);
        return 1;
    }

    int numChampions = atoi(argv[1]);
    if (numChampions <= 0) {
        printf("Number of champions must be greater than 0.\n");
        return 1;
    }

    srand(4); //For testing purposes, 4;
    //Building the player fighter lists
    Champion* player1 = buildChampionList(numChampions);
    Champion* player2 = buildChampionList(numChampions);

    //Game Code, starts at round 1 and continues till a tie or one player has no champions left
    int round = 1;
    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
    while (player1 != NULL && player2 != NULL) {
        printf("----- ROUND %d -----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("\n");
        printf("Player 2: ");
        printChampionList(player2);
        printf("\n");

        // Implement the outcomes for each permutation of Champion roles here
        battleOutcome(&player1, &player2);

        printf("\n");
        round++;
    }

    printf("\n============ GAME OVER =============\n\n");
    printf("Player 1 ending champion list: ");
    printChampionList(player1);
    printf("\n");
    printf("Player 2 ending champion list: ");
    printChampionList(player2);
    printf("\n");

    if (player1 == NULL && player2 == NULL) {
        printf("TIE -- both players ran out of champions.\n");
    } else {
        if (player1 == NULL) {
            printf("Player 1 ran out of champions. Player 2 wins.\n");
        } else {
            printf("Player 2 ran out of champions. Player 1 wins.\n");
        }
    }

    // Free memory
    player1 = destroyChampionList(player1);
    player2 = destroyChampionList(player2);

    return 0;
}
