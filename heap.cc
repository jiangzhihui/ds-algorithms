/**
An implementation of max heap
**/

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std; 

//to store MAXN elements
const int MAXN = 10000;

vector<int> elements(MAXN,0);
int size = 0; 

/*
To push an element to the heap, we need put the element to the tail and then 
popup until the parent is no smaller than the element
Notice element[0] does not store any element
*/
void push(int n){
    int i = ++size; 
    while(i > 1){
        int p = i / 2; 
        if(elements[p] > n)
            break;
        elements[i] = elements[p];
        i = p ;
    }
    elements[i] = n;
}

/*
the max element is stored in location 1 not 0
*/
int pop(){
    int value = elements[1];
    int i = 1;
    int n = elements[size--];
    while( i*2 <= size){
        int left = i*2,right = i*2 + 1;
        if(right <= size && elements[left] < elements[right])
            left = right;
        if(elements[left] < n)    
            break;
        elements[i] = elements[left];
        i = left;
    }
    elements[i] = n;
    return value; 
}

int main(){
    int N = 1000;
    priority_queue<int> pque;
    for(int i = 0; i < N; i ++){
        push(i); 
        pque.push(i);
    }
    ofstream out1("out1");
    ofstream out2("out2");
    for(int i = 0; i < N; i ++)
        out1 << pop() << "\n";
    for(int i = 0; i < N; i ++){
        out2 << pque.top() << "\n";
        pque.pop();
    }
    out1.close();
    out2.close();
}
