#include "queueP.hpp"
#include <iostream>

using namespace std;

void QueueP::pushFront(Node* d){
    if (head == nullptr){
        head = d;
        head->prev = nullptr;
    } else {
        d->next = head;
        head = d;
        size++;
    }
    size++;
}

void QueueP::pushBack(Node* d){
    if (head == nullptr){
        head = d;
        head->prev = nullptr;
    } else {
        last->next = d;
        d->prev = last;
    }
    last = d;
    last->next = nullptr;
    size++;
}

void QueueP::insert(Node *d, int idx){
    if(idx == size-1){
        pushBack(d);
        return;
    }
    if(idx == 0){
        pushFront(d);
        return;
    }

    int cnt = 0;
    for (Node * i = head; i != 0; i = i->next){
        if (cnt == idx){
            i->prev->next = d;
            d->next = i;
            size++;
            break;
        }
        cnt++;
    }
}

void QueueP::push(int data, int prior){
    Node* d = new Node(data, prior);
    if (size == 0){
        pushBack(d);
    }
    else {
        int cnt = 0;
        for(Node* i = head; i != 0; i = i->next){
            if (prior > i->prior){
                insert(d, cnt);
                return;
            }
                
            cnt++;
            if (cnt == size){
                pushBack(d);
            }
        }
        
    }
}

void QueueP::pop(){
    int cnt = 0;
    for(Node* i = head; i != 0; i = i->next){
        cnt++;
        if (cnt == size-1){
            Node* tmp = i;
            delete tmp->next;
            i->next = nullptr;
            size--;
        }
    }
}

void QueueP::show(){
    for(Node* i = head; i != 0; i = i->next){
        cout << i->data << "(" << i->prior << ")" << "  ";
    }
    cout << endl;
}

QueueP::QueueP():head(nullptr), size(0){};
QueueP::~QueueP(){
    if (!head) return;
    for(int i = 0; i < size; i++){
        pop();
    }
}
