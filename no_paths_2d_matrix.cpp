#include <iostream>

using namespace std;

int count_paths_one(int arr[][3], int r, int c, int N, int M){
    if(r == N-1 || c == M-1)
        return 1;

    int right = count_paths_one(arr, r, c+1, N, M);
    int down = count_paths_one(arr, r+1, c, N, M);

    return right + down;
}

int count_paths_two(int arr[][3], int r, int c, int N, int M){
    if(r >= N || c >= M)
        return 0;

    if(r == N-1 && c == M-1)
        return 1;

    int right = count_paths_two(arr, r, c+1, N, M);
    int down = count_paths_two(arr, r+1, c, N, M);

    return right + down;
}

void test_count_paths_one(){
    int arr[][5] = {{1,2,3,4,5},
                   {6,7,8,9,10},
                   {11,12,13,14,15},
                   {16,17,18,19,20}};

    int arr3x3[][3] = {{1,2,3},
                       {6,7,8},
                       {11,12,13}};
    int N = sizeof(arr3x3)/sizeof(arr3x3[0]);
    int M = sizeof(arr3x3[0])/sizeof(int);
    cout << "Number of Paths from Start(0,0) to End(N,M) : " << count_paths_one(arr3x3,0,0, N, M) << endl;
}

void test_count_paths_two(){
    int arr[][5] = {{1,2,3,4,5},
                   {6,7,8,9,10},
                   {11,12,13,14,15},
                   {16,17,18,19,20}};

    int arr3x3[][3] = {{1,2,3},
                       {6,7,8},
                       {11,12,13}};
    int N = sizeof(arr3x3)/sizeof(arr3x3[0]);
    int M = sizeof(arr3x3[0])/sizeof(int);
    cout << "Number of Paths from Start(0,0) to End(N,M) : " << count_paths_two(arr3x3,0,0, N, M) << endl;
}

int main(){
    test_count_paths_one();
    test_count_paths_two();
    return 0;
}
