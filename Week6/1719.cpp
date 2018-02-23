#include<stdio.h>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

int dist[201][201];
vector<int> adj[201];
vector<int> cost[201];

int ans[201][201];

int main() {
    int n,m;

    scanf("%d %d",&n,&m);
    
    for(int i = 0; i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);

    }
    for(int i = 1; i<=n; i++) 
        for(int j = 1; j<=n; j++)
            dist[i][j] = INT_MAX;

    for(int i= 1; i<= n; i++) {
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int, int> > > pq;
        dist[i][i] = 0;
        pq.push({0,i});
        while(!pq.empty()) {
            int cur = pq.top().second;
            int c= pq.top().first;
            pq.pop();

            if(dist[i][cur] != c) continue;
            for(int j = 0; j< adj[cur].size();j++) {
                int next = adj[cur][j];
                int nd = cost[cur][j] +c;
                if(dist[i][next] > nd) {
                    dist[i][next] =nd;
                    pq.push({nd,next});
                }
            }
        }
    }
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j<= n; j++) {
            if(i==j) continue;
            for(int k = 0; k<adj[i].size(); k++) {
                int nxt = adj[i][k];
                if(dist[i][j]  == dist[j][nxt]+cost[i][k])
                    ans[i][j] = nxt;
            }
        }
    }
    for(int i=1; i<=n;i++) {
        for(int j= 1; j<=n;j++) {
            if(i !=j)printf("%d ",ans[i][j]);
            else printf("- ");
        }
        printf("\n");
    }
}   
