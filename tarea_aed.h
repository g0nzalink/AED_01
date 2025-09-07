#ifndef TAREA_AED_H
#define TAREA_AED_H

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next = nullptr;
};

template<typename T>
class forward_list {
    Node<T>* head = nullptr;

public:
    T front() {return head->data;}
    T back() {
        Node<T>* temp = head;
        while(temp->next != nullptr){temp = temp->next;}
        return temp->data;
    }
    void push_front(T data) {
        Node<T>* nuevo;
        nuevo.data = data;
        nuevo->next = head;
        head = nuevo;
    }
    void push_back(T data) {
        Node<T>* nuevo;
        nuevo.data = data;
        Node<T>* temp = head;
        while(temp->next != nullptr){temp = temp->next;}
        temp->next = nuevo;
            }
    T pop_front() {
        Node<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp->data;
    }
    T pop_back() {
        Node<T>* temp = head;
        while(temp->next->next != nullptr){temp = temp->next;}
        Node<T>* temp2 = temp->next;
        temp->next = nullptr;
        return temp2->data;
    }
    T operator[](int pos) {
        Node<T>* temp = head;
        for(int i = 0; i<pos; i++){temp = temp->next;}
        return temp->data;
    }
    bool empty() {
        return head == nullptr;
    }
    int size() {
        int contador = 0;
        Node<T>* temp = head;
        while(temp->next->next != nullptr){temp = temp->next; contador++;}
        return contador;
    }
    void clear() {
        Node<T>* temp = head;
        while(head->next != nullptr) {
            head = head->next;
            temp->next = nullptr;
            temp = head;
        }
        head = nullptr;
    }
    void sort() {
        Node<T> cabeza = head;
        while(cabeza->next != nullptr) {
            Node<T>* temp = cabeza;
            Node<T>* anterior = nullptr;
            int a = 0;
            while(temp->next != nullptr) {
                if(temp->next->data > temp->data) {
                    //swap
                    if(anterior == nullptr) {
                        temp->next = temp->next->next;
                        temp->next->next = temp;
                    }
                    anterior->next = temp->next;
                    temp->next = temp->next->next;
                    temp->next->next = temp;

                    if(a == 0){head = temp;}
                    a++;
                }
                anterior = temp;
                temp = temp->next;
            }
            cabeza = cabeza->next;

        }

    }
    void reverse() {
        if(head == nullptr || head->next == nullptr){return;}

        Node<T>* temp1 = head->next;
        Node<T>* temp2 = temp1->next;

        head->next = nullptr;
        if(temp2 == nullptr) {
            temp1->next = head;
            head = temp1;
            return;
        }

        while(temp2 != nullptr) {
            temp1->next = head;
            head = temp1;
            temp1 = temp2;
            if(temp2->next == nullptr) {
                temp1->next = head;
                head = temp1;
                break;
            }
            temp2 = temp2->next;
        }
    }

};



#endif //TAREA_AED_H
