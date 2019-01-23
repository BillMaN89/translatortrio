#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
	
	string str1 = "ekfrasi";
	int i=0,count=1;
	srand (time(NULL));
	
	while(i<=str1.length()){
		
		if(str1.substr(i,7)=="ekfrasi"){
			cout<<"Step "<<count<<": "<<str1<<endl;
			int x =rand() % 10;
			if ((x%2)==1){
				str1.replace(i,7,"oros");
			}
			else{
				str1.insert(i+7,"+oros");
			}
		}
		else if(str1.substr(i,4)=="oros"){
			cout<<"Step "<<count<<": "<<str1<<endl;
			int x =rand() % 10 ;
			if ((x%2)==1){
				str1.replace(i,4,"paragontas");
			}
			else{
				str1.insert(i+4,"*paragontas");
			}
		}
		else if(str1.substr(i,10)=="paragontas"){
			cout<<"Step "<<count<<": "<<str1<<endl;
			int x =rand() % 3 + 1;
			if (x==1){
				str1.replace(i,10,"a");
			}
			else if (x==2){
				str1.replace(i,10,"b");
			}
			else{
				str1.replace(i,10,"c");
			}
		}
		else{
			i+=1;
			count--;
		}
		count++;
	}
	cout<<"Generated String: "<<str1<<endl;
}