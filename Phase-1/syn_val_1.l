%{
    #include "y.tab.h"
    
%}
%option yylineno
alpha [A-Za-z_]
digit [0-9]
%%
\/\*(.*\n)*.*\*\/  {};	
\/\/(.*) ; 
[ \t\n] ;

"do" {return DO;}
"while" {return WHILE;}
"if" {return IF;}
"else" {return ELSE;}
"cout" {return COUT;}
"endl" {return ENDL;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"void" {return VOID;}
"double" {return DOUBLE;}
"#include" {return INCLUDE;}
"main()" {return TOK_MAIN;}
"class" {return CLASS;}
"private" {return PRIVATE;}
"protected" {return PROTECTED;}
"public" {return   PUBLIC;}
"using" {return USING;}
"namespace" {return NAMESPACE;}
"std"   {return STD;}
{digit}+    {return NUM;}
{alpha}({alpha}|{digit})*    {return ID;}
{alpha}({alpha}|{digit})*"\.h"?   {return HEADER;}

\".*\" {return STRING;}
"<"   {return lt;}
">"     {return gt;}
"="     {return eq;}
"<="    {return lteq;}
">="    {return gteq;}
"=="    {return eqeq;}
"!="    {return neq;}
"+"     {return pl;}
"-"     {return min;}
"*"     {return mul;}
"/"     {return division;}
"++"    {return incr;}
"--"    {return decr;}
"!"     {return not;}
"||"    {return or;}
"&&"    {return and;}
"%"     {return perce;}
.    {return yytext[0];}

%%



int yywrap ()
{
    return 1;
}
