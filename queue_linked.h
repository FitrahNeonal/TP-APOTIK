// queue_linked.h

#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

#include <iostream>
#include <string>
using namespace std;

// Node untuk antrian
struct NodeAntrian {
    string namaPasien;
    NodeAntrian* next;
    
    NodeAntrian(const string& nama) : namaPasien(nama), next(nullptr) {}
};

// Struktur Queue berbasis Linked List
struct QueuePasien {
    NodeAntrian* front;
    NodeAntrian* rear;
    
    // Konstruktor
    QueuePasien() : front(nullptr), rear(nullptr) {}
    
    // Destruktor (membersihkan memori)
    ~QueuePasien() {
        while (front != nullptr) {
            NodeAntrian* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
    
    // Cek apakah antrian kosong
    bool isEmpty() const {
        return front == nullptr;
    }
    
    // Tambah pasien ke belakang antrian
    void enqueue(const string& nama) {
        NodeAntrian* newNode = new NodeAntrian(nama);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Pasien '" << nama << "' berhasil ditambahkan ke antrian.\n";
    }
    
    // Keluarkan pasien dari depan antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Tidak ada pasien dalam antrian.\n";
            return;
        }
        
        string nama = front->namaPasien;
        cout << "Memanggil pasien: " << nama << endl;
        
        NodeAntrian* temp = front;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr; // antrian jadi kosong
        }
        
        delete temp;
    }
    
    // Tampilkan seluruh antrian
    void tampilkan() const {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
            return;
        }
        
        cout << "\n=== ANTRIAN PASIEN SAAT INI ===\n";
        cout << "No.\tNama Pasien\n";
        cout << "----------------------------\n";
        
        NodeAntrian* current = front;
        int no = 1;
        while (current != nullptr) {
            cout << no << ".\t" << current->namaPasien << endl;
            current = current->next;
            no++;
        }
        cout << "==============================\n";
    }
};

#endif // QUEUE_LINKED_H
