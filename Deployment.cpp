// All DAA Practicals in One File

#include <bits/stdc++.h> using namespace std;

// 1. Insertion Sort void insertionSort(vector<int>& arr) { int n = arr.size(); int comparisons = 0; for (int i = 1; i < n; i++) { int key = arr[i]; int j = i - 1; while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; comparisons++; } arr[j + 1] = key; comparisons++; } cout << "Insertion Sort: "; for (int x : arr) cout << x << " "; cout << "\nComparisons: " << comparisons << endl; }

// 2. Merge Sort void merge(vector<int>& arr, int l, int m, int r) { int n1 = m - l + 1; int n2 = r - m; vector<int> L(n1), R(n2); for (int i = 0; i < n1; i++) L[i] = arr[l + i]; for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; int i = 0, j = 0, k = l; while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; while (i < n1) arr[k++] = L[i++]; while (j < n2) arr[k++] = R[j++]; } void mergeSort(vector<int>& arr, int l, int r) { if (l < r) { int m = l + (r - l) / 2; mergeSort(arr, l, m); mergeSort(arr, m + 1, r); merge(arr, l, m, r); } }

// 3. Heap Sort void heapify(vector<int>& arr, int n, int i) { int largest = i, l = 2 * i + 1, r = 2 * i + 2; if (l < n && arr[l] > arr[largest]) largest = l; if (r < n && arr[r] > arr[largest]) largest = r; if (largest != i) { swap(arr[i], arr[largest]); heapify(arr, n, largest); } } void heapSort(vector<int>& arr) { int n = arr.size(); for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i); for (int i = n - 1; i > 0; i--) { swap(arr[0], arr[i]); heapify(arr, i, 0); } }

// 4. Quick Sort int partition(vector<int>& arr, int low, int high) { int pivot = arr[high], i = (low - 1); for (int j = low; j <= high - 1; j++) { if (arr[j] < pivot) swap(arr[++i], arr[j]); } swap(arr[i + 1], arr[high]); return i + 1; } void quickSort(vector<int>& arr, int low, int high) { if (low < high) { int pi = partition(arr, low, high); quickSort(arr, low, pi - 1); quickSort(arr, pi + 1, high); } }

// 5. Strassen’s Matrix Multiplication (2x2) void strassenMultiplication(int A[2][2], int B[2][2], int C[2][2]) { int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]); int M2 = (A[1][0] + A[1][1]) * B[0][0]; int M3 = A[0][0] * (B[0][1] - B[1][1]); int M4 = A[1][1] * (B[1][0] - B[0][0]); int M5 = (A[0][0] + A[0][1]) * B[1][1]; int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]); int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]); C[0][0] = M1 + M4 - M5 + M7; C[0][1] = M3 + M5; C[1][0] = M2 + M4; C[1][1] = M1 - M2 + M3 + M6; } void printMatrix(int M[2][2]) { for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) cout << M[i][j] << " "; cout << endl; } }

// 6. Count Sort void countSort(vector<int>& arr) { int max_elem = *max_element(arr.begin(), arr.end()); vector<int> count(max_elem + 1, 0); for (int x : arr) count[x]++; arr.clear(); for (int i = 0; i <= max_elem; i++) while (count[i]--) arr.push_back(i); }

// 7 & 8. BFS and DFS class Graph { int V; list<int>* adj; public: Graph(int V) { this->V = V; adj = new list<int>[V]; } void addEdge(int v, int w) { adj[v].push_back(w); } void BFS(int s) { vector<bool> visited(V, false); queue<int> q; visited[s] = true; q.push(s); while (!q.empty()) { s = q.front(); q.pop(); cout << s << " "; for (auto i : adj[s]) { if (!visited[i]) { visited[i] = true; q.push(i); } } } cout << endl; } void DFSUtil(int v, vector<bool>& visited) { visited[v] = true; cout << v << " "; for (auto i : adj[v]) if (!visited[i]) DFSUtil(i, visited); } void DFS(int v) { vector<bool> visited(V, false); DFSUtil(v, visited); cout << endl; } };

// 9. Prim’s MST #define V 5 int minKey(int key[], bool mstSet[]) { int min = INT_MAX, min_index; for (int v = 0; v < V; v++) if (!mstSet[v] && key[v] < min) min = key[v], min_index = v; return min_index; } void primMST(int graph[V][V]) { int parent[V], key[V]; bool mstSet[V]; fill(key, key + V, INT_MAX); fill(mstSet, mstSet + V, false); key[0] = 0; parent[0] = -1; for (int count = 0; count < V - 1; count++) { int u = minKey(key, mstSet); mstSet[u] = true; for (int v = 0; v < V; v++) if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) parent[v] = u, key[v] = graph[u][v]; } for (int i = 1; i < V; i++) cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl; }

// 10. 0-1 Knapsack int knapsack(int W, int wt[], int val[], int n) { int dp[n + 1][W + 1]; for (int i = 0; i <= n; i++) { for (int w = 0; w <= W; w++) { if (i == 0 || w == 0) dp[i][w] = 0; else if (wt[i - 1] <= w) dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); else dp[i][w] = dp[i - 1][w]; } } return dp[n][W]; }

// Main function demonstrating all practicals int main() { cout << "\n--- Insertion Sort ---\n"; vector<int> a1 = {12, 11, 13, 5, 6}; insertionSort(a1);

cout << "\n--- Merge Sort ---\n";
vector<int> a2 = {12, 11, 13, 5, 6}; mergeSort(a2, 0, a2.size() - 1);
for (int x : a2) cout << x << " "; cout << endl;

cout << "\n--- Heap Sort ---\n";
vector<int> a3 = {12, 11, 13, 5, 6}; heapSort(a3);
for (int x : a3) cout << x << " "; cout << endl;

cout << "\n--- Quick Sort ---\n";
vector<int> a4 = {10, 7, 8, 9, 1, 5}; quickSort(a4, 0, a4.size() - 1);
for (int x : a4) cout << x << " "; cout << endl;

cout << "\n--- Strassen’s Multiplication ---\n";
int A[2][2] = {{1, 2}, {3, 4}}, B[2][2] = {{5, 6}, {7, 8}}, C[2][2];
strassenMultiplication(A, B, C); printMatrix(C);

cout << "\n--- Count Sort ---\n";
vector<int> a5 = {1, 4, 1, 2, 7, 5, 2}; countSort(a5);
for (int x : a5) cout << x << " "; cout << endl;

cout << "\n--- BFS ---\n";
Graph g1(4); g1.addEdge(0,1); g1.addEdge(0,2); g1.addEdge(1,2); g1.addEdge(2,0); g1.addEdge(2,3); g1.addEdge(3,3); g1.BFS(2);

cout << "\n--- DFS ---\n";
Graph g2(4); g2.addEdge(0,1); g2.addEdge(0,2); g2.addEdge(1,2); g2.addEdge(2,0); g2.addEdge(2,3); g2.addEdge(3,3); g2.DFS(2);

cout << "\n--- Prim's MST ---\n";
int graph[V][V] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}}; primMST(graph);

cout << "\n--- 0-1 Knapsack ---\n";
int val[] = {60, 100, 120}, wt[] = {10, 20, 30}; int W = 50;
cout << "Maximum value in knapsack = " << knapsack(W, wt, val, 3) << endl;

return 0;

}

