%{
#include <stdio.h>
#include <string.h>
int lines=1;
int vf = 0;
%}
VAR ["var"]
ID [a-zA-Z]+[a-zA-Z0-9]*
CMID ,[ ]*[a-zA-Z]+[a-zA-Z0-9]*
T :
TYPE "integer"|"boolean"|"char"|"real"
E ;
NL \n
S [ ]*{ID}[ ]*{CMID}*[ ]*{T}[ ]*{TYPE}[ ]*{E}
%%
{NL} {
  ++lines;
}
{VAR} {
  vf = 1;
}
{VAR}?{S} {
  if(lines==1 && vf==1)
    printf("Result for the %d line: YES\n", lines);
  else if(lines>1 && vf==1)
    printf("Result for the %d line: YES\n", lines);
  else
    printf("Result for the %d line: NO\n", lines);
}
[\t\n]+
.
%%
main(){
  yylex();
}
