//
//  main.cpp
//  main
//
//  Created by 이상아 on 04/09/2019.
//  Copyright © 2019 snaag. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//
//// 문제를 풀기에 앞서, 순열을 한번 만들어보자
//
//int main(){
//
//    int N;
//    cin >> N;
//
//    vector<int> vv;
//    vv.resize(N);
//    // vv.reserve(N) 으로 했을때는 순열이 안구해졌는데, vv.resize(N)으로 했을 때는 순열이 구해졌다.
//    // 둘의 차이는 무엇일까?
//
//    for(int i=0; i<N; i++) {
//        vv[i] = i+1;
//    }
//
//    do{
//
//        for(int i=0; i<N; i++){
//            cout << vv[i] << " ";
//        }
//
//        cout << '\n';
//
//    }while(next_permutation(vv.begin(),vv.end()));
//
//    return 0;
//
//}


// 1722번 순열의 순서
long long f[21];

int factorial(int n){
    if(n == 1)
        return 1;

    else
        return factorial(n-1)*n;
}

// q==2 일 때 (순열을 입력받고, 이 순열이 몇 번째 순열인지 알고 싶을 때)
int getIdx(vector<int> v, int n){
    int count = 1;
    // 방문 vector 인 did
    vector<bool>did;
    did.resize(n+1);
    for(int i=0; i<n+1; i++) {
        did.push_back(false);
    }

    for(int i=0; i<n; i++) {
        did[v[i]] = true;

        for(int j=1; j<v[i]; j++) {
            // 방문하지 않은 경우에만
            if(did[j] == false) {
                count = count+factorial(n-1-i);
            }
        }
    }
    return count;
}

// q==1 일 때 (cnt를 입력받고, 그 때 어떤 순열이 나오는지 알고 싶을 때)
void getNth(int n, int cnt) {
    // n: length
    // cnt: 몇 번째인지

    vector<int>remain; // 남은 숫자들이 있는 vector
    vector<bool>isVisit;
    vector<int>result;
    bool isEnd = false;
    int len = n;

    
    for(int i=0; i<n; i++){
        remain.push_back(i+1);
        isVisit.push_back(false);
    }
    
    while(len > 0) {
        for (int i=0; i<n; i++) {
            if(isVisit[i] == true) continue;
            if(cnt - f[len-1] > 0)
                cnt -= f[len-1];
            else {
                isVisit[i] = true;
                result.push_back(remain[i]);
                len = len-1;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
}

void init() {
    for(int i=1; i<21; i++) {
        f[i] = factorial(i);
    }
}

int main() {
    init();
    int n, q;

    cin >> n;
    cin >> q;
    switch(q) {
        case 1:
            // 몇 번째인지를 입력받는다
            int cnt;
            cin >> cnt;
            getNth(n, cnt);
            break;
        case 2:
            // 순열을 입력받는다
            vector<int> v;

            for(int i=0; i<n; i++) {
                int temp;
                cin >> temp;
                v.push_back(temp);
            }
            cout << getIdx(v, n);
            break;
    }

    return 0;
}
