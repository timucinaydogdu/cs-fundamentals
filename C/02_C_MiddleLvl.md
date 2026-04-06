# C Programlama — Öğrenme Yolu

IoT ve embedded systems için C programlama konuları sırasıyla.

---

## İçindekiler

- [Orta](#orta)
- [İleri](#i̇leri)
- [Arduino Uygulaması](#arduino-uygulaması)

---

## Orta

| # | Konu | Açıklama | Notlar |
|---|------|----------|--------|
| 10 | Pointer Temelleri | Adres operatörü (&), pointer (*), NULL | |
| 11 | Pointer İleri | Pointer aritmetiği, array ile pointer ilişkisi | |
| 12 | Struct | Struct tanımlama, üyelere erişim, typedef | |
| 13 | Enum | Enum tanımlama, sabitleri yönetme | |
| 14 | Dinamik Bellek | malloc, calloc, realloc, free | |
| 15 | Dosya İşlemleri | fopen, fclose, fread, fwrite, fprintf | |
| 16 | Preprocessor | #define, #include, #ifdef, makrolar | |
| 17 | Bit İşlemleri | AND, OR, XOR, shift operatörleri | |

---

10 - Pointer Temelleri
* Pointerler sensor verileri tasimazlar. adresi vererek bellek tasarufu saglar. 

* Fonksiyon kullaniminda birden fazla deger verebilir.// Sensor okuma 
* Verileri kopyalamadigi icin bellek tasarufu saglar.// Buyuk ver
* Donanim uzerindeki kontrolu arttirir.  // Pin,Register,Interupt
* Normal degiskenler -> Deger saklar. 
* Pointerler -> Bellek adresi saklayarak degere erisim saglar. 
```c
int sayi = 42;
int *ptr = &sayi; // Sayi adresindeki, adres bilgisini ptr`ye *ptr ise icindeki veriyi tanimlar. 

printf("%d\n",  sayi);   // 42       → değer  - Normal degisen erisimi
printf("%p\n",  &sayi);  // 0x1000   → adres  - Sayi degiskeninin bellek adresini verir. 
printf("%p\n",  ptr);    // 0x1000   → Tanimladamadan adres bilgisi ptr verisine girildi. 
printf("%d\n",  *ptr);   // 42       → ptr adresindeki veriye * ile erisim saglandi. 

```
Pointer ile Deger Degistirme
* Pointerlar adres uzerinden bagli oldugu icin bir noktadan yapilan deger atamasi tum degiskenleri degistirir. Ama adresler ayni kalir. 

```c
int sayi = 42;
int *ptr = &sayi;

*ptr = 100;   // ptr'nin gösterdiği yere 100 yaz

printf("%d\n", sayi);    // 100 → sayi degiskenine bellek adresi uzerinden eristi. 
printf("%d\n", *ptr);    // 100
                         // Null olarak tanimlanmis bir pointera deger atamaya calismak programi cokertir.
                         
```
* Fonsiyonlarda pointer kullanimi
```c
void ikiKat(int *ptr) {     // Varsayilan olarak genel adresteki veri parametre olarak alir. 
    *ptr = *ptr * 2;        // Parametre verisine gore islemi tamamlar. 
}

int x = 5;
ikiKat(&x);                 // Iki kat fonksiyonuna, x`degiskeninin adresini gondererek fonksiyonun adresteki veriye erisimi saglar. 
printf("%d\n", x);          // Fonksiyonun donderdigi islem degeri 10 olarak ekrana yazilir.                          
```
---

11 - Pointer ileri seviye
* Pointerlari dizeler gibi kullanarak degerler arasindan gecis saglayabilirsin. 
```c

int sayilar[] = {10, 20, 30, 40, 50};
int *ptr = sayilar;         // Sayilar dizesinin degerlerine adresleri uzerinden ulasir. 

printf("%d\n", *ptr);       // ptr + 0 olarak varsayilan olarak ilk degeri getirir. 
printf("%d\n", *(ptr + 1)); // ptr + 1 olarak ikinci degeri getirir. Ve 20 degerini verir. 
printf("%d\n", *(ptr + 2)); // ptr + 2 olarak ucuncu degeri getirir. 

// IoT Kullanim Ornegi Array'i pointer ile fonksiyona geç

void ortalamaHesapla(int *dizi, int boyut) { // Ortalama hesaplama fonksiyonu 
    int toplam = 0;
    for (int i = 0; i < boyut; i++) {
        toplam += *(dizi + i);   // Dizi + 0 ~ 5 ile fonksiyona gelen tum verileri toplama alir.  
    }
    printf("Ortalama: %.1f\n", (float)toplam / boyut);
}

int main() {
    int olcumler[] = {720, 735, 741, 728, 750};
    ortalamaHesapla(olcumler, 5);   // Olcumler dizisini ve boyutu fonksiyona ilet -> 734.8
    return 0;
}


```
