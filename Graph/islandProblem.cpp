/*
Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

#include <iostream>
using namespace std;

void dfs (int **edges, int sv, bool *visited) {
    visited[sv] = true;
    for (int i = 1; i <= n; i++) {
        if (i == sv)
            continue;
        if (edges[sv][i] && !visited[i]) {
            dfs(edges, i, visited);
        }
    }
}

int solve (int **edges, int n) {
    int count = 0;
    bool *visited = new bool[n];
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    

    for (int i = 1; i <= n; i++ ) {
        if (!visited[i])
            dfs(edges, i, visited); 
            count++;
    }

    delete [] visited;
    return count;
    
}

int main () {
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for (int i = 1; i <= n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 1; i <= e; i++) {
        int f,s;
        cin >> f >> s;
        edges[i][j] = 1;
        edges[j][i] = 1; 

    }

    int solve(edges,n);

    for (int i = 1; i <= n; i++) {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;

}