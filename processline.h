#include <iostream>
#include <fstream>
#include "all2.h";
#include "optable.h";
#include "hexfunc.h";
#include "subtract_hex.h";
#include "pass2.h";

#ifndef PROCESSLINE_H_INCLUDED
#define PROCESSLINE_H_INCLUDED

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
        {if(w!=""){words[cword++]=w;w="";break;}
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
        if(cword==1||cword==2 || cword==3)
        processword(words,cword);

    //cout<<cword<<endl;
}


void processword(string words[],int cword)
{

    store_count++;

cout<<"-----------------------"<<endl;
    ofstream myfile;
  myfile.open ("example.txt", ios::out | ios::app);

    //-->
    cout<<"inside processword..."<<endl;
    for(int i=0;i<cword;i++)cout<<words[i]<<endl;
    cout<<endl;

    string label="",operat="",operand="";



if(cword==1 && words[0]=="RSUB")
{
    addr=addhex(addr,"3");
    myfile<<words[0]<<"  "<<addr<<endl;
    store[store_count]=addr;
    return;
}










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
      //*****
      myfile<<label<<" ";

    }
    cout<<"operat,operand...."<<operat<<"--"<<operand<<"--"<<endl;
    //search optab for opcode...

//cout<<"--->operat<--"<<operat<<"--"<<endl;


 //----defining....
    short code=0;char form;//for format..
    int f;


    if(operat=="START")
    {
        cout<<"inside!!!"<<endl;
        start=true;

       /* int temp=0x0,d=0;
    char chh;
    for(int i=0;i<operand.length();i++)
    {chh=operand[i];
    if(chh>=48 && chh<=57){d=chh-48;}
    else if( (chh>=65 && chh<=70) ){d=chh-65+10;}
    temp=temp*10+(d);}
    cout<<"***************"<<temp<<endl;*/
//locctr=temp;

addr=operand;start_add=operand;
myfile<<operat<<" "<<operand<<" "<<addr;
store[store_count]=addr;
        insert_symtab(label);//***CHECK FOR ERROR HERE>>>OPERAND HAS TO BE HEX. NO.
        //locctr=operand;
    }


    else//if not start
    {
        //find=false;
        int aa,bb;string cc="";


//if(operat=="BASE"){myfile<<operat<<"  "<<operand<<endl;return;}



        bool found4=false;
        char qw=operat[0];
        if(qw=='+'){found4=true;operat=operat.substr(1);}

        bool find=false;find=search(operat);
        if(find==true)
        {
            form=temp.format;
            f=form-48;
            if(found4==true && f==3){form++;operat=qw+operat;}// else if(found4==true) ******** ERROR
            //code=temp.opcode;
            //cout<<"find is true....."<<f<<"  "<<code<<endl<<endl;
            myfile<<operat<<" "<<operand<<" "<<addr;store[store_count]=addr;
            string ss="";ss=ss+form;
            addr=addhex(addr,ss);
        }
        else if(operat=="END")
         myfile<<operat<<" "<<operand;
         else if(operat=="RESW")
          {
              bb=0;
            //operand to integer...integer to hex...
            for(int dd=0;dd<operand.length();dd++)
             {qw=operand[dd];aa=qw-48;bb=bb*10+aa;}
             cc=tohexstr(3*bb); // 3*bb because size of each word is 3 bytes...


            //remove next 2 lines
            //cout<<"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"<<endl<<bb<<endl<<cc<<endl<<addr<<endl<<endl;;
            myfile<<operat<<" "<<operand<<" "<<addr;
            store[store_count]=addr;
            addr=addhex(addr,cc);
          }

          else if(operat=="RESB")
          {
              bb=0;
            //operand to integer...integer to hex...
            for(int dd=0;dd<operand.length();dd++)
             {qw=operand[dd];aa=qw-48;bb=bb*10+aa;}
             cc=tohexstr(bb);


            //remove next 2 lines
            //cout<<"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"<<endl<<bb<<endl<<cc<<endl<<addr<<endl<<endl;;
            myfile<<operat<<" "<<operand<<" "<<addr;
            store[store_count]=addr;addr=addhex(addr,cc);
          }

          else if(operat=="WORD")
          {
              bb=0;
            //operand to integer...integer to hex...
            //for(int dd=0;dd<operand.length();dd++)
            // {qw=operand[dd];aa=qw-48;bb=bb*10+aa;}
            // cc=tohexstr(3*bb); // 3*bb because size of each word is 3 bytes...
             cc="3";

            //remove next 2 lines
            //cout<<"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"<<endl<<bb<<endl<<cc<<endl<<addr<<endl<<endl;;
            myfile<<operat<<" "<<operand<<" "<<addr;
            store[store_count]=addr;
            addr=addhex(addr,cc);
          }

          else if(operat=="BASE")
           {
           //assuming that after BASE there is a label as operand...

           myfile<<operat<<" "<<operand;

           }

         else if(operat=="BYTE")
         {
            char q=operand[0];
             if(q=='C')
             {
                 int qwerty=operand.length();
                 cc=tohexstr(qwerty-3);//operand=operand.substr(2,qwerty-3);
                 myfile<<operat<<" "<<operand<<" "<<addr;store[store_count]=addr;
                 addr=addhex(addr,cc);
             }
             else if(q=='X')
             {
                 int qwerty=operand.length();
                 cc=tohexstr( (qwerty-3+1)/2 );//operand=operand.substr(2,qwerty-3);
                 myfile<<operat<<" "<<operand<<" "<<addr;store[store_count]=addr;
                 addr=addhex(addr,cc);
             }

         }

        else
         cout<<operat<<"  NOT FOUND!!!!!!!!"<<endl;
    }
myfile<<endl;
 myfile.close();

}

#endif // PROCESSLINE_H_INCLUDED
