#ifndef CHAMPION //Header guard
#define CHAMPION
//enum creation for Champ roles
enum ChampionRole{MAGE,FIGHTER,SUPPORT,TANK};

//Champion
struct Champion 
{
    
    int level;
    struct Champion* next; //node for linked list
    Champion* createChampion();
    Champion* addChampion(Champion *head, Champion *c);
    Champion* buildChampionList(int n);
    void printChampionList(Champion *head); 
};

#endif
