// 2667 단지번호붙이기 - DFS
// 11724번과 유사하다고 한다.
/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
 */
// DFS
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define MAX 26
//
//using namespace std;
//
//int pyo[MAX][MAX];
//bool isVisit[MAX][MAX];
//vector<int> area;
//int n, cnt=0;
//int xCoor[4] = {-1, 0, 1, 0};
//int yCoor[4] = {0, 1, 0, -1};
//
//
//int main() {
//    void solve(int x, int y);
//    void printPyo();
//
//
//    // 입력
//    cin >> n;
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            scanf("%1d", &pyo[i][j]);
//            isVisit[i][j] = false;
//        }
//    }
//
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            cnt = 0;
//            if(pyo[i][j] == 1 && !isVisit[i][j]){
//                solve(i, j);
//                area.push_back(cnt);
//            }
//        }
//    }
//
//    sort(area.begin(), area.end(), greater<int>());
//    printf("%d\n", area.size());
//    for(int i=area.size()-1; i>=0; --i) {
//        printf("%d\n", area[i]);
//    }
//}
//
//void solve(int x, int y) {
//    if(pyo[x][y] == 0 || isVisit[x][y]) return;
//
//    isVisit[x][y] = true;
//    cnt++;
//
//    for(int i=0; i<4; i++) {
//        int newX = x + xCoor[i];
//        int newY = y + yCoor[i];
//
//        if(newX < 0 || newY < 0 || newX > n-1 || newY > n-1) continue;
//        if(pyo[newX][newY] == 0 || isVisit[newX][newY]) continue;
//
//        solve(newX, newY);
//    }
//}

// 1260 DFS와 BFS
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define MAX 1001
//
//using namespace std;
//
//vector<int> graph[MAX];
//bool visited[MAX];
//int n, m, v;
//
//int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    void dfs(int i);
//    void bfs(int i);
//
//    cin >> n >> m >> v;
//
//    // graph, visited 초기화
//    int r, c;
//
//    for(int i=0; i<m; i++) {
//        cin >> r >> c;
//        graph[r].push_back(c);
//        graph[c].push_back(r);
//    }
//
//    for(int i=0; i<n; i++) {
//        visited[i+1] = false;
//    }
//
//    // 간선 정보를 담은 []vector를 정렬
//    for(int i=1; i<n+1; i++) {
//        sort(graph[i].begin(), graph[i].end());
//    }
//
//    // DFS
//    dfs(v);
//
//    cout << "\n";
//    std::fill(visited, visited+n+1, false);
//
//    // BFS
//    bfs(v);
//}
//
//void dfs(int idx) {
//    if(visited[idx]) return;
//
//    visited[idx] = true;
//    cout << idx << " ";
//
//    int size = graph[idx].size();
//    for(int i=0; i<size; i++) {
//        dfs(graph[idx][i]);
//    }
//
//}
//
//void bfs(int idx) {
//    queue<int> q;
//    if(visited[idx]) return;
//
//    visited[idx] = true;
//    q.push(idx);
//
//    while(!q.empty()) {
//        int front = q.front();
//        q.pop();
//        cout << front << " ";
//
//        int size = graph[front].size();
//        for(int i=0; i<size; i++) {
//            if(!visited[graph[front][i]]){
//                q.push(graph[front][i]);
//                visited[graph[front][i]] = true;
//            }
//        }
//    }
//}
//
//void printGraph() {
//    for(int i=1; i<n+1; i++) {
//        printf("%d: ", i);
//        for(int j=0; j<graph[i].size(); j++) {
//            printf("%d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//}
//


// 11724 연결요소의 갯수 - BFS
//#include <algorithm>
//#include <iostream>
//#include <queue>
//#include <vector>
//
//#define MAX 1001
//
//using namespace std;
//
//vector<int> graph[MAX];
//bool visited[MAX];
//int n, m, cnt=0;
//
//int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    void bfs(int idx);
//
//    cin >> n >> m;
//    // visited 초기화
//    for(int i=1; i<n+1; i++)
//        visited[i] = false;
//
//    // 간선의 정보 입력받고, graph에 초기화해주기
//    int r, c;
//    for(int i=0; i<m; i++) {
//        cin >> r >> c;
//        graph[r].push_back(c);
//        graph[c].push_back(r);
//    }
//
//    // graph 정렬
//    for(int i=1; i<n+1; i++)
//        sort(graph[i].begin(), graph[i].end());
//
//    // bfs
//    for(int i=1; i<n+1; i++) {
//        if(!visited[i]) {
//            cnt++;
//            bfs(i);
////            cout << endl;
//        }
//    }
//
//    cout << cnt ;
//}
//
//void bfs(int idx) {
//    if(visited[idx]) return;
//
//    queue<int> q;
//
//    visited[idx] = true;
//    q.push(idx);
//
//    while(!q.empty()) {
//        int front = q.front();
//        q.pop();
////        cout << front << " ";
//
//        int size = graph[front].size();
//        for(int i=0; i<size; i++) {
//            if(!visited[graph[front][i]]) {
//                q.push(graph[front][i]);
//                visited[graph[front][i]] = true;
//            }
//        }
//    }
//}


