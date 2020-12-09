#ifndef queueP_hpp
#define queueP_hpp

#include <stdio.h>


class Node{
public:
    Node* next;
    Node* prev;
    int data;
    int prior;
    Node(int _data, int _prior):
        data(_data), prior(_prior), next(0), prev(0){};
};

class QueueP{
    Node* head;
    Node* last;
    int size;
    void pushBack(Node* d);
    void pushFront(Node* d);
    void insert(Node* d, int idx);
public:
    QueueP();
    ~QueueP();
    void push(int data, int prior);
    void pop();
    void show();
};

#endif /* queueP_hpp */
