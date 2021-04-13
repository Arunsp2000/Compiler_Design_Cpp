#!/bin/bash

lex syn_val_1.l
yacc -d syn_vak_1.y
gcc y.tab.c -ll -ly -w
./a.out < rand.cpp
