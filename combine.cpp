// basic file operations
#include <iostream>
#include <fstream>
#include "all2.h";
#include "optable.h";
#include "hexfunc.h";
#include "subtract_hex.h";
#include "pass2.h";
#include "processline.h";
#include "objectprog.h";
#include "listing.h"
using namespace std;
//**************CHECK FOR RSUB AND JSUB


void insert_symtab(string lab);
void print_symtab();
//void processword_2(string words[],int cword);
//void processline_2(string s);
void writeheader()
{

}





void insert_symtab(string lab)
{
    //cout<<"CHECK SYMTAB_CTR..........."<<symtab_ctr<<endl;
    SYMTAB[symtab_ctr].label=lab;
    //string loc=hex(locctr)
    SYMTAB[symtab_ctr].address=addr;symtab_ctr++;
}

void print_symtab()
{
    cout<<"printing symtab...."<<endl;
    for(int i=0;i<symtab_ctr;i++)
     cout<<SYMTAB[i].label<<"  "<<SYMTAB[i].address<<endl;cout<<endl;
}


int main ()
{
    ofstream myfile;
    myfile.open("example.txt");
    myfile.close();
     myfile.open("output.txt");
    myfile.close();

    start=false;base="";
  string line;locctr=0;symtab_ctr=0;
  addr="0";
 // ifstream in;in.open("test.txt");
  int lcount=0;//counts the no. of lines

FILE* fptr;
fptr=fopen("test3.txt","r");
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
//----
cout<<"final val. of addr:"<<addr<<endl;
length=subtract_hex(addr,start_add);
cout<<"length of file in bytes..."<<length<<endl;




start=false;
//  string line;
  //locctr=start_add;symtab_ctr=0;
  //addr="0";
 // ifstream in;in.open("test.txt");
//  int lcount=0;//counts the no. of lines

//FILE* fptr;
 fptr=fopen("example.txt","r");
//cin.get();
    while (fgets(buffer,256,fptr) != NULL)
	{
      //getline (in,line);if(line=="")continue;
      lcount++;
      cout <<"line,lcount..."<< buffer <<" "<<lcount<<endl;//cout<<"22222222222222222222222 "<<buffer<<" @@@@@@@@@@"<<endl;
      processline_2(buffer);
      //fgets(buffer,256,fptr);
    }
   //print_symtab();
   //cout<<"symtab_ctr..."<<symtab_ctr<<endl;
    fclose(fptr);
cout<<"LENGTH "<<length<<endl;
write();
listingf();
}



