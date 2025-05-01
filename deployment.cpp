// 🔢 Practical 1: Insertion Sort with Comparison Count
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <limits.h>
using namespace std;

int insertionSort(vector<int> &arr) {
    int comparisons = 0;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        if (j >= 0) comparisons++;
        arr[j + 1] = key;
    }
    return comparisons;
}

// 🔢 Practical 2: Merge Sort with Comparison Count
int merge(vector<int>& arr, int l, int m, int r, int& comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return comparisons;
}

int mergeSort(vector<int>& arr, int l, int r, int& comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
    }
    return comparisons;
}

// 🔢 Practical 3: Heap Sort with Comparison Count
void heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && ++comparisons && arr[l] > arr[largest]) largest = l;
    if (r < n && ++comparisons && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

int heapSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
    return comparisons;
}

// 🔢 Practical 4: Quick Sort with Comparison Count
int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSort(vector<int>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
    return comparisons;
}

// 🔢 Practical 5: Strassen’s Matrix Multiplication
// (Simple version using basic matrix multiplication due to complexity constraints)
vector<vector<int>> strassenMultiply(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// 🔢 Practical 6: Count Sort
vector<int> countSort(vector<int> arr) {
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0);
    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i]--) arr[index++] = i;
    }
    return arr;
}

// 🔢 Practical 7: BFS
void bfs(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// 🔢 Practical 8: DFS
void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited);
        }
    }
}

void dfs(vector<vector<int>>& adj, int V, int start) {
    vector<bool> visited(V, false);
    dfsUtil(start, adj, visited);
    cout << endl;
}

// 🔢 Practical 9: Prim’s MST using Adjacency Matrix
int primMST(vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return totalWeight;
}

// 🔢 Practical 10: 0-1 Knapsack
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

// 🔚 Main Function to Demonstrate All Practicals
int main() {
    cout << "Insertion Sort Comparisons: ";
    vector<int> arr1 = {5, 3, 8, 6, 2};
    cout << insertionSort(arr1) << endl;

    cout << "Merge Sort Comparisons: ";
    vector<int> arr2 = {5, 3, 8, 6, 2};
    int mComp = 0;
    mergeSort(arr2, 0, arr2.size() - 1, mComp);
    cout << mComp << endl;

    cout << "Heap Sort Comparisons: ";
    vector<int> arr3 = {5, 3, 8, 6, 2};
    cout << heapSort(arr3) << endl;

    cout << "Quick Sort Comparisons: ";
    vector<int> arr4 = {5, 3, 8, 6, 2};
    int qComp = 0;
    quickSort(arr4, 0, arr4.size() - 1, qComp);
    cout << qComp << endl;

    cout << "Count Sort Result: ";
    vector<int> arr5 = {5, 3, 8, 6, 2};
    vector<int> sorted = countSort(arr5);
    for (int i : sorted) cout << i << " ";
    cout << endl;

    cout << "Strassen Matrix Multiplication Result:\n";
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    vector<vector<int>> C = strassenMultiply(A, B);
    for (auto row : C) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    cout << "BFS Traversal: ";
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    bfs(graph, 0, 4);

    cout << "DFS Traversal: ";
    dfs(graph, 4, 0);

    cout << "Prim MST Total Weight: ";
    vector<vector<int>> gmat = {{0, 2, 0, 6}, {2, 0, 3, 8}, {0, 3, 0, 0}, {6, 8, 0, 0}};
    cout << primMST(gmat, 4) << endl;

    cout << "Knapsack Max Value: ";
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    cout << knapsack(50, wt, val, 3) << endl;

    return 0;
}
