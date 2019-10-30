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



## `BFS` 7569 토마토

```cpp
#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct triplet {
    int h, m, n;
};

int m, n, h, pyo[MAX][MAX][MAX], day=-1;
int hCoor[6] = {0,0,0,0,1,-1}, mCoor[6] = {0,1,0,-1,0,0}, nCoor[6] = {1,0,-1,0,0,0};
queue<triplet> q;

int main() {
    void bfs();
    
    scanf("%d %d %d", &n, &m, &h); // m: 3, n: 5, h: 1
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                scanf("%d", &pyo[i][j][k]);
                if(pyo[i][j][k] == 1)
                    q.push({i, j, k});
            }
        }
    }
    
    bfs();
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                if(pyo[i][j][k] == 0) {
                    printf("%d\n", -1);
                    exit(0);
                }
            }
        }
    }
    
    printf("%d\n", day);
}


void bfs() {
    while(q.size()) {
        int size = q.size();
        for(int s=0; s<size; s++) {
            triplet t = q.front(); q.pop();
            
            for(int i=0; i<6; i++) {
                int newH = t.h + hCoor[i];
                int newM = t.m + mCoor[i];
                int newN = t.n + nCoor[i];
                
                if(newH < 0 || newM < 0 || newN < 0 || newH > h-1 || newM > m-1 || newN > n-1) continue;
                if(pyo[newH][newM][newN] != 0) continue;
                
                pyo[newH][newM][newN] = 1;
                q.push({newH, newM, newN});
            }
        }
        day++;
    }
}
```

* 토마토 상자가 쌓일 수 있다는 것을 제외하면 지난번에 풀었던 [토마토 (7576)](https://www.acmicpc.net/problem/7576) 문제와 완전히 같다.

* 이 문제를 풀면서 추가로 알게 된 건, queue의 class로 struct를 넣을 수 있다는 것이다.

> 처음에 변수 세개를 queue의 인자로 넘겨야 하는 것 때문에 고민이 되었다. pair는 두 개밖에 못넣고, 그렇다고 pair에 pair를 쓰자니 너무 복잡하고, 그래서 찾아봤더니 struct로 손쉽게 하는 것을 보았다.

```cpp
struct triplet {
    int h, m, n;
};
```



## `BFS` 2206 벽 부수고 이동하기

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

struct triplet {
    int x, y, nCrash;
};

queue<triplet> q;
int m, n, init[MAX][MAX], dist[MAX][MAX][2];
int xCoor[4] = {1, 0, -1, 0}, yCoor[4] = {0, -1, 0, 1};

int main() {
    int bfs();
    void printInit();
    void printDist();
    
    scanf("%d %d", &m, &n);
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &init[i][j]);
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }
    
    q.push({0, 0, init[0][0]});
    printf("%d", bfs());
    
}

int bfs() {
    void printDist();
    
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            triplet front = q.front(); q.pop();
            int x=front.x; int y=front.y; int nCrash=front.nCrash;
            if(x == m-1 && y == n-1) return dist[x][y][nCrash]+1;
            
            for(int j=0; j<4; j++) {
                int newX = x+xCoor[j];
                int newY = y+yCoor[j];
                int newNCrash = init[newX][newY];
                
                if(newX < 0 || newY < 0 || newX > m-1 || newY > n-1) continue;
                if(nCrash==1 && newNCrash==1) continue;
                if(dist[newX][newY][nCrash+newNCrash] > 0) continue;

                q.push({newX, newY, newNCrash+nCrash});
                
                dist[newX][newY][newNCrash+nCrash] = dist[x][y][nCrash]+1;
            }
        }
    }
    return -1;
}
```

>  BFS, DFS 문제집의 마지막 문제이다. 너만 조지면끝이야.. 하는 마음으로 풀었다. 지금 진짜졸린데 이문제를 안해치우면 잠이안올것같아서 풀었다. 왜냐면 거의다 풀었었거든

1. visit가 필요하지 않은 이유

* 처음에는 visit와 dist를 각각 만들었었으나, 다른 사람들의 코드를 참고하고 든 생각은 메모리를 오지게 낭비하겠구나 였다. **왜냐하면 한번 간 길은 다시 가지 않을 테니**, 내가 여태까지 방문하는데 걸리는 cost를 기록한 dist만으로 visit 여부를 판단할 수 있기 때문이었다. (visit가 0이면 안들린거고, 0보다 크면 들린 것일테니까)

* 웃긴건 앞에 미로탐색(2178)에서는 dist 하나만을 놓고 풀었다는 것이다.

2. 두 개의 `dist[m][n]` 가 필요한 이유

* 문제를 풀면서, 하나하나 손으로 값을 적어보면서 어떻게 값이 변하는지 알기 전까지, 굳이 `dist[m][n]` 가 두개나 필요한 이유를 몰랐다.

> 어짜피 최단거리인데, 미로탐색(2178)처럼 `dist[m][n]` 한개에다가 경로 값을 넣으면 되지 않을까?

* 라고 생각을 했지만, 손으로 하나하나 값을 따져보니 아니더라.

* 만약 `dist[m][n]`이 하나일 때 어떤 위치로 가려고 한다. 이 때 벽을 부수지 않고도 갈 수 있고, 벽을 부수고도 갈 수 있다. 이 때 벽을 부수지 않고 가는 길을 먼저 보고 그 다음에 벽을 부수고 가는 길을 본다고 가정한다. 이렇게 되면 벽을 부수지 않고 가는 길의 cost c 가 `dist[m'][n']`에 들어간다. (`dist[m'][n'] = c`)

* 그렇다면 이런 경우에는 벽을 부수고 가는 것이 더 최소한의 cost를 가짐에도 불구하고, `dist[m'][n']` 의 값이 0보다 크기 때문에, 이미 들렸다고 생각하여 부수지 않고 가는 길을 아예 거들떠도 안보게 되는 것이다. 따라서 벽을 부수고 가는 경우의 수와 벽을 부수지 않고 가는 경우의 수, 총 두 개의 경우의 수를 고려해주어야 하여 `dist[m][n][2]` 가 필요한 것이다.

3. 

```cpp
dist[newX][newY][newNCrash+nCrash] = dist[x][y][nCrash]+1; // (O)

dist[newX][newY][newNCrash+nCrash] = dist[x][y][newNCrash+nCrash]+1; // (X)
```

* 이게 무슨말이냐 하면, 아래꺼가 내가 처음에 했던 실수이고 위에꺼가 올바른 답이다. 부모(`nCrash`)로부터 +1을 더하도록 했어야 했는데, 자신(`newNCrash+nCrash`)으로부터 +1늘 더하도록 했다.

* 그러니까, 부모 위치에서는 벽돌을 안부쉈는데 나는 부쉈다 하면, 내가 가져야할 cost 값은 `dist[m'][n'][0]+1` 인 것이지, `dist[m'][n'][1]+1` 이 아닌 것이다. 왜냐하면 내가 이전에 있던 위치는 부모의 위치니까, 그 위치의 cost를 더해야 하기 때문이다.