#include <bits/stdc++.h>
using namespace std;
const int BOARD_SIZE = 8;

const int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[] = {-1,  1, -2,  2,-2, 2,-1, 1};
pair<int,int> to_coords(const string& square) {
    int col = square[0] - 'a';
    int row = square[1] - '1';
    return {row, col};
}
int bfs_knight_moves(const string& start_sq, const string& end_sq)
{
    if (start_sq == end_sq)
        return 0;
    auto start = to_coords(start_sq);
    auto goal = to_coords(end_sq);
    vector<vector<int>> dist(BOARD_SIZE, vector<int>(BOARD_SIZE, -1));
    queue<pair<int,int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == goal.first && c == goal.second)
            return dist[r][c];

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < BOARD_SIZE && nc >= 0 && nc < BOARD_SIZE) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return -1;
}

void solve() {
    string start_square, end_square;
    while (cin >> start_square >> end_square) {
        int moves = bfs_knight_moves(start_square, end_square);
        cout << "To get from " << start_square
             << " to " << end_square
             << " takes " << moves
             << " knight moves." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

