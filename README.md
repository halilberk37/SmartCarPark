#Akıllı Otopark Projesi
Bu proje, Arduino kullanarak basit bir akıllı otopark sistemini simüle etmektedir. Proje, araçların giriş ve çıkışlarını kontrol ederek otoparktaki araç sayısını otomatik olarak saymakta ve bu bilgiyi bir LCD ekranda göstermektedir. Ayrıca, otopark dolduğunda giriş kapısını kapalı tutarak yeni araçların girmesini engellemektedir.

Özellikler
Araç Sayma: Ultrasonik sensörler kullanarak araçların giriş ve çıkışlarını algılar.
Servo Motor Kontrolü: Araç girişi ve çıkışı sırasında servo motorları kullanarak bariyerlerin açılıp kapanmasını sağlar.
LCD Ekran: Otoparktaki araç sayısını 16x2 LCD ekranda gösterir.
Otopark Dolu Uyarısı: Otopark kapasitesi dolduğunda yeni araçların girmesini engeller ve çıkış yapılana kadar bekler.
Bağlantı ve Pinler
Giriş Sensörü:
Trig Pin: 8
Echo Pin: 6
Çıkış Sensörü:
Trig Pin: 13
Echo Pin: 12
Servo Motorlar:
Giriş Servo: Pin 10
Çıkış Servo: Pin 11
LCD Ekran: I2C bağlantısı ile 0x27 adresinde 16x2 LCD ekran
Kod Açıklaması
Başlatma: LCD ekranı başlatır ve geri aydınlatmasını açar. Sensörlerin ve servo motorların pinlerini tanımlar.

Giriş ve Çıkış Kontrolü:

Araç giriş sensörü (tr_pin1 ve ec_pin1) aracılığıyla mesafeyi ölçer. Mesafe 10 cm'den az olduğunda giriş servo motorunu (giris) 90 derece açar ve araç sayacını bir arttırır.
Araç çıkış sensörü (tr_pin2 ve ec_pin2) aracılığıyla mesafeyi ölçer. Mesafe 10 cm'den az olduğunda çıkış servo motorunu (cikis) 90 derece açar ve araç sayacını bir azaltır.
Araç Sayısı: Araba sayısını 8 (otopark kapasitesi) üzerinde tutmaz, böylece kapasite dolduğunda yeni araç girişi engellenir.

LCD Ekran: Otoparktaki toplam araç sayısını ve "AKILLI OTOPARK" mesajını LCD ekranda gösterir.

Fonksiyonlar: girisMesafe() ve cikisMesafe() fonksiyonları, ultrasonik sensörlerden mesafe verilerini okur ve hesaplar.
