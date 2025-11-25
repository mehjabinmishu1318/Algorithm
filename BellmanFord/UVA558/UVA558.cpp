#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);

        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        bool negCycle = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                negCycle = true;
                break;
            }
        }

        if (negCycle)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }

    return 0;
}

