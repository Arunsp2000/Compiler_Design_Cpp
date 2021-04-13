%{


    // #include "symbol.h"
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

"do" {yylval.value=strdup(yytext);return DO;}
"while" {yylval.value=strdup(yytext);return WHILE;}
"if" {yylval.value=strdup(yytext);return IF;}
"else" {yylval.value=strdup(yytext);return ELSE;}
"cout" {yylval.value=strdup(yytext);return COUT;}
"endl" {yylval.value=strdup(yytext);return ENDL;}
"break" {yylval.value=strdup(yytext);return BREAK;}
"continue" {yylval.value=strdup(yytext);return CONTINUE;}
"int" {yylval.value=strdup(yytext);return INT;}
"float" {yylval.value=strdup(yytext);return FLOAT;}
"char" {yylval.value=strdup(yytext);return CHAR;}
"void" {yylval.value=strdup(yytext);return VOID;}
"double" {yylval.value=strdup(yytext);return DOUBLE;}
"#include" {yylval.value=strdup(yytext);return INCLUDE;}
"main()" {yylval.value=strdup(yytext);return TOK_MAIN;}
"class" {yylval.value=strdup(yytext);return CLASS;}
"private" {yylval.value=strdup(yytext);return PRIVATE;}
"protected" {yylval.value=strdup(yytext);return PROTECTED;}
"public" {yylval.value=strdup(yytext);return   PUBLIC;}
"using" {yylval.value=strdup(yytext);return USING;}
"namespace" {yylval.value=strdup(yytext);return NAMESPACE;}
"std"   {yylval.value=strdup(yytext);return STD;}
{digit}+    {yylval.value=strdup(yytext);return NUM;}
{alpha}({alpha}|{digit})*    {yylval.value=strdup(yytext);return ID;}
{alpha}({alpha}|{digit})*"\.h"?   {yylval.value=strdup(yytext);return HEADER;}

\".*\" {yylval.value=strdup(yytext);return STRING;}
"<"   {yylval.value=strdup(yytext);return lt;}
">"     {yylval.value=strdup(yytext);return gt;}
"="     {yylval.value=strdup(yytext);return eq;}
"<="    {yylval.value=strdup(yytext);return lteq;}
">="    {yylval.value=strdup(yytext);return gteq;}
"=="    {yylval.value=strdup(yytext);return eqeq;}
"!="    {yylval.value=strdup(yytext);return neq;}
"+"     {yylval.value=strdup(yytext);return pl;}
"-"     {yylval.value=strdup(yytext);return min;}
"*"     {yylval.value=strdup(yytext);return mul;}
"/"     {yylval.value=strdup(yytext);return division;}
"++"    {yylval.value=strdup(yytext);return incr;}
"--"    {yylval.value=strdup(yytext);return decr;}
"!"     {yylval.value=strdup(yytext);return not;}
"||"    {yylval.value=strdup(yytext);return or;}
"&&"    {yylval.value=strdup(yytext);return and;}
"%"     {yylval.value=strdup(yytext);return perce;}
.    {yylval.value=strdup(yytext);return yytext[0];}

%%



int yywrap ()
{
    return 1;
}
