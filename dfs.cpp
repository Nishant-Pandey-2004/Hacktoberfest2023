#include <iostream>
using namespace std;

int adj[6][6];

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void dfs(int start, bool visited[])
{
    cout << start << " ";

    visited[start] = true;

    for (int i = 0; i < 6; i++) {

        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i, visited);
        }
    }
}

int main()
{
    int v = 6;
    int e = 5;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);
	addEdge(1, 5);
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    dfs(0, visited);

    return 0;
}
