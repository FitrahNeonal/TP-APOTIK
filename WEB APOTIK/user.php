<?php
session_start();

if (!isset($_SESSION['username']) || $_SESSION['role'] != 'user') {
    header("Location: apotik.php");
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container_user">
        <h2>Menu User</h2>
        <p>Selamat datang, <?php echo $_SESSION['username']; ?>!!</p>
        
        <ul> 
            <a href="beli_obat.php">Beli obat</a>
        </ul>
        
        <a href="logout.php">Logout (keluar)</a>
    </div>
</body>
</html>