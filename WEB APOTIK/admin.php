<?php
session_start();

if (!isset($_SESSION['username']) || $_SESSION['role'] != 'admin') {
    header("Location: apotik.php");
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h2>Menu Admin</h2>
        <p>Selamat datang, <?php echo $_SESSION['username']; ?>!</p>
        
        <ul>
            <li><a href="riwayat.php">Riwayat Transaksi</a></li>
        </ul>
        
        <a href="logout.php">Logout (keluar)</a>
    </div>

</body>
</html