%{
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Errors
#include "quad.h"
#define YYSTYPE yylval_type
void yyerror();
int yylex();

// Implementations
#include "symbol.h"


// Lex Libraries
extern char *yytext;
extern int yylineno;

//Varaibles
int errorcount=0;
int global_scope;
int table_index = 0;
ST st[10000];
quadlist ql;


%}



%token PRIVATE PUBLIC PROTECTED DO DOUBLE WHILE IF ELSE COUT ENDL BREAK CONTINUE INT FLOAT CHAR VOID INCLUDE TOK_MAIN CLASS NUM ID BOOL FLOAT_VAL CHAR_VAL BOOL_VAL
%token HEADER STRING_VAL lt gt eq lteq gteq eqeq neq pl min mul division incr decr or and not perce USING NAMESPACE STD STRING


%left pl min
%left mul division
%nonassoc lt gt lteq gteq eqeq neq
%start S
%%


S
    : START {if(errorcount>0){exit(0);}}
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
    |lt lt STRING_VAL CASCADE
    |lt lt STRING_VAL
    |lt lt ENDL
    ;

ASSIGN_EXPR
    :ID eq ARITH_EXPR 
                    {
                          search_id($1.value,yylineno);
                          int val=get_type($1.value);
                          printf("%d\n",val);
                          int val2;
                          if($3.type==1)
                          {
                            val2=get_type($3.value);
                          }
                          else
                          {
                              val2=$3.type;
                          }
                          if(val==5)
                          {
                              if(val2!=5)
                              {
                                  char error[50];
                                  char type_err[20];
                                  typetostring(type_err,val2);
                                  sprintf(error,"Error at line %d : Cannot convert %s to char* \n",yylineno,type_err);
                                  yyerror(error);
                                  errorcount++;   
                              }
                          }
                          else if(val!=5)
                          {
                              if(val2==5)
                              {
                                  char error[50];
                                  char type_err[20];
                                  typetostring(type_err,val);
                                  sprintf(error,"Error at line %d : Cannot convert char* to %s \n",yylineno,type_err);
                                  yyerror(error);
                                  errorcount++;  
                              }
                          }   
                          update($1.value,yylineno,$3.value);
                          quad* temp= quadnode($2.value,$3.value,"",$1.value);
                          insertquad(temp);
    
    
                    }
    
    |TYPE ID eq ARITH_EXPR 
                          {
                                if((!strcmp($1.value,"char*") && $4.type!=5))
                                {
                                        if($4.type==1)
                                        {
                                            int val=get_type($4.value);
                                            if(val!=5)
                                            {
                                                // if($4.rel!=1)
                                                // {
                                                char error[50];
                                                char type_err[20];
                                                typetostring(type_err,val);                                                   
                                                sprintf(error,"Error at line %d : Cannot convert %s to char* \n",yylineno,type_err);
                                                yyerror(error);
                                                errorcount++;    
                                                // }
                                            }
                                        }
                                        else
                                        {
                                            // if($4.rel!=1)
                                            // {
                                            char error[50];
                                            char type_err[20];
                                            typetostring(type_err,$4.type);                                                   
                                            sprintf(error,"Error at lines %d : Cannot convert %s to char* \n",yylineno,type_err);
                                            yyerror(error);
                                            errorcount++;
                                            // }
                                        }
                                }
                                if($4.type==5)
                                {
                                    // printf("%s",$1.value);
                                    if(strcmp($1.value,"char*")!=0)
                                    {       
                                            // if($4.rel!=1)
                                            // {
                                            char error[50];
                                            // char type_err[20];
                                            // typetostring(type_err,$1.type);
                                            sprintf(error,"Error at line %d : Cannot convert char* to %s \n",yylineno,$1.value);
                                            yyerror(error);
                                            errorcount++;
                                            // }
                                    }
                                }
                                if($4.type==1)
                                {
                                    int val=get_type($4.value);
                                    if(val==5)
                                    {
                                        if(strcmp($1.value,"char*")!=0)
                                        {
                                            char error[50];
                                            sprintf(error,"Error2 at line %d : Cannot convert char* to %s \n",yylineno,$1.value);
                                            yyerror(error);
                                            errorcount++;
                                        }
                                    }
                                }
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
    : RELLATIONAL_EXPR {$$ = $1;}
    | LOGICAL_EXPR LOG RELLATIONAL_EXPR { 
                                            // $$.rel=1;
                                            char type[10];
                                            int flag=0;
                                            if($1.type == 4 || $3.type == 4)
                                                strcpy(type,"char");
                                            if($1.type == 0 || $3.type == 0)
                                                strcpy(type,"int");
                                            if($1.type == 3 || $3.type == 3)
                                                strcpy(type,"double");
                                            // if($1.type==5 || $3.type==5)
                                            // {
                                            //     flag=1;
                                            //     char error[100];
                                            //     sprintf(error,"Error at line %d : Cannot perform logical operations on char* \n",yylineno);
                                            //     yyerror(error);
                                            //     errorcount++;
                                            // }
                                            int val1=$1.type;
                                            int val2=$3.type;
                                            if($1.type==1)
                                            {
                                                val1=get_type($1.value);
                                            }
                                            if($3.type==1)
                                            {
                                                val2=get_type($3.value);
                                            }
                                            // if(val1==5 || val2==5)
                                            // {
                                            //     if(flag==0)
                                            //     {
                                            //         char error[100];
                                            //         sprintf(error,"Error at line %d : Cannot perform logical operations on char* \n",yylineno);
                                            //         yyerror(error);
                                            //         errorcount++;  
                                            //     }
                                            // }
                                            if(val1==0 && val2==0)
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if((val1==4 && val2==0) || (val2==4 && val1==0))
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if(val1==3 || val2==3)
                                            {   
                                                strcpy(type,"double");
                                                $$.type=3;
                                            }  

                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,type);
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            // printf("%s\n",$$.value);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;
RELLATIONAL_EXPR
    :ADDITIVE {$$ = $1;}
    |RELLATIONAL_EXPR REL ADDITIVE { 
                                            char type[10];
                                            int flag=0;
                                            if($1.type == 4 || $3.type == 4)
                                                strcpy(type,"char");
                                            if($1.type == 0 || $3.type == 0)
                                                strcpy(type,"int");
                                            if($1.type == 3 || $3.type == 3)
                                                strcpy(type,"double");
                                            if($1.type==5 || $3.type==5)
                                            {
                                                flag=1;
                                                char error[100];
                                                sprintf(error,"Error at line %d : Cannot perform relational operations on char* \n",yylineno);
                                                yyerror(error);
                                                errorcount++;
                                            }
                                            int val1=$1.type;
                                            int val2=$3.type;
                                            if($1.type==1)
                                            {
                                                val1=get_type($1.value);
                                            }
                                            if($3.type==1)
                                            {
                                                val2=get_type($3.value);
                                            }
                                            if(val1==5 || val2==5)
                                            {
                                                if(flag==0)
                                                {    
                                                    char error[100];
                                                    sprintf(error,"Error at line %d : Cannot perform logical operations on char* \n",yylineno);
                                                    yyerror(error);
                                                    errorcount++; 
                                                }
                                            }
                                            if(val1==0 && val2==0)
                                            {
                                                strcpy(type,"int");
                                            }
                                            if((val1==4 && val2==0) || (val2==4 && val1==0))
                                            {
                                                strcpy(type,"int");
                                            }
                                            if(val1==3 || val2==3)
                                            {   
                                                strcpy(type,"double");
                                            }        

                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,type);
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

ADDITIVE
    :MULTIPLCIATIVE {$$ = $1;}
    |ADDITIVE ADD_SUB MULTIPLCIATIVE { 
                                            char type[10];
                                            int flag=0;
                                            if($1.type == 4 || $3.type == 4)
                                                strcpy(type,"char");
                                            if($1.type == 0 || $3.type == 0)
                                                strcpy(type,"int");
                                            if($1.type == 3 || $3.type == 3)
                                                strcpy(type,"double");
                                            if($1.type==5 || $3.type==5)
                                            {
                                                flag=1;
                                                char error[100];
                                                sprintf(error,"Error at line %d : Cannot perform Addition and Subtraction on char* \n",yylineno);
                                                yyerror(error);
                                                errorcount++;
                                            }
                                            int val1=$1.type;
                                            int val2=$3.type;
                                            if($1.type==1)
                                            {
                                                val1=get_type($1.value);
                                            }
                                            if($3.type==1)
                                            {
                                                val2=get_type($3.value);
                                            }
                                            if(val1==5 || val2==5)
                                            {
                                                if(flag==0)
                                                {
                                                    char error[100];
                                                    sprintf(error,"Error at line %d : Cannot perform Addition and Subtraction on char* \n",yylineno);
                                                    yyerror(error);
                                                    errorcount++;  
                                                }
                                            }
                                            if(val1==0 && val2==0)
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if((val1==4 && val2==0) || (val2==4 && val1==0))
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if(val1==3 || val2==3)
                                            {   
                                                strcpy(type,"double");
                                                $$.type=3;
                                            }        
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
            
                                            
                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,type);
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

MULTIPLCIATIVE
    :FINAL {$$ = $1;}
    |MULTIPLCIATIVE PROD_QUO FINAL {
                                            int flag=0; 
                                            char type[10];
                                            if($1.type == 4 || $3.type == 4)
                                                strcpy(type,"char");
                                            if($1.type == 0 || $3.type == 0)
                                                strcpy(type,"int");
                                            if($1.type == 3 || $3.type == 3)
                                                strcpy(type,"double");
                                            if($1.type==5 || $3.type==5)
                                            {
                                                flag=1;
                                                char error[100];
                                                sprintf(error,"Error at line %d : Cannot perform Multiplication and Division on char* \n",yylineno);
                                                yyerror(error);
                                                errorcount++;
                                            }
                                            int val1=$1.type;
                                            int val2=$3.type;
                                            if($1.type==1)
                                            {
                                                val1=get_type($1.value);
                                            }
                                            if($3.type==1)
                                            {
                                                val2=get_type($3.value);
                                            }
                                            if(val1==5 || val2==5)
                                            {
                                                if(flag==0)
                                                {
                                                    char error[100];
                                                    sprintf(error,"Error at line %d : Cannot perform Multiplication and Division on char* \n",yylineno);
                                                    yyerror(error);
                                                    errorcount++;  
                                                }
                                            }
                                            if(val1==0 && val2==0)
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if((val1==4 && val2==0) || (val2==4 && val1==0))
                                            {
                                                strcpy(type,"int");
                                                $$.type=0;
                                            }
                                            if(val1==3 || val2==3)
                                            {   
                                                strcpy(type,"double");
                                                $$.type=3;
                                            }        
                                            char temp_expr[32];
                                            strcpy(temp_expr,$1.value);
                                            strcat($$.value," "); 
                                            strcat($$.value,$2.value); 
                                            strcat($$.value," ");
                                            strcat($$.value,$3.value);
                                            // printf("%s %s\n",$1,$$);

                                            char *t=tempname();
                                            lookup(t,yylineno,'T',NULL,type);
                                            update(t,yylineno,$$.value);
                                            strcpy($$.value,t);
                                            free(t);
                                            quad *temp=quadnode($2.value,temp_expr,$3.value,$$.value);
                                            insertquad(temp);


                                        }
    ;

FINAL
    :'(' ARITH_EXPR ')' { $$.value=$2.value; }
    |LITERAL {$$ = $1;}
    ;

TYPE
      : INT 
      | CHAR 
      | FLOAT 
      | DOUBLE 
      | BOOL
      | STRING
      | VOID
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
    : ID {search_id($1.value,yylineno);$$ = $1;}
    | FLOAT_VAL {$$ = $1;}
    | CHAR_VAL {$$ = $1;}
    | BOOL_VAL {$$ = $1;}
    | STRING_VAL {$$ = $1;}
    | NUM {$$ = $1;}
    | min ID {$$ = $1;}
    | min NUM {$$ = $1;}
    ;


%%


#include "lex.yy.c"

void yyerror(char *error){
  printf("%s",error);
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
    freefromsymb();
  }
  else
  {
    printf("\nParsing failed\n");
  }
}
