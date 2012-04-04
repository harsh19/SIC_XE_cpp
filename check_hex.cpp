// basic file operations
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    short x=0x11;
    short a=11;
    string s="11";
    int temp=0x0;
    char ch;
    for(int i=0;i<s.length();i++){ch=s[i];temp=temp*10+(ch-48);}
    cout<<temp<<endl;

    int p=0x0;
    cout<<x<<endl;
}

