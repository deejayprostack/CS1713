#include "champion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a new Champion
Champion* createChampion() {
    //Dynamically allocates a new Chamption struct object.
    Champion* newChampion = (Champion*)malloc(sizeof(Champion));

    // Assigning random role
    int roleProbability = rand() % 4;
    newChampion->role = (ChampionRole)roleProbability;

    // Assigning random level based on role
    switch (newChampion->role) {
        case MAGE:
            newChampion->level = rand() % 4 + 5; // Random number between 5 and 8
            break;
        case FIGHTER:
            newChampion->level = rand() % 4 + 1; // Random number between 1 and 4
            break;
        case SUPPORT:
            newChampion->level = rand() % 4 + 3; // Random number between 3 and 6
            break;
        case TANK:
            newChampion->level = rand() % 8 + 1; // Random number between 1 and 8
            break;
    }

    newChampion->next = NULL;
    return newChampion;
}

// Function to add a new Champion to the linked list in descending order of level
Champion* addChampion(Champion* head, Champion* c) {
    if (head == NULL || c->level > head->level) {
        c->next = head;
        return c;
    }

    Champion* current = head;
    while (current->next != NULL && current->next->level > c->level) {
        current = current->next;
    }

    c->next = current->next;
    current->next = c;

    return head;
}

// Function to build a list of champions using a linked list
Champion* buildChampionList(int n) {
    Champion* head = NULL;
    for (int i = 0; i < n; i++) {
        Champion* newChampion = createChampion();
        head = addChampion(head, newChampion);
    }
    return head;
}

// Function to print the entire list of champions
void printChampionList(Champion* head) {
    Champion* current = head;

    while (current != NULL) {
        switch (current->role) {
            case MAGE:
                printf("M%d ", current->level);
                break;
            case FIGHTER:
                printf("F%d ", current->level);
                break;
            case SUPPORT:
                printf("S%d ", current->level);
                break;
            case TANK:
                printf("T%d ", current->level);
                break;
        }
        current = current->next;
    }
}
// Function to remove and deallocate the first node in the linked list
Champion* removeChampion(Champion* head) {
    if (head == NULL) {
        return NULL;
    }

    Champion* newHead = head->next;
    free(head);

    return newHead;
}

// Function to destroy the linked list and free memory
Champion* destroyChampionList(Champion* head) {
    while (head != NULL) {
        head = removeChampion(head);
    }
    return NULL;
}
