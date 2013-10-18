/*                                                                              
 ============================================================================
 Try to implement trie data structure
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std; 

const int CHARS = 26;

typedef struct Node{
    int words;
    int prefixes;
    struct Node * childs[CHARS];
    Node(int w=0,int p=0):words(w),prefixes(p){
        for(int i = 0; i < CHARS; i ++)
            childs[i] = NULL;
    }
} Node;

/*
add word by recursion
*/
void add_word(Node & n, string s,int depth){    
    if(depth == s.size()){
        n.words ++;    
        return;
    }
    n.prefixes ++;
    int ind = s[depth]-'a';
    if(n.childs[ind] == NULL)
        n.childs[ind] = new Node();
    add_word(*n.childs[ind],s,depth+1);
}

/*
count a word occurence 
*/
int count_word(Node & n , string s, int depth){
    if(depth == s.size())
        return n.words; 
    int ind = s[depth] - 'a';
    if(n.childs[ind] == NULL)
        return 0; 
    
    return count_word(*n.childs[ind],s,depth+1);
}

/*
count a prefix occurence 
*/
int count_prefix(Node & n, string s, int depth){
    if(depth == s.size())
        return n.prefixes;
    int ind = s[depth]-'a';
    if(n.childs[ind] == NULL)
        return 0;
    return count_prefix(*n.childs[ind],s,depth+1);
}

void print_trie(Node & n){

    bool leaf = true;
    for(int i = 0;i < CHARS; i ++){
        if(n.childs[i] != NULL){
            cout <<(char) ('a'+i);       
            print_trie(*n.childs[i]);
            leaf = false;
        }
    }
    if(leaf) 
        cout << endl;
}

void test(){
    Node root;
    string ss[17] = {"hello","hell","hill","hack","hackthon","has","jiang","zhi","hui","andy","smile","every","day","is","a","new","day"};
    string dup[8] = {"hill","hack","has","has","andy","andy","new","day"}; 
    string no_occur[4] = {"ha","sm","ne","da"}; 
    for(int i = 0; i < 4; i++)
        cout << no_occur[i] << ":" << count_prefix(root,no_occur[i],0) << endl;
    for(int i = 0; i < 17 ; i ++)
        add_word(root,ss[i],0);
    for(int i = 0; i < 8; i++)
        add_word(root,dup[i],0);
    for(int i = 0; i < 8; i++)
        cout << dup[i] << ":" << count_word(root,dup[i],0) << endl; 
    for(int i = 0; i < 4; i++)
        cout << no_occur[i] << ":" << count_word(root,no_occur[i],0) << endl;
    for(int i = 0; i < 4; i++)
        cout << no_occur[i] << ":" << count_prefix(root,no_occur[i],0) << endl;
}

int main()
{
    test();
}

