%{
    #include "y.tab.h"
    #include <string.h>
    
%}

%option yylineno
alpha [A-Za-z_]
digit [0-9]
%%
\/\*(.*\n)*.*\*\/  {};	
\/\/(.*) ; 
[ \t\n] ;

"do" {yylval=strdup(yytext);return DO;}
"while" {yylval=strdup(yytext);return WHILE;}
"if" {yylval=strdup(yytext);return IF;}
"else" {yylval=strdup(yytext);return ELSE;}
"cout" {yylval=strdup(yytext);return COUT;}
"endl" {yylval=strdup(yytext);return ENDL;}
"break" {yylval=strdup(yytext);return BREAK;}
"continue" {yylval=strdup(yytext);return CONTINUE;}
"int" {yylval=strdup(yytext);return INT;}
"float" {yylval=strdup(yytext);return FLOAT;}
"char" {yylval=strdup(yytext);return CHAR;}
"void" {yylval=strdup(yytext);return VOID;}
"double" {yylval=strdup(yytext);return DOUBLE;}
"#include" {yylval=strdup(yytext);return INCLUDE;}
"main()" {yylval=strdup(yytext);return TOK_MAIN;}
"class" {yylval=strdup(yytext);return CLASS;}
"private" {yylval=strdup(yytext);return PRIVATE;}
"protected" {yylval=strdup(yytext);return PROTECTED;}
"public" {yylval=strdup(yytext);return   PUBLIC;}
"using" {yylval=strdup(yytext);return USING;}
"namespace" {yylval=strdup(yytext);return NAMESPACE;}
"std"   {yylval=strdup(yytext);return STD;}
{digit}+    {yylval=strdup(yytext);return NUM;}
{alpha}({alpha}|{digit})*    {yylval=strdup(yytext);return ID;}
{alpha}({alpha}|{digit})*"\.h"?   {yylval=strdup(yytext);return HEADER;}

\".*\" {yylval=strdup(yytext);return STRING;}
"<"   {yylval=strdup(yytext);return lt;}
">"     {yylval=strdup(yytext);return gt;}
"="     {yylval=strdup(yytext);return eq;}
"<="    {yylval=strdup(yytext);return lteq;}
">="    {yylval=strdup(yytext);return gteq;}
"=="    {yylval=strdup(yytext);return eqeq;}
"!="    {yylval=strdup(yytext);return neq;}
"+"     {yylval=strdup(yytext);return pl;}
"-"     {yylval=strdup(yytext);return min;}
"*"     {yylval=strdup(yytext);return mul;}
"/"     {yylval=strdup(yytext);return division;}
"++"    {yylval=strdup(yytext);return incr;}
"--"    {yylval=strdup(yytext);return decr;}
"!"     {yylval=strdup(yytext);return not;}
"||"    {yylval=strdup(yytext);return or;}
"&&"    {yylval=strdup(yytext);return and;}
"%"     {yylval=strdup(yytext);return perce;}
.    {yylval=strdup(yytext);return yytext[0];}

%%



int yywrap ()
{
    return 1;
}
