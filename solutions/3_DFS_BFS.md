# DFS와 BFS

* 백준에 있는 DFS, BFS 문제집의 문제를 풉니다.
* 이 문제집을 풀기 전에 따로 풀었던 문제는 적지 않았습니다.

> 처음에는 이 문제집이 있는지도 몰랐고, 아마 알더라도 풀 생각을 딱히 하진 않았을 것 같다. 왜냐하면 몇몇 DFS 문제와 숨바꼭질 문제를 한 문제만 빼고 다 풀면서 나름 DFS, BFS에 익숙해졌다고 생각했기 때문이었다. 
>
> 하지만 ACM 한 문제를 너무나도 힘들게 푸는 나를 보고 해웅오빠가 DFS 문제에 기초가 부족한 것 같다며 이 문제집을 추천해주었다. (그 문제는 끝까지 못풀었다)
>
> 풀다보면서 느낀거지만, 하나의 문제만을 풀다보면 (이를테면 숨바꼭질 1번부터 6번까지) 너무 그 상태에 매몰되는것같다. 같은 유형이라도 여러 문제를 풀며 머리를 환기시켜야 할 필요가 있는 것 같다.



## `DFS` 2606 바이러스

```cpp
#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

vector<int> g[MAX];
bool visited[MAX] = {false, };
int nComputer, n, nWorm = -1;

int main() {
    void dfs(int idx);

    scanf("%d", &nComputer);
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }


    dfs(1);
    printf("%d", nWorm);
}

void dfs(int idx) {
    if(visited[idx]) return;
    visited[idx] = true;
    nWorm ++;

    int size = g[idx].size();
    for(int i=0; i<size; i++) {
        dfs(g[idx][i]);
    }

}

```



## `DFS` 1012 유기농 배추

```cpp
#include <iostream>

#define MAX 51

using namespace std;

int pyo[MAX][MAX];
bool visited[MAX][MAX];
int xCoor[4] = {0, 1, 0, -1};
int yCoor[4] = {-1, 0, 1, 0};
int nWorm, m, n, k;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    void dfs(int x, int y);

    int tc;
    cin >> tc;

    for(int t=0; t<tc; t++) {
        scanf("%d %d %d", &m, &n, &k);
        fill(&pyo[0][0], &pyo[n][m], 0);
        fill(&visited[0][0], &visited[n][m], 0);
        nWorm = 0;

        for(int i=0; i<k; i++) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            pyo[v2][v1] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(!visited[i][j] && pyo[i][j] == 1) {
                    nWorm ++;
                    dfs(i, j);
                }
            }
        }

        cout << nWorm << "\n";
    }



}
void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i=0; i<4; i++) {
        int newX = x + xCoor[i];
        int newY = y + yCoor[i];

        if(newX < 0 || newY < 0) continue;
        if(newX > n || newY > m) continue;
        if(visited[newX][newY] || pyo[newX][newY] != 1) continue;

        dfs(newX, newY);
    }
}

```



* 표를 만들 때, 흔히 우리가 현실에서 `10 x 3`의 표를 만든다 라고 생각하면, 가로의 길이가 10이고 세로의 길이가 3인 사각형을 생각한다.

* 이 때 `10 x 3`을 `m x n` 이라고 했을 때 m은 가로에 대응되고, n은 세로에 대응되는 것이 아니다. 오히려 그 반대이다. 나는 이 부분에서 매일 헷갈려서, 가로 세로 길이가 다른 표 문제를 풀 때면 항상 화가났다.

* 이제 이 좆같은 문제를 풀었고 `m x n` 일 때 각각이 가로/세로에 대응되는 것이 아니라는 것을 안다. 만약 `10 x 3`의 사각형을 만들으라고 하였을 때 10이 m이고 3이 n이라면 내가 만들 matrix는 `matrix[n][m]` 모양을 갖게 된다. 그리고 이후에 `(x, y)` 에 5를 넣으라고 한다면, `matrix[y][x] = 5` 가 되는 것이다. 모두 다 반대로 생각하는 것이다.



## `BFS` 2178 미로 탐색

```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

#define MAX 101
int pyo[MAX][MAX];
bool visited[MAX][MAX];
int xCoor[4] = {-1, 0, 1, 0}, yCoor[4] = {0, 1, 0, -1}, cnt=1, n, m;
queue<pair<int, int>> q;

int main() {
    void printCnt();
    void bfs();

    scanf("%d %d", &n, &m);

    fill(&visited[0][0], &visited[n][m], false);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &pyo[i][j]);
        }
    }

    q.push(make_pair(0, 0));
    bfs();

    printf("%d", pyo[n-1][m-1]);
}

void bfs() {
    while(q.size()) {
        int size = q.size();
        for(int i=0; i<size; i++) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(visited[x][y]) continue;
            visited[x][y] = true;


            for(int i=0; i<4; i++) {
                int newX = x+xCoor[i];
                int newY = y+yCoor[i];

                if(newX < 0 || newY < 0 || newX > n || newY > m) continue;
                if(visited[newX][newY] || pyo[newX][newY] == 0) continue;

                pyo[newX][newY] = pyo[x][y]+1;
                q.push(make_pair(newX, newY));
            }
        }
    }
}

```

* 처음에 풀 때는 BFS만 생각하고 풀었다. newX, newY를 구하는 for loop 전체를 한 번 돌 때마다 cnt+1 해주는 식으로 풀었었다. 그러나 이렇게 풀었을 때는 큰 문제가 있었다.

* 미로를 더 짧은 경로로 통과할 수 있는 방법이 있음에도 불구하고 모든 곳을 들르기 때문에 계속해서 +1을 해주는 문제가 있었다.

* 그래서 몇몇자료를 찾아봤더니, DP와 BFS를 같이 쓰면 되는 것이라는걸 알게 되었다. 그리고 나 또한 이 방법으로 풀었다.