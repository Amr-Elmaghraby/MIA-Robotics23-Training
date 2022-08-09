#include "robots.h"
#include <bits/stdc++.h>
using namespace std;

bool flag=0;                                       //flag to know if the name that is being searched is found or not
Robots::Robots(string rn, string id, string p)
{
    Robo_N=rn;                                           //saving name

    //taking the id and save each fn of it and make sure that it is right input
    int tem=0,iid=0;                                                 //tem to know it is false input or not, iid to transform it from string to int
    int ssize=id.size();                                            //ssize===> size of the id
    for(int i=1;i<ssize;i=i+2){                                    //looping with the size from 1 to size with 2 steps (to indicate ',' )
        int y,yp,yv;
        char yi;                                                      //y,yp,yv,yi int,char to transform id to
        stringstream w;w<<id[i-1];w>>y;                              //transform the element before ',' =====>y
        stringstream wu;wu<<id[i+1];wu>>yp;                         //transform the element after ','  =====>yp
        stringstream wi;wi<<id[ssize-1];wi>>yv;                    //transform the last element       =====>yv
        yi=id[i];                                                 //transform the ',' element        =====>yi
        if(yi==','&&y<=5&&y>=1&&yv<=5&&yv>=1&&yp!=y&&y!=yv)      //make sure that yi is equal to ',' and 1<=y<+5 and 1<=yv<=5 and also there is no id is entered twice or more
        {}else{tem=1;}}                                         //if there is any mistake ==> tem=1, knowing that the input is false
        if(ssize==1)                                           //dealing with the one element alone, as the first loop will not get it
        {   int y;                                            //y to transform it to int
            stringstream w;w<<id[0];w>>y;                    //id[0](which should be the only element here) =====>y
            if(y>=1&&y<=5){tem=0;}else{tem=1;}              //checking that 1<=y<=5
        }

        if(tem==0){                                        //if tem didn't change then the input is correct
            for(int i=0;i<ssize;i++){                      //looping with it's size
                if(id[i]==','){                            //checking where is the ','
                  stringstream si;si<<id[i-1];si>>iid;     //transform the element before the ',' to int saved in iid
                  switch (iid){                                                 //switch on iid to get the function
                        case 1:Fn_ID.push_back("Cleaner Robot(1)"); break;
                        case 2:Fn_ID.push_back("Driver Robot(2)"); break;
                        case 3:Fn_ID.push_back("Assignment Solver Robot(3)"); break;
                        case 4:Fn_ID.push_back("Cook Robot(4)"); break;
                        case 5:Fn_ID.push_back("Hairstylist Robot(5)"); break;}}
                if(i==(ssize-1)){                                               //this if will deal with the last element and if there was only one element
                  int iid;                                                      //int to transform id to int by
                  stringstream s1;s1<<id[i];s1>>iid;                            //transform id to int
                  switch (iid){                                                 //switch on iid to get the function
                        case 1:Fn_ID.push_back("Cleaner Robot(1)"); break;
                        case 2:Fn_ID.push_back("Driver Robot(2)"); break;
                        case 3:Fn_ID.push_back("Assignment Solver Robot(3)"); break;
                        case 4:Fn_ID.push_back("Cook Robot(4)"); break;
                        case 5:Fn_ID.push_back("Hairstylist Robot(5)"); break;}
                    }}}else {
                      cout<<"\tInvalid id num (default 1)\n";               //if entered invalid, it will be saved as 1 as default
                      Fn_ID.push_back("Cleaner Robot(1)");}

        float pi;
        stringstream s1;s1<<p;s1>>pi;PPD=pi;                    //transform price to float
        if(pi<=0){
        cout<<"\tInvalid price value(default 50)\n";             //check if entered coreect, if not will be saved as "50" as default
        PPD=50;}

}



void Robots::All_R(int i){                                         //typing out all the robots details
    int sfn=Fn_ID.size();                                          //size of the fn (to know the number of the Fn_ID in the robot)
    cout<<"\t\tRobot "<<(i+1)<<":\n"
        <<"\t\t\tName:"<<Robo_N
        <<"\n\t\t\tFunction :";
    if(sfn==1){cout<<Fn_ID[0];}else{
    for(int i=0;i<sfn;i++){
        cout<<Fn_ID[i]<<", ";}}                                    //lloping with the size of the Fn_ID to print out all it's function's
        cout<<"\n\t\t\tPrice per day:"<<PPD<<"\n";
        int sizz=Dat.size();                                       //size of Dat which is storing the Date the robot being rented in
if(sizz!=0){cout<<"\t\t\tRobot is rented in : ";                   // if the size is not 0 then there's a saved date in the robot
        cout<<Dat[0];                                              //printing out the first date alone (just not to show the ',' if only one date)
        for(int i=1;i<sizz;i++){
               cout<<", "<<Dat[i]<<"\n";}if(sizz==1){cout<<"\n";}  //looping to get the date saved in the robot
        }
}



void Robots::Ser(string s_n,int i){                              //search the enetred robot name
    if(s_n==Robo_N){
       int sfn=Fn_ID.size();
       cout<<"\t\tRobot "<<(i+1)<<":\n"
           <<"\t\t\tName:"<<Robo_N
           <<"\n\t\t\tFunction :";
       if(sfn==1){cout<<Fn_ID[0];}else{                         //looping to get the whole Fn_ID
       for(int i=0;i<sfn;i++){
           cout<<Fn_ID[i]<<", ";}}
       cout<<"\n\t\t\tPrice per day:"<<PPD<<"\n";flag=1;       //typing out if found ,flag=>1
       int sizz=Dat.size();
       if(sizz!=0){cout<<"\t\t\tRobot is rented in : ";
               cout<<Dat[0];
               for(int i=1;i<sizz;i++){
                      cout<<", "<<Dat[i]<<"\n";}if(sizz==1){cout<<"\n";} //looping to get the whole Date saved
       }}
}
void Robots::check(){
    if (flag==0){cout<<"\tRobot not found\n\n";}               //check if flag=>0 to know that there is no robot found (when searching with name)
    flag=0;
}


vector<int> Robots::rent(string Date, int i){
    int sfn=Fn_ID.size();                                            //size of Fn_ID
    static vector<int> vec;                                          //static vector which save the all available robots in the entered date
    int u=Dat.size();                                                //size of the date saved
    static int to=0;       if(i==0){to++;if(to>=2){vec.clear();}}    //static int and if condition to clear the vector when ever entering the fn again (i=0)
    bool temp=0;                                                    //bool to check if the date is saved in this robot or not
    for(int oo=0;oo<u;oo++){
        if(Date==Dat[oo]){temp=1;}                                 //looping with size of Dat to know
    }
    if(temp!=1){                                                   //if not saved then showing it, as the robot is not rented in that day
        cout<<"\n\tRobot "<<(i+1)<<"\n"
            <<"\t\t\tName:"<<Robo_N
            <<"\n\t\t\tFunction :";
        if(sfn==1){cout<<Fn_ID[0];}else{                         //loop to get all it's fn_id
        for(int i=0;i<sfn;i++){
            cout<<Fn_ID[i]<<", ";}}
            cout<<"\n\t\t\tPrice per day:"<<PPD<<"\n";vec.push_back(i+1);
    }
    return vec;}                                               //returning vec which will be used to know whether the input is one of the shown  robots or not

void Robots::add(string date,int robo){
    Dat.push_back(date);                                       //adding the date to the robot (saved in the Dat vector)
    cout<<"The Robot "<<robo<<" has been rented succssefully\n\n";

}






















