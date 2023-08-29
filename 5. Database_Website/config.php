<?php

// kết nối database

$server = "localhost";
$user = "admin";
$password = "123456";
$dbname = "users";

$conn = mysqli_connect($server,$user,$password,$dbname);
// Kiểm tra kết nối
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

?>