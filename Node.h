#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev, *next;
    
    Node(){
        val = 0;
        prev = next = nullptr;
    }

    Node(int v){
        val = v;
        prev = next = nullptr;
    }

    Node(int v, Node* p, Node* n){
        val = v;
        prev = p;
        next = n;
    }

    ~Node() {}

};


