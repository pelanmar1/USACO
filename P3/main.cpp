/*
ID: pelanma1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream reader("friday.in");
	ofstream writer("friday.out");
	int n;
	reader >> n;
	int y=1900;
	int i=(2+12)%7;
	bool leap=false;
	n=n+1900;
	int j;
	int arr[7];
	for(int i=0;i<7;i++)
		arr[i]=0;
	while(y<n){
		if((y%4==0&&y%100!=0)||y==2000)
			leap=true;
		arr[i]++;
		j=1;
		while(j<12){
			switch(j){
				case 4:case 6: case 9: case 11:
					i=(i+30)%7;
					break;
				case 2:
					if(leap)
						i=(i+29)%7;
					else
						i=(i+28)%7;
					break;
				default:
					i=(i+31)%7;
					break;
			}
			arr[i]++;
			j++;
		}
		i=(i+31)%7;
		y++;
		leap=false;
	}
	for(int i=0;i<7;i++){
		if(i==6)
			writer << arr[i]<<endl;
		else
			writer << arr[i] << " ";
	
	}
	return 0;

}