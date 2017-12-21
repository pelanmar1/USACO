/*
ID: pelanma1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <string>
#include <string.h>	
#include <map>
#include <fstream>
#include <stdlib.h>


using namespace std;

int main(){
	
	
	ifstream reader("gift1.in");
	ofstream writer("gift1.out");
	string line;
	map<string,int> arr;
	
	getline(reader, line);
	int n=atoi(line.c_str());
	string ord[n];
        int i=0,j=0,k=0;
	while (k<n){
		getline(reader,line);
		//Remove \r
		int cr_pos = line.rfind('\r');
		if ( cr_pos != std::string::npos )
			line = line.substr(0, cr_pos);
		
		if(line!=""){
			arr[line]=0;
			ord[k]=line;
                        k++;
		}

	}
	int mon;
	int fr;
        while(j<n)
	{
		getline(reader,line);
		//Remove \r
		int cr_pos = line.rfind('\r');
		if ( cr_pos != std::string::npos )
			line = line.substr(0, cr_pos);
		
		
		reader >> mon >> fr ;
		if(line!=""){
			if(fr!=0)
				arr[line]+= (mon%fr)-mon;
                        else
                            getline(reader,line);
                        i=0;
                        j++;
                }
                
		
                
                while(i<fr){
			getline(reader,line);
			
			//Remove \r
			int cr_pos = line.rfind('\r');
			if ( cr_pos != std::string::npos )
				line = line.substr(0, cr_pos);
			
			if(line!=""){
				arr[line]+= mon/fr;
				i++;
			}
			
		}
                
		

	}
	
	for(int i=0;i<n;i++)
		writer << ord[i] << " " << arr[ord[i]] <<	 endl;
	
	
	
	
	
	
	return 0;
}
