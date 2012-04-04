//after pass1 we hv completed the SYMTAB
// example.txt contains intermediate file....=> each line has additional field as address appended at last..


/*
--> tohex func.
--> -ive displacement for p=1;
--> base relative...
*/



#include <iostream>
#include <fstream>
#include "all2.h";
#include "optable.h";
#include "hexfunc.h";
#include "subtract_hex.h";
using namespace std;

void processword(string words[],int cword);
void writeheader()
{

}


void processline(string s)
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
        processword(words,cword);
    //cout<<cword<<endl;
}


void processword(string words[],int cword)
{
   string address,code;


    ofstream myfile;
  myfile.open ("output.txt", ios::out | ios::app);

    //-->
    cout<<"inside processword..."<<endl;cout<<cword<<endl;
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
        writeheader();return;
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

   bool found4=false;
        char qw=operat[0];
        if(qw=='+'){found4=true;operat=operat.substr(1);}

        bool find=search(operat);
        if(find==true)
        {
            form=temp.format;if(found4==true && form=='3'){form++;operat=qw+operat;}
            //f=form-48;

            code=temp.opcode;
            //-->decide n,i-->code to code-->TWO HALF BYTES...
            qw=operand[0];


            n=1;i=1;
            t=n*2+i;
            foradd=tohexstr(t);
            code=addhex(code,foradd);
            myfile<<code;

            //decide x,b,p,e...
            p=1;t=x*8+b*4+p*2+e*1;
            foradd=tohexstr(t);
            mid=addhex(foradd,mid);
            myfile<<mid;//ONE HALF BYTE....

            //find displacement in 3 HALF BYTES FOR FORMAT 3!!!!!!*******....
            //cout<<"find is true....."<<f<<"  "<<code<<endl<<endl;
            disp=address;
            myfile<<disp;
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




int main ()
{
   // ofstream myfile;
    //myfile.open("example.txt");
    //myfile.close();

  start=false;
  string line;
  //locctr=start_add;symtab_ctr=0;
  //addr="0";
 // ifstream in;in.open("test.txt");
  int lcount=0;//counts the no. of lines

FILE* fptr;
fptr=fopen("example.txt","r");
//cin.get();
    while (fgets(buffer,256,fptr) != NULL)
	{
      //getline (in,line);if(line=="")continue;
      lcount++;
      cout <<"line,lcount..."<< buffer <<" "<<lcount<<endl;
      processline(buffer);
      //fgets(buffer,256,fptr);
    }
   //print_symtab();
   //cout<<"symtab_ctr..."<<symtab_ctr<<endl;
    fclose(fptr);
//----
//cout<<"final val. of addr:"<<addr<<endl;
//length=subtract_hex(addr,start_add);
//cout<<"length of file in bytes..."<<length<<endl;
}
