#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {

	string input;
	cout<<"Do you want to insert your own string for check, or use the default one([[y:x]+[x:y]])?"<<endl;
	cout<<"Insert your string now with '$' at the end or type 'no' to use the default"<<endl;
	cin>>input;
	if (input=="no")
		input = "[[y:x]+[x:y]]$";
  	stack<char> topdownsyntax;
  	topdownsyntax.push('$');
  	topdownsyntax.push('S');
	  int i = 0;
	  while (i<input.length()) {
	    if (topdownsyntax.top() == input[i] && input[i]!='$' && topdownsyntax.top()!='$') {
	      topdownsyntax.pop();
	      i++;
	    }
	    else if (input[i]=='$' && topdownsyntax.top()=='$')
	    {
	    	cout<<endl<<"The result is:"<<endl<<"Yes"<<endl;
	    	break;
	    }
	    else if (topdownsyntax.top()=='S'){
	      cout <<"S->[A]"<<endl;
	      topdownsyntax.pop();
	      topdownsyntax.push(']');
	      topdownsyntax.push('A');
	      topdownsyntax.push('[');
	    }
	    else if (topdownsyntax.top()=='A') {
	      cout <<"A->BE"<<endl;
	      topdownsyntax.pop();
	      topdownsyntax.push('E');
	      topdownsyntax.push('B');
	    }
	    else if (topdownsyntax.top()=='B') {
	      if (input[i]=='x') {
	        cout <<"B->x"<<endl;
	        topdownsyntax.pop();
	        topdownsyntax.push('x');
	      }
	      else if (input[i]=='y') {
	        cout <<"B->y"<<endl;
	        topdownsyntax.pop();
	        topdownsyntax.push('y');
	      }
	      else if (input[i]=='[') {
	        cout <<"B->S"<<endl;
	        topdownsyntax.pop();
	        topdownsyntax.push('S');
	      }
	    }
	    else if (topdownsyntax.top()=='E') {
	      if (input[i]==':') {
	        cout <<"E->:A"<<endl;
	        topdownsyntax.pop();
	        topdownsyntax.push('A');
	        topdownsyntax.push(':');
	      }
	      else if (input[i]=='+') {
	        cout <<"E->+A"<<endl;
	        topdownsyntax.pop();
	        topdownsyntax.push('A');
	        topdownsyntax.push('+');
	      }
	      else{
	        cout <<"E->e"<<endl;
	        topdownsyntax.pop();
	      }
	    }
	    else{
	      	cout<<endl<<"The result is:"<<endl<<"No"<<endl;
			break;
	    }
	  }
}