// 7576 토마토
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>
//#include <algorithm>
//
//#define MAX 1001
//
//using namespace std;
//
//int pyo[MAX][MAX], r, c, day=0;
//int xCoor[4] = {-1, 0, 1, 0};
//int yCoor[4] = {0, 1, 0, -1};
//
//queue<pair<int, int>> q;
//
//int main() {
//    void printPyo();
//    void bfs();
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    // pyo, c, r 에 초기값 주기
//    cin >> c >> r;
//    for(int i=0; i<r; i++){
//        for(int j=0; j<c; j++) {
//            cin >> pyo[i][j];
//        }
//    }
//
//    // q 에 초기값 넣어주기
//    for(int i=0; i<r; i++) {
//        for(int j=0; j<c; j++) {
//            if(pyo[i][j] == 1){
//                q.push(make_pair(i, j));
//            }
//        }
//    }
//
//    // bfs
//    bfs();
//
//    // 익지 않은 토마토가 있는지 검사하기
//    for(int i=0; i<r; i++) {
//        for(int j=0; j<c; j++) {
//            if(pyo[i][j] == 0) {
//                cout << -1;
//                exit(0);
//            }
//        }
//    }
//
//    cout << day-1 ;
//}
//
//void bfs() {
//    void printPyo();
//
//    while(!q.empty()) {
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//            int x = q.front().first;
//            int y = q.front().second;
//            q.pop();
//
//            for(int j=0; j<4; j++) {
//                int newX = x + xCoor[j];
//                int newY = y + yCoor[j];
//                if(newX<0 || newY<0 || newX>r-1 || newY>c-1) continue;
//                if(pyo[newX][newY] == -1 || pyo[newX][newY] == 1) continue;
//
//                q.push(make_pair(newX, newY));
//                pyo[newX][newY] = 1;
//
//            }
//
//        }
////        printPyo();
//        day++;
//    }
//}
//
//void printPyo() {
//    for(int i=0; i<r; i++) {
//        for(int j=0; j<c; j++) {
//            cout << pyo[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout<<endl;
//}


// 1697 숨바꼭질
//#include <iostream>
//#include <queue>
//
//#define MAX 100001
//
//using namespace std;
//
//int (*operation[3])(int) = {
//    [](int a){return a-1;},
//    [](int a){return a+1;},
//    [](int a){return a*2;}
//};
//int n, k, t=0; // n: 수빈, k: 동생, t: 시간(초)
//bool visited[MAX] = {false,};
//queue<int> q;
//
//int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    void bfs(int idx);
//
//    // n, k 초기화 하기
//    cin >> n >> k;
//
//    // q에 초기값 넣어주기
//    visited[n] = true;
//    q.push(n);
//
//    // bfs
//    bfs(n);
//}
//
//void bfs(int idx) {
//
//    while(!q.empty()) {
//        int size = q.size();
//        for(int i=0; i<size; i++) {
//            int f = q.front();
//            q.pop();
//            if(f == k) {
//                cout << t;
//                exit(0);
//            }
//
//            for(int j=0; j<3; j++) {
//                int newN = operation[j](f);
//                if(newN < 0 || newN > MAX || visited[newN]) continue;
//
//                q.push(newN);
//                visited[newN] = true;
//            }
//
//        }
//        t++;
//    }
//}

