#include<iostream>
#include<vector>

using namespace std;

vector<int> optimal_prize(int n){
    vector<int> prize;
    if (n==2) {
        prize.push_back(n);
        return prize;
    }
    int sum=0,temp;
    for(int i=1; i<n; ++i){
        prize.push_back(i);
        sum = sum + prize[i-1];
        int remainder = n - sum;
        if(remainder == 0)
            break;
        if(remainder < prize[i-1]){
            temp = prize[i-1];
            prize.pop_back();
            prize.push_back(temp + remainder);
            break;
        }
        
            // 1 2 3 2  ==> 1 2 5
    }
    return prize;
}

int main(){
    int n;
    cin >> n;
    vector<int> prize = optimal_prize(n);
    for(size_t i = 0; i < prize.size(); ++i){
        cout << prize[i] << ' ' ;
    }
    cout << endl;
}