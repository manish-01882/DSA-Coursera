#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long double FibList(int n){
    int <long double> F;
    F.push_back(0);
    F.push_back(1);

    for(int i=2; i<=n; ++i){
        F.push_back(F[i-1] + F[i-2]); 
    }
    long double ans = F[n];
    return fmod(ans,10);
}

int main(){
    int n;
    cin>> n;

    cout<<FibList(n)<<endl;
}

 