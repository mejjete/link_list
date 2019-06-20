#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *pList)
{
    *pList = NULL;
}

bool ListIsEmpty(const List *pList)
{
    if(pList == NULL)
        return true;
    else 
        return false;
}

bool ListIsFull(const List *pList)
{
    Node *pt;
    bool full;
    pt = (Node*) malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else 
        full = false;
    free(pt);
    return full;
}

unsigned ListItemsCount(const List *pList)
{
    unsigned int count = 0;
    Node *pnode = *pList;
    while(pnode != NULL)
    {
        count++;
        pnode = pnode->next;
    }
    return count;
}

bool AddItems(Item item, List *pList)
{
    Node *pnew;
    Node *scan = *pList;
    pnew = (Node*) malloc(sizeof(Node));
    if(pnew == NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if(scan == NULL)
        *pList = pnew;
    else 
    {
        while(scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
}

void Travers(const List *pList, void(*pfun)(Item item))
{
    Node *pnode = *pList;
    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *pList)
{
    Node *psave;
    while(*pList != NULL)
    {
        psave = (*pList)->next;
        free(*pList);
        *pList = psave;
    }
}

static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}
