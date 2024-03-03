/*****************************************
 * Sort the array in Merge Sort and then *
 * output the sorted array and number of *
 * inversions in array                   *
 *****************************************/

#include <iostream>
#include <vector>
#include<cmath>


using namespace std;

vector<int> merge(vector<int> &B , vector<int> &C,int &count){
    vector<int> D;
    while(B.size() > 0 && C.size() > 0){
    if(B[0]<=C[0]){
        D.push_back(B.front());
        B.erase(B.begin());
    }
    else{
        D.push_back(C.front());
        C.erase(C.begin());
        count++;
    }
    }
    move(begin(B),end(B), back_inserter(D));
    move(begin(C),end(C), back_inserter(D));
    return D;

}

vector<int> mergeSort(vector<int> &A,int &count){
    if(A.size() == 1)
        return A;
    int m = floor(A.size()/2);
    vector<int> B(A.begin(), A.begin() + m);
    vector<int> C(A.begin() + m,A.end());

    vector<int> sortedB = mergeSort(B,count);
    vector<int> sortedC = mergeSort(C,count);

    return merge(sortedB,sortedC,count);
}



int main(){
    int n,count = 0;
  cin >> n;
  vector<int> a(n);
  for(size_t i=0; i<a.size(); ++i){
    cin >> a[i];
  }
  vector<int> sorted_a = mergeSort(a,count);
  for (size_t i = 0; i < sorted_a.size(); ++i) {
    std::cout << sorted_a[i] << ' ';
  }
  cout << "\n" <<count;
  std::cout << std::endl;
}