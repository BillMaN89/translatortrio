%{
#include <stdio.h>
#include <string.h>
%}
ID [a-zA-Z][a-zA-Z0-9]*
TYPE ["integer""boolean""char""real"]
%%
var {
  printf("Var word found\n");
}
{TYPE} {
  printf("Type found\n");
}
{ID} {
  printf("ID found\n");
}
[\t\n]+
.


%%
main(){
  yylex();
}
