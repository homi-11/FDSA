#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of buildings: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter connected buildings: ";
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting building: ";
    cin >> start;

    cout << "DFS Traversal: ";
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}