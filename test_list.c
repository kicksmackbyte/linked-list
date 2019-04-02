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
    int data[] = {8, 6, 7, 5, 3, 0, 9};
    List list = DEFAULT_LIST;

    _test_list(&list, data, 0);

    list.insert(&list, 0, 8);
    _test_list(&list, data, 1);

    list.insert(&list, 1, 6);
    _test_list(&list, data, 2);

    list.insert(&list, 2, 7);
    _test_list(&list, data, 3);

    list.insert(&list, 3, 5);
    _test_list(&list, data, 4);

    list.insert(&list, 4, 3);
    _test_list(&list, data, 5);

    list.insert(&list, 5, 0);
    _test_list(&list, data, 6);

    list.insert(&list, 6, 9);
    _test_list(&list, data, 7);
}

void test_insert_v2()
{
    int data_0[] = {};
    List list = DEFAULT_LIST;

    _test_list(&list, data_0, 0);

    int data_1[] = {8};
    list.insert(&list, 0, 8);
    _test_list(&list, data_1, 1);

    int data_2[] = {6, 8};
    list.insert(&list, 0, 6);
    _test_list(&list, data_2, 2);

    int data_3[] = {7, 6, 8};
    list.insert(&list, 0, 7);
    _test_list(&list, data_3, 3);

    int data_4[] = {5, 7, 6, 8};
    list.insert(&list, 0, 5);
    _test_list(&list, data_4, 4);

    int data_5[] = {3, 5, 7, 6, 8};
    list.insert(&list, 0, 3);
    _test_list(&list, data_5, 5);

    int data_6[] = {0, 3, 5, 7, 6, 8};
    list.insert(&list, 0, 0);
    _test_list(&list, data_6, 6);

    int data_7[] = {9, 0, 3, 5, 7, 6, 8};
    list.insert(&list, 0, 9);
    _test_list(&list, data_7, 7);
}

void test_insert_v3()
{
    int data_0[] = {};
    List list = DEFAULT_LIST;

    _test_list(&list, data_0, 0);

    int data_1[] = {8};
    list.insert(&list, 0, 8);
    _test_list(&list, data_1, 1);

    int data_2[] = {6, 8};
    list.insert(&list, 0, 6);
    _test_list(&list, data_2, 2);

    int data_3[] = {6, 7, 8};
    list.insert(&list, 1, 7);
    _test_list(&list, data_3, 3);

    int data_4[] = {6, 7, 8, 5};
    list.insert(&list, 4, 5);
    _test_list(&list, data_4, 4);

    int data_5[] = {6, 3, 7, 8, 5};
    list.insert(&list, 1, 3);
    _test_list(&list, data_5, 5);

    int data_6[] = {6, 3, 7, 0, 8, 5};
    list.insert(&list, 3, 0);
    _test_list(&list, data_6, 6);

    int data_7[] = {6, 9, 3, 7, 0, 8, 5};
    list.insert(&list, 1, 9);
    _test_list(&list, data_7, 7);
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
    int data[] = {8, 6, 7, 5, 3, 0, 9};
    int reverse_data[] = {9, 0, 3, 5, 7, 6, 8};
    List list = DEFAULT_LIST;

    //list.update(&list, 0, 9); //make sure this crashes
    list.add(&list, 8);
    list.update(&list, 0, 9);
    _test_list(&list, reverse_data, 1);

    list.add(&list, 6);
    list.update(&list, 1, 0);
    _test_list(&list, reverse_data, 2);

    list.add(&list, 7);
    list.update(&list, 2, 3);
    _test_list(&list, reverse_data, 3);
}

void test_delete()
{
    List list = DEFAULT_LIST;

    int data[] = {8, 6, 7, 5, 3, 0, 9};
    list.add(&list, 8);
    list.add(&list, 6);
    list.add(&list, 7);
    list.add(&list, 5);
    list.add(&list, 3);
    list.add(&list, 0);
    list.add(&list, 9);
    _test_list(&list, data, 7);

    list.delete(&list, 6);
    _test_list(&list, data, 6);

    list.delete(&list, 5);
    _test_list(&list, data, 5);

    list.delete(&list, 4);
    _test_list(&list, data, 4);

    list.delete(&list, 3);
    _test_list(&list, data, 3);

    list.delete(&list, 2);
    _test_list(&list, data, 2);

    list.delete(&list, 1);
    _test_list(&list, data, 1);

    list.delete(&list, 0);
    _test_list(&list, data, 0);
}

