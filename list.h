#ifndef LIST_H
#define LIST_H

typedef struct Node
{
        int data;
        struct Node* next;
} Node;

typedef struct List
{
    Node* head;
    Node* tail;
    int size;
    void (*add)(struct List* list, int data);
    int (*get)(struct List* list, int index);
    int (*index_of)(struct List* list, int data);
    void (*update)(struct List* list, int index, int data);
    void (*delete)(struct List* list, int index);
    void (*insert)(struct List* list, int index, int data);
    void (*extend)(struct List* a, struct List* b);
} List;

//Create
void add(List* list, int data);
void insert(List* list, int index, int data);

//Retrieve
int get(List* list, int index);
int index_of(List* list, int data);

//Update
void update(List* list, int index, int data);

//Delete
void delete(List* list, int index);

//Other
void extend(List* a, List* b);
void print_list(List* list);

extern const List DEFAULT_LIST;
extern const int ITEM_NOT_FOUND;

#endif
