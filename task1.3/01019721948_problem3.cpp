
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned short int q;                                             //q:Number of test cases

    cin>>q;
    while(q--){                                                                        //looping q times
        string s,p,si,sn,smm;int te=0;                                     // s:string, smm:another variable to change s with, p:to contacenate two elements from s si,sn the two elements to be contacenated
        int num=0;                                                           //num:used to convert string to int and vise versa,stsize:to get string size,
        cin>>s;smm=s;int stsize=s.size();
        for(int u=0;u<stsize;u++){                                           //first loop on each element of the string(10&--26&)
           if(s[u]=='&'){                                                    //to get the second type to be decoded
                         si=s[u-2];sn=s[u-1];                                //get u-1,u-2 of the string to contacenate
                         p=si + sn;
                            char  c='J';string son="10";                     //identify the first value of the letter of the second type"**&", (10==>J, and so on)
                              for(int i=0;i<=16;i++){                        //loop on string from 0==>16 (J==>Z) to get decoded
                              if(p==son){smm.erase((u-te*2-1),2);            //erase the extra values as we replace 3 char with only one (20&==>T)
                              smm[(u-2-te*2)]=c;te++;break;}else{c++;stringstream s1;s1<<son;s1>>num;num++;stringstream s2;s2<<num;s2>>son;}    //decode and convert from string to int to increase the value and back again
                              }}}
        for(int j=0;j<stsize;j++){                                          //second loop to get the first state(1--9)
       char c='A';string net="1";p=smm[j];                                      //c to be the fist element of the first state(A),net the value of it (1==>A)
        for(int u=0;u<9;u++){                                                //loop on string from 0 to 9 as A--I
            if(p==net){                                                      //check if char from the string is equal to the char from net
                smm[j]=c;}else{c++;stringstream s1;s1<<net;s1>>num;num++;stringstream s2;s2<<num;s2>>net;} //decode and convert to increase as the first loop
        }}

   cout<<smm<<endl; }                                                     //Output of the Code
    return 0;
}


