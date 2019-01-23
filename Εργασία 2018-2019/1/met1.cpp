#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
	stack<char> nas;
	char x;
	int steps;
	nas.push('$');
	ifstream myfile;
	myfile.open(argv[1]);
	cout << "Do you want to display the steps done?" << endl<<"Type 1 for yes,2 for no"<<endl;
	cin>>steps;
	while (myfile >> x) {
		if (x == '(') {
			nas.push('A');
      		if (steps==1)
				cout << "Left Parenthesis Found. Stack status: (k1, A inserted)"<<endl;
		}
		else if (x == ')') {
			if (nas.top()!='$') {
				nas.pop();
	       		if (steps==1)
					cout << "Right Parenthesis Found. Stack status: (k1, A popped out)"<<endl;
			}
			else {
        		nas.push('A');
       			if (steps==1){
					cout << "Rigt Parenthesis Found without a Left to close. No rule found for that situation."<<endl;
					break;
				}
			}
		}
	}
		if (nas.top()=='$') {
			if (steps==1)
				cout<<"No more Parenthesis to insert. Stack status: (k2,$)"<<endl;
			cout << "YES"<<endl;
		}
		else {
			if (steps==1)
				cout<<"No more Parenthesis to insert. Stack status: (k2,A)"<<endl;
			cout << "NO"<<endl;
		}
	return 0;
}
