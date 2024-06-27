#include <LiquidCrystal_I2C.h>

#include <Servo.h>
Servo giris,cikis;
LiquidCrystal_I2C lcd(0x27,16,2);

//Akıllı Otopark Projesi
//Giriş Otopark (1)
const int tr_pin1 = 8;
const int ec_pin1 = 6;

int sure1;
int mesafe1;
//Çıkış Otopark (2)
const int tr_pin2 = 13;
const int ec_pin2 = 12;

int sure2;
int mesafe2;

int arabaSayac = 0;

void setup() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  pinMode(tr_pin1 , OUTPUT);
  pinMode(ec_pin1 , INPUT);
  
   pinMode(tr_pin2 , OUTPUT);
  pinMode(ec_pin2 , INPUT);

  giris.attach(10);
  cikis.attach(11);
  Serial.begin(9600);
  
}
void loop() {
int girisMesafesi = girisMesafe();
if(girisMesafesi<10){
  giris.write(90);

  arabaSayac++;
    delay(3000);
  //Kontrol Yeri kod fallback
  Serial.print("ic");
  Serial.println(girisMesafesi);
  Serial.print("arac:");
  Serial.println(arabaSayac);
}
else{
  giris.write(0);
  Serial.print("dıs");
  Serial.println(girisMesafesi);
}

int cikisMesafesi = cikisMesafe();
if(cikisMesafesi<10){
  cikis.write(90);

  arabaSayac--;
    delay(3000);
  //Kontrol Yeri kod fallback
  Serial.print("ic");
  Serial.println(cikisMesafesi);
  Serial.print("arac:");
  Serial.println(arabaSayac);
}
else{
  cikis.write(0);
  Serial.print("dıs");
  Serial.println(cikisMesafesi);
}

if(arabaSayac<0){
  arabaSayac=0;
}
if(arabaSayac==8){
//Otopark Full
  while(1){
    if(cikisMesafe()<10){
      break;
    }
  }
  
}
lcd.setCursor(0,0); // İlk satırın başlangıç noktası
lcd.print("AKILLI OTOPARK"); 

lcd.setCursor(0,1); // İlk satırın başlangıç noktası
lcd.print("Araba Sayisi:"); 

lcd.setCursor(14,1); // İlk satırın başlangıç noktası
lcd.print(arabaSayac); 


}
int girisMesafe(){
  digitalWrite(tr_pin1 , HIGH);
  delayMicroseconds(1000);
  digitalWrite(tr_pin1 , LOW);
  sure1 = pulseIn(ec_pin1 , HIGH);
  mesafe1 = (sure1 / 2) / 29.1;
  return mesafe1;
  
  /*int yakinlik1 = map(mesafe1, 0, 100, 1, 4);
  Serial.print(" cisme olan uzaklık 1= ");
  Serial.println(mesafe1);
  Serial.println("------------------");*/
}
int cikisMesafe(){
  digitalWrite(tr_pin2 , HIGH);
  delayMicroseconds(1000);
  digitalWrite(tr_pin2 , LOW);
  sure2 = pulseIn(ec_pin2 , HIGH);
  mesafe2 = (sure2 / 2) / 29.1;
  return mesafe2;
  /*int yakinlik2 = map(mesafe2, 0, 100, 1, 4);
  Serial.print(" cisme olan uzaklık 2= ");
  Serial.println(mesafe2);
  Serial.println("------------------");*/
}
