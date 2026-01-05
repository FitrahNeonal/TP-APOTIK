<?php
session_start();
include "config.php";

// Cek user
if (!isset($_SESSION['role']) || $_SESSION['role'] != "user") {
    header("Location: apotik.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Beli Obat</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="container_obat">
    <h2>Pilih Obat yang Ingin Dibeli</h2>

    <form action="pembayaran.php" method="post">
        
        <div class="table-box">
            <table>
                <tr>
                    <th>No</th>
                    <th>Nama Obat</th>
                    <th>Stok</th>
                    <th>Harga</th>
                    <th>Fungsi</th>
                    <th>Beli Berapa?</th>
                </tr>

                <?php 
                $no = 1;
                foreach ($obat as $index => $o) { ?>
                    <tr>
                        <td><?php echo $no++; ?></td>
                        <td><?php echo $o['nama']; ?></td>
                        <td><?php echo $o['stok']; ?></td>
                        <td><?php echo "Rp " . number_format($o['harga'], 0, ',', '.'); ?></td>
                        <td><?php echo $o['fungsi']; ?></td>
                        <td>
                            <input 
                                type="number" 
                                name="jumlah[<?php echo $index; ?>]" 
                                min="0" 
                                max="<?php echo $o['stok']; ?>" 
                                value="0"
                                class="input-jumlah"
                            >
                        </td>
                    </tr>
                <?php } ?>
            </table>
        </div>

        <br>
        <button type="submit" class="btn-submit">OK</button>
    </form>

    <br>
    <a href="user.php" class="kembali">Kembali</a>
</div>

</body>
</html>