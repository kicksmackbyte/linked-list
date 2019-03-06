#!/bin/sh

gcc -c list.c -o list.o
gcc -c test_list.c -o test_list.o

gcc list.o test_list.o -o test
