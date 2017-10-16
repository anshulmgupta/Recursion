#include <iostream>
#include <vector>

using namespace std;

vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void find_combinations(string &str, vector<string> &result, string res, int idx){
    if(res.length() == str.length()){
        result.push_back(res);
        return;
    }
    for(auto ch : v[str[idx]-'0']){
        res.push_back(ch);
        find_combinations(str, result, res, idx+1);
        res.pop_back();
    }

}

void test_case_one(){
    string str = "23";
    vector<string> result;
    find_combinations(str, result, "", 0);
    for(auto st : result)
        cout << st << ",";
    cout << endl;
}

void test_case_two(){
    string str = "2276696";
    vector<string> result;
    find_combinations(str, result, "", 0);
    for(auto st : result)
        cout << st << ",";
    cout << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}
