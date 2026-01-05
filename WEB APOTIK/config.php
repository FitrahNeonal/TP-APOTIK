<?php

$users = [
    [
        "username" => "admin",
        "password" => "admin123",
        "role" => "admin"
    ],
    [
        "username" => "user",
        "password" => "user123",
        "role" => "user"
    ]
];

// Load obat dari file JSON
$obat = json_decode(file_get_contents("obat.json"), true);