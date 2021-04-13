%{
#include <stdio.h>
#include <stdlib.h>
extern int yylineno;
int yyerror();

%}


%token PRIVATE PUBLIC PROTECTED DO DOUBLE WHILE IF ELSE COUT ENDL BREAK CONTINUE INT FLOAT CHAR VOID INCLUDE TOK_MAIN CLASS NUM ID 
%token HEADER STRING lt gt eq lteq gteq eqeq neq pl min mul division incr decr or and not perce USING NAMESPACE STD

%left lt gt
%left pl min
%left mul division

%%


S
    : START {printf("Input accepted.\n");exit(0);}
    ;

START
    : INCLUDE lt HEADER gt START
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
    :TYPE ID '(' PARAMETER_LIST ')' MAIN_BODY
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
    : '{' LINES '}'
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
  	: '{' LINES '}'
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
    |TYPE ID eq ARITH_EXPR
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
    | LOGICAL_EXPR and RELLATIONAL_EXPR
    | LOGICAL_EXPR or RELLATIONAL_EXPR
    ;
RELLATIONAL_EXPR
    :ADDITIVE
    |RELLATIONAL_EXPR eqeq ADDITIVE
    |RELLATIONAL_EXPR gteq ADDITIVE
    |RELLATIONAL_EXPR lteq ADDITIVE
    |RELLATIONAL_EXPR neq ADDITIVE
    |RELLATIONAL_EXPR lt ADDITIVE
    |RELLATIONAL_EXPR gt ADDITIVE
    ;

ADDITIVE
    :MULTIPLCIATIVE
    |ADDITIVE pl MULTIPLCIATIVE
    |ADDITIVE min MULTIPLCIATIVE
    ;

MULTIPLCIATIVE
    :FINAL
    |MULTIPLCIATIVE division FINAL
    |MULTIPLCIATIVE mul FINAL
    |MULTIPLCIATIVE perce FINAL
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
    : ID
    | NUM
    | min ID
    | min NUM
    ;


%%


#include "lex.yy.c"

int yyerror(){
  printf("Error at line at %d\n",yylineno);
}

int main(int argc, char* args[])
{
return yyparse();
}
