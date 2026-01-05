#ifndef QUEUE_GENERIC_H
#define QUEUE_GENERIC_H

#include <iostream>
using namespace std;

// ============================
// NODE GENERIC
// ============================
template <typename T>
struct QueueNode {
    T data;
    QueueNode<T>* next;
};

// ============================
// CLASS QUEUE GENERIC
// ============================
template <typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Cek kosong
    bool isEmpty() {
        return front == NULL;
    }

    // ============================
    // ENQUEUE (tambah belakang)
    // ============================
    void enqueue(T x) {
        QueueNode<T>* baru = new QueueNode<T>;
        baru->data = x;
        baru->next = NULL;

        if (isEmpty()) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }
    }

    // ============================
    // DEQUEUE (hapus depan)
    // ============================
    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return false;
        }

        QueueNode<T>* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return true;
    }

    // ============================
    // AMBIL DATA DEPAN
    // ============================
    T getFront() {
        return front->data;
    }

    // ============================
    // TAMPILKAN QUEUE
    // ============================
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }

        QueueNode<T>* temp = front;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

#endif
