// Tiling Up Blocks
// UVa ID: 1196
// Verdict: Accepted
// Submission Date: 2017-10-05
// UVa Run Time: 0.010s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

struct tile
{
    int l, m;
    bool operator<(const tile &t) const
    {
        if (l != t.l) return l < t.l;
        else return m < t.m;
    }
};

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int n, left, middle;
    while (cin >> n, n > 0)
    {
        vector<tile> tiles;
        vector<int> length(n, 1);
        for (int i = 0; i < n; i++)
        {
            cin >> left >> middle;
            tiles.push_back(tile{left, middle});
        }
        
        sort(tiles.begin(), tiles.end());

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (tiles[i].l >= tiles[j].l && tiles[i].m >= tiles[j].m)
                    if (length[j] + 1 > length[i])
                        length[i] = length[j] + 1;
        
        cout << *max_element(length.begin(), length.end()) << '\n';
    }
    cout << "*\n";

    return 0;
}
