#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  // write your code here
  sort(a.begin(), a.end());
  int count = 1;
  for (size_t i = 1; i < a.size(); ++i)
  {
    if (a[i - 1] == a[i])
    {
      count++;
    }
    else if( count > int(a.size()) / 2){
      return a[i - 1];
    }
    else
      count = 1;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
