//main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "champion.h"
#include "champion.c"


//function to print the ending champions
void printEndingChampions(Champion* player1, Champion* player2)
{
    //print ending champions
    printf("======GAME OVER======\n");
    printf("Player 1 ending champion list : ");
    printChampionList(player1);
    printf("\n");
    printf("Player 2 ending champion list : ");
    printChampionList(player2);
    printf("\n");
}

//check whether game is still on or not
//if not, the finish the game
bool isGameRunning(Champion* player1, Champion* player2)
{
    //get the size of champion list
    int size1 = getSize(player1);
    int size2 = getSize(player2);

    //check the size of both champion list
    if(size1==0 && size2==0)
    {
        //both are lose
        printEndingChampions(player1,player2);
        printf("\nTIE -- both players ran out of champions.");
        return false;
    }
    else if(size1==0)
    {
        //player1 is lost
        printEndingChampions(player1,player2);
        printf("\nPlayer 1 ran out of champions. Player 2 wins.");
        return false;
    }
    else if(size2==0)
    {
        //player2 is lost
        printEndingChampions(player1,player2);
        printf("\nPlayer 2 ran out of champions. Player 1 wins.");
        return false;
    }

    //if above conditions are not true, game is still on
    return true;
}

//main function
int main(int argc, char const *argv[])
{
    //the random number generator
    srand(time(NULL));

    //check the number of command line arguments
    if(argc != 2)
    {
        printf("ERROR: INVALID COUNT OF COMMAND LINE ARGUMENTS");
        exit(EXIT_SUCCESS);
    }
    else
    {
        //getting the number and convert into integer
        int n = atoi(argv[1]);
        
        //check the n is positive number or not
        if(n>0)
        {
            //game starts!
            printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");

            //generate champions for player1 and player2
            Champion* player1 = buildChampionList(n);
            Champion* player2 = buildChampionList(n);

            //game begins here
            int round=0;
            while(true)
            {
                //print the round number and other information
                printf("----- ROUND %d -----\n", ++round);
                printf("Player 1 : ");
                printChampionList(player1);
                printf("\n");
                printf("Player 2 : ");
                printChampionList(player2);
                printf("\n");
                printf("Player 1 is a ");
                printChampion(player1);
                printf(" and Player 2 is a ");
                printChampion(player2);
                printf("\n");

                //get the type of player1's champion
                ChampionRole role1 = player1->role;
                //get the type of player2's champion
                ChampionRole role2 = player2->role;

                //get the level of player1's champion
                int level1 = player1->level;
                //get the level of player2's champion
                int level2 = player2->level;

                //remove the first champion from player 1
                player1 = removeChampion(player1);
                //remove the first champion from player 2
                player2 = removeChampion(player2);

                //Decision making according to fight roles
                if(role1==MAGE && role2==MAGE)
                {
                    //MM fight
                    if(level1>level2)
                    {
                        printf("Player 1 (MAGE) wins and gains one champion.\nPlayer 2 (MAGE) loses one champion.\n");
                        Champion* champion = createChampion();
                        player1 = addChampion(player1,champion);
                        player2 = removeChampion(player2);
                    }
                    else if (level1<level2)
                    {
                        printf("Player 1 (MAGE) loses one champion.\nPlayer 2 (MAGE) wins and gains one champion.\n");
                        Champion* champion = createChampion();
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2,champion);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS\n");
                    }
                }
                else if (role1 == MAGE && role2 == FIGHTER)
                {
                    //MF fight
                    if(level1>level2)
                    {
                        printf("Player 1 (MAGE) wins and gains one champion.\nPlayer 2 (FIGHTER) loses with no penalty.\n");
                        Champion* champion = createChampion();
                        player1=addChampion(player1,champion);
                    }
                    else if (level1<level2)
                    {
                        printf("Player 1 (MAGE) loses one champion\nPlayer 2 (FIGHTER) wins and gains no reward.\n");
                        player1=removeChampion(player1);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS\n");
                    }
                }
                else if (role1 == MAGE && role2 == SUPPORT)
                {
                    //MS fight
                    if (level1>level2)
                    {
                        printf("Player 1 (MAGE) wins and gains one champion.\nPlayer 2 (SUPPORT) loses two champions.\n");
                        Champion* champion = createChampion();
                        player1 = addChampion(player1,champion);
                        player2 = removeChampion(player2);
                        player2 = removeChampion(player2);
                    }
                    else if (level1<level2)
                    {
                        printf("Player 1 (MAGE) loses  one champion.\nPlayer 2 (MAGE) wins and gains two champions.\n");
                        player1 = removeChampion(player1);
                        Champion* champion1 = createChampion();
                        Champion* champion2 = createChampion();
                        player2 = addChampion(player2,champion1);
                        player2 = addChampion(player2,champion2);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS\n");
                    }
                }
                else if (role1 == MAGE && role2 == TANK)
                {
                    //MT fight
                    printf("Player 1 (MAGE) wins and gains one champion.\nPlayer 2 (TANK) loses one champion.\n");
                    Champion* champion = createChampion();
                    player1 = addChampion(player1,champion);
                    player2 = removeChampion(player2);
                }
                else if (role1 == FIGHTER && role2 == FIGHTER)
                {
                    //FF fight
                    printf("Player 1 (FIGHTER) and Player 2 (FIGHTER) gains a new champion.\n");
                    Champion* champion1 = createChampion();
                    Champion* champion2 = createChampion();
                    player1 = addChampion(player1,champion1);
                    player2 = addChampion(player2,champion2);
                }
                else if (role1==FIGHTER && role2==SUPPORT)
                {
                    //FS fight
                    if(level1>level2)
                    {
                        printf("Player 1 (FIGHTER) wins with no rewards.\nPlayer 2 (SUPPORT) loses one champion.\n");
                        player2=removeChampion(player2);
                    }
                    else if(level1<level2)
                    {
                        printf("Player 1 (FIGHTER) loses  with no penalty.\nPlayer 2 (SUPPORT) wins and gains one champion.\n");
                        Champion* champion = createChampion();
                        player2 = addChampion(player2,champion);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS/n");
                    }
                }
                else if (role1==FIGHTER && role2==TANK)
                {
                    //FT fight
                    printf("Player 1 (FIGHTER) wins and gains  one champion.\nPlayer 2 (TANK) loses with no penalty.\n");
                    Champion* champion = createChampion();
                    player1 = addChampion(player1,champion);
                }
                else if (role1==FIGHTER && role2==MAGE)
                {
                    //FM fight
                    if (level1>level2)
                    {
                        printf("Player 1 (FIGHTER) wins  with no reward.\nPlayer 2 (MAGE) loses one champion.\n");
                        player1 = removeChampion(player1);
                    }
                    else if (level1<level2)
                    {
                        printf("Player 1 (FIGHTER) loses  with no penalty.\nPlayer 2 (MAGE) wins and gains one champion.\n");
                        Champion* champion = createChampion();
                        player2 = addChampion(player2,champion);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS\n");
                    }
                }
                else if(role1 == SUPPORT && role2==MAGE)
                {
                    //SM fight
                    if(level1>level2)
                    {
                        printf("Player 1 (SUPPORT) wins and gains two champions.\nPlayer 2 (MAGE) lose one champion.\n");
                        Champion* champion1 = createChampion();
                        Champion* champion2 = createChampion();
                        player1 = addChampion(player1,champion1);
                        player1 = addChampion(player1,champion2);
                        player2 = removeChampion(player2);

                    }
                    else if(level1<level2)
                    {
                        printf("Player 1 (SUPPORT) loses two champions.\nPlayer 2 (MAGE) wins and gains one champion.\n");
                        Champion* champion = createChampion();
                        player1 = removeChampion(player1);
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2,champion);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS\n");
                    }
                }
                else if(role1 == SUPPORT && role2==FIGHTER)
                {
                    //SF fight
                    if(level1>level2)
                    {
                        printf("Player 1 (SUPPORT) wins and gains one champion.\nPlayer 2 (FIGHTER) loses with no penalty.\n");
                        Champion* champion = createChampion();
                        player1 = addChampion(player1,champion);
                    }
                    else if(level1<level2)
                    {
                        printf("Player 1 (SUPPORT) loses one champion.\nPlayer 2 (FIGHTER) won with no rewards.\n");
                        player1 = removeChampion(player1);
                    }
                    else
                    {
                        printf("TIE. NOTHING HAPPENS");
                    }
                }
                else if(role1==SUPPORT && role2==SUPPORT)
                {
                    //SS fight
                    printf("Player 1 (SUPPORT) and Player 2 (SUPPORT) loses one champion.\n");
                    player1=removeChampion(player1);
                    player2=removeChampion(player2);
                }
                else if(role1==SUPPORT && role2==TANK)
                {
                    //ST fight
                    printf("Player 1 (SUPPORT) loses with no penalty.\nPlayer 2 (TANK) wins and gains a new champion.\n");
                    Champion* champion = createChampion();
                    player2 = addChampion(player2,champion);
                }
                else if(role1==TANK && role2==MAGE)
                {
                    //TM fight
                    printf("Player 1 (TANK) loses one champion.\nPlayer 2 (MAGE) wins and gains one champion.\n");
                    player1 = removeChampion(player1);
                    Champion* champion = createChampion();
                    player2 = addChampion(player2,champion);
                }
                else if(role1==TANK && role2==FIGHTER)
                {
                    //TF fight
                    printf("Player 1 (TANK) loses with no penalty.\nPlayer 2 (FIGHTER) wins and gains one champion.\n");
                    Champion* champion = createChampion();
                    player2 = addChampion(player2,champion);
                }
                else if(role1==TANK && role2==SUPPORT)
                {
                    //TS fight
                    printf("Player 1 (TANK) wins and gains one champion.\nPlayer 2 (SUPPORT) loses with no penalty.\n");
                    Champion* champion = createChampion();
                    player1 = addChampion(player1,champion);
                }
                else
                {
                    //TT fight
                    printf("Nothing happens. No penalty or reward\n");
                }
                //game finished check
                if(!isGameRunning(player1,player2))
                {
                    //destroy champions of both
                    destroyChampion(player1);
                    destroyChampion(player2);
                    //end the game
                    break;
                }
            }
        }
    }
    //termination successful
    return 0;
}
