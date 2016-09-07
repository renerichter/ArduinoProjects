//HYT939 Beispiel Sketch

#define HYT939_ADDR 0x28
#define LED_PIN 13

#include <Wire.h>

// used functions for testing
void printHex(int num, int precision) {
  char tmp[16];
  char format[128];

  sprintf(format, "0x%%.%dX", precision);

  sprintf(tmp, format, num);
  Serial.println(tmp);
}


void setup()
{
  //I2C Interface initialisieren,

  Wire.begin();
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("~System initialized~");
}

void loop() {

  //Skalierungsfaktoren laut Datenblatt
#define TFACTOR 99.2909
#define TDELTA  40.0
#define HFACTOR 163.83


  unsigned int traw;
  unsigned int hraw;

  double temp;
  double hum;
  int i;
  unsigned char buffer[4];

  //Messung starten
  /*
    Serial.print("Wire available:");
    Serial.print(Wire.available());
    Serial.print("\nHYT939-Address:");
    Serial.print(HYT939_ADDR);
  */
  Wire.beginTransmission(HYT939_ADDR); // transmit to device #44 (0x2c)
  Wire.endTransmission();     // stop transmitting

  //100ms warten
  delay(100);


  //4 Bytes vom Sensor lesen

  Wire.requestFrom(HYT939_ADDR, 4, true);
  //Serial.println("\nI'm here!");
  i = 0;


  while (Wire.available()) {

    char c = Wire.read();    // receive a byte as character

    buffer[i] = c;

    i++;

  }

  //Rohdaten aus Puffer lesen
  traw = (buffer[2] << 8) + buffer[3]; //buffer[2] sind höchstwertige 8bit der Temp., buffer[3] kommt nach [Acknowledge]-Bit > niedrigwertige 6Bit >> letzte 2 Bit müsse noch gelöscht werden
  hraw = (buffer[0] << 8) + buffer[1]; //entspricht: buffer[0] * 256 + buffer[1];
  /*
  Serial.print("\nI'm printing the buffer now:\n");
  for (int i = 0; i < 4; i++) {
    Serial.print("buffer[");
    Serial.print(i);
    Serial.print("]=");
    printHex(buffer[i], 4);

  }
  Serial.print("\nTemp Raw before conversion:");
  printHex(traw, 4);
  Serial.print("\nHum Raw before conversion:");
  printHex(hraw, 4);
  Serial.print("\nTemp Raw Vergleich:");
  printHex((buffer[2] << 8) + buffer[3],4);
  */
  //Daten laut Datenblatt maskieren
  
  /*Serial.print("\nTemp Raw before shift:");
  printHex(traw, 4);
  printHex((traw>>2)&0x3fff,4);
  */
  
  traw >>= 2; // throw away last two Bits of Temp.data
  traw &= 0x3fff;
  hraw &= 0x3fff;
  

  //Rohdaten ausgeben, zur eventuellen Fehlersuche
  /*
  Serial.print("\r\nTemp Raw:");
  //Serial.println(traw);
  printHex(traw, 4);
  Serial.print("Hum Raw:");
  //Serial.println(hraw);
  printHex(hraw, 4);
  */

  //Rohdaten Umrechnen
  temp = (double)traw / TFACTOR;
  temp = temp - TDELTA;


  hum = (double)hraw / HFACTOR;

  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print(';');

  Serial.print("Hum:");
  Serial.println(hum);
  Serial.print("\n");


  //LED Blinken
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);

  //Pause vor dem nächsten Durchlauf
  //Serial.read();
  delay(10000);
}





