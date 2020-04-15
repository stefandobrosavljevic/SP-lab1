#include<iostream>
using namespace std;

class Node
{
public:
    int value, key;
    Node *prev, *next;
    
    Node(){
        value = key = 0;
        prev = next = nullptr;
    }

    Node(int v, int k){
        value = v;
        key = k;
        prev = next = nullptr;
    }

    Node(int v, int k, Node* p, Node* n){
        value = v;
        key = k;
        prev = p;
        next = n;
    }

    ~Node() {}
    
    void stampa(){
        cout << "(" << value << "," << key << ") ";
    }

};


