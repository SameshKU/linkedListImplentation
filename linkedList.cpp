#include "linkedList.h"

List::List() {
    HEAD = NULL;
    TAIL = NULL;
}

List::~List() {

}

bool List::isEmpty() {
    return (HEAD==NULL);
}

void List::addToHead(int data) {
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = HEAD;
    HEAD = newNode;
    if(TAIL==NULL) TAIL = HEAD;
}

void List::add(int data, Node *predecessor) {
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = predecessor->next;
    predecessor->next = newNode;  
}

void List::addToTail(int data) {
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = NULL;
    TAIL->next = newNode;
    TAIL = newNode;
}

void List::removeFromHead() {
    if(isEmpty()) cout << "nothing to delete, list empty...";
    else {
        Node *nodeToDelete = this->HEAD;
        this->HEAD = this->HEAD->next;
        delete nodeToDelete;
    }
}

void List::remove(int data) {

}

bool List::search(int data) {
    Node *temp = HEAD;
    while(temp!=NULL) {
        if(temp->info == data) return true;
        temp = temp->next;
    }
    return false;
}

void List::traverse() {
    Node *temp = HEAD;
    while(temp != NULL) {
        cout << temp->info;
        temp = temp->next;
    } 
}

Node* List::retrieve(int data) {
    Node *p = HEAD;
    while (p != NULL) {
        if (p->info == data) {
            Node *outputptr = p;
            return outputptr;
        }
        p = p->next;
    }
    return NULL;
}

int main() {
    List list;
    list.addToHead(4);
    list.addToHead(5);
    list.addToHead(6);

    Node * pre = list.retrieve(4);
    list.add(8,pre);
    list.traverse();
    return 0;
}

