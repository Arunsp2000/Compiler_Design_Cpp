#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

extern int table_index;
extern ST st[10000];
extern int global_scope;
extern int yyerror();
extern int errorcount;

void lookup(char *token,int line,char type,char *value,char *datatype)
{
  int flag = 0;
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      if(st[i].scope==global_scope)
      {  
        flag = 1;
        char error[50];
        sprintf(error,"Error at line %d : %s is redefined\n",line,token);
        yyerror(error);
        errorcount++;
      }
    }
  }
  
  //Insert
  if(flag == 0)
  {
    st[table_index].scope=global_scope;
    strcpy(st[table_index].name,token);
    st[table_index].type=type;
    if(value==NULL)
        st[table_index].value=NULL;
    else
        strcpy(st[table_index].value,value);
        
    if(datatype==NULL)
        st[table_index].datatype=NULL;
    else
    {
        st[table_index].datatype=(char*)malloc(sizeof(strlen(datatype)));
        strcpy(st[table_index].datatype,datatype);
      
    }    
    st[table_index].line = line;
    table_index++;
  }
}

void search_id(char *token,int lineno)
{
  int flag = 0;
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      flag = 1;
      return;
    }
  }
  if(flag == 0)
  { 
    char error[50];
    sprintf(error,"Error at line %d : %s is not defined\n",lineno,token);
    yyerror(error);
    errorcount++;
  }
}

void update(char *token,int lineno,char *value)
{
  int flag = 0;
  // printf("%s\n",value);
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      if(st[i].scope == global_scope)
      {  
        flag = 1;
        st[i].value = (char*)malloc(sizeof(char)*strlen(value));
        //sprintf(st[i].value,"%s",value);
        strcpy(st[i].value,value);
        st[i].line = lineno;
        return;
      }
    }
  }
  for(int k=global_scope-1;k!=-1;k--)
  {
    for(int i = 0;i < table_index;i++)
    {
      if(!strcmp(st[i].name,token))
      {
        if(st[i].scope == k)
        {  
          flag = 1;
          st[i].value = (char*)malloc(sizeof(char)*strlen(value));
          //sprintf(st[i].value,"%s",value);
          strcpy(st[i].value,value);
          st[i].line = lineno;
          return;
        }
      }
    }
  }
  if(flag == 0)
  {
    char error[50];
    sprintf(error,"Error at line %d : %s is not defined\n",lineno,token);
    yyerror(error);
    errorcount++;
  }
}

int  get_type(char *var)
{
  for(int j=global_scope;j!=0;--j)
  {
    for(int i=0;i<table_index;i++)
    {
      if((!strcmp(st[i].name,var) && (j==st[i].scope)))
      {
          if(!strcmp(st[i].datatype,"int"))
          {
            return 0;
          }
          else if(!strcmp(st[i].datatype,"bool"))
          {
            return 2;
          }
          else if(!strcmp(st[i].datatype,"float"))
          {
            return 3;
          }
          else if(!strcmp(st[i].datatype,"char"))
          {
            return 4;
          }
          else if(!strcmp(st[i].datatype,"char*"))
          {
            return 5;
          }
          else if(!strcmp(st[i].datatype,"double"))
          {
            return 3;
          }
      }

    }
  }
}

// int get_val(char *token)
// {
//   int flag = 0;
//   for(int i = 0;i < table_index;i++)
//   {
//     if(!strcmp(st[i].name,token))
//     {
//       flag = 1;scope
//       return st[i].value;
//     }
//   }
//   if(flag == 0)
//   {
//     printf("Error at line : %s is not defined\n",token);
//     exit(0);
//   }
// }

void freefromsymb()
{
  for(int i=0;i<table_index;i++)
  { 
    if(st[i].datatype!= NULL)
    {
      free(st[i].datatype);
    }
    if(st[i].value!= NULL)
    {
      free(st[i].value);
    }
    
  }
}