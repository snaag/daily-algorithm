# Solutions
## Ch2 완전 탐색 0
### 순열
* 문제: [순열의 순서 1722](<https://www.acmicpc.net/problem/1722>)

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



### 알게된 것

* `resize(n)` 함수는 vector의 값을 그대로 보존하되, 사이즈만 n으로 바꾸어주는 함수이다.




