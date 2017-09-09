#include <iostream>
#include <set>
#include <string>
using namespace std;

void subsets(string str, string result, int k){
    if(k == str.length()){
        cout << result << endl;
        return;
    }
    subsets(str, result, k + 1);
    result.push_back(str[k]);
    subsets(str, result, k + 1);
    result.pop_back();
}

void subsets(string str, string result){
    if(str.empty()){
        cout << result << endl;
        return;
    }
    subsets(str.substr(1), result + str[0]);
    subsets(str.substr(1), result);
}

void subsets(string str){
    for(int i = 0; i < (1 << str.length()); i++){
        string result;
        for(int j = 0; j < str.length(); j++){
            if( i & (1 << j) )
                result.push_back(str[j]);
        }
        cout << result << endl;
    }
}

void test_case_one(){
    cout << "Enter String To Print Subsets : ";
    string str;
    cin >> str;
    subsets(str, "", 0);
}

void test_case_two(){
    cout << "Enter String To Print Subsets : ";
    string str;
    cin >> str;
    subsets(str, "");
}

void test_case_three(){
    cout << "Enter String To Print Subsets : ";
    string str;
    cin >> str;
    subsets(str);
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    return 0;
}
