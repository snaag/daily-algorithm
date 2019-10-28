/*
// cin cout 속도 개선
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 
 */
// 백준 문제집
// 그리디 DnC 이분탐색 그래프 BFS DFS 백트래킹 최단거리 트리 위상정렬 DS MST - jh05013

// DnC 1992 쿼드트리
/*
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011
 */
//#include <iostream>
//#define MAX 65
//
//int pyo[MAX][MAX] = {0, };
//
//int main(int argc, const char * argv[]) {
//    void dnc(int size, int prevX, int prevY);
//
//    int n;
//    scanf("%d", &n);
//
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            scanf("%1d", &pyo[i][j]);
//        }
//    }
//
//    dnc(n, 0, 0);
//}
//
//void dnc(int size, int prevX, int prevY) {
//    int defaultValue = pyo[prevX][prevY];
//    bool isSame = true;
//
//    if(size == 1) {
//        printf("%d", defaultValue);
//        return;
//    }
//
//    for(int i=prevX; i<prevX+size; i++) {
//        if(!isSame) break;
//        for(int j=prevY; j<prevY+size; j++) {
//            if(defaultValue != pyo[i][j]) {
//                isSame = false;
//                break;
//            }
//        }
//    }
//
//    if(isSame){
//        printf("%d", defaultValue);
//        return;
//    }
//
//    printf("(");
//    dnc(size/2, prevX, prevY);
//    dnc(size/2, prevX, prevY+size/2);
//    dnc(size/2, prevX+size/2, prevY);
//    dnc(size/2, prevX+size/2, prevY+size/2);
//    printf(")");
//}


// BFS 1389 케빈 베이컨의 6단계 법칙
//#include <iostream>
//#include <queue>
//#include <numeric>
//using namespace std;
//
//#define MAX 101
//
//vector<int> graph[MAX];
//int reduce[MAX];
//int n, m; //n: user 수, m: 간선의 수
//
//int main() {
//    void solve(int idx);
//    int getSmallestIdx(int arr[]);
//
//
//    scanf("%d %d", &n, &m);
//    for(int i=0; i<m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        graph[a].push_back(b);
//        graph[b].push_back(a);
//    }
//
//    fill(reduce+1, reduce+n+1, 0);
//
//    for(int i=1; i<=n; i++)
//        solve(i);
//
//
//    printf("%d", getSmallestIdx(reduce));
//}
//
//void solve(int idx) {
//    // 시작 준비
//    int visited[MAX];
//    fill(visited+1, visited+n+1, -1);
//    int depth = 0;
//    queue<int> q;
//
//    q.push(idx);
//    visited[idx] = 0;
//
//    // 시작
//    while(q.size()) {
//        int size = q.size();
//        depth = depth + 1;
//
//        for(int i=0; i<size; i++) {
//            int front = q.front(); q.pop();
//
//            for(int j=0; j<graph[front].size(); j++) {
//                int next = graph[front][j];
//                if(visited[next] < 0) { // 방문한 적이 없을 때에만 q에 넣는다
//                    visited[next] = depth;
//                    q.push(next);
//                }
//            }
//        }
//    }
//    reduce[idx] = std::accumulate(visited+1, visited+n+1, 0);
//}
//
//
//int getSmallestIdx(int arr[]) {
//    int ret=1;
//
//    for(int i=2; i<=n; i++) {
//        if(arr[i] < arr[ret]) {
//            ret = i;
//        }
//    }
//    return ret;
//}


// DFS 2606 바이러스
//#include <iostream>
//#include <vector>
//
//#define MAX 101
//
//using namespace std;
//
//vector<int> g[MAX];
//bool visited[MAX] = {false, };
//int nComputer, n, nWorm = -1;
//
//int main() {
//    void dfs(int idx);
//
//    scanf("%d", &nComputer);
//    scanf("%d", &n);
//
//    for(int i=0; i<n; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        g[a].push_back(b);
//        g[b].push_back(a);
//    }
//
//
//    dfs(1);
//    printf("%d", nWorm);
//}
//
//void dfs(int idx) {
//    if(visited[idx]) return;
//    visited[idx] = true;
//    nWorm ++;
//
//    int size = g[idx].size();
//    for(int i=0; i<size; i++) {
//        dfs(g[idx][i]);
//    }
//
//}

