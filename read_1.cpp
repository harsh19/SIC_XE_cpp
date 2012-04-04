// basic file operations
#include <iostream>
#include <fstream>
#include "all2.h";
using namespace std;

void processword(string words[],int cword);


void processline(string s)
{
    s=s+" ";//adding space to end..
    string words[3];

    int len;len=s.length();
    char ch;string w;
    w="";
    int cword=0;//count words of line....

    for(int i=0;i<len;i++)
    {
        ch=s[i];
        //if(ch==':')
        //{if(w!=""){words[cword++]=w;w="";}
       // else break;}//rest is comment portion

        if(cword==3)break;//rest is considered to be comment...

        if(ch==32 && w!="")//space
        {
            words[cword]=w;
            cword++;
            w="";
        }
        else if(ch!=32)
         {
             w=w+ch;
         }
    }
   // cword++;
    //-->
    cout<<s<<"  "<<cword<<endl;
    //<--

        //processword(words,cword);
           // if(cword==1)//symbol in label field
           // {
                //...search in symtab...
                //...if(found) error..
                //else insert into symtab(w,locctr)
               // w="";
            //}

           // else if(cword==2)//operation
           // {
                //...search optab
             //   w="";
            //}
             //else//operand...
            //{
               // ....
            //}




    //cout<<cword<<endl;
}


void processword(string words[],int cword)
{
    //-->
    cout<<"in..."<<endl;
    for(int i=0;i<cword;i++)cout<<words[i]<<endl;
    cout<<endl;

    string label="",operat="",operand="";

    if(cword==2)//no label
    {
        operat=words[0];operand=words[1];
    }
    else//word==3
    {
        label=words[0];operat=words[1];operand=words[2];
        cout<<"label..."<<label<<endl;
        //1) search for label...
        //2) if found set error
        //3) if not found insert into symtab
    }
    cout<<"operat,operand...."<<operat<<"  "<<operand<<endl;
    //search optab for opcode...

}


int main ()
{
  string line;
 // ifstream in;in.open("test.txt");
  int lcount=0;//counts the no. of lines

FILE* fptr;
fptr=fopen("test.txt","r");
//cin.get();
    while (fgets(buffer,256,fptr) != NULL)
	{

      //getline (in,line);if(line=="")continue;
      lcount++;
      cout <<"line,lcount..."<< buffer <<" "<<lcount<<endl;
      //processline(line);

   }
    fclose(fptr);
}
