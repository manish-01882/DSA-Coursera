#include<iostream>
#include <vector>
using namespace std;

int MinTotalWaitingTime(vector<int> t, int n){
    int waitingTime = 0;
    vector<int> treated(n,0);
    for(int i = 1; i<n; ++i){
        int tmin = 8888;
        int minIndex = 0;
        for(int j=1; j<n; ++j){
            if (treated[j] == 0 && t[j] < tmin){
                tmin = t[j];
                minIndex = j;
            }
        }
        waitingTime = waitingTime + (n-i)*tmin;
        treated[minIndex] = 1;
    }
    return waitingTime;
    
}

int main(){
   vector<int> t;
   int n;
   cin>> n;
   for(int i=1; i<=n; ++i){
    t.push_back(i);
   }
   cout << MinTotalWaitingTime(t,n) << endl;
}