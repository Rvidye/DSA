#include"header.h"

int main(void)
{
    int v = 5, e = 7;
    Graph G(v, e);
    G.addEdge(0, 1);
    G.addEdge(0, 4);
    G.addEdge(0,3);
    G.addEdge(1, 2);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    std::vector<bool> visited(v, false);
    G.DFS(0, visited);
    cout<<endl<<" BFS::"<<endl;
    G.BFS(0);
}