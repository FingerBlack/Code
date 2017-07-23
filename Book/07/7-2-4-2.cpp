#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXN = 1000000;

int primes[MAXN], phi[MAXN] = {0, 1}, counterOfPrimes = 0;

void sieve(int *primes, int n, int &counterOfPrimes)
{
    counterOfPrimes = 0; iota(phi, phi + n, 0);

    for (int i = 2; i < n; i++)
        if (phi[i] == i)
        {
            primes[counterOfPrimes++] = i;
            for (int j = i; j < n; j += i) phi[j] -= phi[j] / i;
        }
}

int main(int argc, char *argv[])
{
    sieve(primes, MAXN, counterOfPrimes);

    for (int i = 0; i <= 10000; i++)
        cout << primes[i] << ' ' << phi[i] << '\n';

    return 0;
}
