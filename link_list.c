#include <stdio.h>
#include <stdlib.h> // _Exit, qsort, exit, 
#include <string.h>
#include <stdbool.h>

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};
bool ListisEmpty(struct film const *head);
unsigned int ListItemCount(struct film *head); 
void free_list(struct film *head, struct film *current);
char *s_gets(char *st, int n);
int main (int argc, char *argv[])
{   
    struct film *head = NULL;       // Указатель на первый елемент структуры
    struct film *prev, *current;    // prev - указатель на структуру выделенную в прошлый раз
    char input[TSIZE];

    //Cбор и сохранение информации
    puts("Enter a title film: ");
    while(s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film*) malloc(sizeof(struct film)); // Выделяем память
        if(head == NULL) 
            head = current;
        else                                //Следующие структуры
            prev->next = current;           //
        current->next = NULL;               //Установка указателя следующей структуры в NULL
        strcpy(current->title, input);
        puts("Enter a value a rating: ");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Enter a new film: ");
        prev = current;                     //Предыдущая структура 
    }
    //Отображение списка фильмов
    if(head == NULL)
        printf("No data\n");
    else 
        printf("Film list: \n");
    current = head;
    while(current != NULL || ListisEmpty(head))
    {
        printf("Film: %s  Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
    printf("Items film: %d\n", ListItemCount(head));
    free_list(head, current);
    //Освобождение памяти
    /*current = head;             //Установка указателя current на голову списка
    while(current != NULL)
    {
        current = head;         //Установка указателя на голову списка
        head = current->next;   //Установка головного указателя на следующую структуру (указатель head указывает на следующую структуру)
        free(current);          //Освобождение памяти
    }
    */
    printf("\nProgramm exit...");
    return 0;
}
void free_list(struct film *head, struct film *current) // Освобождение памяти
{
    if(!ListisEmpty(head))
    {
        printf("List is empty!");
        exit(1);
    }
    current = head;
    while(current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
}
bool ListisEmpty(struct film const *head)
{
    return (head == NULL);
}
unsigned int ListItemCount(struct film *head)
{
    struct film *current;
    current = head;
    unsigned int count = 0;
    while(current)
    {
        ++count;
        current = current->next;
    }
    return count;
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