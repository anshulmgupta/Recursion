#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int num){
 
    if(num == 0 || num == 1)
        return num;
    int fib = fibonacci(num-1) + fibonacci(num-2);
    return fib;
}

int fibonacci_itr(int num){

    vector<int> dp(2);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=num; i++){
        int tmp = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = tmp;
    }
    return dp[1];
}

void test_case_one(){
    int num = 9;
    int result = fibonacci(num);
    cout << "Fibonacci of 9 = " << result << endl;
}

void test_case_two(){
    int num = 9;
    int result = fibonacci_itr(num);
    cout << "Fibonacci of 9 = " << result << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}
