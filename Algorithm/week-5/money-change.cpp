#include <iostream>

int get_change(int m) {
  //write your code here
  int result = 0;
  if(m==0){
    return 0;
  }
  else if(m>4 && m%4==2){
    return (m/4)-1+2;
  }
  else if(m%4==3){
    return (m/4)+1;
  }
  else if(m%4==0){
    return m/4;
  }
  else if(m==2){
    return 2;
  }
  else{
    return (m/4)+1;
  }
//   while (m>0)
//   {
//     if(m==6){
//         result += 2;
//         return result;
//   }
//   else if (m>4)
//   {
//     m-= 4;
//     result += 1;
//   }
//   else if(m==3){
//     m=0;
//     return result+1;
//   }
  
//   else{
//     m-=1;
//     result += 1;

//   }
  
  
  
//   }
//   return result;
// //   return m / 4;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
