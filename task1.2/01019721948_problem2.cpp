#include <bits/stdc++.h>

using namespace std;

int main()
{
  int hp=0,re=0;                                                 //defined int as max is 1e5
  unsigned short int q=0,P=0,H=0;                               //defined short int as max is 30,30,30 respectively
   cin>>q;
   while(q--)                                                 //iterate until q=0 (iterate 'q' time)
   {
       bool flag=0;                                         //define flag to know whether it get in the if or not
       cin>>hp>>P>>H;
   for(int i=0;i<P;i++){                                  //the hp after using each plasma blast
           hp=floor(hp/2)+10;
           for(int j=1;j<=H;j++){
               re=hp-10*j;
               if(re<=0){flag=1;break;}}              //check after usage of each plasma and every hellfire if it get lower than 0, to save the ammo if it get <=0
           }
       if(flag==1){cout<<"YES"<<endl;}
       else{cout<<"NO"<<endl;}}
   return 0;
}
     /* for(int i=0;i<P;i++){
        hp=floor(hp/2)+10;
         }
        hp=hp-10*H;
         if(hp<=0){cout<<"YES"<<endl;}
         else{cout<<"NO"<<endl;}}*/      // to only know whether it is possible to defeat the creator or not, discard using the whole ammo







