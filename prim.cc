/*******************************
A simple implementation of prim algorithm 
*******************************/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<queue>
#include<cmath>
using namespace std; 

//define the element of priority queue first element is edge cost, second is tail node of edge
typedef pair<int,int> P;

struct edge{
    int to;
    int cost;
    edge(int t = 0, int c = 0):to(t),cost(c){}
};
const int INF = 10000;
const int MAX_N = 100000;

void prim(vector<edge> * g,int nodenum){

    int s=0;        //select node 0 as the root of the tree 
    vector<int>  dis(nodenum,INF);
    dis[s]  = 0;
    priority_queue<P,vector<P>,greater<P> > pque;
    pque.push(P(dis[s],s));
    int count = 0;
    while(count < nodenum){
        P p = pque.top();
        pque.pop();
        int node = p.second;
        cout << node << " " << p.first << endl;
        ++count;
        vector<edge> es = g[node];
        for(size_t i = 0; i < es.size() ; ++i){
            edge e = es[i];
            if(dis[e.to] > e.cost){
                dis[e.to] = e.cost;    
                pque.push(P(dis[e.to],e.to));
            }
        }
        
    }
}

int main()
{

    int source , nodenum;
    cin >> source >> nodenum ;
    vector<edge> edges[MAX_N];
    int s,d,cost;
    while(cin >> s >> d >> cost){
        edges[s].push_back(edge(d,cost));    
    }
    prim(edges,nodenum);
}

