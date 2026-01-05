#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

#include "data_obat.h"
#include "queue_linked.h"
#include "stack_array.h"
#include "tree_obat.h"

using namespace std;

struct dataapotik {
    string namapasien;
    int umurpasien;
    char jeniskelaminpasien;
    string riwayatpenyakitpasien;

    // Array 1D untuk data obat
    string namaObat[JUMLAH_OBAT];
    string fungsiObat[JUMLAH_OBAT];
    int hargaObat[JUMLAH_OBAT];
    int stokObat[JUMLAH_OBAT];

    int pilihannomorobat;
    int jumlahobat;
    int total = 0;
    int batas = 0;
    int x = 0;
    int y = 0;
    int jumlahrestock;
    int simpan[100];
    int temp[100];
    char belilagi;
    int pilihmenuAdmin;
    int pilihmenuUser;
    int pilihmenuLogin;
    int pilihpengambilan;
    int jarakkirim;
    int biayaongkir;
    string a;
    string b;
    string admin;
    string passwordAdmin;
    string user;
    string passwordUser;
    int metodebayarpilih;
    string metodebayar;
    int cash;
    
    QueuePasien antrian;
    StackRiwayat riwayat;
};

NodeObat* root = NULL;		// buat tree

// rebuaild tree, biar update saat restok, update, hapus, beli
void rebuildTree(dataapotik &d) {
    hapusTree(root);
    root = NULL;

    for(int i = 0; i < JUMLAH_OBAT; i++) {
        if(d.namaObat[i] != "") {
            root = insertObat(
                root,
                d.namaObat[i],
                d.hargaObat[i],
                d.stokObat[i],
                d.fungsiObat[i]
            );
        }
    }
}


// Fungsi untuk menyimpan stok ke file
void saveStokToFile(dataapotik &d) {
    ofstream file("stok_obat.txt");
    if (file.is_open()) {
        for (int i = 0; i < JUMLAH_OBAT; i++) {
            file << d.namaObat[i] << ";" 
                 << d.hargaObat[i] << ";" 
                 << d.stokObat[i] << ";" 
                 << d.fungsiObat[i] << "\n";
        }
        file.close();
    } else {
        cout << "Gagal menyimpan stok obat!" << endl;
    }
}

// Fungsi untuk mengisi data obat awal
void isidataobat(dataapotik &d) {
    for (int i = 0; i < JUMLAH_OBAT; i++) {
        d.namaObat[i] = NAMA_OBAT[i];
        d.fungsiObat[i] = FUNGSI_OBAT[i];
        d.hargaObat[i] = HARGA_OBAT[i];
        d.stokObat[i] = STOK_AWAL_OBAT[i];
    }
}

// Fungsi untuk memuat stok dari file
void loadStokFromFile(dataapotik &d) {
    ifstream file("stok_obat.txt");
    if (file.is_open()) {
        string line;
        int i = 0;
        while (getline(file, line) && i < JUMLAH_OBAT) {  // ? di sini
            stringstream ss(line);
            string part;

            getline(ss, d.namaObat[i], ';');
            getline(ss, part, ';');
            d.hargaObat[i] = stoi(part);
            getline(ss, part, ';');
            d.stokObat[i] = stoi(part);
            getline(ss, d.fungsiObat[i]);
            i++;
        }
        file.close();
    } else {
        isidataobat(d);
        saveStokToFile(d);
    }
    rebuildTree(d);
}

// === Fungsi-fungsi lain tetap sama, tapi disesuaikan dengan array 1D ===

void menulogin(dataapotik &d){
    system("cls");
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "|           SELAMAT DATANG DI MENU LOGIN         |\n";
    cout << "|                   APOTEK K-24                  |\n";
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "| 1. Admin                                       |\n";
    cout << "| 2. Pelanggan                                   |\n";
    cout << "| 3. Keluar                                      |\n";
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> d.pilihmenuLogin;
    cin.ignore();  
}

