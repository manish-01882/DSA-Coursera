#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

string largest_number(vector<string> salary){
    stringstream answer;
    string maxDigit="0";
    sort(salary.begin(), salary.end(), greater<string>());

    for(size_t i=1; i<salary.size(); ++i){
        if(salary[i].front() == salary[i-1].front() && salary[i].size() < salary[i-1].size()){
            string temp;
            temp = salary[i];
            salary[i] = salary[i-1];
            salary[i-1] = temp;
        }
    }

    for(size_t i =0; i<salary.size(); ++i){
        answer << salary[i];
    }
    string newSalary;
    answer >> newSalary;
    return newSalary;
}

int main(){
    int n;
    cin >> n;
    vector<string> salary(n);
    for(size_t i=0; i < salary.size(); ++i){
        cin >> salary[i];
    }
    cout << largest_number(salary) <<endl;
}