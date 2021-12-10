IVT.DAT изначально в DOS кодировке, перекодируем, сохраняем оригинальный файл

iconv -f CP866 -t utf8 < IVT.DAT  > 1
mv IVT.DAT IVT.DAT.CP866
mv 1 IVT.DAT

Run:

 gcc -o z  main.c
 ./z

