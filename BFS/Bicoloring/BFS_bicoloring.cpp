#include <bits/stdc++.h>
using namespace std;
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
while (true) {
    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) break;
    int l;
    cin >> l;
    vector<vector<int>> adj(n);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n, -1);
    bool ok = true;
    for (int start = 0; start < n && ok; start++) {
        if (color[start] != -1) continue;
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while (!q.empty() && ok) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
               if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    ok = false;
                    break;
                }
            }
        }
    }

cout << (ok ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
}
return 0;
}

