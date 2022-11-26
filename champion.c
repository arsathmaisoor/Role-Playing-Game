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
        struct1->role=M;
        break;}
    case 1:{
        struct1->role=F;
        break;}
    case 2:{
        struct1->role=S;
        break;}
    case 3:{
        struct1->role=T;
        break;}
    default:
        {break;}
    }

    //level assigning according to the roles
    switch(struct1->role)
    {
        case M:{
            int upper = 8, lower = 5;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case F:{
            int upper = 4, lower = 1;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case S:{
            int upper = 6, lower = 3;
            struct1->level=(rand()%(upper-lower+1))+lower;
            break;}
        case T:{
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
    struct Champion* temp;
    c = createChampion();
    temp = head;
    
    while (temp->next->level > c->level)
    {
        temp = temp->next;
    }
    
    c->next = temp->next;
    temp->next = c;
}

struct Champion* buildChampionList(int n)
{
    struct Champion* head = NULL;
    //struct Champion* p;
    struct Champion* c;
    c = createChampion();
     
    if (head == NULL)
    {
        head = c;
    } 
    else
    {
        addChampion(head,c);
    }
    
}

void printChampionList(struct Champion *head)
{
    struct Champion* temp = head;
    while (temp != NULL)
    {
        int roLe = temp->role;
        switch(roLe)
        {
            case 0 :{
                printf("M");
                break;}
            case 1 :{
                printf("F");
                break;}
            case 2 :{
                printf("S");
                break;}
            case 3 :{
                printf("T");
                break;}
            default:{break;}
        }
        printf(temp->level);
        printf("\t");
    }
}

struct Champion* removeChampion(struct Champion *head)
{
    struct Champion* temp;
    temp = head;
    head->next = head->next->next;
}

struct Champion* destroyChampion(struct Champion *head)
{
    struct Champion* temp = head;
    struct Champion* current;
    while(temp != NULL)
    {
        if(temp==NULL)
        break;
        else{
            current = temp;
            temp = temp->next;
            delete current;
        }
    }
}

