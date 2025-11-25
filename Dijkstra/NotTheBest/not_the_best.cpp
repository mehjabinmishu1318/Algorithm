#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct Edge {
    int v, w;
};

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int T;
cin >> T;
for (int tc = 1; tc <= T; tc++) {
    int N, R;
    cin >> N >> R;
    vector<vector<Edge>> adj(N + 1);
    while (R--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist1(N + 1, INF), dist2(N + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist1[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist2[u]) continue;
        for (auto &e : adj[u]) {
            ll nd = d + e.w;
            int v = e.v;
            if (nd < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = nd;
                pq.push({dist1[v], v});
            }
            else if (nd > dist1[v] && nd < dist2[v]) {
                dist2[v] = nd;
                pq.push({dist2[v], v});
            }
        }
    }

    cout << "Case " << tc << ": " << dist2[N] << "\n";
}
return 0;
}


