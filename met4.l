%{
#include <stdio.h>
#include <string.h>
int vf = 0;
%}
ID [a-zA-Z]+[a-zA-Z0-9]*
CMID ,[ ]*[a-zA-Z]+[a-zA-Z0-9]*
T :
TYPE "integer"|"boolean"|"char"|"real"
E ;
S [ ]*{ID}[ ]*{CMID}*[ ]*{T}[ ]*{TYPE}[ ]*{E}
UN [,]+[ ]*
ER [ ]*{ID}[ ]*{UN}+{CMID}*[ ]*{T}[ ]*{TYPE}[ ]*{E}
%%
"var" {
  vf = 1;
}
{S}+ {
  if(vf==1){
    printf("The result for the input (%s) is: YES\n", yytext);
    }
  else{
    vf=0;
    printf("The result for the input (%s) is: NO (No var keyword found)\n", yytext);
    }
}
{ER}+ {
  vf=0;
  printf("The result for the input (%s) is: NO (more than 1 ',')\n", yytext);
}
[\t\n]+
[!-~]+ {
  vf=0;
  printf("Unrecognised text: %s\n", yytext);
}
.
%%
main(){
  yylex();
}
