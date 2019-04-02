#!/bin/sh

gcc -g -c list.c -o list.o
gcc -g -c test_list.c -o test_list.o

gcc -g list.o test_list.o -o test
