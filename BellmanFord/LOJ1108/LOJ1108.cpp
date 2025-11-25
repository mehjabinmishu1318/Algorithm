#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
void solve_test_case(int test_case_num) {
    int n;
    if (!(cin >> n)) return;
    vector<int> busyness(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> busyness[i];
    }

    int r;
    cin >> r;
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < r; ++i) {
        int u, v;
        cin >> u >> v;
        ll diff = (ll)busyness[v] - busyness[u];
        ll cost = diff * diff * diff;

        edges.emplace_back(u, v, cost);
    }
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : edges) {
            int u, v;
            ll cost;
            tie(u, v, cost) = edge;
            if (dist[u] != INF && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges) {
            int u, v;
            ll cost;
            tie(u, v, cost) = edge;
            if (dist[u] != INF && dist[u] + cost < dist[v]) {
                dist[v] = -INF;
            }
            if (dist[u] == -INF && dist[v] != -INF) {
                dist[v] = -INF;
            }
        }
    }
    int q;
    cin >> q;
    cout << "Set #" << test_case_num << endl;

    for (int i = 0; i < q; ++i) {
        int dest;
        cin >> dest;

        ll result = dist[dest];

        if (result == INF || result == -INF || result < 3) {
            cout << "?" << endl;
        } else {
            cout << result << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case_num = 1;
    while (cin.peek() != EOF) {
        solve_test_case(test_case_num++);
    }

    return 0;
}

