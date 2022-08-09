#include <bits/stdc++.h>
using namespace std;
#include "robots.h"
#include "users.h"


int main()
{
    int st=0;string n,t,e;                                   //st to take the choosen value in, string n=>to save user name,t=>telephone,e=>email
    string rn;string id;string p;                            //rn=>robot name , id=> function id , p=> price per day
    vector<Robots> r;                                        //create vector of objects of class Robots
    vector<Users> u;                                         //create vector of objects of class Users
    vector<int> vec;
    cout<<"Welcome Admin to Amr's Robot Rental System!\n"
       <<"Main Menu:\n"
         <<"\t1 - Add robot\n"
         <<"\t2 - Add user\n"
         <<"\t3 - Display all robots\n"
         <<"\t4 - Display all users\n"
         <<"\t5 - Search for robot by name\n"
         <<"\t6 - Search for user by name\n"
         <<"\t7 - Rent robot\n"
         <<"\t8 - Exit!\n";
    while(st!=8){  string sti;                                                 //looping programme unit choose exit
    cout<<"\n===============>Enter your choice:\t"; cin>>sti;cout<<"\n";      //taking st as input
    stringstream s;s<<sti;s>>st;
    if(st<1||st>8){cout<<"\t\tplease enter a valid input\n";}
    int ua=u.size(); int ra=r.size();                                        //number of objects in Users,Robots
    int c=0;                                                                //int to know whether entered All_R function from case 4 or 7
    switch(st){                                                            // switch on the input value
    case 1:{                                                              //first case to add robot name,fn_id,price per day
        cout<<"Enter Robot Name:\t";cin>>rn;
        cout<<"Enter Robot id:\t";cin>>id;
        cout<<"Enter Robot price per day:\t";cin>>p;cout<<"\n";
        r.push_back(Robots(rn,id,p));                                 //add values to each object
        break;}
    case 2:{                                                         //second case to add user name,number,email
        cout<<"Enter User Name:\t";cin>>n;
        cout<<"Enter User Telephone Number:\t";cin>>t;
        cout<<"Enter User Email:\t";cin>>e;cout<<"\n";
        u.push_back(Users(n,t,e));                                 //add values to each object

        break;}
    case 3:{                                                     //loopig on each object to get it's data by use of All_R
        if(ra==0){cout<<"There is no robots\n";break;};
        for(int i=0;i<ra;i++){
         r[i].All_R(i);}
        break;}
    case 4:{                                                     //loopig on each object to get it's data by use of All_U
        if(ua==0){cout<<"There is no users\n";break;};
        for(int i=0;i<ua;i++){
        u[i].All_U(i,c);}
        break;}
    case 5:{
        if(ra==0){cout<<"There is no robots\n";break;};
        string s_n;
        cout<<"\tEnter name:\t";cin>>s_n;                           //taking name to be searched
        for(int i=0;i<ra;i++){                                      //loop to get the robot that you are searching for by Ser
            r[i].Ser(s_n,i);
        }r[ra-1].check();                                          //entering last object to detect whehter the name was found or not by use of check
        break;}
    case 6:{
        if(ua==0){cout<<"There is no users\n";break;};
        string s_n;
        cout<<"\tEnter name:\t";cin>>s_n;                          //taking name to be searched
        for(int i=0;i<ua;i++){                                    //loop to get the robot that you are searching for by Ser
            u[i].Ser(s_n,i);
        }u[ua-1].check();                                        //entering last object to detect whehter the name was found or not by use of check
        break;}
    case 7:{
        if(ra==0||ua==0){cout<<"There's no robots or users\n";break;}             //there should be available users and robots, so checking that both are available
        c=1;                                                                      //making c=>1 (so when call All_U know that it was from case 7)
        int re=1;                                                                 //re is used twice for the same thing which is keep repeating if the input is false
        int robo;                                                                 //robo is used to take the number of the chosen robot
        for(int i=0;i<ua;i++){                                                    //looping with the size of the users to know which to select
        u[i].All_U(i,c);}                                                         //calling All_U fn to get the users
        int ch;string d,m,y,Date;                                                 //ch is used to take the chosen user, d(day),m(month),y(year),Date to create the Date
        while(re){string chi;                                                     //looping until re=0(entering right input),creating chi as string to deal with false iputs (as if it is int and input is string it will enter infinite loop)
         cout<<"\nWhich user to rent to:\t";cin>>chi;cout<<"\n";                  //taking chi as input
         stringstream s;s<<chi;s>>ch;                                             //transform it to int
        if(ch>=1&&ch<=ua){re=0;}else{cout<<"Please enter correct user\n";}}       //checking input is correct, re=>0 to knw that the input is correct so stop looping
            cout<<"Please enter the date(day/month/year)"                         //taking d,m,y
                <<"\n\tDay:";cin>>d;
            cout<<"\n\tMonth:";cin>>m;
            cout<<"\n\tYear:";cin>>y;
            Date=u[ch-1].rent(d,m,y);                                             //Date is the return of the rent fn which is d,m,y contacenated as d/m/y
         for(int i=0;i<ra;i++){                                                   //looping with the size of the robots to know which is available in that date
            vec=r[i].rent(Date,i);}                                               //vec is the vector returning from rent fn in users which is vector with the number of the available robots
         int sizz=vec.size();                                                     //sizz is the size of the vector
         if(sizz==0){cout<<"\nthere's no robot available on this day\n";break;}   //if size is =>0 then there is no available robots in that date
         re=1;                                                                    //returning re back to 1 to use with while until getting right input
         while(re){string roboi;                                                  //roboi string to deal with false input
         cout<<"\nEnter the robot number you want to rent:\t";cin>>roboi;cout<<"\n";  //taking input in roboi
         stringstream s;s<<roboi;s>>robo;                                         //transforming to int
         bool bol=0;                                                              //create to know that the input value is in the vector that containing the numbers of the whole available robots
         for(int i=0;i<sizz;i++){if(robo==vec[i]){bol=1;}}                        //loop to know if the input is inside the vector or not, changing bol=>1 if yes
         if(bol==1){                                                             // checke input is inside the vector
             r[robo-1].add(Date,robo);                                           //as dispalyed robots are from 1,2,3,... and the vector of objects is from 0,1,2 so calling the object ==>(robo-1)
                                                                                 //and calling the function add which take the number of the chosen robot and the date and it is adding date to the vector Dat in the robot's class
             re=0;                                                               //making re=>0 to know that the input is correct
         u[ch-1].avail(robo);}                                                   //calling user num ch-1 with the fn avail to add to the user the robot to be rented
         else{cout<<"Please enter correct number\n";}}
        break;}
    }
}

    return 0;
}









