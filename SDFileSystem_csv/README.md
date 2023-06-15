# SDFilesystem_csv

## Overview (概要)
- SDカードとNUCLEOボード間をSPI通信で接続し、外部記憶装置として使用できるようにしたものです。このサンプルプログラムではMPU6050センサの値を読み込み、その値をSDカードにcsv形式で保存するという動作をしています。<br>
This project can connect NUCLEO board to SDcard by using SPI connection and make SDcard a external memory of NUCLEO board. In this sample program, NUCLEO board will read MPU6050 sensor and saves its values as CSV file.
  
- ジャイロセンサの値をcsvファイルに記録し、値の誤差を観察するために使用しました。<br>
  You can check MPU6050's margin of error.

<br>

## Features (性質/特徴)
コンパイルする前に、ルートディレクトリにmbed_app.json及びcustom_targets.jsonを追加し、値を設定する必要があります。<br>
You should add mbed_app.json and custom_targets.json into your root directory and set their value before you compile this project.

<br>
## Directory (ディレクトリ構成)
```
.
├── SDFileSystem
|   ├── SDFileSystem.cpp
|   ├── SDFileSystem.h
|
├── compile_commands.json
├── custom_tagets.json
├── main.cpp
├── mbed_app.json
├── mbed-os
├── MPU6050.h
├── SDFileSystem.lib
└── README.md
```

## Environments (開発環境)
|          |     |
|   :-:    | --- |
| OS       | Windows 10 Pro, mbed OS5|
| IDE      | Arm Keil Studio|
| HARD     | NUCLEO F446RE, ダイセン電子工業 C-SDC SDカード変換基板 |
| LANG     | C++|
| OTHERS   | MPU6050.h |


---
<br>

## 参考サイト

SDFileSystemを追加する<br>
https://os.mbed.com/users/mbed_official/code/SDFileSystem/

インポートしたSDFyleSystem内のFATFileSystemを削除した後、
以下のサイトを参考に、ルートディレクトリにmbed_app.json、custom_targets.jsonを追加し、値を書き込む(ココ大事！)<br>
https://os.mbed.com/questions/82585/SDBlockDeviceh-not-found/

SDカードスロットのピン<br>
http://dad8893.blogspot.com/2016/11/nucleo-f401rembedsd.html

ダイセン電子工業　C-SDC SDカード変換基板<br>
https://www.sengoku.co.jp/mod/sgk_cart/detail.php?code=EEHD-47ZR

---



## Author (リポジトリ作成者)
- Nkanato