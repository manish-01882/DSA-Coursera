#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long)numbers[first]) * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int> & numbers){
  int n = numbers.size();

  int max_index1 = -1;
  for (int first = 0; first < n; ++first)
    if ((max_index1 == -1) || (numbers[first] > numbers[max_index1]))
      max_index1 = first;

  int max_index2 = -1;
  for (int second = 0; second < n; ++second)
    if ((second != max_index1) && ((max_index2 == -1) || (numbers[second] > numbers[max_index2])))
      max_index2 = second;

  //std::cout << max_index1 << ' ' << max_index2 << "\n";

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}


int main() {
 /* while(true){
    int n = rand()%100 + 2;
    std::cout << n <<std::endl;
    std::interval<int> a;
    for(int i=0; i < n; ++i){
      a.push_back(rand() % 100000);
    }
    for(int i = 0; i<n ; ++i){
      std::cout << a[i] << ' ';
    }
    cout << endl;
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if(res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << endl;
      break;
    }
    else{
      cout << "OK"<< endl;
    }
  }*/


    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers); 
    std::cout << result<< "\n";
    return 0;
}
