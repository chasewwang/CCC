#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// CCC '24 J5 - Harvest Waterloo
// 6/20/2025
// Chase Wang
void bfs(int sr, int sc, vector<vector<char>> &g, vector<vector<bool>> &v, int &s, int &m, int &l)
{
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    queue<int> q;
    q.push(sr);
    q.push(sc);
    v[sr][sc] = true;
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        int c = q.front();
        q.pop();
        char ch = g[r][c];
        if (ch == 'S')
        {
            s++;
        }
        else if (ch == 'M')
        {
            m++;
        }
        else if (ch == 'L')
        {
            l++;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g[0].size() && !v[nr][nc] && g[nr][nc] != '*')
            {
                v[nr][nc] = true;
                q.push(nr);
                q.push(nc);
            }
        }
    }
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<char>> g(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> g[i][j];
        }
    }
    int sr, sc;
    cin >> sr >> sc;
    if (g[sr][sc] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<bool>> v(R, vector<bool>(C, false));
    int s = 0, m = 0, l = 0;
    bfs(sr, sc, g, v, s, m, l);
    cout << s * 1 + m * 5 + l * 10 << endl;
    return 0;
}
