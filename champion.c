#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "champion.h" //importing the champion header-file

struct Champion* createChampion()
{
    struct Champion* struct1 = NULL; //creating a pointer

    struct1 = (struct Champion*) malloc(sizeof(struct Champion)); //dynamically allocates new Champion struct

    srand(time(NULL));
    int chRoleSelector = rand() % 4; //random role selection

    //ROLE assigning randomly
    switch (chRoleSelector)
    {
    case 0:{
        struct1->role=MAGE;
        break;}
    case 1:{
        struct1->role=FIGHTER;
        break;}
    case 2:{
        struct1->role=SUPPORT;
        break;}
    case 3:{
        struct1->role=TANK;
        break;}
    default:
        {break;}
    }

    //level assigning according to the roles
    switch(struct1->role)
    {
        case MAGE:{
            int upper = 8, lower = 5;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case FIGHTER:{
            int upper = 4, lower = 1;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case SUPPORT:{
            int upper = 6, lower = 3;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case TANK:{
            int upper = 1, lower = 8;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        default:
            {break;}
    }
    
    //return a pointer to the struct object
    return (&struct1);
}  

struct Champion* addChampion(struct Champion *head, struct Champion *c)
{

}

struct Champion* buildChampionList(int n)
{

}

void printChampionList(struct Champion *head)
{

}

 