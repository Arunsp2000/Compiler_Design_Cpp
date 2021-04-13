%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE char *
int yyerror();
extern char *yytext;
extern int yylineno;
int global_scope;
typedef struct symbol_table
{
  int line;
  int scope;
  char name[31];
  char type;
  char *value;
  char *datatype;
}ST;
int table_index = 0;
ST st[10000];

%}


%token PRIVATE PUBLIC PROTECTED DO DOUBLE WHILE IF ELSE COUT ENDL BREAK CONTINUE INT FLOAT CHAR VOID INCLUDE TOK_MAIN CLASS NUM ID 
%token HEADER STRING lt gt eq lteq gteq eqeq neq pl min mul division incr decr or and not perce USING NAMESPACE STD

%left lt gt
%left pl min
%left mul division
%start S
%%


S
    : START {printf("Input accepted.\n");}
    ;

START
    : INCLUDE  lt HEADER gt START 
    | INCLUDE "\"" HEADER "\"" START 
    | INCLUDE lt ID gt START 
    | MAIN
    | ASSIGN_EXPR ';' START
    | CLASS_DEF ';' START
    | FUNCTION START
    | USING NAMESPACE STD ';' START
    ;

FUNCTION
    :FUNC_DEF
    |FUNC_DECL
    ;
FUNC_DECL
    :TYPE ID '(' PARAMETER_LIST ')' ';' {lookup($2,yylineno,'I',NULL,$1);}
    |TYPE ID '('')' ';' {lookup($2,yylineno,'I',NULL,$1);}
    ;

FUNC_DEF
    :TYPE ID  '(' PARAMETER_LIST ')' {lookup($2,yylineno-1,'I',NULL,$1);}  MAIN_BODY 
    |TYPE ID '('')' {lookup($2,yylineno-1,'I',NULL,$1);} MAIN_BODY
    ;

PARAMETER_LIST
    :TYPE ID ',' PARAMETER_LIST
    |TYPE ID
    ;

CLASS_DEF
    :CLASS ID '{' CLASS_BODY '}'
    ;

CLASS_BODY
    :ACCESS_SPECIFIER ':' CLASS_BODY
    |TYPE ID ';' CLASS_BODY 
    |TYPE ID ';'
    |FUNC_DECL
    ;


ACCESS_SPECIFIER
    :PRIVATE 
    |PROTECTED 
    |PUBLIC 
    ;


MAIN
    : VOID TOK_MAIN {lookup($2,yylineno,'I',NULL,$1);} MAIN_BODY 
    | INT TOK_MAIN {lookup($2,yylineno,'I',NULL,$1);} MAIN_BODY
    ;
MAIN_BODY
    : '{' {global_scope++;} LINES '}'{global_scope--;}
    | '{''}'
    ;

LINES
    :LINES STATEMENT ';'
    |LINES LOOP 
    |STATEMENT ';'
    |LOOP 
    |';'
    ;

LOOP
    : IF '(' COND ')' LOOPBODY 
    | IF '(' COND ')' LOOPBODY ELSE LOOPBODY 
    | DO LOOPBODY WHILE '(' COND ')' ';' 
    ;

COND
      :ARITH_EXPR
      ;



LOOPBODY
  	: '{' {global_scope++;} LINES '}' {global_scope--;}
    |STATEMENT ';'
    ;
STATEMENT
    : ASSIGN_EXPR
    | ARITH_EXPR
    | PRINT
    ;

PRINT 
    : COUT CASCADE
    ;

CASCADE
    :lt lt ID CASCADE
    |lt lt ID
    |lt lt STRING CASCADE
    |lt lt STRING
    |lt lt ENDL
    ;

ASSIGN_EXPR
    :ID eq ARITH_EXPR {search_id($1,yylineno);update($1,yylineno,$3);}
    |TYPE ID eq ARITH_EXPR {lookup($2,yylineno,'I',NULL,$1);update($2,yylineno,$4);}
    |TYPE ID
    ; 

ARITH_EXPR
      : LOGICAL_EXPR
      | ID unary_arop
      | unary_arop ID
      | not LOGICAL_EXPR 
      ;
LOGICAL_EXPR
    : RELLATIONAL_EXPR
    | LOGICAL_EXPR and RELLATIONAL_EXPR { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    | LOGICAL_EXPR or RELLATIONAL_EXPR { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    ;
RELLATIONAL_EXPR
    :ADDITIVE
    |RELLATIONAL_EXPR eqeq ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |RELLATIONAL_EXPR gteq ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |RELLATIONAL_EXPR lteq ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |RELLATIONAL_EXPR neq ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |RELLATIONAL_EXPR lt ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |RELLATIONAL_EXPR gt ADDITIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    ;

ADDITIVE
    :MULTIPLCIATIVE
    |ADDITIVE pl MULTIPLCIATIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |ADDITIVE min MULTIPLCIATIVE { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    ;

MULTIPLCIATIVE
    :FINAL
    |MULTIPLCIATIVE division FINAL { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |MULTIPLCIATIVE mul FINAL { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    |MULTIPLCIATIVE perce FINAL { strcat($$," "); strcat($$,$2); strcat($$," ");strcat($$,$3);}
    ;

FINAL
    :'(' ARITH_EXPR ')'
    |LITERAL
    ;

TYPE
      : INT 
      | CHAR 
      | FLOAT 
      | DOUBLE 
      ;





unary_arop
    : incr 
    | decr 
    ;




LITERAL
    : ID {search_id($1,yylineno);}
    | NUM 
    | min ID
    | min NUM
    ;


%%


#include "lex.yy.c"

int yyerror(){
  printf("Error at line at %d\n",yylineno);
}

int main()
{
if(!yyparse())  //yyparse-> 0 if success
  {
  	printf("Parsing Complete\n");
    printf("Number of entries in the symbol table = %d\n\n",table_index);
    printf("-----------------------------------Symbol Table--------------------------------------\n\n");
    printf("S.No\t  Token  \t Line Number \t Category \t DataType \t Value \t  Scope \n");
    
    for (int i = 0;i < table_index;i++)
    {
      char *ty;
      
     if(st[i].type=='I')
      {
        ty="identifier";
        printf("%-4d\t  %-7s\t   %-10d \t %-9s\t  %-7s\t   %-5s   %-7d\n",i+1,st[i].name,st[i].line,ty,st[i].datatype,st[i].value,st[i].scope);
      }
    }
  }
  else
  {
    printf("Parsing failed\n");
  }
}


void lookup(char *token,int line,char type,char *value,char *datatype)
{
  // printf("Token %s\n",token);
  int flag = 0;
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      if(st[i].scope==global_scope)
      {  
        flag = 1;
        printf("Error at line %d : %s is redefined\n",line,token);
        exit(0);
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
        st[table_index].datatype=datatype;
        
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
    printf("Error at line %d : %s is not defined\n",lineno,token);
    exit(0);
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
    printf("Error at line %d : %s is not defined\n",lineno,token);
    exit(0);
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