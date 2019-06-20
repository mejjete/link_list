#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void showmovies(Item item);
char *s_gets(char *st, int n);

int main(void)
{
    List movies; // movies это указатель, поэтому после сначала нужно выделить память под новый тип = (Node*) malloc(sizeof(Node))
    Item temp;
    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr, "All memory if Full! Exiting...");
        exit(1);
    }
    
    puts("Enter a title film: ");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {         
        puts("Enter a value a rating: ");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        if(AddItems(temp, &movies) == false)
        {
            fprintf(stderr, "Problem Allocaltion Memory!\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("List if Full.");
            break;
        }
        puts("Enter a title next film: ");
    }
    if(ListIsEmpty(&movies))
        printf("No data");
    else 
    {
        printf("List film: \n");
        Travers(&movies, showmovies);
    }
    printf("You enter a %d films\n", ListItemsCount(&movies));
    EmptyTheList(&movies);
    printf("Program finish");
}
char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
void showmovies(Item item)
{
    printf("Films: %s\tRating: %d\n", item.title, item.rating);
}