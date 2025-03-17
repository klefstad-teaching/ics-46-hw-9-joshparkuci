#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include "dijkstras.h"

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& graph, int source, vector<int>& previous){
    int numVertices = graph.size();
    // NOTE: Does this functionally do the same thing as .resize? It seems to, but idk if its just technicalities
    // Update, the difference is the first is a declaration while the second is modifying an existing thing
    vector<int> distances(numVertices, INF);  
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous.resize(numVertices, UNDEFINED);  // NOTE: not resizing this gave me a segfault lol
    previous[source] = UNDEFINED;
    
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({0, source});

    while(!minHeap.empty()){
        int u = minHeap.top().second;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge edge : graph[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> path;
    for(int i = destination; i != UNDEFINED; i = previous[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}
void print_path(const vector<int>& v, int total){
    if (total == INF) {
        cout << "Path is empty" << endl;
        return;
    }
    for (int path : v) {
        cout << path << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