void test_delete_v2()
{
    List list = DEFAULT_LIST;

    int data_1[] = {8, 6, 7, 5, 3, 0, 9};
    list.add(&list, 8);
    list.add(&list, 6);
    list.add(&list, 7);
    list.add(&list, 5);
    list.add(&list, 3);
    list.add(&list, 0);
    list.add(&list, 9);
    _test_list(&list, data_1, 7);

    int data_2[] = {6, 7, 5, 3, 0, 9};
    list.delete(&list, 0);
    _test_list(&list, data_2, 6);

    int data_3[] = {7, 5, 3, 0, 9};
    list.delete(&list, 0);
    _test_list(&list, data_3, 5);

    int data_4[] = {5, 3, 0, 9};
    list.delete(&list, 0);
    _test_list(&list, data_4, 4);

    int data_5[] = {3, 0, 9};
    list.delete(&list, 0);
    _test_list(&list, data_5, 3);

    int data_6[] = {0, 9};
    list.delete(&list, 0);
    _test_list(&list, data_6, 2);

    int data_7[] = {9};
    list.delete(&list, 0);
    _test_list(&list, data_7, 1);

    int data_8[] = {};
    list.delete(&list, 0);
    _test_list(&list, data_8, 0);
}

void test_delete_v3()
{
    List list = DEFAULT_LIST;

    int data_1[] = {8, 6, 7, 5, 3, 0, 9};
    list.add(&list, 8);
    list.add(&list, 6);
    list.add(&list, 7);
    list.add(&list, 5);
    list.add(&list, 3);
    list.add(&list, 0);
    list.add(&list, 9);
    _test_list(&list, data_1, 7);

    int data_2[] = {8, 6, 7, 3, 0, 9};
    list.delete(&list, 3);
    _test_list(&list, data_2, 6);

    int data_3[] = {8, 6, 7, 0, 9};
    list.delete(&list, 3);
    _test_list(&list, data_3, 5);

    int data_4[] = {8, 7, 0, 9};
    list.delete(&list, 1);
    _test_list(&list, data_4, 4);

    int data_5[] = {8, 7, 9};
    list.delete(&list, 2);
    _test_list(&list, data_5, 3);

    int data_6[] = {8, 7};
    list.delete(&list, 2);
    _test_list(&list, data_6, 2);

    int data_7[] = {7};
    list.delete(&list, 0);
    _test_list(&list, data_7, 1);

    int data_8[] = {};
    list.delete(&list, 0);
    _test_list(&list, data_8, 0);
}

void test_print_list()
{
}

void test_extend()
{
    List a = DEFAULT_LIST;
    a.add(&a, 8);
    a.add(&a, 6);
    a.add(&a, 7);

    List b = DEFAULT_LIST;
    b.add(&b, 5);
    b.add(&b, 3);
    b.add(&b, 0);
    b.add(&b, 9);

    a.extend(&a, &b);

    int data[] = {8, 6, 7, 5, 3, 0, 9};
    _test_list(&a, data, 7);
}

void test_clear()
{
    List list = DEFAULT_LIST;
    list.add(&list, 8);
    list.add(&list, 6);
    list.add(&list, 7);
    list.add(&list, 5);
    list.add(&list, 3);
    list.add(&list, 0);
    list.add(&list, 9);

    int data[] = {8, 6, 7, 5, 3, 0, 9};
    _test_list(&list, data, 7);

    list.clear(&list);
    _test_list(&list, data, 0);
}

void test_reverse()
{
    List list = DEFAULT_LIST;
    list.add(&list, 8);
    list.add(&list, 6);
    list.add(&list, 7);
    list.add(&list, 5);
    list.add(&list, 3);
    list.add(&list, 0);
    list.add(&list, 9);

    int data[] = {8, 6, 7, 5, 3, 0, 9};
    _test_list(&list, data, 7);

    list.reverse(&list);

    int reverse_data[] = {9, 0, 3, 5, 7, 6, 8};
    _test_list(&list, reverse_data, 7);
}

int main()
{
    test_add();
    test_insert();
    test_insert_v2();
    test_insert_v3();
    test_get();
    test_index_of();
    test_update();
    test_delete();
    test_delete_v2();
    test_delete_v3();
    test_extend();
    test_reverse();
    test_clear();
    test_print_list();
}
