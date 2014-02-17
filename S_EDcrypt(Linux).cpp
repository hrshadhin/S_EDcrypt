#include <iostream>
#include<sstream>
#include<algorithm>
#include <string>
#include <cmath>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include <termios.h>
#include <unistd.h>
using namespace std;
string getkey(void);
void enString(char m, char n);

void help(void);


string mstr="";
string key;
string eStringPlain="";

int main(int argc, char *argv[]){

     if(argc == 3)
     {

         ifstream the_file ( argv[1] ); //input file
         if ( !the_file.is_open() )
                cout<<"Could not open file.File not exits!\n";
         else {
                key = getkey(); //get key value
                ofstream outputFile;
                outputFile.open(argv[2]); //output file
                string readstr;
                cout<<"\nPlease wait.your file is being processing........"<<endl;
                //read input file until end
                while(!the_file.eof()){
                    getline(the_file,readstr);
                    mstr = readstr;
                    int j=0;
                    int len_key=key.size();
                    for(int i=0;i<mstr.size();i++){


                             enString(mstr[i],key[j]);

                            j++;
                            if(j==len_key){
                                j=0;
                            }


                    }

                    outputFile<<eStringPlain;
                    outputFile<<"\n";
                    eStringPlain="";
                    mstr="";
                }
                the_file.close();
                outputFile.close();
                cout<<"|===============================================|"<<endl;
                cout<<"         Your file save as "<<argv[2]<<endl;
                cout<<"|===============================================|"<<endl;
        }
     }
     else if(argc > 3)
     {
          cout<<"Error in command line input.Too many arguments given.\nUse '-h or --help' for help note"<<endl;
          return 1;
     }
     else if(argc == 2)
     {

        if(strcmp(argv[1], "-h") == 0){
           help();
         }
         else if(strcmp(argv[1], "--help") == 0){
            help();
         }
         else
         {
              cout<<"Error in command line input.\nGiven Flag is incorrect.\nUse '-h or --help' for help note"<<endl;
         }

     }
     else{

        cout<<"Error in command line input.\nToo few arguments given.\nUse '-h or --help' for help note"<<endl;
     }


    return 0;
}


//Encription method
void enString(char m, char n){

     int ms = (int)m;
     int ns = (int)n;
     int result = ~(ms^ns);
     eStringPlain += (char)result;



}

//key input in hide moude function
string getkey(void)
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cout<<"Enter your key:";
    string s;
    getline(cin, s);
    if(s.size()<6){
        cout<<"\nError: *key lenght is too small. It should be greater than 6"<<endl;
        getkey();
    }
    else{
        return s;
    }

}
//help function
void help(void)
{
     cout<<"|===============================================|"<<endl;
     cout<<"|           Help Note Of S_EDcrypt              |"<<endl;
     cout<<"|===============================================|"<<endl;
     cout<<" This 'S_EDcrypt' is a simple encryption program based on \n'Vigenere cipher' method with some  extended functionality"<<endl;
     cout<<"Its do both encryption and decryption.\nUsage syntax:"<<endl;
     cout<<"++++++++++++++++++"<<endl;
     cout<<"./S_EDcrypt <input file> <output file>" <<endl;
     cout<<"+++++++++++++++++++++700+++++++++++++++++++++++++++"<<endl;
     cout<<"Product Info:"<<endl;
     cout<<"--------------"<<endl;
     cout<<"Name: S_EDcrypt"<<endl;
     cout<<"Version:1.13.12"<<endl;
     cout<<"FeedBack: https://github.com/hrshadhin/S_EDcrypt"<<endl;
     cout<<"--------------------------------"<<endl;

     cout<<"This Program is made by H.R.Shadhin :#$"<<endl;
     cout<<"Email: hrshadhin.i386@gmail.com"<<endl;
     cout<<"Social Media: t@hrshadhin <> g@HabiburRahmanShadhin"<<endl;
     cout<<"++++++++++++++++++++++++0++++++++++++++++++++++++++++++"<<endl;


}
