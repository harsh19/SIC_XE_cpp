

#include <iostream>
#include <fstream>
#include "all2.h";
#include "optable.h";
#include "hexfunc.h";
#include "subtract_hex.h";
using namespace std;


int main()
{
    int a=27;//char ch=a;cout<<a<<endl;
    //string s=tohexstr(a);cout<<s<<endl;
   // string s2="1D";
    //cout<<s2.find('3')<<endl;
    //cout<<compare(s,s)<<endl;
    //cout<<("003">"004")<<endl;
    //cout<<compare("0033","0026")<<endl;
    //cout<<tohexstr(4096)<<endl;

string operand="#4096",net="";
char qw=operand[0];
if(qw=='#')
{
 else
  {
    net=operand.substr(1);
    int ab,num=0;char dig;
    for(int ka=0;ka<net.length();ka++)
    {
        ab=net[ka]-48;
        num=num*10+ab;
    }
     net=tohexstr(num);
  }

}
}
