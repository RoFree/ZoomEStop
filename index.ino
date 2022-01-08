#include <BleConnectionStatus.h>
#include <BleKeyboard.h>
#include <KeyboardOutputCallbacks.h>
int button = 15;
BleKeyboard bleKeyboard("ESP32STOP", "Ron", 100);
int stat = 1;
bool counter;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("On");
  bleKeyboard.begin();
  pinMode(button, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bleKeyboard.isConnected()){
   counter = digitalRead(button);
   Serial.println(counter);
   if(counter == 0 && stat == 0){
      emkill();
      Serial.println("estop pressed");
      stat = stat + 1;
      delay(20);
  }
  if (counter == 1){
    stat = 0;
  }
  delay(100);
  }
  else{
  Serial.println("No connection. 10 second timeout");
  delay(5000);
  }


}
void emkill(){
  Serial.println("estop!!!");
  bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.releaseAll();
   /// bleKeyboard.press('v');
    /// bleKeyboard.press(KEY_LEFT_ALT);
   /// bleKeyboard.releaseAll();
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press('a');
    bleKeyboard.releaseAll();
    Serial.println("done");
}
