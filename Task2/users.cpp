#include "users.h"
#include <bits/stdc++.h>
using namespace std;

static bool flag=0;                                                //flag to know if the name that is being searched is found or not
Users::Users( string n, string t, string e)
{
    Name=n;
    TeleNo=t;                                                       //saving name,telephone,email
    Email=e;


}
void Users::All_U(int i, int Case){
    if(Case==0){                                                  //to know whether from case 4 or 7 (0 =>case 4)
        cout<<"\t\tUser "<<(i+1)<<":\n"
            <<"\t\t\tName:"<<Name
            <<"\n\t\t\tTelephone number:"<<TeleNo                 //typing out each user
            <<"\n\t\t\tEmail:"<<Email<<"\n";
        int sizz=ava.size();                                      //sizz is the size of ava to know whether the user is renting robots or not and which ones
        if(sizz!=0){cout<<"\t\t\tUser is renting robot number : ";
                cout<<ava[0]<<" in ("<<Datee<<")";                //printing out saved robot number and the date to be rented in
                for(int i=1;i<sizz;i++){
                       cout<<", "<<ava[i]<<" in ("<<Datee<<")\n";}if(sizz==1){cout<<"\n";}}  //printing out first rented robot alone just not to print ',' if there were only one robot is rented
        }
    else{
        cout<<"\t\tUser "<<(i+1)<<":"<<Name<<"\n";                //else(meaning that it is entered from case 7) just typing name,user number
    }


}
void Users::Ser(string s_n,int i){
    if(s_n==Name){                                               //check if the entered name is equal any user name
       cout<<"\t\tUser "<<(i+1)<<":\n"
           <<"\t\t\tName:"<<Name
           <<"\n\t\t\tTelephone number:"<<TeleNo
           <<"\n\t\t\tEmail:"<<Email<<"\n";flag=1;            //typing out it's data if found ,flag=>1 to know there is a match
       int sizz=ava.size();
       if(sizz!=0){cout<<"\t\t\tUser is renting robots number : ";
               cout<<ava[0];
               for(int i=1;i<sizz;i++){                                        //loop to show the robots rented be the user
                      cout<<", "<<ava[i]<<"\n";}if(sizz==1){cout<<"\n";}}
}}
void Users::check(){
    if (flag==0){cout<<"\tUser not found\n\n";}               //if flag=>0(there is no match), type out user not found
    flag=0;                                                   //returning flag to 0 after each check
}

string Users::rent(string d,string m ,string y){
    int di,mi,yi;                                                //int to transform strings to
    stringstream s2;s2<<d;s2>>di;
    stringstream s3;s3<<m;s3>>mi;
    stringstream s1;s1<<y;s1>>yi;                               //transform d,m,y to int
    if(di>=1 && di<=30){Day=d;}else{cout<<"Invalid Day Entered(default 6)\n";Day="6";}            //make sure the entered day is correct, if not it will be saved as "6" as default
    if(mi>=1 && mi<=12){Month=m;}else{cout<<"Invalid Month Entered(default 10)\n";Month="10";}     //make sure the entered month is correct, if not will be saved as "10" as default
    if(yi<2022||yi>2100){
    cout<<"Invalid Year Entered(default 2022)\n";          //make sure the entered year is correct ,if not will be saved as "2022" as default
    Year="2022";}else{Year=y;}
    string Date= Day+"/"+Month+"/"+Year;                   //contacenate the whole date
    Datee=Date;                                      //saving Date to the instance string Datee to be used to show the date of the rented robots
    return Date;
}

void Users::avail(int robo){
 ava.push_back(robo);                                      //saving the number of the chosen robot(to be rented) in ava vector
}





















