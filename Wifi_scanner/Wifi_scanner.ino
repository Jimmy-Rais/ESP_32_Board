/* 
 Wifi  scanner using ESP 32 in STA mode(Station mode,the ESP 32 acts as another client of the router)

 author:JIMMY-RAIS
*/
#include <WiFi.h>
int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(500);
Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scan start....");
 int n=WiFi.scanNetworks();
 if (n==0)
 {
  Serial.println("No networks found");
  }
  else {
 Serial.print(n);
  Serial.println(" Networks found ");
  for(i=0;i<n;i++)
  {
    Serial.print(i+1);
    Serial.print(".");
    Serial.print(WiFi.SSID(i));
    Serial.print("(");
    Serial.print(WiFi.RSSI(i));
    Serial.print(")");
    Serial.println((WiFi.encryptionType(i)==WIFI_AUTH_OPEN)? " Open":" Password required");
    Serial.println("Scan done");
    }
  }
  Serial.println("");
  delay(1000);
}
