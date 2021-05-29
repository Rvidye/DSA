#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
    int v,e;
    int ** adj;
    list<int> *adjList;

    public:
    Graph(int v);
    Graph(int v,int e);
    void addEdge(int start,int e);
    void DFS(int start,std::vector<bool>& visited);
    void BFS(int s);
};

Graph::Graph(int v,int e)
{
    this->v = v;
    this->e = e;
    adj = new int*[v];
    for(int row = 0 ; row < v; row++)
    {
        adj[row] = new int[v];
        for(int column = 0;column < v; column++)
        {
            adj[row][column] = 0;    
        }
    }
    adjList = new list<int>[v];
}

void Graph::addEdge(int start,int e)
{
    adj[start][e] = 1;
    adj[e][start] = 1;
    adjList[start].push_back(e);
}


void Graph::DFS(int start,std::vector<bool>& visited)
{
    printf("%d\t",start);
    visited[start] = true;
    for (int i = 0; i < v; i++) 
    {
        if (adj[start][i] == 1 && (!visited[i])) 
        {
            DFS(i, visited);
        }
    }
}

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for(int i = 0; i< v;i++)
        visited[i] = false;
    
    list<int>queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty())
    {
        s = queue.front();
        cout<< s << " ";
        queue.pop_front();
        for(i = adjList[s].begin();i!=adjList[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

