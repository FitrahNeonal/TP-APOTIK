<?php
session_start();
include "config.php";

if (!isset($_SESSION['role']) || $_SESSION['role'] != "user") {
    header("Location: apotik.php");
    exit;
}

$jumlah = $_POST['jumlah'];
$totalBayar = 0;
$keranjang = [];

// Ambil data obat dari config.php dan proses
foreach ($jumlah as $index => $jml) {
    if ($jml > 0) {

        $item = $obat[$index];
        $item['jumlah'] = $jml;
        $item['subtotal'] = $item['harga'] * $jml;

        $totalBayar += $item['subtotal'];
        $keranjang[] = $item;
    }
}

// Simpan session utk halaman selesai.php
$_SESSION['keranjang'] = $keranjang;
$_SESSION['totalBayar'] = $totalBayar;

?>
<!DOCTYPE html>
<html>
<head>
    <title>Detail Pembayaran</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="container">
    <h2>Detail Pembelian</h2>

    <?php 
        if (count($keranjang) == 0) {
            echo "<p>Tidak ada obat yang dipilih.</p>";
            echo "<a href='beli_obat.php'>Kembali</a>";
            exit;
        }
    ?>

    <table>
        <tr>
            <th>Nama Obat</th>
            <th>Jumlah</th>
            <th>Harga</th>
            <th>Subtotal</th>
        </tr>

        <?php foreach ($keranjang as $item) { ?>
            <tr>
                <td><?= $item['nama']; ?></td>
                <td><?= $item['jumlah']; ?></td>
                <td>Rp <?= number_format($item['harga'], 0, ',', '.'); ?></td>
                <td>Rp <?= number_format($item['subtotal'], 0, ',', '.'); ?></td>
            </tr>
        <?php } ?>
    </table>

    <h3>Total Bayar: Rp <?= number_format($totalBayar, 0, ',', '.'); ?></h3>

    <form action="selesai.php" method="post">
        <label>Metode Pembayaran:</label>
        <select name="metode" required>
            <option value="">-- pilih --</option>
            <option value="Cash">Cash</option>
            <option value="Transfer Bank">Transfer Bank</option>
            <option value="E-Wallet">E-Wallet</option>
        </select>

        <button type="submit">Lanjutkan Pembayaran</button>
    </form>

    <br>
    <a href="beli_obat.php" class="back">Kembali</a>
</div>

</body>
</html>