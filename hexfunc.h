#ifndef HEXFUNC_H_INCLUDED
#define HEXFUNC_H_INCLUDED
#include "subtract_hex.h"




string addhex(string str1,string str2)
{
    char ch1,ch2,ch3;int d1,d2,s,c,i,j;string s1,s2,ans="";


   // cout<<"enter 2 integers"<<endl;
    //cin>>str1>>str2;
    if(str1.length()>str2.length())
       {s1=str1;s2=str2;}
    else
      {s1=str2;s2=str1;}

      c=0;int q=s1.length()-s2.length();

      for(int a=1;a<=q;a++)
      {s2='0'+s2;}



      //if(s1.length()==s2.length()){s1='0'+s1;}
      //s2='0'+s2;
      for(i=s2.length()-1;i>=0;i--)
      {
              ch1=s1[i];if(ch1>=65)d1=10+ch1-65;else d1=ch1-48;
              ch2=s2[i];if(ch2>=65)d2=10+ch2-65;else d2=ch2-48;
              s=d1+d2+c;
              c=0;
              if(s>15)
              {

                     c=s/16;
                     s=s%16;
              }
              ch3=s+48;
              if(ch3>57)ch3=55+s;
              ans=ch3+ans;
              //cout<<ch1<<endl<<ch2<<endl<<d1<<endl<<d2<<endl<<s<<endl<<ans<<endl;
      }

      if(c>0)
       {ch3=c+48;
       ans=ch3+ans;}
     return ans;
}

string tohexstr(int n)
{

char ch='0';
    if(n<16)
    {
       // cout<<"<16..."<<endl;
        int x=n;if(x<10)ch=x+48;
    else{int p=x-9;ch=p+48;ch=ch+16;}

     //cout<<"ch..."<<ch<<endl;
    string temp="";temp=temp+ch;
    return temp;
    }
//cout<<">16..."<<endl;
    int x=n%16;if(x<10)ch=x+48;
    //int p=x;cout<<p<<endl<<"ngtjnhy"<<endl;
     else{int p=x-9;ch=p+48;ch=ch+16;}
    //else{ch=55+x;}
    //cout<<"ch..."<<ch<<endl;
    return (tohexstr(n/16)+ch);
}

string compliment(string a)//2s compliment on the input hex 'a'
{
    int len=a.length();string ans="";
    for(int i=0;i<len;i++)
     ans='F'+ans;
    ans=subtract_hex(ans,a);//t_hex
    ans=addhex(ans,"1");
    return ans;

}

bool compare(string s1,string s2)//for equality, return true..
{
    //removing leading zeroes..
    int i=0;char ch=s1[i];
    while(i<s1.length() && ch=='0')
    {
        ch=s1[i];
        i++;
    }
    s1=s1.substr(max(0,i-1));

    i=0;ch=s2[i];
    while(i<s2.length() && ch=='0')
    {
        ch=s2[i];
        i++;
    }
    s2=s2.substr(max(0,i-1));
cout<<"s1,s2..."<<s1<<"..."<<s2<<endl;

    if(s1.length()>s2.length())return true;
    if(s2.length()>s1.length())return false;
    //cout<<"befjbjsd"<<endl;
    i=0;ch=s1[i];char ch2;ch2=s2[i];
    while(i<s1.length())
    {
        ch=s1[i];ch2=s2[i];
        if(ch2>ch)return false;
        else if(ch2<ch)return true;
        i++;
    }
    return true;

}

#endif // HEXFUNC_H_INCLUDED