// DFS 1012 유기농 배추
//#include <iostream>
//
//#define MAX 51
//
//using namespace std;
//
//int pyo[MAX][MAX];
//bool visited[MAX][MAX];
//int xCoor[4] = {0, 1, 0, -1};
//int yCoor[4] = {-1, 0, 1, 0};
//int nWorm, m, n, k;
//
//int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    void dfs(int x, int y);
//
//    int tc;
//    cin >> tc;
//
//    for(int t=0; t<tc; t++) {
//        scanf("%d %d %d", &m, &n, &k);
//        fill(&pyo[0][0], &pyo[n][m], 0);
//        fill(&visited[0][0], &visited[n][m], 0);
//        nWorm = 0;
//
//        for(int i=0; i<k; i++) {
//            int v1, v2;
//            scanf("%d %d", &v1, &v2);
//            pyo[v2][v1] = 1;
//        }
//
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//
//                if(!visited[i][j] && pyo[i][j] == 1) {
//                    nWorm ++;
//                    dfs(i, j);
//                }
//            }
//        }
//
//        cout << nWorm << "\n";
//    }
//
//
//
//}
//void dfs(int x, int y) {
//    visited[x][y] = true;
//
//    for(int i=0; i<4; i++) {
//        int newX = x + xCoor[i];
//        int newY = y + yCoor[i];
//
//        if(newX < 0 || newY < 0) continue;
//        if(newX > n || newY > m) continue;
//        if(visited[newX][newY] || pyo[newX][newY] != 1) continue;
//
//        dfs(newX, newY);
//    }
//}
/*
표를 만들 때, 흔히 우리가 현실에서 10X3의 표를 만든다 라고 생각하면, 가로의 길이가 10이고 세로의 길이가 3인 사각형을 생각한다.
이 때 10X3을 mXn 이라고 했을 때 m은 가로에 대응되고, n은 세로에 대응되는 것이 아니다. 오히려 그 반대이다. 나는 이 부분에서 매일 헷갈려서, 가로 세로 길이가 다른 표 문제를 풀 때면 항상 화가났다.

이제 이 좆같은 문제를 풀었고 mXn 일 때 각각이 가로/세로에 대응되는 것이 아니라는 것을 안다. 만약 10X3의 사각형을 만들으라고 하였을 때 10이 m이고 3이 n이라면 내가 만들 matrix는 matrix[n][m] 모양을 갖게 된다. 그리고 이후에 (x, y) 에 5를 넣으라고 한다면, matrix[y][x] = 5 가 되는 것이다. 모두 다 반대로 생각하는 것이다.
 */


// BFS 2178 미로탐색
//#include <iostream>
//#include <algorithm>
//#include <utility>
//#include <queue>
//
//using namespace std;
//
//#define MAX 101
//int pyo[MAX][MAX];
//bool visited[MAX][MAX];
//int xCoor[4] = {-1, 0, 1, 0}, yCoor[4] = {0, 1, 0, -1}, cnt=1, n, m;
//queue<pair<int, int>> q;
//
//int main() {
//    void printCnt();
//    void bfs();
//
//    scanf("%d %d", &n, &m);
//
//    fill(&visited[0][0], &visited[n][m], false);
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            scanf("%1d", &pyo[i][j]);
//        }
//    }
//
//    q.push(make_pair(0, 0));
//    bfs();
//
//    printf("%d", pyo[n-1][m-1]);
//}
//
//void bfs() {
//    while(q.size()) {
//        int size = q.size();
//        for(int i=0; i<size; i++) {
//
//            int x = q.front().first;
//            int y = q.front().second;
//            q.pop();
//
//            if(visited[x][y]) continue;
//            visited[x][y] = true;
//
//
//            for(int i=0; i<4; i++) {
//                int newX = x+xCoor[i];
//                int newY = y+yCoor[i];
//
//                if(newX < 0 || newY < 0 || newX > n || newY > m) continue;
//                if(visited[newX][newY] || pyo[newX][newY] == 0) continue;
//
//                pyo[newX][newY] = pyo[x][y]+1;
//                q.push(make_pair(newX, newY));
//            }
//        }
//    }
//}
/*
처음에 풀 때는 BFS만 생각하고 풀었다. newX, newY를 구하는 for loop 전체를 한 번 돌 때마다 cnt+1 해주는 식으로 풀었었다. 그러나 이렇게 풀었을 때는 큰 문제가 있었다.
미로를 더 짧은 경로로 통과할 수 있는 방법이 있음에도 불구하고 모든 곳을 들르기 때문에 계속해서 +1을 해주는 문제가 있었다.
그래서 몇몇자료를 찾아봤더니, DP와 BFS를 같이 쓰면 되는 것이라는걸 알게 되었다. 그리고 나 또한 이 방법으로 풀었다.
 */
