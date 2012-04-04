// basic file operations
#include <iostream>
#include <fstream>
#include "all.h";
#include "optable.h";
using namespace std;

void processword(string words[],int cword);
void insert_symtab(string lab);
void print_symtab();


void processline(string s)
{
    bool flag_comment=false;

   // s=s+" ";//adding space to end..
    //cout<<s<<"hi"<<endl<<endl;
    string words[3];

    int len;len=s.length();
    char ch;string w;
    w="";
    int cword=0;//count words of line....

    for(int i=0;i<len-1;i++)
    {
        ch=s[i];//cout<<"i,ch,cword  "<<i<<" "<<ch<<" "<<cword<<endl;

        if(ch=='/n')continue;

        if(ch==':')//{flag_comment=true;break;}
        {if(w!=""){words[cword++]=w;w="";}
        else break;}//rest is comment portion

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
    if(w!=""){words[cword]=w;w="";cword++;}
   // cword++;
    //-->
    cout<<"processing line....."<<endl;
    cout<<s<<"  "<<cword<<endl;
    //<--
        if(cword==2 || cword==3)
        processword(words,cword);
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
    cout<<"inside processword..."<<endl;
    for(int i=0;i<cword;i++)cout<<words[i]<<endl;
    cout<<endl;

    string label="",operat="",operand="";

    if(cword==2)//no label
    {
        operat=words[0];operand=words[1];
       // cout<<operand<<endl<<endl;
    }
    else//word==3
    {
        label=words[0];operat=words[1];operand=words[2];
        cout<<"label..."<<label<<endl;
//cout<<operand<<endl<<endl;
        //1) search for label...
        //2) if found set error
        //3) if not found insert into symtab

        //**1)....
        if(start!=false)
        {insert_symtab(label);}


    }
    cout<<"operat,operand...."<<operat<<"  "<<operand<<endl;
    //search optab for opcode...

cout<<"--->operat<--"<<operat<<"--"<<endl;
    if(operat=="START")
    {
        cout<<"inside!!!"<<endl;
        start=true;

        int temp=0x0,d=0;
    char chh;
    for(int i=0;i<operand.length();i++)
    {chh=operand[i];
    if(chh>=48 && chh<=57){d=chh-48;}
    else if( (chh>=65 && chh<=70) ){d=chh-65+10;}
    temp=temp*10+(d);}
    cout<<"***************"<<temp<<endl;
locctr=temp;

        insert_symtab(label);//***CHECK FOR ERROR HERE>>>OPERAND HAS TO BE HEX. NO.
        //locctr=operand;
    }


}


void insert_symtab(string lab)
{
    //cout<<"CHECK SYMTAB_CTR..........."<<symtab_ctr<<endl;
    SYMTAB[symtab_ctr].label=lab;
    SYMTAB[symtab_ctr].address=locctr;symtab_ctr++;
}

void print_symtab()
{
    cout<<"printing symtab...."<<endl;
    for(int i=0;i<symtab_ctr;i++)
     cout<<SYMTAB[i].label<<"  "<<SYMTAB[i].address<<endl;cout<<endl;
}


int main ()
{
    start=false;
  string line;locctr=0;symtab_ctr=0;
 // ifstream in;in.open("test.txt");
  int lcount=0;//counts the no. of lines

FILE* fptr;
fptr=fopen("test_2.txt","r");
//cin.get();
    while (fgets(buffer,256,fptr) != NULL)
	{

      //getline (in,line);if(line=="")continue;
      lcount++;
      cout <<"line,lcount..."<< buffer <<" "<<lcount<<endl;
      processline(buffer);
      //fgets(buffer,256,fptr);

   }
   print_symtab();
   cout<<"symtab_ctr..."<<symtab_ctr<<endl;
    fclose(fptr);
}
