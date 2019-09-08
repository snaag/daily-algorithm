//
//  main.cpp
//  main
//
//  Created by 이상아 on 05/09/2019.
//  Copyright © 2019 snaag. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 10819 차이를 최대로
//int main(int argc, const char * argv[]) {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n, temp, max=-1, differ=0;
//    vector<int> v;
//
//    cin >> n;
//    for(int i=0; i<n; i++) {
//        cin >> temp;
//        v.push_back(temp);
//    }
//    sort(v.begin(), v.end());
//
//    do{
//        differ = 0;
//
//        for(int i=1; i<n; i++)
//            differ += abs(v[i-1]-v[i]);
//
//
//        if(differ > max)
//            max = differ;
//
//    }while(next_permutation(v.begin(), v.end()));
//
//    cout << max << "\n";
//
//    return 0;
//}

// 6603 로또
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//#define FIXED_SIZE 6
//
//using namespace std;
//
//int main() {
//
//    int cnt=1;
//    while(cnt != 0) {
//        scanf("%d", &cnt);
//
//        vector<int> subV(cnt, 0);
//        vector<int> v(cnt, 0);
//
//        for(int i=0; i<cnt; i++)
//            scanf("%d", &v[i]);
//
//
//        // 보조순열 만들기
//        for(int i=FIXED_SIZE; i<cnt; i++)  // 6번부터 추가
//            subV[i] = 1;
//
//
//        do{
//
//            for(int i=0; i<cnt; i++) {
//                if(subV[i] == 0)
//                    printf("%d ", v[i]);
//            }
//
//            printf("\n");
//
//        }while(next_permutation(subV.begin(), subV.end()));
//
//        printf("\n");
//    }
//}


/*
 참고: https://lmcoa15.tistory.com/31 (상세한 설명과 예시가 있어서 이해하는데 큰 도움을 준 글)
 보조순열을 만들어서 해결했다. 보조순열이라 함은, 여기서 우리는 무조건 6개의 숫자만을 돌아가면서 출력을 해야하는데, 그 때 어떤걸 고르느냐를 보조순열이 결정하였다.
 예를 들어 입력받은 값이 (갯수 제외) 1 2 3 4 5 6 7 이라하면, 우리가 출력해야 하는 값은
 1 2 3 4 5 6
 1 2 3 4 5 7
 1 2 3 4 6 7
 1 2 3 5 6 7
 1 2 4 5 6 7
 1 3 4 5 6 7
 2 3 4 5 6 7
 이렇게 된다. 즉 처음에는 7이 빠지고, 두 번째에는 6이, 그 다음에는 5가 ... 마지막에는 1이 빠지며 끝난다.
 
 어떤 수를 빼고, 어떤 수들을 출력할지 어떻게 결정할까? 보조순열이다. 보조 순열은, 어떤 값을 출력하고 어떤 값을 출력하지 않을 지 결정하는데 도와주는 순열이다. (사실은 조합이다)
 0, 0, 0, 0, 0, 0, 1 의 형태로 되어있으며 1의 위치를 바꾸면서, 0일때만 출력하게 한다.
 
 do{
 
 for(int i=0; i<cnt; i++) {
 if(subV[i] == 0)
 printf("%d ", v[i]); // suvV[i]가 0이면 출력한다
 }
 
 printf("\n");
 
 }while(next_permutation(subV.begin(), subV.end()));
 
 바로 이 부분을 말한다. subV의 순열을 구하면서, 0인 부분만 출력하도록 한다.
 */

// 9095 1, 2, 3 더하기

#include <iostream>
#include <vector>

#define MAX 12

using namespace std;

int main() {
    vector<int> v(MAX, 0);

    v[0] = 0; v[1] = 1;
    v[2] = 2; v[3] = 4;
    for(int i=4; i<MAX; i++) {
        v[i] = v[i-3]+v[i-2]+v[i-1];
    }

    int cnt, temp;
    scanf("%d", &cnt);

    for(int i=0; i<cnt; i++) {
        scanf("%d", &temp);
        printf("%d\n", v[temp]);
    }
}

int main() {
    int getVal(int n);
    
    int cnt, temp;
    scanf("%d", &cnt);
    
    for(int i=0; i<cnt; i++) {
        scanf("%d", &temp);
        printf("%d\n", getVal(temp));
    }
}

int getVal(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    return getVal(n-1)+getVal(n-2)+getVal(n-3);
}


/*
 규칙만 파악하면 풀 수 있는 간단한 문제였다. 규칙은 1일 때 1, 2일 때 2, 3일 때 4, 4일 때 7로, 즉 i번째의 수는 i-3 + i-2 + i-1일 때의 값의 합과 같다는 것이다. 나는 미리 최댓값까지 다 만들어놓고, 필요할 때 idx로 접근하여 가져가는 형태로 구현하였다.
 array를 써서 푸는 것이 일반적이지만 나는 vector를 별로 안써봐서, vector와 익숙해지려고 vector로 풀었다.
 재귀로 한번, dp로 한번 풀어봤다
 dp:
     v[0] = 0; v[1] = 1;
     v[2] = 2; v[3] = 4;
     for(int i=4; i<MAX; i++) {
         v[i] = v[i-3]+v[i-2]+v[i-1];
     }
 
 재귀:
 int getVal(int n){
 if (n==1) return 1;
 if (n==2) return 2;
 if (n==3) return 4;
 return getVal(n-1)+getVal(n-2)+getVal(n-3);
 }
 */
