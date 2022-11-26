#ifndef CHAMPION //Header guard
#define CHAMPION

//enum creation for Champ roles
typedef enum ChampionRole{MAGE,FIGHTER,SUPPORT,TANK} ChampionRole;


//Champion
typedef struct Champion
{
    ChampionRole role;
    int level;
    struct Champion* next; //node for linked list
    
}Champion;


//function prototypes mentioned in the assignment
Champion* createChampion(); 
Champion* addChampion(Champion* head,Champion* c);
Champion* buildChampionList(int n);
void printChampionList(Champion *head);
Champion* removeChampion(Champion *head);
Champion* destroyChampion(Champion *head);

//extra function prototypes
int getSize(Champion* head);
void printChampion(Champion* champion);

#endif
