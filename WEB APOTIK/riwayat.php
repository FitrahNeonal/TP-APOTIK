<?php
session_start();

// Cek login admin
if (!isset($_SESSION['role']) || $_SESSION['role'] != "admin") {
    header("Location: apotik.php");
    exit;
}

// Ambil riwayat transaksi (dari sesi dulu)
$transaksi = $_SESSION['transaksi'] ?? [];

?>
<!DOCTYPE html>
<html>
<head>
    <title>Riwayat Transaksi</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="container_user">
    <h2>Riwayat Transaksi</h2>

<?php 
    if (count($transaksi) == 0) { 
    ?>
        <p>Belum ada transaksi.</p>
        <a href="admin.php">Kembali</a>
    <?php 
        exit; 
    }
?>


    <table border="1" width="100%">
        <tr>
            <th>No</th>
            <th>Nama Pembeli</th>
            <th>Daftar Obat</th>
            <th>Total Bayar</th>
            <th>Metode</th>
            <th>Tanggal</th>
        </tr>

        <?php foreach ($transaksi as $index => $data) { ?>
            <tr>
                <td><?= $index + 1 ?></td>
                <td><?= $data['nama'] ?></td>
                <td>
                    <ul>
                    <?php foreach ($data['keranjang'] as $item) { ?>
                        <li><?= $item['nama'] ?> (<?= $item['jumlah'] ?> pcs)</li>
                    <?php } ?>
                    </ul>
                </td>
                <td><?= "Rp " . number_format($data['total'], 0, ',', '.') ?></td>
                <td><?= $data['metode'] ?></td>
                <td><?= $data['tanggal'] ?></td>
            </tr>
        <?php } ?>
    </table>

    <br>
    <a href="admin.php">Kembali</a>
</div>

</body>
</html>