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
long long int f[21];

// q==2 일 때 (순열을 입력받고, 이 순열이 몇 번째 순열인지 알고 싶을 때)
// 풀었다
long long int getIdx(vector<int> v, int n){
    long long int count = 1;
    // 방문 vector 인 did
    vector<bool>did;
    for(int i=0; i<n+1; i++) {
        did.push_back(false);
    }

    for(int i=0; i<n; i++) {
        did[v[i]] = true;

        for(int j=1; j<v[i]; j++) {
            // 방문하지 않은 경우에만
            if(did[j] == false) {
                count = count+f[n-1-i];
            }
        }
    }
    return count;
}

// q==1 일 때 (cnt를 입력받고, 그 때 어떤 순열이 나오는지 알고 싶을 때)
// 어렵다
void getNth(int n, long long int cnt) {
    // n: length
    // cnt: 몇 번째인지

    vector<int>numList; // 남은 숫자들이 있는 vector
    vector<bool>isVisit;
    vector<int>result;

    
    for(int i=0; i<n; i++){
        numList.push_back(i+1);
        isVisit.push_back(false);
    }
    isVisit.push_back(false);

    
    // result에 넣는 것과 관련한 for 문이다
    // result[0]=?, result[1]=? ...
    int i = 0;
    while(result.size() < n) {
        
        for(int j=0; j<n; j++) {
            // result에 어떤 값이 들어갈지 계산하는 for 문이다
            
            if(isVisit[j] == true) continue;
            
            if(cnt-f[n-1-i] > 0) {
                cnt = cnt - f[n-1-i];
            } else {
                isVisit[j] = true;
                result.push_back(j+1);
                break;
            }
        }
        
        i=i+1;
    }

    for(int i=0; i<n; i++) {
        cout << result[i] << " ";
    }
    
}

void init() {
    f[0] = 1;
    for(int i=1; i<21; i++) {
        f[i] = f[i-1]*i;
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
            long long int cnt;
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
