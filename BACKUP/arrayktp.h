#ifndef ARRAYKTP_H
#define ARRAYKTP_H

#include <iostream>
#include "array1d.h"
#include "ktp.h"

using namespace std;

class ArrayKTP {
private:
    Array1D<KTP> data;
    int size;
    int kapasitas;

public:
    ArrayKTP(int max = 100) : data(max) {
        kapasitas = max;
        size = 0;
    }

    bool isFull() {
        return size >= kapasitas;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insert(KTP x) {
        if (isFull()) {
            cout << "Array penuh!\n";
            return;
        }
        data[size] = x;
        size++;
    }
    
    void display() {
    if (isEmpty()) { cout << "Array kosong!\n"; return; }
    cout << "\n==== DATA KTP (ARRAY) ====\n";
    for (int i = 0; i < size; i++) {
        cout << data[i] << endl; // Otomatis mencetak semua field!
    }
}

};

//    void display() {
//        if (isEmpty()) {
//            cout << "Array masih kosong!\n";
//            return;
//        }

//        cout << "\n==== DATA KTP (Array 1D Generic) ====\n";
//        for (int i = 0; i < size; i++) {
//            cout << "\nNIK               : " << data[i].nik
//                 << "\nNama              : " << data[i].nama
//                 << "\nTempat Lahir      : " << data[i].tempat_lahir
//                 << "\nTanggal Lahir     : "
//                 << data[i].tgl_lahir.hari << "-"
//                 << data[i].tgl_lahir.bulan << "-"
//                 << data[i].tgl_lahir.tahun
//                 << "\nJenis Kelamin     : " 
//                 << (data[i].jenis_kelamin ? "Laki-laki" : "Perempuan")
//                 << "\nGolongan Darah    : " << data[i].gol_darah
//                 << "\nAlamat            : " << data[i].alamat
//                 << "\nRT/RW             : " << data[i].rt << "/" << data[i].rw
//                 << "\nKelurahan         : " << data[i].kel_desa
//                 << "\nKecamatan         : " << data[i].kecamatan
//                 << "\nAgama             : " << getAgama(data[i].agama)
//                 << "\nStatus Kawin      : " 
//                 << (data[i].status_perkawinan ? "Belum" : "Kawin")
//                 << "\nPekerjaan         : " << data[i].pekerjaan
//                 << "\nKewarganegaraan   : " 
//                 << (data[i].kewarganegaraan ? "WNI" : "WNA")
//                 << "\nBerlaku Hingga    : " << getBerlaku(data[i].berlaku_hingga)
//                 << "\n----------------------------------";
//        }
//    }


#endif
