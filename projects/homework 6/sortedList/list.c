#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

List* createList(List* list)
{
    return calloc(1, sizeof(List));
}

Position* createPosition(List* list)
{
    Position* position = calloc(1, sizeof(Position));
    position->position = list->head;
    return position;
}

void positionToHead(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return;
    }
    position->position = list->head;
}

void positionToNext(Position* position)
{
    if (position == NULL)
    {
        return;
    }
    position = position->position->next;
}

bool isPositionNull(Position* position)
{
    return position == NULL || position->position == NULL;
}

void deletePosition(Position* position)
{
    free(position);
}

int getValue(Position* position)
{
    if (position == NULL || position->position == NULL)
    {
        return 0;
    }
    return position->position->value;
}

void addElement(List* list, const int value)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* element = list->head;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (element == NULL)
    {
        list->head = newElement;
        return;
    }
    if (value < element->value)
    {
        newElement->next = element;
        list->head = newElement;
        return;
    }
    while (element->next != NULL && value < element->next->value)
    {
        element = element->next;
    }
    if (element->next == NULL)
    {
        element->next = newElement;
    }
    else
    {
        newElement->next = element->next;
        element->next = newElement;
    }
    return;

}

void deleteElement(List* list, const int value)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* element = list->head;
    if (element == NULL)
    {
        return;
    }
    if (element->value == value)
    {
        list->head = element->next;
        free(element);
        return;
    }
    while (element->next != NULL && value <= element->next->value)
    {
        if (element->next == value)
        {
            ListElement* temp = element->next;
            element->next = element->next->next;
            free(temp);
            return;
        }
        element = element->next;
    }
    return;
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        return;
    }
    while (list->head != NULL)
    {
        ListElement* newListElement = list->head->next;
        free(list->head);
        list->head = newListElement;
    }
    return;
}