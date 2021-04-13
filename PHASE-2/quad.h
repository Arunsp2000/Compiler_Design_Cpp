#include <stdio.h>

typedef struct Quad
{
    char op[20];
    char src1[20];
    char src2[20];
    char des[20];
    struct Quad *link;
} quad;

struct yylval_type
{
    char *value;
    char *label[10];
};
typedef struct yylval_type yylval_type;

typedef struct QuadList
{
    quad * first;
}quadlist;

extern quadlist ql;


quad* quadnode(char* op,char* src1,char* src2,char* dest);
void insertquad(quad * quad1 );
void disp();
char* tempname();
char* labelname();

