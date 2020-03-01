#include <ThingerESP8266.h>

#define USERNAME "vutri500"
#define DEVICE_ID "ex1"
#define DEVICE_CREDENTIAL "$69IFReOn23#"
#define DEBUG 
#define SSID "TranYen"
#define SSID_PASSWORD "46512345"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  thing.add_wifi(SSID, SSID_PASSWORD);
  thing["led"] << [](pson& in){
  digitalWrite(LED_BUILTIN, in ? HIGH : LOW);
};
}
void loop() {
  thing.handle();
}
