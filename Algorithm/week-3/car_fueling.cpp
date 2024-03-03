#include<iostream>
#include <vector>
using namespace std;

 int MinRefills(vector<int> x,int n , int L,int distance){
    int numRefill = 0, currentRefill = 0;
    if(L>=distance)
        return numRefill;
    while(currentRefill < (n-1)){
        int lastRefill = currentRefill;
        while(currentRefill < (n-1) && (x[currentRefill + 1] - x[lastRefill] <= L)){
            currentRefill++;
        }
        if(currentRefill == lastRefill)
            return -1;
        if(currentRefill < n)
            numRefill++;
    }
    return numRefill;
 }

 int main(){

    int distance, L, n, i;
    vector<int> x;

    cin>>distance;
    cin>>L;
    cin>>n;
    while (x.size() < n && cin >> i)
    {
        x.push_back(i);
    }
    cout << MinRefills(x , n ,L,distance) << endl;
 }