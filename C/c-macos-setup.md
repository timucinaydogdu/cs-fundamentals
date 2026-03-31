# macOS'ta C Geliştirme Ortamı Kurulumu

Platform: macOS (Apple Silicon — M1/M2/M3)

---

## 1. Compiler Kurulumu

macOS'ta C derlemek için Xcode Command Line Tools gerekir. Terminal'i aç ve şu komutu çalıştır:

```bash
xcode-select --install
```

Ekrana bir kurulum penceresi gelir, **"Install"** butonuna tıkla ve tamamlanmasını bekle.

Kurulum tamamlandıktan sonra doğrula:

```bash
gcc --version
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

---

## 3. Build Task Kurulumu

Bu ayar sayesinde `Cmd+Shift+B` kısayolu ile açık olan dosyayı otomatik derleyip çalıştırabilirsin. Hem `.c` hem `.cpp` dosyalarını otomatik tanır.

### Adım 1: Task oluştur

Herhangi bir `.c` dosyası açıkken:

`Cmd+Shift+P` → **"Tasks: Configure Default Build Task"** yaz → seç → **"C/C++: gcc build active file"** seç

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
            "command": "if [[ '${file}' == *.cpp ]]; then g++ '${file}' -o '${fileDirname}/${fileBasenameNoExtension}' && '${fileDirname}/${fileBasenameNoExtension}'; else gcc '${file}' -o '${fileDirname}/${fileBasenameNoExtension}' && '${fileDirname}/${fileBasenameNoExtension}'; fi",
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

| Dosya | Derleyici |
|-------|-----------|
| `.c` | `gcc` |
| `.cpp` | `g++` |

Tek task her ikisini otomatik ayırt eder.

---

## 4. Terminal Fonksiyon Kurulumu

Bu yöntemle terminalde `c dosyaadi.c` yazarak herhangi bir dosyayı derleyip çalıştırabilirsin.

> ⚠️ **Önemli:** `alias` sözdizimi zsh'da fonksiyon tanımlamak için çalışmaz. Aşağıdaki gibi düzgün fonksiyon sözdizimini kullan.

### Adım 1: .zshrc dosyasını aç

```bash
code ~/.zshrc
```

### Adım 2: Fonksiyonu ekle

Dosyanın en altına şunu ekle:

```bash
# C aliases
c() {
    gcc "$1" -o out && ./out
}
```

Kaydet: `Cmd+S`

### Adım 3: Değişikliği uygula

```bash
source ~/.zshrc
```

Hata mesajı gelmezse kurulum başarılıdır.

---

## 5. .gitignore Ayarı

Derleme sonucu oluşan dosyalar git'e eklenmemeli. Proje klasöründe `.gitignore` dosyasına şunları ekle:

```bash
echo "out" >> .gitignore
echo "*.dSYM" >> .gitignore
```

---

## Kullanım

### Yöntem 1 — VSCode kısayolu (dosya adından bağımsız)

Herhangi bir `.c` dosyası açıkken:

```
Cmd+Shift+B
```

Dosyayı otomatik derler ve terminalde çalıştırır.

### Yöntem 2 — Terminal (dosya adı parametre olarak verilir)

> Terminalde önce dosyanın bulunduğu klasöre geçmeyi unutma.

```bash
cd ~/CodeS/cs-fundamentals/C/basics
c dosya.c
c main.c
```

---

## Test

`test.c` adında bir dosya oluştur:

```c
#include <stdio.h>

int main() {
    printf("Kurulum basarili!\n");
    return 0;
}
```

Terminalde çalıştır:

```bash
c test.c
```

Çıktı:

```
Kurulum basarili!
```

---

## Notlar

- `c` komutu terminalde **dosyanın bulunduğu klasörden** çalıştırılmalıdır
- `Cmd+Shift+B` ise dosya nerede olursa olsun çalışır
- C dosyaları `.c`, C++ dosyaları `.cpp` uzantısıyla kaydedilmeli