/*
 lambda 식을 array 안에 담는 방법: 함수 포인터 array를 사용하면 된다.
 * 일부 자료를 찾아봤을 때, `auto f1 = [](int a){return a+1;};` 이런 식으로 되어있길래, 처음에는 그저 auto 라는 type이 있는 줄 알고,
 `auto operation[3] = { ... }` 이렇게 선언했었다. 그러나 잘 되지 않아, 알아보니 auto 는 compile time 에 타입이 결정되는 것을 말한다고 한다.
 예를 들어 int a=5 가 있을 때, auto b = a; 이런 문장이 있다면 b는 int type을 갖게 되는 것이다. 따라서 선언과 동시에 크기가 결정이 되어야하는 array에는 auto를 사용해 선언할 수가 없는 것이다. 그렇다면 어떻게 선언해야 할까?
* 함수 포인터를 사용하면 된다. lambda는 함수이다. 따라서 lambda를 array로 담고 싶다면 함수 포인터 array를 사용해야 한다.
 ```c++
 int (*operation[3])(int) = {
     [](int a){return a-1;},
     [](int a){return a+1;},
     [](int a){return a*2;}
 };
 
 cout << operation[0](3) << endl;
 ```
 */

// 12851 숨바꼭질 2
//#include <iostream>
//#include <queue>
//
//#define MAX 100001
//
//using namespace std;
//
//int (*operation[3])(int) = {
//    [](int a){return a-1;},
//    [](int a){return a+1;},
//    [](int a){return a*2;}
//};
//int n, k, cnt=0, t=0; // n: 수빈, k: 동생, cnt: 갯수, t: 시간
//bool visited[MAX+1] = { false, };
//queue<int> q;
//
//int main() {
//    void bfs(int idx);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n >> k;
//
//    if(n == k) {
//        cout << t << endl;
//        cout << 1 << endl;
//        exit(0);
//    }
//
//    q.push(n);
//    bfs(n);
//
//
//}
//
//void bfs(int idx) {
//    while(!q.empty()) {
//
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//            int front = q.front(); q.pop();
//            visited[front] = true;
//
//            if(front == k)
//                cnt++;
//
//            for(int j=0; j<3; j++) {
//                int newN = operation[j](front);
//
//                if(newN < 0 || newN > MAX+1) continue;
//                if(newN != k && visited[newN]) continue;
//
////                visited[newN] = true;
//                /*
//                 여기서 visited를 체크하면,
//                 +1, *2 의 결과가 같은 경우에
//                 예를 들면 입력이 1 4 인 경우를 가정한다면 1-2(1+1)-3-4, 또는 1-2(1*2)-3-4 라는 경우의 수가 생기는데
//                 이들을 각각 하나로 생각을 해야 하지만, 그렇게 생각하지를 못한다.
//                 따라서 추가할 때가 아닌, pop할 때 visited를 체크해주어야 한다.
//                 */
//
//                q.push(newN);
//            }
//        }
//
//        if(cnt > 0) {
//            cout << t << endl;
//            cout << cnt << endl;
//            exit(0);
//        }
//        t++;
//    }
//}
//

// 13913 숨바꼭질 4
//#include <iostream>
//#include <vector>
//#include <utility>
////
//#define MAX 100001
////
//using namespace std;
//
//int (*operation[3])(int) = {
//    [](int a){return a-1;},
//    [](int a){return a+1;},
//    [](int a){return a*2;}
//};
//int n, k, t=0;
//bool visited[MAX] = {false, };
//vector<pair<int, int>> v[MAX];
//vector<pair<int, int>> path;
//
//int main() {
//    void bfs(int idx);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n >> k;
//
//    v[0].push_back(make_pair(0, n));
//    visited[n] = true;
//    bfs(n);
//}
//
//void bfs(int idx) {
//    void trace();
//
//    while(true) {
//        int size = v[t].size();
//
//        for(int i=0; i<size; i++) {
//            int preVal = v[t][i].second;
//
//            if(preVal == k){
//                int prePos = v[t][i].first;
//
//                path.push_back(make_pair(prePos, preVal));
//                trace();
//            }
//
//            for(int j=0; j<3; j++) {
//                int newN = operation[j](preVal);
//
//                if(newN < 0 || newN > MAX) continue;
//                if(visited[newN]) continue;
//
//                v[t+1].push_back(make_pair(i, newN));
//                visited[newN] = true;
//            }
//
//        }
//        t++;
//    }
//}
//
//void trace() {
//    for(int i=1; i<t+1; i++) {
//        int prePos = path[i-1].first;
//        pair<int, int> newPair = v[t-(i)][prePos];
//        path.push_back(newPair);
//    }
//
//    reverse(path.begin(), path.end());
//
//    cout << t << "\n";
//    for(int i=0; i<t+1; i++) {
//        cout << path[i].second << " ";
//    }
//
//    exit(0);
//}
/*
 path를 알기 위해선, t 시점의 점들의 정보를 알고 있어야 한다. 따라서 앞서 문제들에서 queue로 저장했던 것들을 []vector 로 저장하였다.
 queue가 아니라 vector인 이유는, 임의의 점에서 다음 점(-1, +1, *2)으로 넘어갈 때 앞서 문제들처럼 pop을 하는 것이 아니라 index로 접근할 때 queue보다 vector가 보다 쉽게 접근할 수 있기 때문이었다.
 */


