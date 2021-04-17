#!/bin/bash

lex ICG.l
yacc -d ICG.y -v
gcc  y.tab.c symbol.c quad.c -lfl -ly
./a.out < rand.cpp