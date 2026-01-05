#ifndef TREE_OBAT_H
#define TREE_OBAT_H

#include <iostream>
#include <string>
using namespace std;

struct NodeObat {
    string nama;
    int harga;
    int stok;
    string fungsi;
    NodeObat* left;
    NodeObat* right;
};

// INSERT BST
NodeObat* insertObat(NodeObat* root,
                     string nama,
                     int harga,
                     int stok,
                     string fungsi)
{
    if(root == NULL) {
        NodeObat* baru = new NodeObat;
        baru->nama = nama;
        baru->harga = harga;
        baru->stok = stok;
        baru->fungsi = fungsi;
        baru->left = baru->right = NULL;
        return baru;
    }

    if(nama < root->nama)
        root->left = insertObat(root->left, nama, harga, stok, fungsi);
    else
        root->right = insertObat(root->right, nama, harga, stok, fungsi);

    return root;
}

// TAMPILKAN TREE (VISUAL)
void tampilTree(NodeObat* root, string prefix = "", bool isLeft = false)
{
    if(root != NULL) {
        cout << prefix;
        cout << (isLeft ? "+-- " : "+-- ");
        cout << root->nama << endl;

        tampilTree(root->left,  prefix + (isLeft ? "¦   " : "    "), true);
        tampilTree(root->right, prefix + (isLeft ? "¦   " : "    "), false);
    }
}

// SEARCH
NodeObat* cariObat(NodeObat* root, string nama)
{
    if(root == NULL)
        return NULL;

    if(root->nama == nama)
        return root;

    if(nama < root->nama)
        return cariObat(root->left, nama);
    else
        return cariObat(root->right, nama);
}


// DELETE TREE
void hapusTree(NodeObat* root)
{
    if(root != NULL) {
        hapusTree(root->left);
        hapusTree(root->right);
        delete root;
    }
}

#endif