// 13549 숨바꼭질 3
// queue
//#include <iostream>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <utility>
//
//#define MAX 100001
//
//using namespace std;
//
//int (*operation[3])(int) = {
//    [](int a){return a*2;},
//    [](int a){return a-1;},
//    [](int a){return a+1;}
//};
//int n, k; // n: 수빈, k: 동생
//
//queue<pair<int, int>> q;
//bool visited[MAX] = {false, };
//
//int main() {
//    void bfs(int idx);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n >> k;
//
//    visited[n] = true;
//    q.push(make_pair(0, n)); // 위치, 시간
//    bfs(n);
//
//}
//
//void bfs(int idx) {
//    while(!q.empty()) {
//
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//            int prevTime = q.front().first;
//            int prevLoc = q.front().second;
//
//            //            cout << prevTime << ", " << prevLoc << endl;
//
//            if(prevLoc == k) {
//                cout << prevTime << endl;
//                exit(0);
//            }
//
//            q.pop();
//
//            for(int j=0; j<3; j++) {
//                int newLoc = operation[j](prevLoc);
//                int newTime;
//
//                if(newLoc < 0 || newLoc > MAX) continue;
//                if(visited[newLoc]) continue;
//
//                if(j == 0)
//                    newTime = prevTime;
//
//                else if(j == 1 || j == 2)
//                    newTime = prevTime + 1;
//
//                q.push(make_pair(newTime, newLoc));
//                visited[newLoc] = true;
//
//            }
//        }
//    }
//}

// priority queue
//#include <iostream>
//#include <vector>
//#include <functional>
//#include <queue>
//#include <utility>
//
//#define MAX 100001
//
//using namespace std;
//
//int (*operation[3])(int) = {
//    [](int a){return a*2;},
//    [](int a){return a-1;},
//    [](int a){return a+1;}
//};
//int n, k; // n: 수빈, k: 동생
//
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//bool visited[MAX] = {false, };
//
//int main() {
//    void bfs(int idx);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n >> k;
//
//    visited[n] = true;
//    q.push(make_pair(0, n)); // 위치, 시간
//    bfs(n);
//
//}
//
//void bfs(int idx) {
//    while(!q.empty()) {
//
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//            int prevTime = q.top().first;
//            int prevLoc = q.top().second;
//
//
//            //            cout << prevTime << ", " << prevLoc << endl;
//
//            if(prevLoc == k) {
//                cout << prevTime << endl;
//                exit(0);
//            }
//
//            q.pop();
//
//            for(int j=0; j<3; j++) {
//                int newLoc = operation[j](prevLoc);
//                int newTime;
//
//                if(newLoc < 0 || newLoc > MAX) continue;
//                if(visited[newLoc]) continue;
//
//                if(j == 0)
//                    newTime = prevTime;
//
//                else if(j == 1 || j == 2)
//                    newTime = prevTime + 1;
//
//                q.push(make_pair(newTime, newLoc));
//                visited[newLoc] = true;
//
//            }
//        }
//    }
//}

/*
 수잘알 준호쓰가 우선순위 큐를 쓰지 않고 푸는 방법을 제안해서 풀어봤다. 다시 풀어보니, 우선순위 큐의 사용 유무 보다는 연산 시 순서가 더 중요했다.
 왜냐하면, *2, -1, +1 순서대로 새로운 좌표를 계산했을 때 어떤 큐를 사용하더라도 올바르게 답이 나왔기 때문이다.
 
 둘의 차이는 성능이었다. 우선순위 큐를 썼을 때의 성능이 그냥 큐를 썼을 때 보다 성능이 조금 더 낮게 나왔다. (+ 248KB, + 8ms)
 따라서 쓰지 않을 수 있다면 쓰지 않는 것이 성능에 더 좋은 것 같다.
*/

