#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;
int adj[MAXN][MAXN];
bool visited[MAXN];

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start)
{
    memset(visited, false, sizeof(visited));
    int q[MAXN], front = 0, rear = 0;
    q[rear++] = start;

    // Set source as visited
    visited[start] = true;

    int vis;
    while (front < rear) {
        vis = q[front++];
        cout << vis << " ";

        for (int i = 0; i < MAXN; i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
                q[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 6;
    memset(adj, 0, sizeof(adj));

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);

    bfs(0);
    return 0;
}
