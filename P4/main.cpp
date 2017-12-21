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
	bool wi=false;
        bool wj=false;
	while(k<n){
                if(!wi)
                    ci=a[i];
                if(!wj)
                    cj=a[j];
		l=0;
		r=0;
                if(wi==true)
                    wi=false;
                if(wj==true)
                    wj=false;
                if(ci=='w'){
                    wi=true;
                    ci='b';
                }
                if(cj=='w'){
                    wj=true;
                    cj='b';
                }
		while((a[i]==ci||a[i]=='w')&&l<n){
			i=mod((i-1),n);
			s++;
			l++;
		}
		while((a[j]==cj||a[j]=='w')&&(l+r)<n){
			j=mod((j+1),n);
			s++;
			r++;
		}
                if(!wi&&!wj){
                    i=mod((i+l+1),n);
                    j=mod((j-r+1),n);
                    k++;
                }
                else{
                    if(wi)
                        ci='r';
                    if(wj)
                        cj='r';
                    i=mod((i+l),n);
                    j=mod((j-r),n);
                }
		if(s>max)
			max=s;
		s=0;
	}
	writer << max << endl;

	
	
    return 0;
}



