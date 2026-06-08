### Swift Basics
---

Var vs Let kullanim farki

```swift
// var — sürekli değişen şeyler
var mevcutMesafe: Double = 0.0      // her ölçümde güncellenir
var alarmAktif: Bool = false         // açılıp kapanır
var watchBaglimi: Bool = false       // bağlantı durumu değişir

// let — sabit kalan şeyler
let uygulamaAdi: String = "GuardianApp"
let minimumMesafe: Double = 3.0      // hiç değişmez
let maksimumMesafe: Double = 30.0    // hiç değişmez

```

* Swift'in Altın Kuralı
Her şeyi önce let yaz. Değiştirmen gerekirse var yap. Neden? Xcode bile bunu söyler —> var tanımlayıp hiç değiştirmezsen sarı uyarı verir:

Tip belirtme ;

```swift
// Tip belirtmek zorunlu değil — Swift otomatik anlar
var mesafe = 10.0       // Double olarak algılar
let isim = "Guardian"   // String olarak algılar
var aktif = true        // Bool olarak algılar

// Ama başlangıç değeri yoksa tip yazmak zorundasın
var gelecekMesafe: Double       // değer sonra atanacak
var cihazIsmi: String?          // optional — sonra açıklayacağız

```

Opsiyonlu Degerler
* Bluetooth bağlantısı bazen yok. Watch bazen bağlı değil. Böyle durumlarda değer nil olur — yani ortada yok. Swift bunu özel bir tip olarak tanımlar: String?, Double?, Bool?

```swift
// Normal String — kesinlikle bir değeri var
var isim: String = "Guardian"

// Optional String — değeri olabilir ya da olmayabilir
var cihazIsmi: String? = nil
```
* Optional'ı doğrudan kullanamazsın, önce içini açman gerekir:
```swift
var watchIsmi: String? = nil

// Henüz nil — bu blok çalışmaz
if let isim = watchIsmi {
    print("Bağlandı: \(isim)")
} else {
    print("Watch bağlı değil")
}

// Watch bağlandı, değer geldi
watchIsmi = "Timu'nun Watch'ı"

// Artık bu blok çalışır
if let isim = watchIsmi {
    print("Bağlandı: \(isim)")   // ✅ Bağlandı: Timu'nun Watch'ı
}
```