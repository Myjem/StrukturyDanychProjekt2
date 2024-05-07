#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

int main(){
    fstream file;
    srand(time(NULL));
    file.open("data.txt",ios::out);
    for(int i=0;i<100000;i++) file<<i+1<<" "<<(rand()%500000)+1<<endl;//quantity of data
    file.close();
    cout<<"Number were generated";
    return 0;
}