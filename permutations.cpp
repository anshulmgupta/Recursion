#include <iostream>

using namespace std;

void permute(string &str, int k){
    if(k == str.length()){
        cout << str << endl;
        return;
    }
    for(int i = k; i < str.length(); i++){
        swap(str[k], str[i]);
        permute(str, k + 1);
        swap(str[k], str[i]);
    }
}

void permute(string str, string tmp){
    if(str.empty()){
        cout << tmp << endl;
        return;
    }
    for(int i = 0; i < str.length(); i++){
        string suff = tmp + str[i];
        string rem = str.substr(0, i) + str.substr(i+1);
        permute(rem, suff);
    }
}

void test_case_one(){
    cout << "Enter String To Permute : ";
    string str;
    cin >> str;
    permute(str, 0);
}

void test_case_two(){
    cout << "Enter String To Permute : ";
    string str;
    cin >> str;
    permute(str, "");
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}
