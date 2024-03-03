#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> polynomial(2*n - 2);
    vector<int> A(n);
    vector<int> B(n);
    for(size_t i=0; i<A.size(); ++i){
        cin >> A[i];
    }
    for(size_t i=0; i<A.size(); ++i){
        cin >> B[i];
    }
    for (size_t i=0; i < polynomial.size(); ++i)
    {
        for (size_t j = 0; j < polynomial.size(); j++)
        {
            polynomial[i+j] = polynomial[i+j] + A[i]*B[j];
        }
        
    }
    for (size_t i = 0; i <= polynomial.size(); i++)
    {
        cout << polynomial[i] << ' ';
    }
    cout << endl;

}