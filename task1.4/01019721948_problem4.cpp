
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned short int q;                                                  //taking the number of test cases
    int flag2=0;                                                          //flag is used to know whether the height was lawer than the previous creatures in line 22
    cin>>q;
    while(q--){                                                         //looping q time
        int N;                                                         // number of creatures
        cin>>N;
        int nn[N];                                                   //making array to store the number of creatures each can see to its right
        float n[N];                                                 //array to the creatures height
     for(int i=0;i<N;i++){cin>>n[i];nn[i]=0;}                      //loop to take the height of each creature
        for(int j=0;j<N;j++){if(n[j]<n[j+1]){nn[j]++;
                cout<<nn[j]<<" ";continue;}else{nn[j]++;}        //loop to each creature and check if the creature next to him is taller than him if so then he can see only one creature that one next to him
            if(j+1>=N){nn[j]=0;}                                //check not to exceed the array and to store a 0 to the last creature
        for(int i=0;i<N;i++){                                  //loop inside the main loop to get into each cretaure along the whole creatures
            if(j+1<i){flag2=0;                                //check i to be greater than j+1, not to check each cretures with the one's that are to his left
             for(int o=1;o<i-j;o++){                         //small loop to make sure that the creature can see the far creatures from him
               {if(n[i]<n[i-o]){flag2=1;}}}                 //if there is any creature between the main one (described by j) and the next one(described by i) is taller than the second one, then the main can't see him
                if(flag2==0) { nn[j]++;}                   //verifing it by using the flag
                     }
                             }
         cout<<nn[j]<<" ";
                            }
              }
    return 0;
}




