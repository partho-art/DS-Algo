#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int n) {
    int minvertex = -1;
    for (int i = 0; i < n; i++) {
        if(!visited[i] && (minvertex == -1 || weight[i] < weight[minvertex])) {
            minvertex = i;
        }
    }
    return minvertex;
}

void prim (int **edges, int n) {
    int * parent = new int[n];
    int * weight= new int[n];
    bool * visited = new bool[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < 0; i++) {

        int minvertex = findMinVertex(weight, visited, n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++) {
            if (edges[minvertex][j] != 0 && !visited) {
                if(edges[minvertex][j] < weight[i]) {
                    weight[j] = edges[minvertex][j];
                    parent[j] = minvertex;
                }
            }
        }

    }

    for (int i = 1; i < n; i++) {
        if(parent[i] < i) {
            cout << parent[i] << " " << i << weight[i] << endl;
        }
        else {
            cout << i << " " << parent[i] << weight[i] << endl;
        }
    }
}

int main () {
    int n, e;

    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < 0; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int sv, ev, weight;
        cin >> sv >> ev >> weight;
        edges[sv][ev] = weight;
        edges[ev][sv] = weight;
    }

    cout << endl;
    prim (edges, n);

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;

}