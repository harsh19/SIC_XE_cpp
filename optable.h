#ifndef OPTABLE_H_INCLUDED
#define OPTABLE_H_INCLUDED
#include <iostream>
# include "all2.h"
using namespace std;
bool search(string operat)
{
//cout<<"SEARCHING!!@!@!"<<endl;
bool found=false;
for(int i=0;i<optab_length;i++)
{
    //cout<<OPTAB[i].mnemonic<<" <=> "<<operat<<endl;
    if(OPTAB[i].mnemonic==operat)
    {
       // cout<<"FOUND...."<<endl<<endl;;
        temp=OPTAB[i];
        return true;
    }
}
return false;
}


#endif // OPTABLE_H_INCLUDED
