<?php
session_start();
session_destroy();
header("Location: apotik.php");
exit;