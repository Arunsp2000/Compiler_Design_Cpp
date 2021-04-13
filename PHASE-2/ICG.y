%{
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Errors
#include "quad.h"
#define YYSTYPE yylval_type
int yyerror();
int yylex();

// Implementations
#include "symbol.h"


// Lex Libraries
extern char *yytext;
extern int yylineno;

//Varaibles
int global_scope;
int table_index = 0;
ST st[10000];
quadlist ql;


%}


%token PRIVATE PUBLIC PROTECTED DO DOUBLE WHILE IF ELSE COUT ENDL BREAK CONTINUE INT FLOAT CHAR VOID INCLUDE TOK_MAIN CLASS NUM ID 
%token HEADER STRING lt gt eq lteq gteq eqeq neq pl min mul division incr decr or and not perce USING NAMESPACE STD


%left pl min
%left mul division
%nonassoc lt gt lteq gteq eqeq neq
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
    :TYPE ID '(' PARAMETER_LIST ')' ';'
    |TYPE ID '('')' ';' 
    ;

FUNC_DEF
    :TYPE ID  '(' PARAMETER_LIST ')'  MAIN_BODY 
    |TYPE ID '('')' MAIN_BODY
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
    : VOID TOK_MAIN MAIN_BODY 
    | INT TOK_MAIN MAIN_BODY
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
:   IF_EXPR LOOPBODY {
                        quad *endif=quadnode("label","","",$1.label[1]);
                        insertquad(endif);
                        
                        
                    }
    | IF_EXPR LOOPBODY {
                            $1.label[2]=labelname();
                            quad *change=quadnode("goto","","",$1.label[2]);
                            insertquad(change);
                            quad *endif=quadnode("label","","",$1.label[1]);
                            insertquad(endif);
        
        } ELSE LOOPBODY {
            quad *final=quadnode("label","","",$1.label[2]);
            insertquad(final);            
        }
    | DO 
        {
        $1.label[0]=labelname();
        quad* true=quadnode("label","","",$1.label[0]);
        insertquad(true);

        } 
        LOOPBODY WHILE  '(' ARITH_EXPR ')'';' 
        {
            quad* ifs=quadnode("if",$6.value,"",$1.label[0]);
            insertquad(ifs);
        } 
    ;

IF_EXPR
    : IF '(' ARITH_EXPR ')' { 
                                $$.label[0]=labelname();
                                $$.label[1]=labelname();
                                quad* ifs=quadnode("if",$3.value,"",$$.label[0]);
                                insertquad(ifs);
                                quad *false = quadnode("goto","","",$$.label[1]);
                                quad *true = quadnode("label","","",$$.label[0]);
                                insertquad(false);
                                insertquad(true);
    } 

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
    :ID eq ARITH_EXPR 
                    {
                          search_id($1.value,yylineno);
                          update($1.value,yylineno,$3.value);
                          quad* temp= quadnode($2.value,$3.value,"",$1.value);
                          insertquad(temp);
    
    
                    }
    
    |TYPE ID eq ARITH_EXPR 
                          {
                                lookup($2.value,yylineno,'I',NULL,$1.value);
                                update($2.value,yylineno,$4.value);
                                quad* temp= quadnode($3.value,$4.value,"",$2.value);
                                insertquad(temp);

                          }
    |TYPE ID {
                lookup($2.value,yylineno,'I',NULL,$1.value);
    
    
              }
    ; 


ARITH_EXPR
      : LOGICAL_EXPR
      | ID unary_arop
      | unary_arop ID
      | not LOGICAL_EXPR 
      ;
LOGICAL_EXPR
    : RELLATIONAL_EXPR
    | LOGICAL_EXPR LOG RELLATIONAL_EXPR { 
                                            // printf("%s %s\n",$1,$$);
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,"Temp");
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            // printf("%s\n",$$.value);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;
RELLATIONAL_EXPR
    :ADDITIVE
    |RELLATIONAL_EXPR REL ADDITIVE { 
                                            // printf("%s %s\n",$1,$$);
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,"Temp");
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

ADDITIVE
    :MULTIPLCIATIVE
    |ADDITIVE ADD_SUB MULTIPLCIATIVE { 
                                            // printf("%s %s\n",$1,$$);
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,"Temp");
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

MULTIPLCIATIVE
    :FINAL
    |MULTIPLCIATIVE PROD_QUO FINAL { 
                                            // printf("%s %s\n",$1,$$);
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,"Temp");
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

FINAL
    :'(' ARITH_EXPR ')' { $$.value=$2.value; }
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


ADD_SUB
    : pl
    | min
    ;

PROD_QUO
    : division
    | mul
    | perce
    ;

LOG
    : and
    | or
    ;

REL
    : eqeq
    | gteq
    | lteq
    | neq
    | lt
    | gt
    ;
LITERAL
    : ID {search_id($1.value,yylineno);}
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
      else
      {
          ty="Temporary";
          printf("%-4d\t  %-7s\t   %-10d \t %-9s\t  %-7s\t   %-5s   %-7d\n",i+1,st[i].name,st[i].line,ty,st[i].datatype,st[i].value,st[i].scope);
      }
      
    }
    // disp();
    FILE *fp;
    fp = fopen("ICG.txt","w");
    disp(fp,',');
    fclose(fp);
  }
  else
  {
    printf("Parsing failed\n");
  }
}
