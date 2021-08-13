#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MAX 5001
#define INF 1e9

using namespace std;

int n, m, p, q, i, j;
int house[MAX], conv[MAX];
vector<pair<int, int>> adj[MAX];
int dist[MAX];
int ans[2];
struct Compare
{
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return x.second > y.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

void solve()
{
    cin >> n >> m;
    
    // 인접 리스트 완성
    while (m--)
    {
        cin >> dist[0] >> dist[1] >> dist[2];
        adj[dist[0]].push_back({ dist[1], dist[2] });
        adj[dist[1]].push_back({ dist[0], dist[2] });
    }
    
    cin >> p >> q;
    
    // 집 후보 및 편의점
    for (i = 0; i < p; i++) cin >> house[i];
    for (i = 0; i < q; i++) cin >> conv[i];
    
    // 다익스트라
    ans[1] = INF;
    for (i = 0; i < p; i++)
    {
        fill_n(dist, n + 1, INF);
        dist[house[i]] = 0;
        pq.push({ house[i], 0 });
        
        while(!pq.empty())
        {
            int curNode = pq.top().first;
            int curDist = pq.top().second;
            pq.pop();
            
            if (dist[curNode] < curDist) continue;
            for (j = 0; j < adj[curNode].size(); j++)
            {
                int nexNode = adj[curNode][j].first;
                int nexDist = adj[curNode][j].second;
                
                if (curDist + nexDist >= dist[nexNode]) continue;
                dist[nexNode] = curDist + nexDist;
                pq.push({ nexNode, dist[nexNode] });
            }
        }
        
        // 최소 거리 탐색
        for (j = 0; j < q; j++)
        {
            if (dist[conv[j]] >= ans[1]) continue;
            ans[0] = house[i];
            ans[1] = dist[conv[j]];
        }
    }
    
    cout << ans[0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    solve();
    return 0;
}