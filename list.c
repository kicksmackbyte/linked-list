#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
const List DEFAULT_LIST = {NULL, NULL, 0, &add, &get, &index_of, &update, &delete, &insert};
const int ITEM_NOT_FOUND = -1;

void add(List* list, int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if(!list->head)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    ++(list->size);
}

void insert(List* list, int index, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;

    Node* node = list->head;
    Node* prev = node;

    while(index && node)
    {
        --index;
        prev = node;
        node = node->next;
    }

    prev->next = newNode;
    newNode->next = node;
}

int get(List* list, int index)
{
    Node* node = list->head;

    while(index && node)
    {
        --index;
        node = node->next;
    }

    assert(node);
    return node->data;
}

int index_of(List* list, int data)
{
    Node* node = list->head;
    int index = 0;

    while(node)
    {
        if(node->data == data)
        {
            return index;
        }

        ++index;
        node = node->next;
    }

    return ITEM_NOT_FOUND;
}

void update(List* list, int index, int data)
{
    Node* node = list->head;

    while(index && node)
    {
        --index;
        node = node->next;
    }

    assert(node);
    node->data = data;
}

void delete(List* list, int index)
{
    Node* node = list->head;
    Node* prev = node;

    while(index && node)
    {
        --index;
        prev = node;
        node = node->next;
    }

    if(node == list->head && node == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else if(node == list->head)
    {
        list->head = list->head->next;
    }
    else if(node == list->tail)
    {
        list->tail = prev;
        list->tail->next = NULL;
    }
    else
    {
        prev->next = node->next;
    }

    free(node);
}

void print_list(List* list)
{
    Node* node = list->head;

    printf("\n");
    while(node)
    {
        if(node != list->head)
        {
            printf(", ");
        }

        printf("%d", node->data);
        node = node->next;
    }
}
