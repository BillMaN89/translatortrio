// met1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
	stack<char> nas;
	char x;
  int steps;

	ifstream myfile;
	myfile.open(argv[1]);
  std::cout << "Do you want to display the steps done?" << endl<<"Type 1 for yes,2 for no"<<endl;
  cin>>steps;
	while (myfile >> x) {
		if (x == '(') {
			nas.push(x);
      if (steps==1)
			   cout << "Left Parenthesis Added to the stack"<<endl;
		}
		else if (x == ')') {
			if (!nas.empty()) {
				nas.pop();
        if (steps==1)
				    cout << "Right Parenthesis inserted->Left Parenthesis Popped out"<<endl;
			}
			else {
        nas.push(')');
        if (steps==1)
				    cout << "No Parenthesis set found"<<endl;
				break;
			}
		}
	}
	if (nas.empty()) {
		cout << "YES"<<endl;
	}
	else {
		cout << "NO"<<endl;
	}




	return 0;
}
