#ifndef PASS2_H_INCLUDED
#define PASS2_H_INCLUDED

#include <iostream>
#include <fstream>
#include "all2.h";
#include "optable.h";
#include "hexfunc.h";
#include "subtract_hex.h";
using namespace std;
void processword_2(string words[],int cword);

void processline_2(string s)
{
    bool flag_comment=false;
    // s=s+" ";//adding space to end..
    //cout<<s<<"hi"<<endl<<endl;
    string words[5];

    int len;len=s.length();
    char ch;string w;w="";
    int cword=0;//count words of line....

    for(int i=0;i<len-1;i++)
    {
        ch=s[i];//cout<<"i,ch,cword  "<<i<<" "<<ch<<" "<<cword<<endl;

       // if(ch=='/n')continue;

        //if(ch==':')//{flag_comment=true;break;}
        //{if(w!=""){words[cword++]=w;w="";break;}
        //else break;}//rest is comment portion

        //if(cword==3)break;//rest is considered to be comment...

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
    //for(int i=0;i<cword;i++)cout<<words[i]<<endl;
        //if(cword==2 || cword==3)
        processword_2(words,cword);
    //cout<<cword<<endl;
}


void processword_2(string words[],int cword)
{
   string address,code;


    ofstream myfile;
  myfile.open ("output.txt", ios::out | ios::app);

    //-->
    cout<<"inside processword_2..."<<endl;cout<<cword<<endl;
    for(int i=0;i<cword;i++)cout<<words[i]<<endl;
    cout<<endl;

    string label="",operat="",operand="";
    //char n='0',i='0',x='0',b='0',p='0',e='0';
    int n=0,i=0,x=0,b=0,p=0,e=0;

    if(cword==3)//no label
    {
        operat=words[0];operand=words[1];address=words[2];
       // cout<<operand<<endl<<endl;
    }
    else//word==4
    {
        label=words[0];operat=words[1];operand=words[2];address=words[3];
        cout<<"label..."<<label<<endl;
//cout<<operand<<endl<<endl;
        //1) search for label...
        //2) if found set error
        //3) if not found insert into symtab

        //**1)....
        //if(start!=false)
        //{insert_symtab(label);}
      //*****
      //myfile<<label<<" ";

    }
    cout<<"operat,operand,address...."<<operat<<"--"<<operand<<"--"<<address<<endl;
    //search optab for opcode...

//cout<<"--->operat<--"<<operat<<"--"<<endl;


 //----defining....
   // short code=0;
   char form;//for format..
   // int f;


    if(operat=="START")
    {
       // writeheader();return;
    }
        //start=true;

       /* int temp=0x0,d=0;
    char chh;
    for(int i=0;i<operand.length();i++)
    {chh=operand[i];
    if(chh>=48 && chh<=57){d=chh-48;}
    else if( (chh>=65 && chh<=70) ){d=chh-65+10;}
    temp=temp*10+(d);}
    cout<<"***************"<<temp<<endl;*/
//locctr=temp;
/*
addr=operand;start_add=operand;
myfile<<operat<<" "<<operand<<" "<<addr;
        insert_symtab(label);//***CHECK FOR ERROR HERE>>>OPERAND HAS TO BE HEX. NO.
        //locctr=operand;

    }*/


   //else//if not start
   // {
   string foradd="";string mid="0",disp="";int t;
   string net;//net operand...

   bool found4=false;e=0;
        char qw=operat[0];
        if(qw=='+'){e=1;found4=true;operat=operat.substr(1);}

        bool find=search(operat);
        if(find==true)
        {
            form=temp.format;if(found4==true && form=='3'){form++;//operat=qw+operat;
            }
            //f=form-48;

            code=temp.opcode;
            //-->decide n,i-->code to code-->TWO HALF BYTES...
            qw=operand[0];bool printmid=true;
            if(found4==true)
            {
                p=0;e=1;net=operand;
                int j;
               // cout<<"************************************"<<endl;
               // cout<<"SEARCHING FOR "<<operand<<endl;
                for(j=0;j<symtab_ctr;j++)
                {
                    //cout<<SYMTAB[j].label<<SYMTAB[j].address<<endl;
                    if(operand == SYMTAB[j].label)
                    {//cout<<"FOUND!!!!!"<<endl;
                    break;}

                }
               // cout<<"***********************"<<endl;
                net=SYMTAB[j].address;

               n=1;i=1; t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;
                //***set length of operand to 5 half bytes
            }
            else if(qw=='#')//immediate...
            {
                n=0;i=1;net=operand.substr(1);

                t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;
            }

            else if(qw=='@')//immediate addressing...
            {
                n=1;i=0;net=operand.substr(1);

                t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;
            }

            else if(form=='1')
             {
                 /*int lp=operand.length();
                 if(lp!=1){//set error!!!!!!!!
                     }
                        n=0;i=0;
                t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;

            printmid=false;string op1;
            switch(operand[0])
                {
                    case'A':op1="0";
                     break;
                    case'X':op1="1";
                     break;
                    case'L':op1="2";
                     break;
                    case'B':op1="3";
                     break;
                    case'S':op1="4";
                     break;
                    case'T':op1="5";
                     break;
                    case'F':op1="6";
                     break;
                      default:op1="";
                }
            net=op1+'0';*/
             }

            else if(form=='2')
            {

                if(operat=="CLEAR")
                {
                    //check length of operand!!!!!!!!!!!!!
                    operand=operand+",A";//since A would correspond to a zero
                }


                int lp=operand.length();if(lp!=3)cout<<"ERRORRRRRRRRRRRRRRRRRRRRR"<<endl;
                char ch1,ch2;
                ch1=operand[0];ch2=operand[2];string op1,op2;
                switch(ch1)
                {
                    case'A':op1="0";
                     break;
                    case'X':op1="1";
                     break;
                    case'L':op1="2";
                     break;
                    case'B':op1="3";
                     break;
                    case'S':op1="4";
                     break;
                    case'T':op1="5";
                     break;
                    case'F':op1="6";
                     break;
                      default:op1="";
                }
                switch(ch2)
                {
                    case'A':op2="0";
                     break;
                    case'X':op2="1";
                     break;
                    case'L':op2="2";
                     break;
                    case'B':op2="3";
                     break;
                    case'S':op2="4";
                     break;
                    case'T':op2="5";
                     break;
                    case'F':op2="6";
                     break;
                      default:op2="";
                }
                n=0;i=0;
                t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;

            printmid=false;
            net=op1+op2;

            }
            else//indirect addressing
            {

                int pos=operand.find(',');int lp=operand.length();x=0;
                if(pos>=0 && pos<lp)//index registering expected...here i am dealing only with format 3
                {
                    x=1;operand=operand.substr(0,lp-2);cout<<".................."<<operand<<endl;
                }

                n=1;i=1;p=1;string tt="";tt=tt+form;
                string pctr=addhex(address,tt);int j;
                cout<<"************************************"<<endl;
                cout<<"SEARCHING FOR "<<operand<<endl;
                for(j=0;j<symtab_ctr;j++)
                {
                    cout<<SYMTAB[j].label<<SYMTAB[j].address<<endl;
                    if(operand == SYMTAB[j].label)
                    {cout<<"FOUND!!!!!"<<endl;break;}

                }
                cout<<"***********************"<<endl;
                net=SYMTAB[j].address;
cout<<"address,PCTR============     "<<address<<"  "<<pctr<<endl;
                if( compare(net,pctr) )
                {
                    net=subtract_hex(net,pctr);//cout<<"111111111111111111111111111111111111111111111111"<<net<<endl;
                }
                else
                {
                    net=subtract_hex(pctr,net);
                    net=compliment(net);
                }


               // net=subtract_hex(pctr,net);
                t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;

            }

           // n=1;i=1;


            //decide x,b,p,e...
            mid="0";
            if(printmid==true)
            {t=x*8+b*4+p*2+e*1;//cout<<"TTTTTTTTTTTTTTTTTTTTTTTTT"<<t<<endl;
            foradd=tohexstr(t);
            mid=addhex(foradd,mid);
            myfile<<mid;//ONE HALF BYTE....
            }
            //find displacement in 3 HALF BYTES FOR FORMAT 3!!!!!!*******....
            //cout<<"find is true....."<<f<<"  "<<code<<endl<<endl;
            //disp=address;

            int j=net.length();
           if(e==0)
           {
             if(form!='2')
            {if(j==4){net=net.substr(1);}
            else{for(int k=1;k<=(3-j);k++)
             net='0'+net;}}
           }
           else
           {
               for(int k=1;k<=(5-j);k++)
             net='0'+net;
           }

            myfile<<net;
            string ss="";ss=ss+form;
            addr=addhex(addr,ss);
        }
        //else if(operat=="END")
         //myfile<<operat<<" "<<operand;
       // else
         //cout<<operat<<"  NOT FOUND!!!!!!!!"<<endl;
 myfile<<endl;
 myfile.close();

}


#endif // PASS2_H_INCLUDED
