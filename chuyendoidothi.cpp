#include <iostream>
#include <vector>
using namespace std;

using AdjMatrix = vector<vector<int>>;
using AdjList   = vector<vector<int>>;
using EdgeList  = vector<pair<int,int>>;

// 1. Ma trận kề -> Danh sách kề
AdjList matrixToList(const AdjMatrix &mat) {
    int n = mat.size();
    AdjList adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) adj[i].push_back(j);
        }
    }
    return adj;
}

// 2. Ma trận kề -> Danh sách cạnh
EdgeList matrixToEdges(const AdjMatrix &mat) {
    int n = mat.size();
    EdgeList edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {       // chỉ lấy nửa trên để tránh lặp
            if (mat[i][j]) edges.push_back({i, j});
        }
    }
    return edges;
}

// 3. Danh sách kề -> Ma trận kề
AdjMatrix listToMatrix(const AdjList &adj) {
    int n = adj.size();
    AdjMatrix mat(n, vector<int>(n, 0));
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) mat[u][v] = 1;
    }
    return mat;
}

// 4. Danh sách kề -> Danh sách cạnh
EdgeList listToEdges(const AdjList &adj) {
    int n = adj.size();
    EdgeList edges;
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (u < v) edges.push_back({u, v}); // tránh lặp
        }
    }
    return edges;
}

// 5. Danh sách cạnh -> Ma trận kề
AdjMatrix edgesToMatrix(int n, const EdgeList &edges) {
    AdjMatrix mat(n, vector<int>(n, 0));
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        mat[u][v] = mat[v][u] = 1;
    }
    return mat;
}

// 6. Danh sách cạnh -> Danh sách kề
AdjList edgesToList(int n, const EdgeList &edges) {
    AdjList adj(n);
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

// ------------------------- DEMO -------------------------
int main() {
    // Ví dụ: đồ thị 4 đỉnh, cạnh: (0,1), (0,2), (1,3)
    EdgeList edges = {{0,1},{0,2},{1,3}};
    int n = 4;

    // 5 -> 3 -> 4 : EdgeList -> AdjMatrix -> AdjList -> EdgeList
    AdjMatrix mat = edgesToMatrix(n, edges);
    AdjList list  = matrixToList(mat);
    EdgeList e2   = listToEdges(list);

    cout << "Edges after convert: \n";
    for (auto &p : e2) cout << p.first << " " << p.second << "\n";
    return 0;
}
