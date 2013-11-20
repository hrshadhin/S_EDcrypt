#include <iostream>
#include<sstream>
#include<algorithm>
#include <string>
#include <cmath>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
string binary(int x);
void strvalue(char y, char z);
void enString(string m, string n);
void b2d(string b);
void help(void);


string mstr="";
string eStringBin="";
string eStringPlain="";

int main(int argc, char *argv[]){

     if(argc == 4)
     {
         string key= argv[3];//key
         ifstream the_file ( argv[1] ); //input file
         if ( !the_file.is_open() )
                cout<<"Could not open file.File not exits!\n";
         else {
                ofstream outputFile;
                outputFile.open(argv[2]); //output file
                string readstr;
                cout<<"Please wait.your file is being processing........"<<endl;
                //read input file until end
                while(!the_file.eof()){
                    getline(the_file,readstr);
                    mstr = readstr;
                    int j=0;
                    int len_key=key.size();
                    for(int i=0;i<mstr.size();i++){
                        eStringBin="";

                            strvalue(mstr[i],key[j]);
                            b2d(eStringBin);
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
                cout<<"         Your file save as "<<argv[3]<<endl;
                cout<<"|===============================================|"<<endl;
        }
     }
     else if(argc > 4)
     {
          cout<<"Error in command line input.Too many arguments given.Use '-h or --help' for help note"<<endl;
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

string binary(int x) //Decimal to binary convert function
{
    string reminder="";
    int number=x;
    int rem;
    while(number!=0)
    {

        rem=number%2;
        ostringstream s;
        s<<rem;
        reminder +=s.str();
        number=number/2;

    }
    reverse(reminder.begin(),reminder.end());
    return reminder;

}

//binary string matching. make equal of main string and key string
void strvalue(char y, char z){
    int value1=int(y);//char to int
    int value2=int(z); //char to int
    string mbin_str=binary(value1); //convert int to binary string
    string kbin_str=binary(value2);
    int ml=mbin_str.size();
    int kl=kbin_str.size();
    int dif = abs(ml-kl);
    if(ml<kl)//check equalty if not then add extra 0 bit
        {
            reverse(mbin_str.begin(),mbin_str.end());
            for(int i=0;i<dif;i++)
            {
                 mbin_str.append("0");
            }

            reverse(mbin_str.begin(),mbin_str.end());
        }
        else if(ml>kl)
        {
            reverse(kbin_str.begin(),kbin_str.end());
            for(int i=0;i<dif;i++)
            {
                 kbin_str.append("0");
            }
            reverse(kbin_str.begin(),kbin_str.end());
        }




    enString(mbin_str,kbin_str);//call encript method

}

//Encription method
void enString(string m, string k){
     string temp_m=m;
     string temp_k=k;
     char *mat ="1";
     for(int i=0;i<temp_m.length();i++){
         if(temp_m[i]==temp_k[i]){

                eStringBin +='1';
         }
         else{
             eStringBin +='0';
         }

     }



}

//Binary to Decimal convert function
void b2d(string b){
    string binaryS=b;
    int len =binaryS.size();
    reverse(binaryS.begin(),binaryS.end());
    int power = 0;
    int decimal1 = 0;
    while(power<len){
        if(binaryS[power]=='1'){
            decimal1 += 1*pow(2,power);
        }
        power++;
    }

    eStringPlain += char(decimal1);


}
//help function
void help(void)
{
     cout<<"|===============================================|"<<endl;
     cout<<"|           Help Note Of S_EDcrypt              |"<<endl;
     cout<<"|===============================================|"<<endl;
     cout<<" This 'S_EDcrypt' is a simple encryption program based on \n'Vigenère cipher' method with some  extended functionality"<<endl;
     cout<<"Its do both encryption and decryption.\nUsage syntax:"<<endl;
     cout<<"++++++++++++++++++"<<endl;
     cout<<"./S_EDcrypt <input file> <output file> <key>" <<endl;
     cout<<"+++++++++++++++++++++700+++++++++++++++++++++++++++"<<endl;
     cout<<"Product Info:"<<endl;
     cout<<"--------------"<<endl;
     cout<<"Name: S_EDcrypt"<<endl;
     cout<<"Version:1.13.11"<<endl;
     cout<<"FeedBack: https://github.com/hrshadhin/S_EDcrypt"<<endl;
     cout<<"--------------------------------"<<endl;

     cout<<"This Program is made by H.R.Shadhin :#$"<<endl;
     cout<<"Email: hrshadhin.i386@gmail.com"<<endl;
     cout<<"Social Media: t@hrshadhin <> g@HabiburRahmanShadhin"<<endl;
     cout<<"++++++++++++++++++++++++0++++++++++++++++++++++++++++++"<<endl;


}
