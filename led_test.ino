#include <SPI.h>
#include <WiFi.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char ssid[] = "YASH";
char pass[]="inactive";

int moisPin = A1;
int ldrPin = A0;
int val;
String str1, str2, str3, z;
int ldrValue=0;
int moisValue=0;
int status = WL_IDLE_STATUS;
IPAddress server(184,106,153,149);

WiFiClient client;

void setup() {
  Serial.begin(9600); //sets serial port for communication
  lcd.begin(16,2);
}
void loop() {
  moisValue = 0;
  ldrValue = 0;
  ldrValue = analogRead(ldrPin);
  moisValue = analogRead(moisPin);

  // read the value from the sensor
  
  if(ldrValue<=120 && moisValue<=250){
    val=5;
    lcd.print("5 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 5 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
  else if(ldrValue<=120 && moisValue>250 && moisValue<=600){
    val=9;
    lcd.print("9 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 9 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
   else if(ldrValue<=120 && moisValue>600){
    val=15;
    lcd.print("15 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 15 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
   else if(ldrValue>120 && ldrValue<=300 && moisValue<=250){
    val=3;
    lcd.print("3 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 3 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
   else if(ldrValue>120 && ldrValue<=300 && moisValue>250 && moisValue<=600){
    val=7;
    lcd.print("7 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 7 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
  else if(ldrValue>120 && ldrValue<=300 && moisValue>600){
    val=13;
    lcd.print("13 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 13 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
  else if(ldrValue>300 && moisValue<=250){
    val=0;
    lcd.print("0 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 0 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
  else if(ldrValue>300 && moisValue>250 && moisValue<=600){
    val=4;
    lcd.print("4 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 4 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }
  else if(ldrValue>300 && moisValue>600){
    val=11;
    lcd.print("11 mins");
    lcd.setCursor(0, 1);
    Serial.println("Water duration 11 min");
    Serial.println(ldrValue);
    Serial.println(moisValue);
  }

  String x="GET /update?api_key=XA1UKIMZ9GM5CEZE&field1=";
  
  str1=String(ldrValue);
  str2=String(moisValue);
  str3=String(val);
  z=x+str1+"&field2="+str2+"&field3="+str3;
  Serial.println(z);
  status = WiFi.begin(ssid, pass);

  if(status != WL_CONNECTED) {
    WiFiClient client;
    delay (10000);
  }

  else {
    if(client.connect(server, 80)) {
      client.println(z);
      delay(18000);
      client.stop();
    }
  }
  delay(1000);
  lcd.clear();
}
