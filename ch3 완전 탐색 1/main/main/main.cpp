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

//#include <iostream>
//#include <vector>
//
//#define MAX 12
//
//using namespace std;
//
//int main() {
//    vector<int> v(MAX, 0);
//
//    v[0] = 0; v[1] = 1;
//    v[2] = 2; v[3] = 4;
//    for(int i=4; i<MAX; i++) {
//        v[i] = v[i-3]+v[i-2]+v[i-1];
//    }
//
//    int cnt, temp;
//    scanf("%d", &cnt);
//
//    for(int i=0; i<cnt; i++) {
//        scanf("%d", &temp);
//        printf("%d\n", v[temp]);
//    }
//}
//
//int main() {
//    int getVal(int n);
//
//    int cnt, temp;
//    scanf("%d", &cnt);
//
//    for(int i=0; i<cnt; i++) {
//        scanf("%d", &temp);
//        printf("%d\n", getVal(temp));
//    }
//}
//
//int getVal(int n){
//    if (n==1) return 1;
//    if (n==2) return 2;
//    if (n==3) return 4;
//    return getVal(n-1)+getVal(n-2)+getVal(n-3);
//}


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


// 1759 암호 만들기
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//4 6
//a t c i s w

int main() {
    bool desc(int a, int b);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int l, c; // l < c
    cin >> l;
    cin >> c;

    vector<bool> subV(c, 0);
    vector<char> keys(c);
    
    vector<bool> isVowel(c, 0); // 모음 - 0으로 초기화
    vector<bool> isConsonant(c, 1); // 자음 - 1로 초기화
    
    for(int i=0; i<c; i++) {
        cin >> keys[i];
        
        if(i >= l)
            subV[i] = 1;
    }
    
    
    sort(subV.begin(), subV.end()); // 보조 순열
    sort(keys.begin(), keys.end()); // 문자
    
    for(int i=0; i<c; i++) {
        if(keys[i] == 'a' || keys[i] == 'e' || keys[i] == 'i' || keys[i] == 'o' || keys[i] == 'u'){
            isVowel[i] = 1; // 앞서 isVowel은 0으로 초기화 했으니, 모음을 만나면 1로 바꾸어준다
            isConsonant[i] = 0; // 앞서 isConsonant는 1로 초기화했으니, 모음을 만나면 0으로 바꾸어준다
        }
    }
 
    
    int cntJa, cntMo;
    do {
        cntJa = 0;
        cntMo = 0;

        for(int i=0; i<c; i++){
            if(subV[i] == 0) { // 출력 가능한 문자 중에서,
                cntJa += isConsonant[i]; // 자음의 갯수를 카운트한다
                cntMo += isVowel[i]; // 모음의 갯수를 카운트 한다
            }
        }

        if(cntMo >= 1 && cntJa >= 2) { // 각각 갯수가 1개, 2개 이상일 때만 출력이 가능하다
            for(int i=0; i<c; i++){
                if(subV[i] == 0)
                    cout << keys[i];
            }
            cout << "\n";
        }
        
    }while(next_permutation(subV.begin(), subV.end()));
    
    subV.clear(); // 초기화 해준다
    keys.clear();
    isVowel.clear();
    isConsonant.clear();
}

/*
 순열이 제대로 나오지 않아, 왜그런지 찾아봤더니 정렬이 필요하였다. 그래서 sort(subV.begin(), subV.end())를 해주었더니 잘 나왔지만, 내가 원하는 결과대로 나오지 않는 것이 문제였다. 나는 입력값이 l: 4, c: 6, keys: a t c i s w 일 때,
 1 1 1 1 0 0
 1 1 1 0 1 0
 1 1 1 0 0 1
 1 1 0 1 1 0
 ...
 0 0 1 1 1 1
 이렇게 나오기를 바랬으나, 나온 결과는 정 반대였다.
 0 0 1 1 1 1
 0 1 0 1 1 1
 0 1 1 0 1 1
 0 1 1 1 0 1
 ...
 1 1 1 1 0 0
 으로 나온 것이다. 왜 이렇게 나올까 생각해봤더니, 원인은, 순열이 다음 순열을 구할 때 쓰는 방식에있었다.
 다음 순열을 구하는 방식은 전체 수열에서 내림차순(감소)을 보여주는 sequence를 찾아, 그 sequence를 다시 오름차순으로 바꿔주는 방식을 반복해서 찾는다. 하지만 순열이 내림차순으로 정렬이 되어있다면, 다음 순열이 없다고 판단하게 되는 것이다. 따라서 내가 원하는 답이 나오게 하려면, 0 0 0 0 1 1로 시작을 했어야 했다. 그렇게 한 결과는
 sort(subV.begin(), subV.end(), desc);
 */

/*
 로또(6603)문제와 유사한 문제이다. 보조 순열을 구하고, 가능한 값을 거기서 추려서 출력하는 것이 메인 아이디어이다. 입력이
 4 6
 a t c i s w
 일 때,
 0 0 0 0 1 1
 0 0 0 1 0 1
 ...
 을 반복하며, 0일 때, 그리고 자음이 2개 이상, 모음이 1개 이상일 때 출력하도록 하면 된다. (왜 1이 아니라 0인지, 아래에 적어놓았다)
 */
/*
 자음 갯수와 모음 갯수를 충족시키는 값을 구하기 위해, isVowel, isConsonant 라는 두개의 vector를 사용하였다. 각각은 모음, 자음일 때 1을 그 외네는 0을 갖는 자료구조이다. 따라서 어떤 문자를 보려고 할 때, 각각의 idx에 해당하는 isVowel, isConsonant의 합들이 각각 조건(1, 2)과 갖거나 큰 값이라면 조건을 충족하게 된다. 따라서 각각의 합이 1, 2와 갖거나 크면 출력을 하도록 하였다.
 */
