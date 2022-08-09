#ifndef USERS_H
#define USERS_H
#include <bits/stdc++.h>
using namespace std;

class Users
{
private:
   string Name;
   string TeleNo;
   string Email;
   string Day,Month,Year;                      //variables for name,telephone,email,day,month,year
   string Datee;
   vector<int> ava;
public:
    Users(string n, string t, string e);          //constructor taking name,telephne,email
    void All_U(int i,int Case);                   //fn to get all saved users
    void Ser(string s_n, int i);                  //fn to search user by name
    void check();                                 //fn to check if name is found or not
    string rent(string d,string m ,string y );    //fn to rent
    void avail(int robo);

};

#endif // USERS_H
