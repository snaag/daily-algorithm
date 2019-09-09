# Solutions
## Ch2 완전 탐색 0
### 순열
#### [순열의 순서 1722](https://www.acmicpc.net/problem/1722)

* 문제는 두 가지로 나누어져있다. index를 입력받으면, 해당 위치의 순열을 출력하는 문제와, 임의의 순열을 입력받으면 그 순열이 몇 번째에 위치해있는지 알아내는 두 문제로 이루어져있다.

  * 그렇다면 어떤 위치에 어떤 순열이 있는지는, 어떤 식으로 알아낼 것인가?
    * 계속해서 next_permutation을 쓴다는건 말이 안된다. 그래서 값을 더하고, 빼면서 알아낼것이다. [참고](https://wjdgus2951.tistory.com/66)

  1. 임의의 순열이 몇 번째에 위치해있는지 알아내기

     * 위에 부분(init)은 단순히 값을 초기화해주는 부분이다. 다만 저기서 isVisit에 한번 더 추가해 준 이유는, 결과를 뽑을 때 자꾸 마지막값이 안나와서 부득이하게 추가하게되었다 ㅠㅠ
     * 아래 부분(반복문)에서 본격적으로 문제를 푼다. 
       * 두개의 반복문으로 구성이 되어있는데, while문은 result[0], result[1].. 에 값을 넣도록 하는 부분이다. 그래서 아래쪽에 보면, while문이 끝날 때 i=i+1을 한다.
       * 내부의 for문은 result[i]에 어떤 값이 계산할지 계산하는 반복문이다. `cnt - f[n-1-i]` 가 0보다 크다면, 동일한 위치(i)에서 다음값(1 -> 2 -> ...) 으로 넘기면 된다는 말이고, `cnt-f[n-1-i]`가 0보다 작다면, 다음 위치(i+1)에서 구해야 된다는 말이다.

     ```c++
     // q==1 일 때 (cnt를 입력받고, 그 때 어떤 순열이 나오는지 알고 싶을 때)
     void getNth(int n, long long int cnt) {
         // n: length
         // cnt: 몇 번째인지
     
         /* initialization */
         vector<int>numList; // 순열 vector
         vector<bool>isVisit; // 방문했는지 여부를 기록하는 vector
         vector<int>result; // 결과를 저장할 vector
     
         for(int i=0; i<n; i++){
             numList.push_back(i+1);
             isVisit.push_back(false);
         }
         isVisit.push_back(false);
     
         /* 반복문 */
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
     
     ```

  2. 해당 위치의 순열 알아내기

     * 초기화를 먼저 해준다 (initialization). `did` vector 는 임의의 숫자가 방문 했는지 여부를 기록한다.
     * 본격적으로 문제를 푸는 반복문 부분에선, 어쨌든 순열은 사전식으로 쭉 연결이 될거고, 때문에 factorial을 쌓아서 count를 구할 수 있다.

     ```c++
     long long int getIdx(vector<int> v, int n){
         /* Initialization */
         long long int count = 1;
         // 방문 vector 인 did
         vector<bool>did;
         for(int i=0; i<n+1; i++) {
             did.push_back(false);
         }
     
         /* 반복문 */
         for(int i=0; i<n; i++) {
             did[v[i]] = true; // 방문 했으니 방문했다고 기록한다 (두번들리면 안되니까)
     
             for(int j=1; j<v[i]; j++) {
                 if(did[j] == false) { // 방문하지 않은 경우에만
                     count = count+f[n-1-i];
                 }
             }
         }
         return count;
     }
     ```

* 문제 자체도 (나한텐) 어려웠지만, 2번보다는 1번이 훨씬 어려웠다. 이 문제만 장장 10시간은 쓴것같다. 그래도 완전 탐색에서 중요한 순열을 풀어서 좋다. 어려워도 포기하지말기!

#### 특이사항

* factorial을 매번 구하지않고, array에 최댓값까지 넣어, 필요할 때 사용하는 방식을 사용했다(dp) [참고](https://wjdgus2951.tistory.com/66)

  * ```c++
    f[0] = 1;
        for(int i=1; i<21; i++) {
            f[i] = f[i-1]*i;
        }
    ```



### 비트마스크

#### [집합 11723](https://www.acmicpc.net/problem/11723)

* 문제는 순열에비해 간단하다고 생각한다. add, remove, toggle, check, all, empty 연산을 비트 연산자(& | ^ ~ >> <<)를 이용하여 계산하는 것이다.
* 연산
  * add: S|(1<<k)
  * remove: S&~(1<<k)
  * toggle: S^(1<<k)
  * check: S&(1<<k)
  * all: (1<<21)-1
  * empty: 0

```c++
int main() {
    // 속도 빠르게
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string op; // 연산의 이름 - all empty add remove toggle check
    
    int n;
    cin >> n;
    int S = 0;
    int k;
    
    for(int i=0; i<n; i++) {
        cin >> op;
        // all empty
        // add remove toggle check
        if(op == "all") {
            S = (1<<21)-1;
        } else if(op=="empty") {
            S = 0;
        } else if(op=="add") {
            cin >> k;
            S = S | (1<<k);
        } else if(op=="remove") {
            cin >> k;
            S = S & ~(1<<k);
        } else if(op=="toggle") {
            cin >> k;
            S = S ^ (1<<k);
        } else if(op=="check") {
            cin >> k;
            if((S&(1<<k)) == 0) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
}
```

#### 특이사항

* 단순 입력, 출력인데 시간초과가떠서 해당 부분을 찾아보니, `cin/cout` 보다 `scanf/printf`가 훨씬 빠르다고 한다. 그래서 이 속도의 간극을 보정해주기 위해서는 아래 코드를 써주어야 한다.

  ```c++
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ```



### 알게된 것

* `resize(n)` 함수는 vector의 값을 그대로 보존하되, 사이즈만 n으로 바꾸어주는 함수이다.



## Ch 3 완전 탐색 1

### 순열 사용하기

#### [차이를 최대로 10819]((https://www.acmicpc.net/problem/10819))

* 굉장히 간단한 문제이다. 입력받은 수를 오름차순으로 한번 정렬해준 후, 계속해서 순열을 구한다. 그리고 매 순열을 구할 때 마다 사잇값의 절댓값을 구해서, 그 합이 최댓값이 되는 값을 구한다.

```c++
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp, max=-1, differ=0;
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    do{
        differ = 0;
        
        for(int i=1; i<n; i++)
            differ += abs(v[i-1]-v[i]);
        
        
        if(differ > max)
            max = differ;
        
    }while(next_permutation(v.begin(), v.end()));
    
    cout << max << "\n";
    
    return 0;
}
```



#### [로또 6603](https://www.acmicpc.net/problem/6603)

* [참고 - 상세한 설명과 예시가 있는 좋은 글이다](https://lmcoa15.tistory.com/31)

* 생각이 조금 필요했던 문제였다. 나는 위의 블로그를 참고하여 풀었다. 여기서 우리는 무조건 6개의 숫자만을 돌아가면서 출력을 해야하는데, 그 때 어떤걸 고르느냐를 **보조순열**이 결정하였다. 예를 들어 입력받은 값이 (갯수 제외) *1 2 3 4 5 6 7* 이라하면, 우리가 출력해야 하는 값은

  *  *1 2 3 4 5 6*

     *1 2 3 4 5 7*

     *1 2 3 4 6 7*

     *1 2 3 5 6 7*

     *1 2 4 5 6 7*

     *1 3 4 5 6 7*

     *2 3 4 5 6 7*

  이렇게 된다. 즉 처음에는 7이 빠지고, 두 번째에는 6이, 그 다음에는 5가 ... 마지막에는 1이 빠지며 끝난다.

* 어떤 수를 빼고, 어떤 수들을 출력할지 어떻게 결정할까? **보조순열**이다. 보조 순열은, 어떤 값을 출력하고 어떤 값을 출력하지 않을 지 결정하는데 도와주는 순열이다. (사실은 조합이다) *0, 0, 0, 0, 0, 0, 1* 의 형태로 되어있으며 1의 위치를 바꾸면서, 0일때만 출력하게 한다. 

```c++
do{
 
     for(int i=0; i<cnt; i++) {
         if(subV[i] == 0)
            printf("%d ", v[i]); // subV[i]가 0이면 출력한다
     }

     printf("\n");
 
}while(next_permutation(subV.begin(), subV.end()));
 
```

* 바로 이 부분을 말한다. subV의 순열을 구하면서, 0인 부분만 출력하도록 한다.
* 아래는 전체 코드이다

```c++
#include <vector>
#include <algorithm>
#include <iostream>

#define FIXED_SIZE 6

using namespace std;

int main() {
    
    int cnt=1;
    while(cnt != 0) {
        scanf("%d", &cnt);
        
        vector<int> subV(cnt, 0); // 크기와 값을 미리 정해줄 수 있다
        vector<int> v(cnt, 0);
        
        for(int i=0; i<cnt; i++) // 입력 받은 값을 바로 넣어주었다
            scanf("%d", &v[i]);
        
        
        // 보조순열 만들기
        for(int i=FIXED_SIZE; i<cnt; i++)  // 6~전체 갯수 까지, 1로 바꿔주었다
            subV[i] = 1;
       
        
        do{
            
            for(int i=0; i<cnt; i++) { // 보조순열을 구했다
                if(subV[i] == 0)
                    printf("%d ", v[i]);
            }
            
            printf("\n");
            
        }while(next_permutation(subV.begin(), subV.end()));
        
        printf("\n");
    }
}

```



### 재귀 호출, 비트마스크

#### [1, 2, 3 더하기 9095](https://www.acmicpc.net/problem/9095)

* 규칙만 파악하면 풀 수 있는 간단한 문제였다. 규칙은 1일 때 1, 2일 때 2, 3일 때 4, 4일 때 7로, 즉 i번째의 수는 i-3 + i-2 + i-1일 때의 값의 합과 같다는 것이다. 

* 나는 미리 최댓값까지 다 만들어놓고, 필요할 때 idx로 접근하여 가져가는 형태(dp)와 재귀, 두 가지 방법으로 풀었다.

* Dp

  * array를 써서 푸는 것이 일반적이지만 나는 vector를 별로 안써봐서, vector와 익숙해지려고 vector로 풀었다.

  ```c++
  v[0] = 0; v[1] = 1;
  v[2] = 2; v[3] = 4;
  for(int i=4; i<MAX; i++) {
  	v[i] = v[i-3]+v[i-2]+v[i-1];
  }
  ```

* 재귀

  ```c++
  int getVal(int n){
      if (n==1) return 1;
      if (n==2) return 2;
      if (n==3) return 4;
      return getVal(n-1)+getVal(n-2)+getVal(n-3);
  }
  ```

* 전체 코드

```c++
// Dp
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

// 재귀
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
```



#### [암호 만들기 1759](https://www.acmicpc.net/problem/1759)

* 로또(6603)문제와 유사한 문제이다. 보조 순열을 구하고, 가능한 값을 거기서 추려서 출력하는 것이 메인 아이디어이다. 입력이 아래와 같을 때,

   *4 6*

   *a t c i s w*

  

*  *0 0 0 0 1 1*

   *0 0 0 1 0 1*

   *...*

* 을 반복하며, 0일 때, 그리고 자음이 2개 이상, 모음이 1개 이상일 때 출력하도록 하면 된다. 그런데 `1 1 1 1 0 0` 이 아니라, `0 0 0 0 1 1` 로 (**0일 때 출력하도록**)한 이유는, **다음 순열을 구하는 문제** 때문이었다. 
* **순열이 제대로 나오지 않는 경우**에는 다음과 같은 이유가 있다.
  1. **정렬이 제대로 되어있지 않은 경우**, 이 경우에는, 정렬만 다시 해주면 된다. `sort(subV.begin(), subV.end());` 
  2. **내림 차순으로 정렬이 되어있어, 다음 순열이 없다고 판단되는 경우**
     * c++에서 next_permutation으로 다음 순열을 구하는 방법은, 전체 수열에서 내림차순(감소)을 보여주는 sequence를 찾아, 그 sequence를 다시 오름차순으로 바꿔주는 방식을 반복해서 찾는다. **하지만 순열이 내림차순으로 정렬이 되어있다면**, 다음 순열이 없다고 판단하게 되는 것이다. 따라서 처음에 생각한 `1 1 1 1 0 0` 으로 계속해서 다음 순열을 구하려고 할 경우, 이미 내림차순으로 정렬이 완료되어있기 때문에 **다음 순열이 없다고 판단**해버린것이다. 따라서 내 의도대로 나오게 하려면, 오름차순인 `0 0 0 0 1 1` 로 하면 된다. 이 때문에 `1 1 1 1 0 0` 이 아닌,  `0 0 0 0 1 1`를 사용하였고, `0`일 때 출력을 하도록 한 것이다.
* **자음 갯수와 모음 갯수를 충족시키는 값을 구하기 위해**, `isVowel`, `isConsonant` 라는 두개의 vector를 사용하였다. 각각은 모음, 자음일 때 1을 그 외에는 0을 갖는 자료구조이다. 따라서 어떤 문자를 보려고 할 때, 각각의 idx에 해당하는 `isVowel`,` isConsonant`의 합들이 각각 조건(1, 2)과 갖거나 큰 값이라면 조건을 충족하게 된다. 따라서 각각의 합이 1, 2와 갖거나 크면 출력을 하도록 하였다. 아래 코드가 이 부분을 말한다.

```c++
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
```

* 전체 코드

```c++
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

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
```



#### [N-Queen 9663](https://www.acmicpc.net/problem/9663)

* 학교에서 수업을 들을 때에도 못 풀었던 문제였고, 문제를 봤을 때도 감이 오지 않아 많이 찾아보았다. 그 중 가장 도움이 되었던 글은 [이 글이다](https://debuglog.tistory.com/82). 그래서 이 분의 코드와 거의 같다. (베끼진 않았다)

* 먼저 문제를 풀기 위해서는 `N X N` 에서 `N` 개의 퀸을 놓는 방법은 무엇이 있는지 생각을 해봐야 한다.

  1. `N X N`크기의 체스판에서 `N`개의 퀸을 놓으려면, 한 줄에 한 개의 퀸이 있어야 한다.

  2. 퀸을 임의의 자리`(r, c)`에 놓았다면, 그 자리를 기준으로 모든 c, 모든 오른쪽/왼쪽 대각선으로는 퀸을 놓을 수 없다. 따라서, 우리는 세 개의 1차원 배열을 생각할 수 있다. `col(column)`, `inc(increase)`, `dec(decrease)`가 그것이다.

     * 예를 들어, 내가 {r:0, c:4} 자리에 퀸을 놓았다고 가정한다. 그렇다면 모든 **{r:?, c:4}** 에는 어떠한 퀸도 올 수 없다. 이 것을 `col`이 기록한다.

     * 다음으로 `inc` 이다. 오른쪽 아래로 증가하는 대각선을 의미하는데, 이들은 **r-c**의 값이 동일하다는 특징을 갖고 있다. 따라서 r-c가 -4가 되는 모든 자리에는 어떠한 퀸도 올 수 없다. (배열에서 음수 인덱스는 존재할 수 없으므로 `+n` 을 해준다)
     * 마지막으로 `dec` 이다. 왼쪽 아래로 감소하는 대각선을 의미하는데, 이들은 **r+c**의 값이 동일하다는 특징을 갖고 있다. 따라서 r+c가 4가 되는 모든 자리에는 어떠한 퀸도 올 수 없다.

* 이 규칙을 생각하면, 문제를 조금 쉽게 접근할 수 있다.

```c++
if(!col[c] && !inc[r-c+n] && !dec[r+c]) {
  col[c] = true;
  inc[r-c+n] = true;
  dec[r+c] = true;

  solve(r+1);

  col[c] = false;
  inc[r-c+n] = false;
  dec[r+c] = false;
}
```

* 전체 코드

```c++
#include <iostream>

int n, answer=0;

bool col[16]; // column (직선 |)
bool inc[31]; // increase (오른쪽 아래 대각선 \)
bool dec[31]; // decrease (왼쪽 아래 대각선 /)

void solve(int r) {
    if(r >= n){
        answer = answer + 1;
        return;
    }

    for(int c=0; c<n; c++) {
        if(!col[c] && !inc[r-c+n] && !dec[r+c]) {
            col[c] = true;
            inc[r-c+n] = true;
            dec[r+c] = true;

            solve(r+1);

            col[c] = false;
            inc[r-c+n] = false;
            dec[r+c] = false;
        }
    }

}

int main() {
    scanf("%d", &n);
    solve(0);
    printf("%d", answer);
}
```

