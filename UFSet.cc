/*
Simple implementation of union-find set
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
using namespace std; 

const int N = 8;

int par[N];     //parent of each node
int rank[N];    //rank of each root node,if the node is not root, then its rank is not used 

/*init the union-find set,set each node's parent node and rank*/
void init()
{
    for(int i = 0; i < N; ++i)
    {
        par[i] = i;
        rank[i] = 1;
    }
}

/*find the root of thr tree x belongs to*/
int find(int x)
{
    int xx = x;
    while(par[x] != x){
        x = par[x];    
    }
    while( xx != x){
        int temp = par[xx];
        par[xx] = x;
        xx = temp; 
    }
    return x;
}

/*unite two trees*/
void unite(int x, int y){
    int xx = find(x);
    int yy = find(y);
    if( xx == yy)
        return;
    if(rank[xx] < rank[yy]){
        par[xx] = yy;
    }else{
        par[yy] = xx;
        if(rank[xx] == rank[yy]){
            rank[xx] ++;
        }
    }
}

void test(){
    init();    
    unite(0,1);
    unite(2,3);
    unite(4,5);
    unite(6,7);
    cout << find(1) << " " << find(3) << " " << find(5) << " " << find(7) << endl;
    unite(1,4);
    unite(2,6);
    cout << find(1) << " " << find(3) << " " << find(5) << " " << find(7) << endl;
    unite(1,3);
    cout << find(1) << " " << find(3) << " " << find(5) << " " << find(7) << endl;
}

int main()
{
   test(); 
}

