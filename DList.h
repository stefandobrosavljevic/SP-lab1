#include"Node.h"
#include<iostream>
using namespace std;


class DList
{
private:
    Node *head, *tail;

public:
    DList(){
        head = nullptr;
        tail = nullptr;
    }

    ~DList()
    {
        Node *pom = nullptr;
        while(head){
            pom = head;
            head = head->next;
            delete pom;
        }
        head = nullptr;
    }

    void ubaciNaPocetak(int val){
        Node* pom = new Node(val);
        if(head == nullptr){
            head = pom;
            tail = pom;
        }
        else{
            pom->next = head;
            head = pom;
            pom->next->prev = pom;
        }
    }

    void ubaciNaKraj(int val){
        Node* pom = new Node(val);
        if(tail->next == nullptr){
            tail->next = pom;
            pom->prev = tail;
            tail = pom;
        }
    }

    void izbrisiEl(int val){
        Node* find = pronadjiEl(val);
        Node* pom = head;

        if(pom == find)
            head = pom->next;
        else{
            while(find != nullptr){
                if(pom->next == find){
                    pom->next = find->next;
                    find->next->prev = pom;
                    delete find;
                    return;
                }
                pom = pom->next;
            }
        }
    }

    Node* pronadjiEl(int val){
        Node* pom = head;
        while(pom != nullptr){
            if(pom->val == val)
                return pom;
            pom = pom->next;
        }
        cout << "Nema elementa u listi" << endl;
        return nullptr;
    }

    void stampaj(){
        Node* pom = head;
        while(pom != nullptr){
            cout << pom->val << " ";
            pom = pom->next;
        }
        cout << endl;
    }

};


