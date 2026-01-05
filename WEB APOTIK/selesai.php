<?php
session_start();

if (!isset($_SESSION['role']) || $_SESSION['role'] != "user") {
    header("Location: apotik.php");
    exit;
}

$keranjang = $_SESSION['keranjang'];
$total = $_SESSION['totalBayar'];
$metode = $_POST['metode'];

// Load data obat
$obat = json_decode(file_get_contents("obat.json"), true);

// Kurangi stok
foreach ($keranjang as $item) {
    foreach ($obat as &$o) {
        if ($o['nama'] === $item['nama']) {
            $o['stok'] -= $item['jumlah'];
        }
    }
}

// Simpan perubahan stok
file_put_contents("obat.json", json_encode($obat, JSON_PRETTY_PRINT));

?>

<!DOCTYPE html>
<html>
<head>
    <title>Pembayaran Selesai</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="container">
    <h2>Pembayaran Berhasil</h2>

    <h3>Detail Transaksi:</h3>

    <table border="1" width="100%" cellpadding="5">
        <tr>
            <th>Nama Obat</th>
            <th>Jumlah</th>
            <th>Subtotal</th>
        </tr>

        <?php foreach ($keranjang as $item) { ?>
            <tr>
                <td><?php echo $item['nama']; ?></td>
                <td><?php echo $item['jumlah']; ?></td>
                <td><?php echo "Rp " . number_format($item['subtotal'], 0, ',', '.'); ?></td>
            </tr>
        <?php } ?>
    </table>

    <h3>Total: <?php echo "Rp " . number_format($total, 0, ',', '.'); ?></h3>
    <p>Metode Pembayaran: <b><?php echo $metode; ?></b></p>

    <br>
    <a href="user.php">Kembali ke Menu User</a>
</div>

</body>
</html>