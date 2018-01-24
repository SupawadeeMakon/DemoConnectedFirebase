//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>




//Explicit ประกาศตัวแปร

//การกำหนดค่าคงที
#define wifiSSID "MastreEWTC_2.4G"    //String wifiSSID="";
#define wifiPassword "12345abcde"



void setup() {
  
//  การกำหนดช่องทางในการ monitor
  Serial.begin(9600);

//  การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSSID, wifiPassword);
  Serial.println("Start Find WiFi");  

  while(WiFi.status() != WL_CONNECTED) 
  {
    //ถ้า Condition Ture จะทำงานที่นี้
    Serial.print("=");
    delay(1000);
    
    }

//    ถ้ามาทำงานตรงนี้คือ Connected WiFi ได้แล้ว
  Serial.println();
  Serial.println("Success Connected WiFi");
  Serial.println(WiFi.localIP());

}//setup

void loop() {
//  Serial.println("Hello Supawadee");
//  delay(2000);






  
}//Loop


