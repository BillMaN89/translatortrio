%{
#include <stdio.h>
#include <string.h>
%}
VAR ["var"]
ID [a-zA-Z]+[a-zA-Z0-9]*
CMID ,[ ]*[a-zA-Z]+[a-zA-Z0-9]*
T :
TYPE "integer"|"boolean"|"char"|"real"
E ;
S {VAR}[ ]*{ID}[ ]*{CMID}*[ ]*{T}[ ]*{TYPE}[ ]*{E}
%%
{S} {
  printf("YES");
}
[\t\n]+
.
%%
main(){
  yylex();
}
