<?php
session_start();
include "config.php";

$username = $_POST['username'];
$password = $_POST['password'];

$loginBerhasil = false;

foreach ($users as $user) {
    if ($username == $user['username'] && $password == $user['password']) {
        $_SESSION['username'] = $user['username'];
        $_SESSION['role'] = $user['role'];
        $loginBerhasil = true;
        
        if($user['role'] == 'admin'){
            header("Location: admin.php");
        } else {
            header("Location: user.php");
        }
        exit;
    }
}

if (!$loginBerhasil) {
    echo "Login gagal. Username atau password salah. <a href='apotik.php'>Coba lagi</a>";
}