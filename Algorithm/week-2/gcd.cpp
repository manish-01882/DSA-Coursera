#include<iostream>
using namespace std;

double NaiveGCD(int a, int b){
    int best = 1;
    for (int d = 1; d <a && d<b; ++d){
        if( a%d == 0 && b%d == 0)
            best = d;
    }
    return best;
}

int EuclidGCD(int a, int b){
    if (b == 0)
        return a;
    int a1 = a % b;
    return EuclidGCD(b,a1);
}

int main(){
    int a,b;
    cin>>a>>b;
    //cout<< NaiveGCD(a,b)<<endl;
    cout<<EuclidGCD(a,b)<<endl;
    return 0;
}