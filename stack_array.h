// stack_array.h

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_RIWAYAT = 20; // sesuaikan dengan kebutuhan

struct StackRiwayat {
    string items[MAX_RIWAYAT];
    int top;

    StackRiwayat() {
        top = -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_RIWAYAT - 1;
    }

    void push(const string& item) {
        if (isFull()) {
            // Optional: hapus yang paling lama jika penuh (circular) atau abaikan
            cout << "Riwayat penuh. Item terlama akan diganti.\n";
            // Geser semua item ke kiri (hapus index 0)
            for (int i = 0; i < MAX_RIWAYAT - 1; i++) {
                items[i] = items[i + 1];
            }
            items[MAX_RIWAYAT - 1] = item;
            return;
        }
        items[++top] = item;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        return items[top--];
    }

    void tampilkan() const {
        if (isEmpty()) {
            cout << "Belum ada riwayat obat.\n";
            return;
        }
        cout << "\n=== RIWAYAT OBAT TERAKHIR (Stack - LIFO) ===\n";
        for (int i = top; i >= 0; i--) {
            cout << (top - i + 1) << ". " << items[i] << endl;
        }
        cout << "===========================================\n";
    }
};

#endif // STACK_ARRAY_H
