#include <iostream>
#include <vector>
using namespace std;

pair<int, int> find_2_repeating_numbers(vector<int> &arr, int num_range){
    int xor_res = 0;
    for(auto num : arr)
        xor_res ^= num;
    for(int i=1;i<=num_range;i++)
        xor_res ^= i;
    int set_bit = xor_res & ~(xor_res-1);
    pair<int, int> result(0,0);
    for(auto num : arr){
        if(num & set_bit)
            result.first ^= num;
        else
            result.second ^= num;
    }
    for(int i=1;i<=num_range;i++){
        if(i & set_bit)
            result.first ^= i;
        else
            result.second ^= i;
    }
    return result;
}

pair<int, int> find_missing_and_repeating(vector<int> &arr, int num_range){
    int xor_res = 0;
    for(auto num : arr)
        xor_res ^= num;
    for(int i=1;i<=num_range;i++)
        xor_res ^= i;
    int set_bit = xor_res & ~(xor_res-1);
    pair<int, int> result(0,0);
    for(auto num : arr){
        if(num & set_bit)
            result.first ^= num;
        else
            result.second ^= num;
    }
    for(int i=1;i<=num_range;i++){
        if(i & set_bit)
            result.first ^= i;
        else
            result.second ^= i;
    }
    for(auto num : arr){
        if(result.first == num){
            return {result.second, result.first};
        }
    }
    return result;
}

void test_case_one(){
    vector<int> arr = {2,1,2,3,4,3};
    int num_range = arr.size() - 2;
    auto result = find_2_repeating_numbers(arr, num_range);
    cout << "Two Repeating Numbers are " << result.first << " and " << result.second << endl;
}

void test_case_two(){
    vector<int> arr = {2,3,5,5,4};
    int num_range = arr.size();
    auto result = find_missing_and_repeating(arr, num_range);
    cout << "Missing Numbers is " << result.first << " and Repeating Number is " << result.second << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}
