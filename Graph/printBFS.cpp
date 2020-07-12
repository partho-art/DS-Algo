#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int V, int SV, bool *visited) {
    
    queue<int> q;
    q.push(SV);
    visited[SV] = true;
    
    while(!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";
        
        for(int i = 0; i < V; i++) {
            if(i == currentVertex)
                continue;
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    
    }
    
	cout << endl;
    
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int **edges = new int*[V];
    for(int i = 0; i < V; i++) {
        edges[i] = new int[V];
        for(int j = 0; j <V; i++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
        
    }
	
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    printBFS(edges, V, 0, visited);
 

  	return 0;
}