void menuutama_admin(dataapotik &d){
    system("cls");
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "|              SELAMAT DATANG ADMIN DI           |\n";
    cout << "|                   APOTEK K-24                  |\n";
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "| 1. Stok Obat                                   |\n";
    cout << "| 2. Data Pembelian                              |\n";
    cout << "| 3. Data Pasien                                 |\n";
    cout << "| 4. Laporan Keuangan                            |\n";
    cout << "| 5. Restok obat                                 |\n";
    cout << "| 6. Hapus Obat                                  |\n";
    cout << "| 7. Kelola Antrian Pasien (Queue)               |\n";
    cout << "| 8. Tampilkan Stok Obat (Tree)                  |\n";
    cout << "| 9. Cari Obat (Tree)                            |\n";
    cout << "| 10. Keluar                                     |\n";
    
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "Masukkan pilihan (1-10): ";
    cin >> d.pilihmenuAdmin;
    cin.ignore();
}

void menuutama_pelanggan(dataapotik &d){
    system("cls");
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "|             SELAMAT DATANG PELANGGAN DI        |\n";
    cout << "|                   APOTEK K-24                  |\n";
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "| 1. Beli Obat                                   |\n";
    cout << "| 2. Stok Obat                                   |\n";
    cout << "| 3. Pilih opsi pembayaran                       |\n";
    cout << "| 4. Cetak struk                                 |\n";
    cout << "| 5. Lihat Riwayat Obat Terakhir                 |\n";
    cout << "| 6. Keluar                                      |\n";
    cout << "|" << setw(51) << setfill('=') << "|\n";
    cout << "Masukkan pilihan (1-6): ";
    cin >> d.pilihmenuUser;
    cin.ignore();
}

