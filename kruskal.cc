/*                                                                              
 ============================================================================
 Simple implementation of kruskal's algorithm
 ============================================================================
 */
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<algorithm>
#include<cmath>
using namespace std; 

const int MAX_N = 10000;
const int INF   = 10000;

struct edge{
    int src;
    int to;
    int cost;
    edge(int s=0,int t = 0, int c = 0):src(s),to(t),cost(c){}
};

struct comp{
    int operator () (const edge & e1, const edge & e2){
        return e1.cost < e2.cost;
    }
};

void initUFSet(vector<int> & par, vector<int> & rank){
    for(size_t i = 0; i < par.size(); ++i)
        par[i] = i;
    for(size_t i = 0; i < rank.size(); ++i)
        rank[i] = 0;
}

int find(vector<int> & par, vector<int> & rank, int x){
    if( par[x] == x)
        return x;
    int xx  = x;
    while( par[x] != x){
        x = par[x];
    }
    while(xx != x){
        int temp = par[xx];
        par[xx]=x;
        xx = temp;
    }
    return x;
}

void unite(vector<int> & par, vector<int> & rank, int x, int y){
    int xx = find(par,rank,x);
    int yy = find(par,rank,y); 
    if(xx == yy){
        return ;
    }
    if(rank[xx] < rank[yy]){
        par[xx] = yy;
    }else {
        par[yy] = xx;
        if(rank[xx] == rank[yy])
            rank[xx]++;
    }
}

void kruskal(vector<edge> * g,int nodenum){ 
    vector<edge> edges; 
    for(int i = 0; i < nodenum ; i++){
        vector<edge> es = g[i];
        for(int j = 0; j < es.size(); ++j)
            edges.push_back(es[j]);
    }
    sort(edges.begin(),edges.end(),comp());
    vector<int> par(nodenum,0);
    vector<int> rank(nodenum,0);
    initUFSet(par,rank); 
    cout << edges.size() << endl;
    for(size_t i = 0; i < edges.size(); ++i){
        edge e = edges[i];
        if(find(par,rank,e.src) != find(par,rank,e.to)){
            unite(par,rank,e.src,e.to);    
            cout << e.src << "->" << e.to << ": " << e.cost <<endl;
        }  
    }
}

int main()
{
    vector<edge> g[MAX_N];
    int source,nodenum;
    cin >> source >> nodenum;  
    int s,t,cost;
    while(cin >> s >> t >> cost){
        g[s].push_back(edge(s,t,cost));
    }
    kruskal(g,nodenum);
}

