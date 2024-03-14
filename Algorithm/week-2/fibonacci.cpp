#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    vector <int> fib{0};
    if(n==0)
        return 0;
    fib.push_back(1);
    for(int i=1; n>=fib.size(); ++i){
        int num = fib[i] + fib[i-1];
        fib.push_back(num);
    }
    return fib.back();
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
