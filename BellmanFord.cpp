#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mx=100010+123;
ll dis[mx],i,j;
ll max1=100000000000000;
bool iscycle;
struct info{

    ll u,v,w;

};
vector<info>e;
bool bellmanford(ll s,ll n,ll m)
{
    for(i=0;i<=n;i++)
    {
        dis[i]=max1;
    }
    dis[s]=0;
    for(j=1;j<=n;j++)
    {

       iscycle=false;

    for(i=0;i<e.size();i++)
    {
        ll u,v,w;
        u=e[i].u;
        v=e[i].v;
        w=e[i].w;
        if(dis[u]<max1)
        {
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                iscycle=true;
            }
        }
    }


    }
    return iscycle;
}
int main()
{
    ll tt;
    cin>>tt;
    while(tt--)
    {
        e.clear();
        ll n,m;
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
           ll u,v,w;
           cin>>u>>v>>w;
           e.push_back({u,v,w});
        }

        if(bellmanford(0,n,m)==true)
        {
            cout<<"possible"<<endl;
        }
        else
        {
            cout<<"not possible"<<endl;
        }

    }
    return 0;
}

 /*

2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

 */
