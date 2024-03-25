
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>


int scanTime = 2;
int sum1 = 0;
int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;
int sum6 = 0;

BLEScan* pBLEScan;
std:: string Add1 = "72:64:6C:13:00:8F";
std:: string Add2 = "72:64:6C:13:00:91";
std:: string Add3 = "72:64:6C:13:00:A5";
std:: string Add4 = "72:64:6C:13:00:8A";
std:: string Add5 = "72:64:6C:13:00:A1";
std:: string Add6 = "72:64:6C:13:00:95";

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      BLEAddress Addx = advertisedDevice.getAddress();
      if(Addx==Add1)
      {
        sum1 = advertisedDevice.getRSSI();
      }
      if(Addx==Add2)
      {
        sum2 = advertisedDevice.getRSSI();
      }
      if(Addx==Add3)
      {
        sum3 = advertisedDevice.getRSSI();
      }
      if(Addx==Add4)
      {
        sum4 = advertisedDevice.getRSSI();
      }
      if(Addx==Add5)
      {
        sum5 = advertisedDevice.getRSSI();
      }
      if(Addx==Add6)
      {
        sum6 = advertisedDevice.getRSSI();
      }
      if (sum1 != 0 && sum2 != 0 && sum3 != 0 && sum4 != 0 && sum5 !=0 && sum6!= 0 )
      {
        Serial.printf("%d %d %d %d %d %d\n",sum1,sum2,sum3,sum4,sum5,sum6);
      }
    }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Scanning...");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); 
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  

  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi...");
  // }
  // Serial.println("Connected to WiFi");
  
  // Serial.println("Connecting to server...");
  // client.connect(serverIP, serverPort); 

}

void loop() {

  static int count = 0;  
  if (count < 20) {
      count++;  
      BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
      Serial.printf("%d,%d,%d,%d,%d,%d\n",sum1,sum2,sum3,sum4,sum5,sum6);
      // client.printf("%d,%d,%d,%d,%d,%d\n",sum1,sum2,sum3,sum4,sum5,sum6);
  }
  else {
    Serial.println("Scan done!");
    while(1); 
  }
  sum1 = 0;
  sum2 = 0;
  sum3 = 0;
  sum4 = 0;
  sum5 = 0;
  sum6 = 0;
  delay(500);
}
