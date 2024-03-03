#include <iostream>
#include <vector>
#include<cmath>


using namespace std;

vector<int> merge(vector<int> &B , vector<int> &C){
    vector<int> D;
    while(B.size() > 0 && C.size() > 0){
    if(B[0]<=C[0]){
        D.push_back(B.front());
        B.erase(B.begin());
    }
    else{
        D.push_back(C.front());
        C.erase(C.begin());
    }
    }
    move(begin(B),end(B), back_inserter(D));
    move(begin(C),end(C), back_inserter(D));
    return D;

}

vector<int> mergeSort(vector<int> &A){
    if(A.size() == 1)
        return A;
    int m = floor(A.size()/2);
    vector<int> B(A.begin(), A.begin() + m);
    vector<int> C(A.begin() + m,A.end());

    vector<int> sortedB = mergeSort(B);
    vector<int> sortedC = mergeSort(C);

    return merge(sortedB,sortedC);
}



int main(){
    int n;
  cin >> n;
  vector<int> a(n);
  for(size_t i=0; i<a.size(); ++i){
    cin >> a[i];
  }
  vector<int> sorted_a = mergeSort(a);
  for (size_t i = 0; i < sorted_a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}