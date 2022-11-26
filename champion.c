//champion.c
//all the functions are implemented here

#include <stdio.h>
#include <stdlib.h>

#include "champion.h" //importing the champion header-file

//function to create a champion node dynamically!
Champion* createChampion()
{
    //dynamically allocate new champion
    Champion* struct1 = (Champion*) malloc(sizeof(Champion));

    //successful memory allocation check
    if(struct1==NULL) exit(EXIT_FAILURE);

    //random number selection
    int chRoleSelector = rand() % 4;

    //Role and Level selection based on number
    switch (chRoleSelector)
    {
    case 0:{
        //25% chance of MAGE
        struct1->role=MAGE;
        //Level is between 5 and 8 inclusive
        int upper = 8, lower = 5;
        struct1->level=(rand()%(upper-lower+1))+lower;
        break;}

    case 1:{
        //25% chance of FIGHTER
        struct1->role=FIGHTER;
        //Level is between 1 and 4 inclusive
        int upper = 4, lower = 1;
        struct1->level=(rand()%(upper-lower+1))+lower;
        break;}

    case 2:{
        //25% chance of SUPPORT
        struct1->role=SUPPORT;
        //Level is between 3 and 6 inclusive
        int upper = 6, lower = 3;
        struct1->level=(rand()%(upper-lower+1))+lower;
        break;}

    case 3:{
        //25% chance of TANK
        struct1->role=TANK;
        //Level is between 1 and 8 inclusive
        int upper = 1, lower = 8;
        struct1->level=(rand()%(upper-lower+1))+lower;
        break;}
    //no need for default case, as there is no chance for another random number than 0,1,2,3
    }

    //update the next link of champion 
    struct1->next = NULL;
    
    //return a pointer to the struct object
    return struct1;
}  

//function to add new champion in descending order of is value
Champion* addChampion(Champion *head, Champion *c)
{
    //check whether list is empty or not
    //if empty, adding champion is first and head
    if(head==NULL) return c;
    if(c==NULL) return head;

    //check whether the champion is to be added in the beginning
    if(c->level > head->level)
    {
        //update the next of this champion
        c->next = head;
        //new head is c now
        return c;
    }

    //find the place of this champion
    Champion* prevChampion = NULL;
    Champion* tempChampion = head;

    while(tempChampion != NULL && tempChampion->level >= c->level)
    {
        prevChampion = tempChampion;
        tempChampion = tempChampion->next;
    }

    //inserting the champion
    c->next = tempChampion;
    prevChampion->next = c;

    //head will be same head
    return head;   
}

//function to build a linked list of given number of champions
Champion* buildChampionList(int n)
{
    //storing the head
    Champion* head = NULL;

    //create n number of champions
    for(int count=0; count<n; count++)
    {
        //create a new champion
        Champion* champion = createChampion();
        //add the created champion to linked list
        head = addChampion(head,champion);
    }  
    //returning the head
    return head;
}

//function to print the champions in the linked list
void printChampionList(Champion *head)
{
    //print all champion
    Champion* tempChampion = head;
    while(tempChampion != NULL)
    {
        //print the current champion
        printChampion(tempChampion);
        //go to next champion
        tempChampion = tempChampion->next;
    }
}

//function to remove the first champion node
Champion* removeChampion(Champion *head)
{
    //check whether the head is NULL or not
    if(head==NULL) return head;

    //putting a new head node
    Champion* newHead = head->next;

    //head de-allocation
    free(head);

    //reurning the new head node
    return newHead;
}

//function to delete all nodes in the linked list
Champion* destroyChampion(Champion *head)
{
    //delete the champions again and again
    do
    {
        //delete the champion
        head=removeChampion(head);
    } while (head!=NULL);
    //returning NULL for any instances
    return NULL;   
}

//function to find the size of the linked list
int getSize(Champion* head)
{
    int size = 0;
    while(head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

//function to print the champion
void printChampion(Champion* champion)
{
    if(champion!=NULL)
    {
        char type='M';
        if(champion->role==FIGHTER) type='F';
        else if(champion->role==SUPPORT) type='S';
        else if(champion->role==TANK) type='T';
        printf("%c%d",type,champion->level);
    }
}