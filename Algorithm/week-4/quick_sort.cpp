#include<iostream>
#include<vector>

using namespace std;

vector<int> partition3(vector<int> &a, int l, int r){
  int x = a[l];
  int j = l;
  int k = l;
  for(int i=l+1; i<=r; ++i){
    if(a[i]<x){
      j++;
      k++;
      swap(a[j],a[i]);
    }
    else if(a[i]==x){
      k++;
      swap(a[i],a[k]);
    }
  }
  swap(a[l],a[j]);
  vector<int> result(2);
  result.push_back(j);
  result.push_back(k);
  return result;
}

void quick_sort(vector<int> &a, int l, int r){
  if(l>=r)
    return;
  vector<int> m(2);
  m = partition3(a,l,r);

  quick_sort(a,l,m[1]-1);
  quick_sort(a,m[2]+1,r);
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(size_t i=0; i<a.size(); ++i){
    cin >> a[i];
  }
  quick_sort(a,0,a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}