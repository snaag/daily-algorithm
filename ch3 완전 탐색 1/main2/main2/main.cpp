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
#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    auto f1 = []() { cout << "foo" << endl; };
    f1();
    
    auto f2 = [](int a) {return a*2;};
    int a = f2(3);
    cout << a << endl;
    
    int (*operation[3])(int) = {
        [](int a) -> int {return a-1;},
        [](int a){return a+1;},
        [](int a){return a*2;}
    };

    cout << operation[0](3) << endl;
//    auto z = std::array<int, 5>();
    
    
}
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
