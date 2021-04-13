#!/bin/bash

lex symbl_tbl.l
yacc -d symbl_tbl.y
gcc y.tab.c -ll -ly -w
./a.out < rand.cpp
