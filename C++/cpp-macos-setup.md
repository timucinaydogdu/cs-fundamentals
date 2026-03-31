# macOS'ta C++ Geliştirme Ortamı Kurulumu

Platform: macOS (Apple Silicon — M1/M2/M3)

# PlatformIO Guide

VS Code üzerinde Arduino geliştirme için PlatformIO kullanım kılavuzu.

---

## İçindekiler

- [1. Kurulum](#1-kurulum)
- [2. Yeni Proje Oluşturma](#2-yeni-proje-oluşturma)
- [3. Proje Yapısı](#3-proje-yapısı)
- [4. Temel Kullanım](#4-temel-kullanım)
- [5. Kütüphane Yükleme](#5-kütüphane-yükleme)
- [6. Seri Port İzleme](#6-seri-port-i̇zleme)
- [7. Kısayollar](#7-kısayollar)

---

## 1. Kurulum

VS Code → Extensions → Şunu ara:

```
platformio.platformio-ide
```

Install → VS Code'u yeniden başlat.

Sol menüde PlatformIO simgesi (karınca ikonu) belirirse kurulum başarılı.

---

## 2. Yeni Proje Oluşturma

1. Sol menüde PlatformIO ikonuna tıkla
2. **PIO Home** → **New Project**
3. Şu bilgileri gir:

| Alan | Değer |
|------|-------|
| Name | proje-adi |
| Board | Arduino Uno |
| Framework | Arduino |
| Location | istediğin klasör |

4. **Finish** — PlatformIO gerekli dosyaları otomatik indirir (ilk seferinde birkaç dakika sürer)

---

## 3. Proje Yapısı

```
proje-adi/
├── src/
│   └── main.cpp        ← kodunu buraya yaz
├── lib/                ← kütüphaneler
├── include/            ← header dosyaları
├── test/               ← testler
└── platformio.ini      ← proje ayarları
```

`platformio.ini` içeriği Arduino Uno için:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
```

---

## 4. Temel Kullanım

`src/main.cpp` dosyası her projede şu yapıyla başlar:

```cpp
#include <Arduino.h>

void setup() {
    // Başlangıç ayarları — bir kez çalışır
}

void loop() {
    // Sürekli çalışan döngü
}
```

### Kodu Karta Yükleme

Arduino'yu USB ile bağla, sonra:

- Alt çubukta **→ (Upload)** ikonuna tıkla
- veya `Ctrl + Alt + U`

### Derleme (Yüklemeden)

- Alt çubukta **✓ (Build)** ikonuna tıkla
- veya `Ctrl + Alt + B`

---

## 5. Kütüphane Yükleme

**Yöntem 1 — PIO Home üzerinden:**
1. PlatformIO ikonu → Libraries
2. Kütüphane adını ara
3. **Add to Project** → projeyi seç

**Yöntem 2 — platformio.ini üzerinden:**

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps =
    adafruit/DHT sensor library
    adafruit/Adafruit Unified Sensor
```

Dosyayı kaydettiğinde PlatformIO otomatik indirir.

---

## 6. Seri Port İzleme

Sensör verilerini veya debug çıktılarını görmek için:

- Alt çubukta **elektrik prizi (Serial Monitor)** ikonuna tıkla
- veya `Ctrl + Alt + S`

Baud rate kodda ne yazdıysan onu seç:

```cpp
void setup() {
    Serial.begin(9600);  // baud rate
}

void loop() {
    Serial.println("Merhaba");
    delay(1000);
}
```

---

## 7. Kısayollar

| İşlem | Kısayol |
|-------|---------|
| Derle | `Ctrl + Alt + B` |
| Karta yükle | `Ctrl + Alt + U` |
| Serial monitor | `Ctrl + Alt + S` |
| Temizle | `Ctrl + Alt + C` |
| Test çalıştır | `Ctrl + Alt + T` |

---

## 1. Compiler Kurulumu

macOS'ta C++ derlemek için Xcode Command Line Tools gerekir. Terminal'i aç ve şu komutu çalıştır:

```bash
xcode-select --install
```

Ekrana bir kurulum penceresi gelir, **"Install"** butonuna tıkla ve tamamlanmasını bekle.

Kurulum tamamlandıktan sonra doğrula:

```bash
g++ --version
```

Şuna benzer bir çıktı gelirse kurulum başarılıdır:

```
Apple clang version 15.0.0 (clang-1500.0.29.2)
Target: arm64-apple-darwin23.0.0
```

---

## 2. VSCode Extension Kurulumu

1. VSCode'u aç
2. Sol kenar çubuğunda **Extensions** ikonuna tıkla ya da `Cmd+Shift+X` kısayolunu kullan
3. Arama kutusuna **C/C++ Extension Pack** yaz
4. Microsoft tarafından yayınlananı seç ve **Install** butonuna tıkla

Bu extension paketi şunları içerir:
- C/C++ — kod renklendirme, hata gösterme
- C/C++ Themes — tema desteği
- CMake Tools — proje yönetimi

---

## 3. Build Task Kurulumu

Bu ayar sayesinde `Cmd+Shift+B` kısayolu ile açık olan `.cpp` dosyasını otomatik derleyip çalıştırabilirsin.

### Adım 1: Task oluştur

Herhangi bir `.cpp` dosyası açıkken:

`Cmd+Shift+P` → arama kutusuna **"Tasks: Configure Default Build Task"** yaz → seç → **"C/C++: g++ build active file"** seç

`.vscode/tasks.json` dosyası otomatik oluşur.

### Adım 2: tasks.json dosyasını düzenle

Oluşan `tasks.json` dosyasını aç ve tüm içeriği sil, yerine şunu yapıştır:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build and run",
            "type": "shell",
            "command": "g++ ${file} -o ${fileDirname}/${fileBasenameNoExtension} && ${fileDirname}/${fileBasenameNoExtension}",
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Kaydet: `Cmd+S`

### Nasıl çalışır?

| Değişken | Anlamı |
|----------|--------|
| `${file}` | Şu an açık olan `.cpp` dosyasının tam yolu |
| `${fileDirname}` | Dosyanın bulunduğu klasör |
| `${fileBasenameNoExtension}` | Uzantısız dosya adı (ör: `main`) |

Yani `main.cpp` açıkken `Cmd+Shift+B` yapınca şunu çalıştırır:
```bash
g++ main.cpp -o main && ./main
```

---

## 4. Terminal Fonksiyon Kurulumu

Bu yöntemle terminalde `cpp dosyaadi.cpp` yazarak herhangi bir dosyayı derleyip çalıştırabilirsin.

> ⚠️ **Önemli:** `run` ismi Oh My Zsh veya pluginler tarafından kullanıldığı için çakışma yaratır. Bunun yerine `cpp` fonksiyon adını kullan.

> ⚠️ **Önemli:** `alias` sözdizimi zsh'da fonksiyon tanımlamak için çalışmaz. Aşağıdaki gibi düzgün fonksiyon sözdizimini kullan.

### Adım 1: .zshrc dosyasını aç

```bash
code ~/.zshrc
```

### Adım 2: Fonksiyonu ekle

Dosyanın en altına şunu ekle:

```bash
# C++ aliases
cpp() {
    g++ "$1" -o out && ./out
}
```

Kaydet: `Cmd+S`

### Adım 3: Değişikliği uygula

```bash
source ~/.zshrc
```

Hata mesajı gelmezse kurulum başarılıdır.

---

## Kullanım

### Yöntem 1 — VSCode kısayolu (dosya adından bağımsız)

Herhangi bir `.cpp` dosyası açıkken:

```
Cmd+Shift+B
```

Dosyayı otomatik derler ve terminalde çalıştırır.

### Yöntem 2 — Terminal (dosya adı parametre olarak verilir)

```bash
cpp dosya.cpp
cpp main.cpp
cpp odev.cpp
```

---

## Test

Kurulumu test etmek için `test.cpp` adında bir dosya oluştur:

```cpp
#include <iostream>

int main() {
    std::cout << "Kurulum basarili!" << std::endl;
    return 0;
}
```

Terminalde çalıştır:

```bash
cpp test.cpp
```

Çıktı:

```
Kurulum basarili!
```

---

## Not: Jupyter Notebook ile C++

xeus-cling paketi **Apple Silicon üzerinde çalışmıyor** (osx-arm64 desteği yok).
VSCode + Terminal kombinasyonu her durumda stabil çalışır, Jupyter'a gerek yoktur.
