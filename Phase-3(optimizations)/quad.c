#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quad.h"


extern quadlist ql;
int tcount=0;
int lcount=0;


void typetostring(char *type1,int t)
{
    if(t==0)
    {
        sprintf(type1,"int");
    }
    else if(t==2)
    {
        sprintf(type1,"bool");
    }
    else if(t==3)
    {
        sprintf(type1,"float");
    }
    else if (t==4)
    {
        sprintf(type1,"char");
    }
    else if (t==5)
    {
        sprintf(type1,"char*");
    }
    
}

quad* quadnode(char* op,char* src1,char* src2,char* des)
{
    quad * node=(quad *)malloc(sizeof(quad));
    strcpy(node->op,op);
    strcpy(node->src1,src1);
    strcpy(node->src2,src2);
    strcpy(node->des,des);
    node->link=NULL;
    return node;    
}

void insertquad(quad * quad1 )
{
    quad* temp=ql.first;
    if(temp==NULL)
    {
        ql.first=quad1;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=quad1;
    }
}

void disp(FILE* fp)
{
    quad* temp=ql.first;
    while(temp!=NULL)
    {
        fprintf(fp,"%s,%s,%s,%s\n",temp->op,temp->src1,temp->src2,temp->des);
        temp=temp->link;
        // printf("\n");
    }
}


char* tempname()
{
    char *tname = calloc(6,sizeof(char));
    sprintf(tname,"T%d",tcount++);
    return tname;
}

char* labelname()
{
    char *lname = calloc(6,sizeof(char));
    sprintf(lname,"L%d",lcount++);
    return lname;
}