// Crimewave
// UVa ID: 563
// Verdict: Accepted
// Submission Date: 2017-09-21
// UVa Run Time: 0.080s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 5100;

class EdmondsKarp
{
private:
    map<int, int> arcs[MAXV];
    int path[MAXV], visited[MAXV];

    bool bfs(int source, int sink)
    {
        memset(visited, 0, sizeof(visited));
        memset(path, -1, sizeof(path));

        queue<int> vertices; vertices.push(source);
        visited[source] = 1;

        while (!vertices.empty())
        {
            int v = vertices.front(); vertices.pop();
            for (auto a : arcs[v])
                if (a.second > 0)
                    if (!visited[a.first])
                    {
                        vertices.push(a.first);
                        visited[a.first] = 1;
                        path[a.first] = v;
                        if (a.first == sink) return true;
                    }
        }

        return false;
    }

    void augmentPath(int source, int sink)
    {
        if (source == sink) return;
        arcs[path[sink]][sink] = 0;
        arcs[sink][path[sink]] = 1;
        augmentPath(source, path[sink]);
    }
    
public:
    void initialize()
    {
        for (int i = 0; i < 5100; i++) arcs[i].clear();
    }

    void addArc(int from, int to, int capacity1, int capacity2)
    {
        arcs[from][to] = capacity1;
        arcs[to][from] = capacity2;
    }

    int maxFlow()
    {
        int netflow = 0, source = 0, sink = 5010;
        while (bfs(source, sink))
        {
            netflow++;
            augmentPath(source, sink);
        }
        return netflow;
    }
};

int offset[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
int problem, streets, avenues, banks;
    
void createGraph(EdmondsKarp &ek)
{
    cin >> streets >> avenues >> banks;

    ek.initialize();
            
    // 在源点和银行之间建立有向弧。
    for (int b = 1, x, y; b <= banks; b++)
    {
        cin >> x >> y;
        ek.addArc(0, (x - 1) * avenues + y, 1, 0);
    }

    int base = streets * avenues;
    for (int s = 1; s <= streets; s++)
        for (int a = 1; a <= avenues; a++)
        {
            int index = (s - 1) * avenues + a;

            // 在城镇边界上的交叉路口和汇点之间建立有向弧。
            if (s == 1 || s == streets || a == 1 || a == avenues)
                ek.addArc(base + index, 5010, 1, 0);

            // 将交叉路口拆分为两个顶点，在顶点间构建残留网络。
            ek.addArc(index, base + index, 1, 0);

            for (int f = 0; f < 4; f++)
            {
                int ss = s + offset[f][0], aa = a + offset[f][1];
                if (ss >= 1 && ss <= streets && aa >= 1 && aa <= avenues)
                    ek.addArc(base + index, (ss - 1) * avenues + aa, 1, 0);
            }
        }
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    EdmondsKarp ek;

    cin >> problem;
    for (int p = 1; p <= problem; p++)
    {
        createGraph(ek);
        cout << (ek.maxFlow() == banks ? "possible" : "not possible") << '\n';
    }

    return 0;
}
