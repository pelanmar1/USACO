/*
ID: pelanma1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>

using namespace std;

int mod (int a, int b)
{  
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
int main(int argc, char** argv) {
        ifstream reader("beads.in");
        ofstream writer("beads.out");
	int n;
	reader>>n;	
        char a[n];
	for(int i=0;i<n;i++){
		reader>>a[i];
	}
	int k=0;
	int l=0;
	int r=0;
	int i=0;
	int j=1;
	int s=0;
	int max=0;
	char ci;
	char cj;
	
	while(k<n){
		ci=a[i];
		cj=a[j];
		l=0;
		r=0;
		while((a[i]==ci||a[i]=='w')&&l<n){
			i=mod((i-1),n);
			s++;
			l++;
		}
		while((a[j]==cj||a[j]=='w')&&l!=n){
			j=mod((j+1),n);
			s++;
			r++;
		}
		i=mod((i+l+1),n);
		j=mod((j-r+1),n);
		k++;
		if(s>max)
			max=s;
		s=0;
	}
	writer << max << endl;
	
	
	
    return 0;
}


