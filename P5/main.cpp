/*
ID: pelanma1
LANG: C++
TASK: milk2
*/
#include<iostream>
#include<fstream>
using namespace std;

bool arr[1000002];
int k;
int s;
int f;
int maxAct;
int maxNAct;
int contA;
int contNA;

int main(){
	ifstream reader("milk2.in");
        ofstream writer("milk2.out");
	int n;
	int minS=1000002;
	int maxF=-1;
	reader>> n;
	
	while(k<n){
		reader >> s;
		reader >> f;
		if(s<minS)
			minS=s;
		if(f>maxF)
			maxF=f;
		while(s<f){
			if(arr[s]==false)
				arr[s]=true;
			s++;
		}
		k++;
	}
	for(int i=minS;i<=maxF;i++){
		if(arr[i]==false){
			contNA++;
			if(contA>0){
				if(contA>maxAct){
					maxAct=contA;
				}
				contA=0;
			}
		}
		else{
			contA++;
			if(contNA>0){
				if(contNA>maxNAct){
					maxNAct=contNA;
				}
				contNA=0;
			}
		}	
	}
	
	writer <<maxAct<<" "<<maxNAct<< endl;
}