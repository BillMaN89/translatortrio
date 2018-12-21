%{
  #include <stdio.h>
  #include <string.h>
  int n, length;
%}
GRAMMA [A-E]
GRAMMATA[a-zA-z]
%%
Dinetai|dinetai {
  printf("%s : einai rima\n", yytext);
}
trigono {
   n=3;
   printf("%s : einai geometriki ontotita\n", yytext);
}
tetragono {
  n=4;
  printf("%s : einai geometriki ontotita\n", yytext);
}
gonia {
  n=1;
  printf("%s : einai geometriki ontotita\n", yytext);
}
{GRAMMA}+ {
  length = strlen(yytext);
  if(length==n)
    printf("%s : einai onoma geometrikis ontotitas\n", yytext);
  else printf("%s : Unreckognized text\n", yytext);
}
[ \t\n]+
{GRAMMATA}+ {
  printf("%s : Unreckognized text\n", yytext);
}
. {
  printf("%s : Unreckognized text\n", yytext);
}
%%
main() {
  yylex();
}
