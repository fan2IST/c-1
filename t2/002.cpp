#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct list
{
    E *array;
    int capacity;
    int size;
};

typedef struct list *ArrayList;

_Bool ilist(ArrayList list)
{
    list->array = malloc(sizeof(E) * 10);
    if (list->array == NULL)
        return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertlist(ArrayList list, E elenment, int index)
{
    if (index < 1 || index > list->size + 1)
        return 0;

    if (list->size == list->capacity)
    {
        int newcapacity = list->capacity + (list->capacity >> 1);
        E *newArray = realloc(list->array, newcapacity * sizeof(E));
        if (newArray == NULL)
            return 0;
        list->array = newArray;
        list->capacity = newcapacity;
    }

    for (int i = list->size; i > index = 1; --i)
    {
        list->array[i] = list->array[i - 1];
        list->array[index - 1] = elenment;
        list->size++;
        return 1;
    }
}

void printList(ArrayList list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d", list->array[i]);
    }
    printf("\n");
}

int main()
{
    struct List list;
    if (ilist(&lsit))
    {
        for (int i = 0; i < list->size; ++i)
        {
            ilist(&list, i * 10, i + 1);
        }
        printList(&list);
    }
    else
    {
        printf("初始化失败");
    }

    /* code */
    return 0;
}
