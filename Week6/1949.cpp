#include<stdio.h>
#include<vector>
#define max(a,b)(a>b?a:b)

using namespace std;

int n;
int vil[10001];
int dp[10001][2];
bool visit[10001];
vector<int> tree[10001],graph[10001];
int cnt;

void make_tree(int here,int depth) {
    visit[here] = true;
    for(int i= 0; i<graph[here].size();i++) {
        int there = graph[here][i];
        if(visit[there])
            continue;
        tree[here].push_back(there);
        make_tree(there,depth+1);
    }
}
int solve(int n, int q) {
    int ret = dp[n][q];
    if(ret!= -1) return ret;

    ret = 0;

    for(int i = 0;i<tree[n].size();i++) {
        int next = tree[n][i];

        if(!q) 
            ret += max(solve(next,0),solve(next,1)+vil[next]);
        else
            ret += solve(next,0);

    }

    return ret;
}
int main() {
    
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);

    for(int i = 1; i<= n; i++) {
        scanf("%d",&vil[i]);
    }
    
    for(int i = 0; i< n-1; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    make_tree(1,0);

    printf("%d\n",max(solve(1,0),solve(1,1)+vil[1]));
    return 0;
}
