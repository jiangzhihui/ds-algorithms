/*                                                                              
 ============================================================================
 Implement segment tree data structure
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
using namespace std; 

typedef struct Node{
    int l,r,mid,cover;
    Node(int l=0,int r=0, int mid=0,int c=0):l(l),r(r),mid(mid),cover(c){}
} Node;

const int MAX_N = (1 << 18);
Node tree[MAX_N];

//make a segment tree by recursion,make the node's range from l to r
void make_tree(int l, int r, int num){
    int mid = (l+r)/2;
    tree[num].l = l; 
    tree[num].r = r;
    tree[num].mid = mid;  
    if(l+1 != r){
        make_tree(l,mid,num*2);
        make_tree(mid,r,num*2+1);
    }
}

void print_tree(){
    for(int i = 1; i < 3000;i ++){
        Node n = tree[i];
        cout <<i << ": " <<  "[" << n.l << "," << n.r << ")  cover: " << n.cover << endl;
    }
}

//search all the intervals that contains the number x
void search(int x,int nodenum){
    Node node = tree[nodenum];
    if(x < node.l || x > node.r)
        return ;
    cout <<nodenum << ": " <<  "[" << node.l << "," << node.r << ") cover: "  <<node.cover << endl;
    if(x < node.mid)
        search(x,2*nodenum);
    else 
        search(x,2*nodenum+1);
     
}

//insert a interval:[l,r) to node n
void insert(int l,int r, int n){
    Node& node = tree[n];
    if( l == node.l && r == node.r){
        node.cover = 1;
        return ;    
    }
    //insert to left subtree
    if(r <= node.mid){
        insert(l,r,n*2);    
    }
    else if(l >= node.mid){
        insert(l,r,n*2+1);    
    }else {
        insert(l,node.mid,2*n);
        insert(node.mid,r,2*n+1); 
    }
}

void traverse(int n ){
    Node node = tree[n];
    if(node.l + 1 == node.r){
        cout << "[" << node.l << "," << node.r << ")" << endl;
    }else{
        traverse(2*n);
        traverse(2*n+1);
    }
}

int main()
{
    int n = 20;
    make_tree(1,n,1);
    traverse(1);
    //search(16,1);
    int l = 1;
    int r = 18;
    if(l >= 1 && l < n && r >=1 && r <= n && l < r){
        insert(l,r,1);
        //print_tree();
    }
}

