// Pizza Cutting
// UVa ID: 10079
// Verdict: Accepted
// Submission Date: 2018-02-18
// UVa Run Time: 0.000s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    long long n;
    while (cin >> n, n >= 0) cout << n * (n + 1) / 2 + 1 << '\n';
    
    return 0;
}
