#ifndef ROBOTS_H
#define ROBOTS_H
#include <bits/stdc++.h>
using namespace std;

class Robots
{
private:
    string Robo_N;
    vector<string> Fn_ID;
    float PPD;                    //define variables to save name,id,price in
    vector<string> Dat;

public:
    Robots(string rn, string id, string p);    //constructor taking name,id,price
    void All_R(int i);                          //fn to get all robots
    void Ser(string s_n, int i);                //fn to search by name
    void check();                               //check if name found or not
    vector<int> rent(string Date, int i );               //fn to rent robot
    void add(string date, int robo );            //fn to add date to robot (renting robot)

};

#endif // ROBOTS_H
