#include <iostream>
#include <cassert>
#include <vector>
#include<cmath>

using namespace std;

int index(int left, int right){
    return floor(left + (right - left)/2);
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = a.size(); 
  int currIndex = index(left,right);
  while(left <= right){
    if(a[currIndex] < x){
        left = currIndex + 1;
        currIndex = index(left, right);
    }
    if(a[currIndex] > x){
        right = currIndex - 1;
        currIndex = index(left,right);
    }
    if (a[currIndex] == a[currIndex - 1])
    {
      currIndex = currIndex - 1;
      continue;
    }
    if (a[currIndex] == a[currIndex + 1] && currIndex > a.size())
    {
      currIndex = currIndex + 1;
    }
    
    
    if(a[currIndex] == x){
        return currIndex;
    }
  }
  return -1;
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  cout << endl;
}
