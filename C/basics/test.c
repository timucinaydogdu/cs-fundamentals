#include <stdio.h>

/*
ctrl + shift + b => build and run // derleme ve calistirma islemi yapar
c *.c => run // Terminalde derlenmis dosyayi calistirir

Command + / => secili kodu yorum satiri yapar veya yorum satirindan cikartir

Algoritma ; konusu
1. Adim: Ihtiyacimiz olan variable'lari bulmak.
2. Adim: Variable'larin tiplerini belirlemek.
3. Adim: Kullanilacak formul yada islemi belirlemek.
4. Adim: Kullacidan gerekli bilgileri almak.
5. Adim: Islemi gerceklestirmek.
6. Adim: Sonucu ekrana yazdirmak.

*/


// int main() {     // Derleyici test kodu
//     printf("C calisiyor!\n");
//     return 0;
// }


// int sayi1, sayi2;   // Global degiskenlerle matematik islemleri
// float sonuc;

// int main() {
//     printf("Birinci sayiyi giriniz: ");
//     scanf("%d", &sayi1);
//     printf("Ikinci sayiyi giriniz: ");
//     scanf("%d", &sayi2);
//     printf("Toplam: %.2f\n", (float)(sayi1 + sayi2));
//     printf("Fark: %.2f\n", (float)(sayi1 - sayi2));
//     printf("Carpim: %.2f\n", (float)(sayi1 * sayi2));
//     return 0;
// }


// float r, cevre, alan;   // Dairenin yaricapi ve alani.
// const float PI = 3.14;

// int main() {
//     printf("Dairenin yaricapini giriniz: ");
//     scanf("%f", &r);
//     cevre = 2 * PI * r;
//     alan = PI * r * r;
//     printf("Dairenin cevresi: %.2f\n", cevre);
//     printf("Dairenin alani: %.2f\n", alan);
//     return 0;
// }

// int main() {     // Atama ve islemli atama operatorleri
//     int sayi;
//     sayi = 10;
//     sayi *=15;
//     printf("Sayi: %d\n", sayi);
//     sayi /= 5;
//     printf("Sayi: %d\n", sayi);
//     sayi += 20;
//     printf("Sayi: %d\n", sayi);
//     sayi -= 5;
//     printf("Sayi: %d\n", sayi);
//     return 0;
// }

// int main() {     // Karsilastirma operatorleri
//     int x,y ;
    
//     x = 5;
//     y = 2;
    
//     printf("x: %d, y: %d\n", x, y);
//     if (x > y && x <10)
//     {
//         printf("x, y'den buyuktur ve 10'dan kucuktur.\n");
        
//     }   else if (x < y && x > 0)
//     {
//         printf("x, y'den kucuktur ve 0'dan buyuktur.\n");
        
//     }
//     printf("\n\n");
//     return 0;
// }

// int main() {        // Gaz basinci hesaplama
//     float pressure, constatR;
//     int numberOfMoles, volume,heat;
//     constatR = 0.082; // ideal gaz sabiti

//     printf("Kabin hacmini giriniz (litre): ");
//     scanf("%d", &volume);
//     printf("Sicakligi giriniz (Celsius): ");
//     scanf("%d", &heat);
//     printf("Mol sayisini giriniz: ");
//     scanf("%d", &numberOfMoles);

//     pressure = (numberOfMoles * constatR * heat) / volume;
//     printf("%d hacimli kaptaki gazin basinci:%f\n\n", volume, pressure);
//     return 0;
// }

// int main() {    // Elektrik faturasi hesaplama
//     int i, fatura_miktari, harcanan_elektrik, birim_fiyati, abonelik_ucret, enflasyon_orani;
//     i = 1;
//     enflasyon_orani = 10; // Aylik enflasyon orani %10
    
//     printf("Harcanan elektrik miktarini giriniz (kWh): ");
//     scanf("%d", &harcanan_elektrik);
//     printf("Elektrik birim fiyatini giriniz (TL/kWh): ");
//     scanf("%d", &birim_fiyati);
//     printf("Abonelik ucretini giriniz (TL): ");
//     scanf("%d", &abonelik_ucret);

//     fatura_miktari = (harcanan_elektrik * birim_fiyati) + abonelik_ucret;
//     printf("1. Ay fatura miktari: %d TL\n", fatura_miktari);

//     for (i = 2; i <= 12; i++) {
//         fatura_miktari += (fatura_miktari * enflasyon_orani) / 100; // Enflasyon etkisi
//         printf("%d. Ay fatura miktari: %d TL\n", i, fatura_miktari);
//     }
//     return 0;
// }

// int main() { // Basamak degeri toplami hesaplama
//     int deger, sonuc;

//     printf("Bir sayi giriniz: ");
//     scanf("%d", &deger);

//     sonuc = 0;
//     while (deger != 0) {        // Sayi 0 olmadigi surece dongu devam eder
//         sonuc += deger % 10;    // Son basamagi al ve sonuca ekle
//         deger /= 10;            // Son basamagi at ve degeri guncelle   
//     }
//     printf("Toplam: %d\n", sonuc);
//     return 0;
// }

// int main () {   // Sinavi gecme durumu hesaplama
//     int vize1, vize2, final, ortalama;

//     printf("1. Vize notunu giriniz: ");
//     scanf("%d", &vize1);
//     printf("2. Vize notunu giriniz: ");
//     scanf("%d", &vize2);
//     printf("Final notunu giriniz: ");
//     scanf("%d", &final);

//     ortalama = (vize1 * 0.3) + (vize2 * 0.3) + (final * 0.4);

//     if (ortalama >= 50) {
//         printf("Tebrikler! Sinavi gectiniz.\n");
//     } else {
//         printf("Maalesef, sinavi gecemediniz.\n");
//     }
//     return 0;

// }

// int main(){ // if - elsenin kisa yazimi

//     int sayi;
//     printf("Bir sayi giriniz: ");
//     scanf("%d", &sayi);
//     (sayi % 2 == 0) ? printf("Sayi cift\n") : printf("Sayi tek\n");
       
//     // ? operatoru, kosula bagli olarak iki farkli ifadeyi secmeye yarar. Kosul dogruysa ilk ifade, yanlissa ikinci ifade calistirilir.
//     // Bu ornekte, sayi ciftse "Sayi cift" yazdirilir, tekse "Sayi tek" yazdirilir. 
//     printf("\n\n");
//     return 0;

// }

// int main () { // Kitap siparisinde indirim hesaplama
//     int bookprice, orderQuantity;
//     float discountRate, noDiscountPrice, discountPrice, sum;
//     bookprice = 20;
//     orderQuantity = 0;
//     printf("Kac adet kitap siparis etmek istiyorsunuz? ");
//     scanf("%d", &orderQuantity);
//     if (orderQuantity >= 60) {
//         discountRate = 0.30;
//     } else {
//         if (orderQuantity >= 30 && orderQuantity < 60) {
//             discountRate = 0.20;
//         } else if (orderQuantity >= 10 && orderQuantity < 30) {
//             discountRate = 0.12;
//         } else {
//             discountRate = 0.01;
//         } 
//     }
//     noDiscountPrice = bookprice * orderQuantity;
//     discountPrice = noDiscountPrice * discountRate;
//     sum = noDiscountPrice - discountPrice;
//     printf("Indirimli fiyat: %.2f\n", sum);

//     return 0;
// }