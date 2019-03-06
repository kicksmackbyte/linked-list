#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void _test_list(List* list, int data[], int size)
{
    assert(list);
    assert(list->size == size);

    if(size == 0)
    {
        assert(list->head == NULL);
        assert(list->tail == NULL);
    }
    else if(size == 1)
    {
        assert(list->head != NULL);
        assert(list->tail != NULL);
        assert(list->head == list->tail);
        assert(list->head->data == data[0]);
    }
    else
    {
        assert(list->head != NULL);
        assert(list->tail != NULL);
        assert(list->head != list->tail);

        int nodesTraversed = 0;
        Node* nodePtr = list->head;
        while(nodePtr)
        {
            assert(nodePtr->data == data[nodesTraversed]);

            nodePtr = nodePtr->next;
            ++nodesTraversed;
        }

        assert(nodesTraversed == size);
    }
}

void test_add()
{
    int data[] = {8, 6, 7, 5, 3, 0, 9};
    List list = DEFAULT_LIST;

    //empty list
    _test_list(&list, data, 0);

    list.add(&list, 8);
    _test_list(&list, data, 1);

    list.add(&list, 6);
    _test_list(&list, data, 2);

    list.add(&list, 7);
    _test_list(&list, data, 3);

    list.add(&list, 5);
    _test_list(&list, data, 4);

    list.add(&list, 3);
    _test_list(&list, data, 5);

    list.add(&list, 0);
    _test_list(&list, data, 6);

    list.add(&list, 9);
    _test_list(&list, data, 7);
}

void test_insert()
{
}

void test_get()
{
    int data;
    List list = DEFAULT_LIST;

    //list.get(&list, 0); //make sure this crashes

    list.add(&list, 8);
    data = list.get(&list, 0);
    assert(data == 8);

    list.add(&list, 6);
    data = list.get(&list, 0);
    assert(data == 8);
    data = list.get(&list, 1);
    assert(data == 6);

    list.add(&list, 7);
    data = list.get(&list, 0);
    assert(data == 8);
    data = list.get(&list, 1);
    assert(data == 6);
    data = list.get(&list, 2);
    assert(data == 7);

    //list.get(&list, 3); //make sure this crashes
}

void test_index_of()
{
    int index = ITEM_NOT_FOUND;
    List list = DEFAULT_LIST;

    index = list.index_of(&list, 8);
    assert(index == ITEM_NOT_FOUND);

    list.add(&list, 8);
    index = list.index_of(&list, 8);
    assert(index == 0);
    index = list.index_of(&list, 6);
    assert(index == ITEM_NOT_FOUND);

    list.add(&list, 6);
    index = list.index_of(&list, 8);
    assert(index == 0);
    index = list.index_of(&list, 6);
    assert(index == 1);
    index = list.index_of(&list, 7);
    assert(index == ITEM_NOT_FOUND);

    list.add(&list, 7);
    index = list.index_of(&list, 8);
    assert(index == 0);
    index = list.index_of(&list, 6);
    assert(index == 1);
    index = list.index_of(&list, 7);
    assert(index == 2);
    index = list.index_of(&list, 5);
    assert(index == ITEM_NOT_FOUND);

    list.add(&list, 6);
    index = list.index_of(&list, 8);
    assert(index == 0);
    index = list.index_of(&list, 6);
    assert(index == 1);
    index = list.index_of(&list, 7);
    assert(index == 2);
    index = list.index_of(&list, 5);
    assert(index == ITEM_NOT_FOUND);
}

void test_update()
{
}

void test_delete()
{
}

void test_print_list()
{
}

int main()
{
    test_add();
    test_insert();
    test_get();
    test_index_of();
    test_update();
    test_delete();
    test_print_list();
}
