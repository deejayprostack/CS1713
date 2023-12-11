#ifndef CHAMPION_H
#define CHAMPION_H

// Enum for Champion Role
typedef enum {
    MAGE,
    FIGHTER,
    SUPPORT,
    TANK
} ChampionRole;

// Struct for Champion
typedef struct Champion {
    ChampionRole role;
    int level;
    struct Champion* next;
} Champion;

// Function prototypes
Champion* createChampion();
Champion* addChampion(Champion* head, Champion* c);
Champion* buildChampionList(int n);
void printChampionList(Champion* head);
Champion* removeChampion(Champion* head);
Champion* destroyChampionList(Champion* head);

#endif

