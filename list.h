#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef Node *List;

void InitializeList(List *pList);
bool ListIsEmpty(const List *pList);
bool ListIsFull(const List *pList);
unsigned ListItemsCount(const List *pList);
bool AddItems(Item item, List *pList);
void Travers(const List *pList, void (*pfun) (Item item));
void EmptyTheList(List *pList);

#endif