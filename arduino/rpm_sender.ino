 #include <SPI.h>
#include <mcp2515.h>
/*SAMD core*/
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
    #define SERIAL SerialUSB
#else
    #define SERIAL Serial
#endif
#define slave 0x0F6
#define PIN_OUT 3
#define CUSTOM_DELAY 100
#define lmillis() ((long)millis())
// struct can_frame recvMsg;
struct can_frame canMsg;
const int SPI_CS_PIN = 9;
MCP2515 mcp2515(SPI_CS_PIN); // Set CS pin
long lastAction;
volatile int count = 0;

void packFloat(byte *data, float value) {
    byte *valueBytes = (byte*)&value;  
    for (int i = 0; i < sizeof(float); i++) {
        data[i] = valueBytes[i];
        Serial.print(data[i]);
    }
}

void isrCount()
{
    count++;
}
void setup() {
    canMsg.can_id = slave;
    canMsg.can_dlc = 4;
    canMsg.data[0]= 0x00;
    canMsg.data[1]= 0x00;
    canMsg.data[2]= 0x00;
    canMsg.data[3]= 0x00;

    while(!Serial){};
    SERIAL.begin(115200);
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_16MHZ);  //header file change
    mcp2515.setNormalMode();
    SERIAL.println("CAN BUS Shield init ok!");
    pinMode(PIN_OUT, INPUT);
    lastAction = lmillis() + CUSTOM_DELAY;
    attachInterrupt(digitalPinToInterrupt(PIN_OUT), isrCount, RISING);
}
// unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
void loop() {
    if (lmillis() - lastAction >= 0) {
        detachInterrupt(digitalPinToInterrupt(PIN_OUT));
        lastAction = lmillis() + CUSTOM_DELAY;
        float div = 10;
        float rpm = (count*3) / div; //[rpm] 
        float speed = rpm*3.40; // [cm/s]
        Serial.println("div: "+ String(div));
        Serial.println("rpm: "+String(rpm));
        Serial.println("speed: "+String(speed));

        packFloat(canMsg.data, rpm);
        count = 0;
        attachInterrupt(digitalPinToInterrupt(PIN_OUT), isrCount, RISING);
    }
  
;
  mcp2515.sendMessage(&canMsg);
  //  Serial.println(canMsg);
   delay(100);
}
