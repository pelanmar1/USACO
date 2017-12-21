/*
ID: pelanma1
LANG: C++
TASK: transform
*/
#include<iostream>
#include<fstream>
using namespace std;
int n;

bool checkEqual(char** m1, char** m2){
    bool resp=true;
    int i=0;
    int j=0;
    while(i<n&&resp){
        j=0;
        while(j<n&&resp){
            if(m1[i][j]!=m2[i][j])
                resp=false;
            j++;
        }
        i++;
    }
    
    return resp;
}
char** trans1Ret(char** mIna){
    char** mA;
    mA= new char*[n];
    for (int i = 0; i < n; i++)
    {       
        mA[i] = new char[n];
        for(int j=0;j<n;j++)
            mA[i][j]=mIna[i][j];
    }
    //Rotamos 90 g
    for (int i = 0; i < n; i++)
    {       
        for(int j=0;j<n;j++){
            mA[i][n-1-j]=mIna[j][i];
        }
    }
    return mA;
}
char** trans2Ret(char** mIna){
    
    char** mA=trans1Ret(mIna);
    return trans1Ret(mA);
}
char** trans3Ret(char** mIna){
    
    char** mA=trans2Ret(mIna);
    return trans1Ret(mA);
}
char** trans4Ret(char** mIna){
    char** mA=0;
    mA= new char*[n];
    for (int i = 0; i < n; i++)
    {       
        mA[i] = new char[n];
        for(int j=0;j<n;j++)
            mA[i][j]=mIna[i][j];
    }
    //Reflejamos horizontalmente
    for (int i = 0; i < n; i++)
    {      
        for(int j=0;j<n;j++)
            mA[i][j]=mIna[i][(n-1)-j];
    }
    return mA;
}
bool trans5RBool(char** mIna,char** mOuta){
    bool resp=false;
    char** mA=trans4Ret(mIna);
    int i=0;
    if(checkEqual(trans1Ret(mA),mOuta)||checkEqual(trans2Ret(mA),mOuta)||checkEqual(trans3Ret(mA),mOuta))
        resp=true;
    return resp;
}




int transformations(){
	ifstream reader("transform.in");
        
        reader >>n;
        char x;
        char** mIn;
        mIn=new char*[n];
        //Leemos entrada y salida
        for(int i=0;i<n;i++){
            mIn[i] = new char[n];
            for(int j=0;j<n;j++){
                reader >> x;
                mIn[i][j]=x;
            }
        }
        char** mOut;
        mOut=new char*[n];
        for(int i=0;i<n;i++){
            mOut[i] = new char[n];
            for(int j=0;j<n;j++){
                reader >> x;
                mOut[i][j]=x;
            }
            
        }
        
        if(checkEqual(trans1Ret(mIn),mOut))
            return 1;
        if(checkEqual(trans2Ret(mIn),mOut))
            return 2;
        if(checkEqual(trans3Ret(mIn),mOut))
            return 3;
        if(checkEqual(trans4Ret(mIn),mOut))
            return 4;
        if(trans5RBool(mIn,mOut))
            return 5;
        if(checkEqual(mIn,mOut))
            return 6;
         
        return 7;
        
        
        
}
int main(){
    ofstream writer("transform.out");
    int x=transformations();
    writer<< x << endl;
    return 0;
}