// 17071 숨바꼭질 5
// 난이도가 많이 높으니 다음에 풀으렴
//#include <iostream>
//#include <queue>
//
//#define MAX 500000
//
//using namespace std;
//
//bool visited[2][MAX+1] = {false,};
//queue<int> q;
//int n, k, t=0; // k: 동생
//int (*operation[3])(int) = {
//    [](int a){return a-1;},
//    [](int a){return a+1;},
//    [](int a){return a*2;}
//};
//
//int main() {
//    void bfs(int idx);
//
//    cin >> n >> k;
//
//    if (n >= MAX || k >= MAX) {
//        cout << -1;
//        exit(0);
//    }
//
//    q.push(n);
//    bfs(n);
//
//    cout << -1;
//}
//
//void bfs(int idx) {
//
//    while(q.size()) {
//        k = k + t;
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//
//            // 1 time
//            int front = q.front(); q.pop();
//            if(front == k) {
//                cout << t << endl;
//                exit(0);
//            }
//
//            if(visited[t%2][front]) continue;
//            visited[t%2][front] = true;
//
//            for(int j=0; j<3; j++) {
//                int newN = operation[j](front); // 수빈이의 새로운 위치
//
//                if(newN > MAX || newN < 0) continue;
//
//                q.push(newN);
//            }
//
//        }
//        t = t + 1;
//    }
//}

// 17087 숨바꼭질 6
// (1)
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//#define MAX 1000000001
//
//using namespace std;
//int n, cntS, nBtwMax; // n: 수빈이 위치, cntS: 동생 명수, nBtw: n, cntS, vS 의 사이 값 중 최댓값
//
//vector<int> vS; // 동생 위치가 저장되어있는 vector
//queue<int> q;
//unsigned int visited; // 앞서 사용했던 visited array와 같은 역할을 비트연산자로 수행할 것이다
//int coor[2] = {-1, +1};
//bool ok = true;
//
//int main() {
//    int getBtw();
//    void bfs(int dist);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    // 초기화
//    cin >> cntS >> n;
//    for(int i=0; i<cntS; i++) {
//        int tmp;
//        cin >> tmp;
//        vS.push_back(tmp);
//    }
//    nBtwMax = getBtw();
//
//    for(int i=nBtwMax; i>0; i--) {
//        std::queue<int> empty; // q 초기화 (사이즈가 0인 queue와 바꿔치기)
//        std::swap(q, empty);
//        visited = 0; // visited 초기화
//        ok = true; // ok 초기화
//
//        q.push(n);
//        visited = visited | (1 << n);
//        bfs(i);
//
//        if(!ok) {
//            cout << i;
//            exit(0);
//        }
//
//    }
//}
//
//int getBtw() {
//    int ret=MAX;
//
//    auto min = min_element(vS.begin(), vS.end());
//
//    for(int i=0; i<cntS; i++) { // 동생들의 위치 vector 에서 가장 작은 사잇값 구하기
//        if(*min == vS[i]) continue;
//        if(abs(*min - vS[i]) < ret)
//            ret = abs(*min - vS[i]);
//    }
//
//    if(ret > n - *min) { // 수빈이의 위치-min 했을 때, 이 값이 위에서 구한 값보다 작다면, 그 값을 return 하기
//        ret = abs(n - *min);
//    }
//
//    return ret;
//}
//
//void bfs(int dist) {
//    int findCount = 0;
//    while(q.size() && ok) {
//        int size = q.size();
//
//        for(int i=0; i<size; i++) {
//            int front = q.front(); q.pop();
//
//            if(std::find(vS.begin(), vS.end(), front) != vS.end())
//                findCount = findCount + 1;
//
//            if(findCount == cntS) {
//                ok = false;
//            }
//
//            for(int j=0; j<2; j++) {
//                int newN = front + dist*coor[j];
//
//                if(newN > MAX || newN < 0) continue;
//                if(visited & (1 << newN)) continue;
//
//                visited = visited | (1 << newN);
//                q.push(newN);
//            }
//
//        }
//    }
//}

/*
 수빈이의 위치, 동생들의 위치 사이의 값들의 최솟값 btwMin를 칮아, btwMin이 0이 될 때 까지 bfs를 수행한다.
 접근은 좋았다고 생각이들지만 지나치게 많은 작업이 필요하다. 따라서 다른 방법을 생각하기로 했다.
 */

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int subin, nBro;
//vector<int> vDif;
//
//int main() {
//    int findGcd(vector<int> v, int n);
//
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> nBro >> subin;
//    for(int i=0; i<nBro; i++) {
//        int t;
//        cin >> t;
//        vDif.push_back(abs(subin-t));
//    }
//
//    cout << findGcd(vDif, nBro) << endl;
//}
//
//int gcd(int a, int b) {
//    while (b != 0)
//    {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
//
//int findGcd(vector<int> v, int n) {
//    int ret = v[0];
//
//    for(int i=1; i<n; i++) {
//        ret = gcd(v[i], ret);
//    }
//
//    return ret;
//}
