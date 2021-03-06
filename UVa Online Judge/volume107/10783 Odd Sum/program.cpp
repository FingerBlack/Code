// Odd Sum
// UVa ID: 10783
// Verdict: Accepted
// Submission Date: 2017-10-04
// UVa Run Time: 0.000s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;

    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        for (int i = (a % 2) ? a : (a + 1); i <= b; i += 2) sum += i;
        cout << "Case " << c << ": " << sum << '\n';
    }

    return 0;
}
