#pragma once
#include <iostream>

template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <class T>
class Queue {
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int amount = 0;
public:
    Queue() {};
    ~Queue();

    int size() { return this->amount; }
    void pushHead(T obj);
    void pushTail(T input_object);
    T popHead();
    T popTail();
    T& operator[](int num);
};

template<class T>
void Queue<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
        amount++;
    }
}

//Добавление в хвост
template<class T>
void Queue<T>::pushTail(T input_object) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = input_object;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    amount++;
}

//Удаление от головы
template<class T>
T Queue<T>::popHead() {
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail) {
        head = head->next;
        head->previous = nullptr;
        Node<T>* tmp = head;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

//Удаление из хвоста
template<class T>
T Queue<T>::popTail() {
    if (!(head)) return T();
    T data = tail->data;
    Node<T> *node = tail;
    if (tail != head) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& Queue<T>::operator[](int num) {
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
        curr = curr->next;
    return curr->data;
}

template<class T>
Queue<T>::~Queue() { while (this->head) { this->popHead(); } }



