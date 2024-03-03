#include <iostream>
#include <string>

using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int D[10][10] = {0};
  int insertion,deletion,match,mismatch;
  for(size_t i=0; i< str1.size(); i++){
    D[i][0] = str1[i];
  }
  for(size_t j=0; j< str2.size(); j++){
    D[0][j] = str2[j];
  }
  for(int j=1;j<=str1.size();j++){
    for(int i=1; i<=str2.size(); i++){
      insertion = D[i][j-1] + 1;
      deletion = D[i-1][j] + 1;
      match = D[i-1][j-1];
      mismatch = D[i-1][j-1]+1;
      if(str1[i]==str2[j]){
        D[i][j] = min(min(insertion,deletion),match);
      }else{
        D[i][j] = min(min(insertion,deletion), mismatch);
      }
    }
  }
  
  return D[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
