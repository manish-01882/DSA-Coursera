#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>


using std::vector;
using namespace std;
void value (int n,int &res,int curr, vector<int> &ref,vector<int> v){
    if(curr>res)
        return;
    if(n==1){   
        res = min(res,curr);
        ref = v;
        return;
    }
    if(n%3==0){
        v.push_back(n/3);
        value(n/3,res,curr+1,ref,v);
        v.pop_back();
    }
    if(n%2==0){
        v.push_back(n/2);
        value(n/2,res,curr+1,ref,v);
        v.pop_back();
    }
    v.push_back(n-1);
    value(n-1,res,curr+1,ref,v);
    v.pop_back();
}

// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while (n >= 1) {
//     sequence.push_back(n);
//     if (n % 3 == 0) {
//       n /= 3;
//     } else if (n % 2 == 0) {
//       n /= 2;
//     } else {
//       n = n - 1;
//     }
//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }
// }

int main() {
  int n;
  std::cin >> n;
//   vector<int> sequence = optimal_sequence(n);
//   std::cout << sequence.size() - 1 << std::endl;
//   for (size_t i = 0; i < sequence.size(); ++i) {
//     std::cout << sequence[i] << " ";
//   }
    vector<int> vect;
    int res=__INT_MAX__;
    value(n,res,0,vect,{n});
    cout << res <<endl;
    reverse(vect.begin(),vect.end());
    for(size_t i=0; i< vect.size(); i++){
        cout << vect[i] << ' ';
    }
    cout << endl;
}
