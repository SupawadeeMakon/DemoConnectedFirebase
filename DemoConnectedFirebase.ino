//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Explicit ประกาศตัวแปร

//การกำหนดค่าคงที
#define wifiSSID "MastreEWTC_2.4G"    //String wifiSSID="";
#define wifiPassword "12345abcde"
//-------------------------------------------------
//การทำงานบนfirebase
#define firebaseHost "supawadeenodemcu.firebaseio.com"
#define firebaseKey  "q6iIgeARHkKbklWfTpUZ3mziiPaptX8XzS0yp6cr"
//-------------------------------------------------
int intIndex=0;




void setup() {
  
//  การกำหนดช่องทางในการ monitor
  Serial.begin(9600);
//-------------------------------------------------
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

//------------------------------------------------------
//  ส่วนของการเชื่อมต่อ Firebase 

  Firebase.begin(firebaseHost, firebaseKey);

}//setup

void loop() {
//  Serial.println("Hello Supawadee");
//  delay(2000);

//Check Connected Firebase
  Firebase.setInt("myTimes", intIndex);
  
  if (Firebase.failed()) {

    //    เมื่อไรก็ตามที่ไม่สามารถเข้า Firebase
    Serial.print("Connot Connected Firebase :...");
    Serial.println(Firebase.error());
    return;
    
    }

    Serial.print("Success Connected Firebase Times ==>");
    Serial.println(Firebase.getInt("myTimes"));

    intIndex = Firebase.getInt("myTimes");

    intIndex++;
    delay(500);


  
}//Loop


