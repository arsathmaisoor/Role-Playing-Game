#include <stdio.h>

#include "champion.h"
#include "champion.c"

int main(int argc)
{
    struct Champion* player1=NULL;
    struct Champion* player2=NULL;


    if(argc)
    {
        if(argc>0)
        {
            int roundNumber=1;
            player1 = buildChampionList(argc);
            player2 = buildChampionList(argc);
            printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
            while((player1 != NULL) && (player2 != NULL))
            {
                printf("----- ROUND %d -----\n",roundNumber);
                printChampionList(player1);
                printf("\n");
                printChampionList(player2);
                printf("\n");
                printf("Player 1 is a %")
                roundNumber++;
            }

        }
        else
        {
            printf("ERROR : GIVEN NUMBER IS NOT GREATER THAN 0");
        }
    }
    else
    {
        printf("ERROR : COMMAND LINE ARGUMENT DOES NOT EXIST\n");
    }
}
