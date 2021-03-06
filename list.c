#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
const List DEFAULT_LIST = {NULL, NULL, 0, &add, &get, &index_of, &update, &delete, &clear, &insert, &extend, &reverse};
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
    // Add at back
    if(index == list->size)
    {
        add(list, data);
    }
    else
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;

        // Add at front
        if(index == 0)
        {
            newNode->next = list->head;
            list->head = newNode;
        }
        // Add in middle
        else
        {
            Node* node = list->head;
            Node* prev = node;

            while(index-- && node)
            {
                prev = node;
                node = node->next;
            }

            prev->next = newNode;
            newNode->next = node;
        }

        ++(list->size);
    }
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

    --(list->size);
    free(node);
}

void clear(List* list)
{
    while(list->head)
    {
        list->delete(list, 0);
    }
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

void extend(List* a, List* b)
{
    Node* node = b->head;

    while(node)
    {
        a->add(a, node->data);
        node = node->next;
    }
}

void reverse(List* list)
{
    int size = list->size;

    int i;
    for(i = 0; i < size/2; ++i)
    {
        int data_a = list->get(list, i);
        int data_b = list->get(list, size - i - 1);

        list->update(list, i, data_b);
        list->update(list, size - i - 1, data_a);
    }
}
