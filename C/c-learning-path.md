# C Programlama — Öğrenme Yolu

IoT ve embedded systems için C programlama konuları sırasıyla.

---

## İçindekiler

- [Temel](#temel)
- [Orta](#orta)
- [İleri](#i̇leri)
- [Arduino Uygulaması](#arduino-uygulaması)

---

## Temel

| # | Konu | Açıklama | Notlar |
|---|------|----------|--------|
| 01 | Ortam Kurulumu | GCC, VS Code, ilk program derleme | |
| 02 | Merhaba Dünya | printf, main fonksiyonu, derleme süreci | |
| 03 | Değişkenler ve Veri Tipleri | int, float, char, double, unsigned | |
| 04 | Operatörler | Aritmetik, karşılaştırma, mantıksal operatörler | |
| 05 | Koşullar | if, else if, else, switch-case | |
| 06 | Döngüler | for, while, do-while, break, continue | |
| 07 | Fonksiyonlar | Tanımlama, parametre, return, scope | |
| 08 | Array | Tek boyutlu dizi, indeks, döngü ile kullanım | |
| 09 | String ve Char | char array, string.h, temel string işlemleri | |


---

01 -  [Ortam kurulumu > Gcc, Vs code](c-macos-setup.md)

---

02 - Merhaba Dünya > printf, main fonksiyonu
```c
#include <stdio.h> // Standart giriş/çıkış kütüphanesini dahil et

int main() { // Programin Basladigi fonksiyon
    printf("Merhaba Dünya\n");  // Ekrana yazdirma fonksiyonu 
                                // \n Yeni satir kacis karakteri
    return 0; // Program basariyla bitti sinyali
}
```
---

Format belirteci — değişkenin yerine geçer.
* printf() bir fonksiyon — ve ilk parametresi her zaman format string alır.
* "Sicaklik: %d"  →  %d'yi bul  →  deger değişkenini oraya koy
* Sıra önemli — format string'deki % işaretleri soldan sağa sırayla değişkenlere eşlenir.
* printf("Konum:%c Sicaklik:%d Nem:%f\n", konum, sicaklik, nem);

```c
printf("Metin\n");              // düz metin
printf("Sayi: %d\n", 42);       // integer
printf("Ondalik: %f\n", 3.14);  // float -> Farkli kullanimlari var.
printf("Deger: %f\n", 3.14);    // → Deger: 3.140000
printf("Deger: %.2f\n", 3.14);  // → Deger: 3.14
printf("Karakter: %c\n", 'A');  // char
printf("String: %s\n", "IoT");  // string
```
---
Print komutlari farklari
* println   -> Yazdir + alt satira gec.
* print     -> Yazdir , alt satira gecme.
* Arduinoda -> Serial.println() karsiligini alir. 

```c
// C
printf("Sicaklik: %d\n", 25);

// Arduino
int sicaklik = 25;
    Serial.print("Sicaklik: ");// Sicaklik: yaz
    Serial.println(sicaklik);  // 25 yazar ve alt satıra geçer
    delay(1000);               // 1 saniye bekle
```
---
03 - Değişkenler ve Veri Tipleri > int, float, char, double, unsigned
* Tanimlama kurallari
```c
int sayi = 5;       // ✅
int 3sayi = 5;      // ❌ rakamla başlayamaz
int int = 5;        // ❌ reserved keyword
int benim sayi = 5; // ❌ boşluk olamaz
int benim_sayi = 5; // ✅ alt çizgi olur
```

* int    sayi    = 25;              // tam sayı       -128 / 127
* float  ondalik = 3.14;            // ondalıklı sayı -2,147,483,648 / 2,147,483,647
* double hassas  = 3.14159;         // ondalıklı sayı ±3.4 × 10³⁸
* char   harf    = 'A';             // tek karakter   ±1.7 × 10³⁰⁸
- Sensör değerleri genellikle negatif olmaz. unsigned kullanmak daha doğru olur.
* unsigned int  pozitif = 300;      // 0 ile 4,294,967,295 arası
* unsigned char kucuk   = 200;      // 0 ile 255 arası
- Arduino veri tipleri 
```c
boolean aktif  = true;    // true / false
byte    deger  = 255;     // 0-255 arası (unsigned char ile aynı)
String  mesaj  = "IoT";   // Arduino'ya özel string tipi
```
---
04 — Operatörler
* Aritmetik Operatorler
```c
int a = 10;
int b = 3;

printf("%d\n", a + b);   // 13  → toplama
printf("%d\n", a - b);   // 7   → çıkarma
printf("%d\n", a * b);   // 30  → çarpma
printf("%d\n", a / b);   // 3   → bölme (tam sayı)
printf("%d\n", a % b);   // 1   → mod (kalan)
```
* Mantiksal Operatorler
```c
int a = 1;
int b = 0;

printf("%d\n", a && b);   // 0  → AND → ikisi de true olmalı
printf("%d\n", a || b);   // 1  → OR  → biri true yeterli
printf("%d\n", !a);       // 0  → NOT → tersini al
```
* Atama Operatorler
```c
int x = 10;

x += 5;    // x = x + 5  → 15
x -= 3;    // x = x - 3  → 12
x *= 2;    // x = x * 2  → 24
x /= 4;    // x = x / 4  → 6
x %= 4;    // x = x % 4  → 2
```
* Atama Operatorler
```c
int x = 5;

x++;    // x = x + 1 → 6
x--;    // x = x - 1 → 5

++x;    // önce artır, sonra kullan
x++;    // önce kullan, sonra artır

int a = 5;

printf("%d\n", a++);   // 5 yazdırır, sonra a=6 olur
printf("%d\n", ++a);   // önce a=7 olur, sonra 7 yazdırır
```
* IoT`de Kullanimi
```c
int sensor = 750;

// Eşik kontrolü
if (sensor > 500 && sensor < 900) {
    printf("Normal aralikta\n");
}

// Sayaç
int okuma_sayisi = 0;
okuma_sayisi++;    // her okumada artır

// Yüzde hesabı
float yuzde = (float)sensor / 1023 * 100;
printf("Yuzde: %.1f\n", yuzde);

```
---
05 Kosullar
* if > else if > else - Deger karsilastirmasinda kullanilir.
```c
int sicaklik = 35;

if (sicaklik > 40) {
    printf("Cok sicak!\n");
} else if (sicaklik > 30) {
    printf("Sicak\n");
} else if (sicaklik > 20) {
    printf("Normal\n");
} else {
    printf("Soguk\n");
}
// çıktı → Sicak

// Kisa if ornegi

int x = 10;
printf("%s\n", x > 5 ? "Buyuk" : "Kucuk");
// çıktı → Buyuk
```

* Switch -  Tek bir degeri, bir cok sabitle karsilastirirken kullanilir. 
```c
int mod = 2;

switch (mod) {
    case 1:
        printf("Manuel mod\n");
        break;                  // Break`ler olmadan tum kod calisir. Onemli. 
    case 2:
        printf("Otomatik mod\n");
        break;
    case 3:
        printf("Uyku modu\n");
        break;
    default:
        printf("Gecersiz mod\n");
}
// çıktı → Otomatik mod
```
* IoT`de Kullanimi
```c
int sensor    = 850;
int esik_dusuk = 300;
int esik_yuksek = 800;

if (sensor < esik_dusuk) {
    printf("Dusuk seviye - alarm!\n");
} else if (sensor > esik_yuksek) {
    printf("Yuksek seviye - alarm!\n");
} else {
    printf("Normal seviye\n");
}
// çıktı → Yuksek seviye - alarm!

```
```c
// Cihaz durumu — switch ile
int durum = 3;

switch (durum) {
    case 1: printf("Baglaniyor\n");  break;
    case 2: printf("Veri okuyor\n"); break;
    case 3: printf("Gonderiyor\n");  break;
    case 4: printf("Uyku\n");        break;
    default: printf("Hata\n");
}
// çıktı → Gonderiyor
```
---
06 Donguler
* For Dongusu
```c
// 3 bolumden olusur. 

for (başlangıç ; koşul ; artış) { }
//    int i=0  ; i < 5 ; i++

for (int i = 0; i < 5; i++) { // Ornek
    printf("%d\n", i);
}
// çıktı → 0 1 2 3 4

// ic ice donguler. 
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("%d x %d = %d\n", i, j, i * j);
    }
}
// çıktı →
// 1 x 1 = 1
// 1 x 2 = 2
// ...
// 3 x 3 = 9

```
* Do - While Dongusu
```c
// Yap sonra kontrol et. 
int i = 0;

do {
    printf("%d\n", i);
    i++;
} while (i < 5);
// çıktı → 0 1 2 3 4

// For`dan Farki — koşul baştan false olsa bile bir kez çalışır
int i = 10;

do {
    printf("Calisir\n");   // bir kez çalışır
} while (i < 5);
```
* Break - Continue
```c
// break — döngüden çık
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    printf("%d\n", i);
}
// çıktı → 0 1 2 3 4

// continue — o turu atla, devam et
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;
    printf("%d\n", i);
}
// çıktı → 1 3 5 7 9
```
* Sonsuz donguler
```c
// Sonuc True oldugu surece calismaya devam eder. 
while (1) {
    printf("Surekli calisiyor\n");
}

// Arduino`da loop() fonksiyonu bu isi yapar. 
while (1) {
    loop();
}
```
* IoT`de kullanimi
```c
// 10 kez sensör oku, ortalamasını al
int toplam = 0;

for (int i = 0; i < 10; i++) {
    int okuma = 800 + i;   // örnek sensör değeri
    toplam += okuma;
    printf("Okuma %d: %d\n", i + 1, okuma);
}

float ortalama = (float)toplam / 10;
printf("Ortalama: %.1f\n", ortalama);

// Belirli eşiğe ulaşana kadar bekle
int sensor = 0;

while (sensor < 500) {
    sensor += 50;   // sensörü simüle et
    printf("Bekleniyor: %d\n", sensor);
}
printf("Esige ulasildi!\n");
```

07 Fonksiyonlar
```c
// Yapi dort bolumden olusur. 
int      topla    (int a, int b)  { return a + b; }
// Tip   isim      parametreler        gövde

// tanımlama
int topla(int a, int b) {
    return a + b;
}

// çağırma
int sonuc = topla(3, 5);
printf("%d\n", sonuc);   // 8

// Void Fonksiyon - Geriye bir islenebilir bir deger(sonuc) dondurmez. Bilgi verir.
void yazdir(int deger) {
    printf("Deger: %d\n", deger);
    // return yok
}

yazdir(42);   // çıktı → Deger: 42

// Birden fazla parametre kullanimi
float hesapla(float voltaj, int direnc) {
    return voltaj / direnc;
}

float akim = hesapla(5.0, 220);
printf("Akim: %.4f A\n", akim);   // 0.0227 A
```
* Fonksiyon Bildirimi(Declaration) -> Fonksiyonun once tanimlanmasidir. 
```c
int topla(int a, int b);            // Bildirim — üstte degerler tanimlanmis. 

int main() {
    printf("%d\n", topla(3, 5));   // ✅ Yazilan fonksiyon burada cagirilir. 
    return 0;
}

int topla(int a, int b) {   // Tanimlanmis fonksiyonun yazildigi yer. 
    return a + b;
}
```
* Fonksiyon Kapsami (Scope) 
```c
int x = 10;                 // global — her yerden erişilir

void fonksiyon() {
    int y = 20;             // lokal — sadece burada geçerli
    printf("%d\n", x);      // ✅ global erişilir
    printf("%d\n", y);      // ✅ lokal erişilir
}

int main() {
    printf("%d\n", x);      // ✅
    printf("%d\n", y);      // ❌ hata — y burada yok
    return 0;
}
```
* IoT`de kullanimi
```c
// Sensör değerini yüzdeye çevir
float yuzdeyeCevir(int deger, int maksimum) {
    return (float)deger / maksimum * 100;
}

// Alarm kontrolü
void alarmKontrol(int sicaklik, int esik) {
    if (sicaklik > esik) {
        printf("ALARM! Sicaklik: %d\n", sicaklik);
    } else {
        printf("Normal. Sicaklik: %d\n", sicaklik);
    }
}

int main() {
    int sensor = 850;
    float yuzde = yuzdeyeCevir(sensor, 1023);
    printf("Sensor: %.1f%%\n", yuzde);   // 83.1%

    alarmKontrol(42, 40);   // ALARM! Sicaklik: 42
    alarmKontrol(35, 40);   // Normal. Sicaklik: 35

    return 0;
}

```
---
08 - Array
```c
// Temel yapi
int     sayilar[5] = {10, 20, 30, 40, 50};
//tip       boyut           değerler

printf("%d\n", sayilar[0]);     // 10 → ilk eleman
printf("%d\n", sayilar[4]);     // 50 → son eleman
printf("%d\n", sayilar[5]);     // ❌ taşma — tanımsız davranış

// Tanimlama yontemleri
int a[5] = {1, 2, 3, 4, 5};     // Boyut ve değer birlikte


int b[5];                       // Sadece boyut — değerler başta 0 olur

int c[] = {1, 2, 3, 4, 5};      // Boyutsuz — otomatik hesaplanır
                                // boyut otomatik 5 olur

int d[5] = {1, 2};              // Kısmi doldurma — geri kalanlar 0
                                // {1, 2, 0, 0, 0}
```
* Dongulerde kullanimi 
```c
int sayilar[5] = {10, 20, 30, 40, 50};

for (int i = 0; i < 5; i++) {   // Tanimlanmis tum arrayi ekrana yazdirir. 
    printf("sayilar[%d] = %d\n", i, sayilar[i]);
}

int toplam = 0;
for (int i = 0; i < 5; i++) {   // Tanimlanmis tum arrayi toplamalar.
    toplam += sayilar[i];
}
printf("Toplam: %d\n", toplam);   // 150
```
* Array eleman sayisini ogrenme
```c
int sayilar[] = {10, 20, 30, 40, 50};
int boyut = sizeof(sayilar) / sizeof(sayilar[0]);
printf("Boyut: %d\n", boyut);   // 5

// Aciklama
// sizeof(sayilar) → tüm dizinin byte boyutu (20)
// sizeof(sayilar[0]) → bir elemanın byte boyutu (4)
// 20 / 4 = 5 → eleman sayısı
```
* Cok boyutlu matrix (Array)
```c
int matris[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

printf("%d\n", matris[1][2]);   // 6 → 2. satır, 3. sütun

// döngü ile yazdır
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matris[i][j]);
    }
    printf("\n");
}
```
* IoT`de kullanimi
```c
// 10 sensör okuması sakla
int olcumler[10] = {720, 735, 741, 728, 750,
                    745, 738, 752, 748, 730};

// en yüksek değeri bul
int maksimum = olcumler[0];
for (int i = 1; i < 10; i++) {
    if (olcumler[i] > maksimum) {
        maksimum = olcumler[i];
    }
}
printf("Maksimum: %d\n", maksimum);   // 752

// ortalama hesapla
int toplam = 0;
for (int i = 0; i < 10; i++) {
    toplam += olcumler[i];
}
float ortalama = (float)toplam / 10;
printf("Ortalama: %.1f\n", ortalama);   // 738.7

```
--- 
09 - String ve Char
* Char  -> Tek bir karaktere verilen addir. ASCII tablosune karsiliklari vardir. 
* String-> Stringler aslinda sadece Char dizisidir. Sonunda \0 null terminator var.
```c
char isim[6] = {'T','i','m','u','r','\0'}; // Null terminator bosluklari temizler
// veya kısa yol
char isim[] = "Timur";

printf("%s\n", isim);   // Timur
```
* string.h kutuphanesi fonksiyonlari

```c
#include <string.h>

char a[] = "Merhaba";
char b[] = "Dunya";

printf("%d\n",  strlen(a));       // 7      → uzunluk
printf("%d\n",  strcmp(a, b));    // 0 değil → eşit değil
printf("%s\n",  strcat(a, b));    // MerhabaDunya → birleştir
strcpy(a, b);                     // b'yi a'ya kopyala

// Karakter karsilastirma. 
char c = 'A';

if (c == 'A') {
    printf("Buyuk A\n");
}

// küçük harfe çevir
char kucuk = c + 32;   // 65 + 32 = 97 = 'a'
printf("%c\n", kucuk);   // a

// Kullanicidan veya disaridan veri okumak icin kullanilan yontemler. 
char a[50];
char b[50];

scanf("%s", a);    // kullanıcı "Timur Aydin" yazarsa → "Timur"
fgets(b, 50, stdin); // kullanıcı "Timur Aydin" yazarsa → "Timur Aydin"

```