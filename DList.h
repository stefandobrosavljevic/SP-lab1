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

    void ubaciNaPocetak(int value, int key){
        Node* pom = new Node(value, key);
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

    void ubaciNaKraj(int value, int key){
        Node* pom = new Node(value, key);
        if(tail->next == nullptr){
            tail->next = pom;
            pom->prev = tail;
            tail = pom;
        }
    }

    void brisiSaPocetka(){
        if(head != nullptr){
            if(head == tail){
                delete head;
                head = tail = nullptr;
            }
            else{
                Node* pom = head;
                head = head->next;
                head->prev = nullptr;
                delete pom;
            }
        }
        else{
            cout << "Lista je prazna" << endl;
        }
    }

    void brisiSaKraja(){
        if(head != nullptr){
            if(head == tail){
                delete head;
                head = tail = nullptr;
            }
            else{
                Node* pom = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete pom;
            }
        }
        else{
            cout << "Lista je prazna" << endl;
        }
    }
    
    void izbrisiEl(int value){
        Node* find = pronadjiEl(value);
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

    Node* pronadjiEl(int value){
        Node* pom = head;
        while(pom != nullptr){
            if(pom->value == value)
                return pom;
            pom = pom->next;
        }
        cout << "Nema elementa u listi" << endl;
        return nullptr;
    }

    void stampaj(){
        Node* pom = head;
        while(pom != nullptr){
            pom->stampa();
            pom = pom->next;
        }
        cout << endl;
    }
    
    void Compact(int k){
        if(head == nullptr){
            cout << "Lista je prazna" << endl;
            return;
        }
        int suma = 0;
        Node* prvi = nullptr;
        //preskace ako je head !!! ISPRAVI !!!
        if(head->key == k){
            suma += head->key;
            prvi = head;
        }
        Node* pom = head;
        while(pom->next != nullptr){
            //proveravam sledeci, posto moram da ga obrisem
            if(pom->next->key == k){
                suma += pom->next->value;
                if(prvi == nullptr){
                    prvi = pom->next;
                    pom = pom->next;
                }
                else{
                    Node* p = pom->next;
                    pom->next = p->next;
                    if(p == tail)
                        tail = pom; 
                   // else{
                   //     pom->next->prev = pom;
                   // }
                    delete p;
                }
            }
            //kada obrisemo element ne treba da idemo
            //na sledeci, vec ce samo da se namesti samo da
            //ukazuje na sledeci 
            else{
                pom = pom->next;
            }
        }
        //provera da li smo uopste nasli jedan element
        if(prvi == nullptr){
            cout << "Nije nadjen ni jedan element sa tim key" << endl;
            return;
        }

        prvi->value = suma;
    }

};


