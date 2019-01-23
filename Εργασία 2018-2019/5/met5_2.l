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
  char array[length];
  int k=0;
  for (int i=0;i<length;i++)
    array[i]=yytext[i];
  for (int i=0;i<length;i++){
    for (int j=i+1;j<length;j++){
      if (array[i]==array[j]){
        k = 1;
        break;
      }
    }
  }
  if(length==n && k==0)
    printf("%s : einai onoma geometrikis ontotitas\n", yytext);
  else printf("%s : Unrecognized text\n", yytext);
}
[ \t\n]+
{GRAMMATA}+ {
  printf("%s : Unrecognized text\n", yytext);
}
. {
  printf("%s : Unrecognized text\n", yytext);
}
%%
main() {
  yylex();
}
