#include <iostream>
#include <stack>
using namespace std;

int main() {
  char input[] = {'[', '[', 'y', ':', 'x', ']', '+', '[', 'x', ':', 'y', ']', ']','$'};
  string array[4][7];
  array[0][0]="S->[A]";
  array[1][0]="A->BE";
  array[1][4]="A->BE";
  array[1][5]="A->BE";
  array[2][0]="B->S";
  array[2][4]="B->x";
  array[2][5]="B->y";
  array[3][1]="E->e";
  array[3][2]="E->:A";
  array[3][3]="E->+A";
  stack<char> topdownsyntax;
  topdownsyntax.push('$');
  topdownsyntax.push('S');
  int i = 0;
  while (i<14) {
    if (topdownsyntax.top() == input[i]) {
      topdownsyntax.pop();
      i++;
    }
    else if (topdownsyntax.top()=='S'){
      cout <<array[0][0]<<endl;
      topdownsyntax.pop();
      topdownsyntax.push(']');
      topdownsyntax.push('A');
      topdownsyntax.push('[');
    }
    else if (topdownsyntax.top()=='A') {
      cout <<array[1][4]<<endl;
      topdownsyntax.pop();
      topdownsyntax.push('E');
      topdownsyntax.push('B');
    }
    else if (topdownsyntax.top()=='B') {
      if (input[i]=='x') {
        cout <<array[2][4]<<endl;
        topdownsyntax.pop();
        topdownsyntax.push('x');
      }
      else if (input[i]=='y') {
        cout <<array[2][5]<<endl;
        topdownsyntax.pop();
        topdownsyntax.push('y');
      }
      else if (input[i]=='[') {
        cout <<array[2][0]<<endl;
        topdownsyntax.pop();
        topdownsyntax.push('S');
      }
    }
    else if (topdownsyntax.top()=='E') {
      if (input[i]==':') {
        cout <<array[3][2]<<endl;
        topdownsyntax.pop();
        topdownsyntax.push('A');
        topdownsyntax.push(':');
      }
      else if (input[i]=='+') {
        cout <<array[3][3]<<endl;
        topdownsyntax.pop();
        topdownsyntax.push('A');
        topdownsyntax.push('+');
      }
      else{
        cout <<array[3][1]<<endl;
        topdownsyntax.pop();
      }
    }
  }
  if (topdownsyntax.empty()) {
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
