/*
Implement dijkstra's algorithm
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map> 
#include<cmath>
using namespace std; 

/*
define the edge of graph
*/
struct edge{
    int dest;
    int cost;
    edge(int d=0,int c=0):dest(d),cost(c){}
};

//define the element of priority_queue, first element is the mim cost ,second is node number
typedef pair<int,int> P;

/*
calculate the shortest distance of each node from source node s
*/
void dijkstra(vector<edge> * edges,vector<int> & dis,int s){
    priority_queue<P,vector<P>,greater<P> >  pque;
    dis[s] = 0;
    pque.push(P(0,s)); 
    while(!pque.empty()){
        P p = pque.top();
        pque.pop();
        int cost = p.first;
        int src =  p.second;    
        for(size_t i = 0; i < edges[src].size(); ++i){
            edge e = edges[src][i];    
            if(dis[e.dest] > dis[src] + e.cost ){
                dis[e.dest] = dis[src] + e.cost;    
                pque.push(P(dis[e.dest],e.dest));
            }
        }
    }
}

int main()
{
    const int INF = 1000000;
    const int MAX_N = 100000;
    int source , nodenum;
    cin >> source >> nodenum ;
    vector<edge> edges[MAX_N];
    vector<int> dis(nodenum,INF); 
    int s,d,cost;
    while(cin >> s >> d >> cost){
        edges[s].push_back(edge(d,cost));    
    }
    for(int i = 0; i < nodenum; ++i){
        vector<edge>& e = edges[i]; 
        for(int j = 0; j < e.size(); ++j)
            cout << i << " " << e[j].dest << " " << e[j].cost<< endl; 
    }
    dijkstra(edges,dis,source);
    for(int i = 0;i < nodenum ; ++i)
        cout << dis[i] << endl;
}

