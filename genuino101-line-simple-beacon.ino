/* LINE Simple Beacon https://github.com/line/line-simple-beacon/blob/master/README.ja.md */

#include <CurieBLE.h>

/*Frame Type */
#define FRAME_TYPE 0x02
/* HWID*/
#define HWID 0x01,0x06,0x6B,0x4F,0x7E
/* Measured TxPower */
#define MEASURED_TXPOWER 0x7F
/* Device Message */
#define DEVICE_MESSAGE 0x00

void setup() {

  BLEService lineService = BLEService("FE6F");
  BLECharacteristic characteristic("FE6F",BLERead|BLEBroadcast,20);

  BLE.begin();
  BLE.setAdvertisedService(lineService);
  lineService.addCharacteristic(characteristic);
  BLE.addService(lineService);
  characteristic.broadcast();

  uint8_t advdata[] = {
    FRAME_TYPE,
    HWID,
    MEASURED_TXPOWER,
    DEVICE_MESSAGE
  };
  characteristic.writeValue(advdata,sizeof(advdata));

  BLE.advertise();

}

void loop() {
  //empty
}