void menuAntrianPasien(dataapotik &d) {
    int pilih;
    do {
        system("cls");
        cout << "=== KELOLA ANTRIAN PASIEN (LINKED LIST) ===\n";
        cout << "1. Tambah Pasien ke Antrian\n";
        cout << "2. Panggil Pasien Berikutnya\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Kembali ke Menu Admin\n";
        cout << "Pilih (1-4): ";
        cin >> pilih;
        cin.ignore();

        switch(pilih) {
            case 1: {
                string nama;
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                if (!nama.empty()) {
                    d.antrian.enqueue(nama);
                } else {
                    cout << "Nama tidak boleh kosong!\n";
                }
                system("pause");
                break;
            }
            case 2:
                d.antrian.dequeue();
                system("pause");
                break;
            case 3:
                d.antrian.tampilkan();
                system("pause");
                break;
            case 4:
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    } while (pilih != 4);
}

void loginAdmin(dataapotik &d){
    system("cls");
    cout << "== ANDA LOGIN SEBAGAI ADMIN ==\n";
    d.admin = "admin";
    d.passwordAdmin = "admin";
    cout << "Masukan username (admin): ";
    cin >> d.a;
    cout << "Masukan password (admin): ";
    cin >> d.b; 
}

void loginUser(dataapotik &d){
    system("cls");
    cout << "== ANDA LOGIN SEBAGAI PELANGGAN ==\n";
    d.user = "user";
    d.passwordUser = "user";
    cout << "Masukan username (user): ";
    cin >> d.a;
    cout << "Masukan password (user): ";
    cin >> d.b; 
}

void isidatapasien(dataapotik &d){
    cout << "Selamat Datang Di Apotik K-24" << endl;
    cout << "Silahkan mengisi data diri anda sebelum membeli obat." << endl;
    cout << "Nama\t\t\t: ";
    getline(cin, d.namapasien);
    cout << "Umur\t\t\t: ";
    cin >> d.umurpasien;
    cout << "Jenis kelamin (L/P)\t: ";
    cin >> d.jeniskelaminpasien;
    cin.ignore();
    cout << "Riwayat Sakit\t\t: ";
    getline(cin, d.riwayatpenyakitpasien);
    cout << "Data sudah tercatat." << endl;
    system("pause");
    system("cls");
}

void menunamaobat(dataapotik &d){
    cout << "Selamat Berbelanja " << d.namapasien << endl;
    cout << "Pilihan Obat : " << endl;
    for(int i = 0; i < JUMLAH_OBAT; i++){
        cout << i+1 << ". " << d.namaObat[i] << endl;
    }
    cout << endl;
}

void detailobat(dataapotik &d){
    int idx = d.pilihannomorobat - 1;

    if(idx < 0 || idx >= JUMLAH_OBAT) {
        cout << "Maaf, obat yang Anda pilih tidak tersedia." << endl;
        return;
    }

    cout << "============================== Obat " << d.pilihannomorobat << " ==============================\n";
    cout << "\tNama obat\t: " << d.namaObat[idx] << endl;
    cout << "\tHarga\t\t: " << d.hargaObat[idx] << "/strip" << endl;
    cout << "\tStok Teredia\t: " << d.stokObat[idx] << endl;
    cout << "\tKegunaan Obat\t: " << d.fungsiObat[idx] << endl;
    cout << "====================================================================\n";

    // ?? SIMPAN KE STACK SEBELUM INPUT JUMLAH
    d.riwayat.push(d.namaObat[idx]);  // ? SIMPAN RIWAYAT

    cout << "Jumlah obat yang dibeli : ";
    cin >> d.jumlahobat;

    if(d.jumlahobat > d.stokObat[idx]) {
        cout << "Maaf, stok tidak mencukupi!" << endl;
        d.jumlahobat = 0;
    } else {
        d.total += d.hargaObat[idx] * d.jumlahobat;
        d.stokObat[idx] -= d.jumlahobat;
        saveStokToFile(d);
    }
    
	rebuildTree(d);
}

void pengambilan(dataapotik &d){
    cout << "============================================================================" << endl;
    cout << endl;
    cout << "Pilihan Pengambilan obat" << endl;
    cout << "Note : Jarak pengiriman Obat Maksimal 15 Km dan dikenakan biaya Rp.3000/1Km." << endl;
    cout << "1. Ambil tempat" << endl;
    cout << "2. Kirim" << endl;
    cout << endl;
    cout << "============================================================================" << endl;
    cout << "Pilihan anda (1/2) : ";
    cin >> d.pilihpengambilan;
}

void ongkir(dataapotik &d){
    switch(d.pilihpengambilan) {
        case 1:
            d.biayaongkir = 0;
            break;
        case 2:
            cout << "Berapa Km Jarak Kirim dari apotik : ";
            cin >> d.jarakkirim;
            if(d.jarakkirim > 15){
                cout << "Maaf maksimal jarak kirim 15Km dari apotik..." << endl;
                d.pilihpengambilan = 0; 
            } else {
                d.biayaongkir = 3000 * d.jarakkirim;
            }
            break;
        default:
            cout << "Pilihan tidak ada..." << endl;
    }
}

void detailpembelian(dataapotik &d){
    cout << "============= TAGIHAN =============" << endl;
    cout << endl;
    cout << "1. Obat\t\t: " << d.total << endl;
    if(d.pilihpengambilan == 2) {
        cout << "2. Ongkir\t: " << d.biayaongkir << endl;
    }
    cout << endl;
    cout << "Total yang harus anda bayar : " << d.total + d.biayaongkir << endl;
    system("pause");
}

void simpanDataPembelian(dataapotik &d) {
    ofstream file("data_pembelian.txt", ios::app);
    if (file.is_open()) {
        file << "====================================\n";
        file << "Nama Pasien     : " << d.namapasien << endl;
        file << "Umur            : " << d.umurpasien << endl;
        file << "Jenis Kelamin   : " << d.jeniskelaminpasien << endl;
        file << "Riwayat Penyakit: " << d.riwayatpenyakitpasien << endl;
        file << "Total Obat      : " << d.total << endl;
        if (d.pilihpengambilan == 2) {
            file << "Biaya Ongkir    : " << d.biayaongkir << endl;
        }
        file << "Total Bayar     : " << d.total + d.biayaongkir << endl;
        file << "Metode Bayar    : " << d.metodebayar << endl;
        file << "====================================\n\n";
        file.close();
    } else {
        cout << "Gagal menyimpan data ke file!" << endl;
    }
}

void tampilkanDataPembelianDariFile() {
    ifstream file("data_pembelian.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Belum ada data pembelian!" << endl;
    }
}

void tampilStok(dataapotik &d) {
    cout << "========== STOK OBAT ==========" << endl;
    for(int i = 0; i < JUMLAH_OBAT; i++){  // ? di sini
        cout << i+1 << ". " << setw(30) << setfill(' ') << d.namaObat[i] 
             << " | Stok: " << setw(3) << d.stokObat[i] 
             << " | Harga: Rp." << setw(6) << d.hargaObat[i] 
             << " | Fungsi: " << d.fungsiObat[i] << endl;
    }
    cout << "===============================" << endl;
}

void metodebayar(dataapotik &d){
    cout << "Pilih metode bayar : " << endl;
    cout << "1. Transfer Bank" << endl;
    cout << "2. Qris" << endl;
    cout << "3. Cash" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> d.metodebayarpilih;

    if(d.metodebayarpilih == 1){
        d.metodebayar = "Transfer Bank";
    } else if(d.metodebayarpilih == 2){
        d.metodebayar = "Qris";
    } else if(d.metodebayarpilih == 3){
        d.metodebayar = "Cash";
        cout << "Anda memilih metode bayar menggunakan cash." << endl;
        cout << "Total tagihan anda : " << d.total + d.biayaongkir << endl;
        cout << "Masukkan nominal uang anda : ";
        cin >> d.cash;
        cout << endl;
        cout << "Anda membayar sejumlah : " << d.cash << endl;

        if(d.cash > d.total + d.biayaongkir){
            cout << "Kembalian anda : " << d.cash - (d.total + d.biayaongkir) << endl;
        } else if(d.cash < d.total + d.biayaongkir){
            cout << "Maaf uang anda kurang....." << endl;
        }
    } else {
        cout << "Pilihan tidak ada...." << endl;
        d.metodebayar = "Belum dipilih";
    }
}

void datapasien(dataapotik &d){
    ofstream file("data_pasien.txt", ios::app);
    if (file.is_open()) {
        file << "====================================\n";
        file << "Nama Pasien     : " << d.namapasien << endl;
        file << "Umur            : " << d.umurpasien << endl;
        file << "Jenis Kelamin   : " << d.jeniskelaminpasien << endl;
        file << "Riwayat Penyakit: " << d.riwayatpenyakitpasien << endl;
        file << "====================================\n\n";
        file.close();
    } else {
        cout << "Gagal menyimpan data ke file!" << endl;
    }
}

void cetakStruk(dataapotik &d){
    ofstream file("struk.txt");
    if (file.is_open()) {
        file << "=============== STRUK ANDA ===============" << endl;
        file << "Nama Pasien      : " << d.namapasien << endl;
        file << "------------------------------------------" << endl;

        for(int i = 0; i < d.batas; i++){
            int idx = d.simpan[i] - 1;
            file << "Obat             : " << d.namaObat[idx] 
                 << " (" << d.temp[i] << " x Rp." << d.hargaObat[idx] << ")" << endl;
        }

        file << "------------------------------------------" << endl;
        if(d.pilihpengambilan == 2){
            file << "Ongkir           : Rp." << d.biayaongkir << endl;
        }
        file << "Metode bayar     : " << d.metodebayar << endl;
        file << "------------------------------------------" << endl;
        file << "TOTAL            : Rp." << d.total + d.biayaongkir << endl;
        file << "==========================================" << endl;
        file.close();
    } else {
        cout << "Gagal menyimpan struk ke file!" << endl;
    }
}

void tampilStruk(){
    ifstream file("struk.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Belum ada struk yang dicetak!" << endl;
    }
}

void tempStruk(dataapotik &d){
    d.temp[d.y] = d.jumlahobat;
    d.batas++;
    d.x++;
    d.y++;
}

void restockObat(dataapotik &d) {
    cout << "=== RESTOCK OBAT ===" << endl;
    cout << "+------+--------------------------------+---------+" << endl;
    cout << "| No.  | Nama Obat                      | Stok    |" << endl;
    cout << "+------+--------------------------------+---------+" << endl;
    // Tampilkan SEMUA obat (200)
	for(int i = 0; i < JUMLAH_OBAT; i++) {
	    cout << "| " << setw(4) << i+1 << " | " 
	         << setw(30) << d.namaObat[i] << " | " 
	         << setw(7) << d.stokObat[i] << " |" << endl;
	}
	cout << "+------+--------------------------------+---------+" << endl;
	
    int nomorObat;
	cout << "\nMasukkan nomor obat yang akan di-restock (1-" << JUMLAH_OBAT << "): ";
    cin >> nomorObat;

    if(nomorObat < 1 || nomorObat > JUMLAH_OBAT) {
    	cout << "Nomor obat tidak valid!" << endl;
    	system("pause");
    	return;
	}

    int indeks = nomorObat - 1;
    cout << "Obat yang dipilih: " << d.namaObat[indeks] << endl;
    cout << "Stok saat ini: " << d.stokObat[indeks] << endl;
    cout << "Masukkan jumlah stok yang akan ditambahkan: ";
    cin >> d.jumlahrestock;

    if(d.jumlahrestock <= 0) {
        cout << "Jumlah restock harus lebih dari 0!" << endl;
        system("pause");
        return;
    }

    d.stokObat[indeks] += d.jumlahrestock;
    saveStokToFile(d);
    cout << "\nRestock berhasil!" << endl;
    cout << "Stok " << d.namaObat[indeks] << " sekarang: " << d.stokObat[indeks] << endl;
    
rebuildTree(d);
}

void hapusObat(dataapotik &d) {
    system("cls");
    cout << "=== HAPUS OBAT ===" << endl;
    tampilStok(d);
    
    int nomorObat;
	cout << "\nMasukkan nomor obat yang ingin dihapus (1-" << JUMLAH_OBAT << "): ";
    cin >> nomorObat;

    if(nomorObat < 1 || nomorObat > JUMLAH_OBAT) {
    	cout << "Nomor obat tidak valid!" << endl;
    	system("pause");
    	return;
	}

    int indeks = nomorObat - 1;
    cout << "\nAnda yakin ingin menghapus obat '" << d.namaObat[indeks] << "'? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;

    if(konfirmasi == 'y' || konfirmasi == 'Y') {
        d.namaObat[indeks] = "";
        d.hargaObat[indeks] = 0;
        d.stokObat[indeks] = 0;
        d.fungsiObat[indeks] = "";
        saveStokToFile(d);
        cout << "\nObat berhasil dihapus!" << endl;
    } else {
        cout << "\nPenghapusan dibatalkan." << endl;
    }
rebuildTree(d);
}

void hasilpilihmenuutamaUser(dataapotik &d) {
    switch (d.pilihmenuUser) {
        case 1:
            system("cls");
            isidatapasien(d);
            do {
                menunamaobat(d);
                cout << "Masukkan nomor obat yang anda pilih (1-200): ";
                cin >> d.pilihannomorobat;
                
                // Saat memilih obat:
				if(d.pilihannomorobat < 1 || d.pilihannomorobat > JUMLAH_OBAT) {
				    cout << "Nomor obat tidak valid! (1-" << JUMLAH_OBAT << ")" << endl;
				    system("pause");
				    system("cls");
				    continue;
				}
				
                d.simpan[d.x] = d.pilihannomorobat;
                system("cls");
                detailobat(d);
                if(d.jumlahobat > 0) {
                    tempStruk(d);
                }
                cout << "Apakah ada obat lain yang akan anda beli? (y/n) : ";
                cin >> d.belilagi;
                system("cls");
            } while (d.belilagi != 'n' && d.belilagi != 'N');

            do {
                pengambilan(d);
                system("cls");
                ongkir(d);
            } while(d.pilihpengambilan == 0);

            detailpembelian(d);
            datapasien(d);
            break;

        case 2:
            system("cls");
            tampilStok(d);
            system("pause");
            break;

        case 3:            
            system("cls");
            metodebayar(d);
            simpanDataPembelian(d);
            cetakStruk(d);
            cout << "Metode pembayaran berhasil dipilih!" << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            tampilStruk();
            system("pause");
            break;

        case 5:
            system("cls");
            d.riwayat.tampilkan();
            system("pause");
            break;
        case 6:
            cout << "Terima kasih! Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid. coba lagi.\n";
    }
}

void tampilDataPasien(){
    ifstream file("data_pasien.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Belum ada data pasien!" << endl;
    }
}

void laporankeuangan(dataapotik &d){
    cout << "=== Laporan Keuangan Apotik K-24 ===" << endl;
    cout << endl;
    cout << "Pemasukkan Bulan Ini : " << d.total + d.biayaongkir << endl;
    cout << endl;
    cout << "====================================" << endl;
}

void hasilpilihmenuutamaAdmin(dataapotik &d){
    switch (d.pilihmenuAdmin) {
        case 1:
            system("cls");
            tampilStok(d);
            system("pause"); 
            break;
        case 2:
            system("cls");
            cout << "== DATA PEMBELIAN OBAT ==" << endl;
            tampilkanDataPembelianDariFile();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "== DATA PASIEN ==" << endl;
            tampilDataPasien();
            system("pause");
            break;
        case 4:
            system("cls");
            laporankeuangan(d);
            system("pause");
            break;
        case 5:
            system("cls");
            restockObat(d);
            system("pause");
            break;
        case 6:
            system("cls");
            hapusObat(d);
            system("pause");
            break;
        case 7:
            menuAntrianPasien(d);
            break;
		case 8:
		    system("cls");
		    cout << "========== STRUKTUR TREE OBAT ==========\n";
		    if(root == NULL)
		        cout << "Tree kosong.\n";
		    else
		        tampilTree(root);
		    system("pause");
		    break;
		case 9: {
		    system("cls");
		    string cari;
		
		    cout << "Masukkan nama obat: ";
		    cin>>ws;         // ?? INI KUNCI UTAMA
		    getline(cin, cari);
		
			
		    NodeObat* hasil = cariObat(root, cari);
		    if(hasil != NULL) {
		        cout << "Obat ditemukan\n";
		        cout << "Nama   : " << hasil->nama << endl;
		        cout << "Harga  : Rp." << hasil->harga << endl;
		        cout << "Stok   : " << hasil->stok << endl;
		        cout << "Fungsi : " << hasil->fungsi << endl;
		    } else {
		        cout << "Obat tidak ditemukan.\n";
		    }
		    system("pause");
		    break;
		}


        case 10:
            cout << "Keluar dari menu admin..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. coba lagi.\n";
    }
}

void hasillogin(dataapotik &d){
    do {
        menulogin(d);
        if(d.pilihmenuLogin == 1){
            loginAdmin(d);
            if(d.a == d.admin && d.b == d.passwordAdmin){
                do {
                    menuutama_admin(d);
                    hasilpilihmenuutamaAdmin(d);
                } while(d.pilihmenuAdmin != 10);
            } else {
                cout << "Login gagal! Username atau password salah." << endl;
                system("pause");
            }
        } else if(d.pilihmenuLogin == 2){
            loginUser(d);
            if(d.a == d.user && d.b == d.passwordUser){
                do {
                    menuutama_pelanggan(d);
                    hasilpilihmenuutamaUser(d);
                } while(d.pilihmenuUser != 6);
            } else {
                cout << "Login gagal! Username atau password salah." << endl;
                system("pause");
            }
        } else if(d.pilihmenuLogin > 3 || d.pilihmenuLogin < 1){
            cout << "Pilihan tidak valid!" << endl;
            system("pause");
        }
    } while(d.pilihmenuLogin != 3);
    cout << "Terimakasih telah menggunakan program" << endl;
}

int main(){
	
    dataapotik data;
    loadStokFromFile(data);
    
    for(int i = 0; i < JUMLAH_OBAT; i++) {
	    if(data.namaObat[i] != "") {
	        root = insertObat(
	            root,
	            data.namaObat[i],
	            data.hargaObat[i],
	            data.stokObat[i],
	            data.fungsiObat[i]
	        );
	    }
	}

    
    hasillogin(data);
    hapusTree(root);
    return 0;
}
