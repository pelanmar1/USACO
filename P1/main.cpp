/*
ID: pelanma1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
	ifstream reader("ride.in");
	ofstream writer("ride.out");
	if(!reader)
		cout << "There has been a problem while reading the file." << endl;
	else
	{
	char x;
	int tot1=1;
	int tot2=1;
	int c;
	bool b=true;
	for (int i=0; !reader.eof();i++){
		reader.get(x);
		if(reader.eof()) break;
		c=int(x)-64;
		if(!(int(x)>64 and int(x)<64+27)){
		   b=false;
		   c=1;
		}
		if(b==true)
		   tot1=tot1*c;
		else
		   tot2=tot2*c;	
	}
	if(tot1%47==tot2%47)
		writer<< "GO" << endl;
	else
		writer<< "STAY" << endl;
	}
	return 0;
}