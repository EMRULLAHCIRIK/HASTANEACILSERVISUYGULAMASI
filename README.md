# Acil Servis Sistemi

Bu proje, bir hastanenin acil servis ve çocuk acil servisi için hasta yönetimi ve öncelik sırasına göre hasta ekleme işlevselliğini sağlayan bir C programıdır. Program, hasta bilgilerini alır ve belirli bir öncelik sırasına göre acil servislere (Acil Servis ve Çocuk Acil) hasta ekler. Her hasta için benzersiz bir reçete numarası oluşturulurken, öncelik sırasına göre listeleme yapılabilir.

## Proje Özeti

Bu proje, acil servis ve çocuk acil servisinde çalışan bir sistemin temel fonksiyonlarını simüle eder. Sistemde hastalar, acil servise geldiklerinde yaş ve önceliklerine göre sıralanır. Ayrıca, her hasta için reçete numarası atanır ve bu numara hasta kaydının bir parçası olarak saklanır.

## Kullanım

1. **Hasta Ekleme:** Yeni bir hasta eklemek için gerekli bilgiler (isim, soyisim, TC kimlik no, yaş, cinsiyet, şikayet, öncelik) girilir. Hastaların yaşı 18'den küçükse, çocuk acil servisinde yer alırken, 18 ve üzeri yaştakiler acil serviste kaydedilir.
   
2. **Acil Servis Hastalarını Listeleme:** Acil servise eklenmiş hastalar öncelik sırasına göre listelenebilir.

3. **Çocuk Acil Servis Hastalarını Listeleme:** Çocuk acil servisine eklenmiş hastalar, yine öncelik sırasına göre listelenebilir.

## Özellikler

- **Hasta Ekleme:** Hasta adı, soyadı, TC kimlik numarası, yaş, cinsiyet, şikayet ve öncelik bilgileri alır. Hastalar, çocuk veya yetişkin olmalarına göre ilgili servise eklenir.
- **Öncelik Sırası:** Hastalar, acil (1), çok acil (2) veya normal (3) öncelik sırasına göre eklenir ve listelenir.
- **Reçete Numarası:** Her hasta için benzersiz bir reçete numarası oluşturulur.
- **Listeleme:** Sistemdeki hastalar, her iki servis için de öncelik sırasına göre listelenebilir.

## Gereksinimler

- C derleyicisi (Dev-C++ veya benzeri bir IDE kullanılabilir)
- Standart C kütüphaneleri

## Kurulum

1. **Dev-C++ veya başka bir C derleyicisi** kullanarak projeyi açın.
2. Kodu derleyip çalıştırarak, hasta ekleme ve listeleme işlemlerini test edebilirsiniz.

## Menü Seçenekleri

1. **Hasta Ekle:** Yeni hasta bilgilerini girerek hasta ekleyebilirsiniz.
2. **Acil Servisteki Hastaları Listele:** Acil servisteki hastaları, öncelik sırasına göre listeleyebilirsiniz.
3. **Çocuk Acil'deki Hastaları Listele:** Çocuk acil servisteki hastaları, öncelik sırasına göre listeleyebilirsiniz.
4. **Çıkış:** Programdan çıkmak için bu seçeneği kullanabilirsiniz.

## Örnek Kullanım

```bash
--- Acil Servis Sistemi ---
1. Hasta Ekle
2. Acil Servisteki Hastalari Listele
3. Cocuk Acil'deki Hastalari Listele
4. Cikis
Secim: 1
Hasta Adi: Yaşar
Hasta Soyadi: Emrullah
TC Kimlik No: 11159500135
Yas: 17
Cinsiyet (Erkek/Kadin): Erkek
Sikayet: Grip
Oncelik (1: Cok Acil, 2: Acil, 3: Normal): 3
Hasta basariyla eklendi (Cocuk Acil)! Recete No: 500, Oncelik: Normal

--- Acil Servis Sistemi ---
1. Hasta Ekle
2. Acil Servisteki Hastalari Listele
3. Cocuk Acil'deki Hastalari Listele
4. Cikis
Secim: 2

--- Acil Servis Hastalari ---
Isim: Yaşar Emrullah, TC: 11159500135, Yas: 17, Cinsiyet: Erkek, Oncelik: Normal, Recete No: 500
