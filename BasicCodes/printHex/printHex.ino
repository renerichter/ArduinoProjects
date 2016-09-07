void printHex(int num, int precision) {
     char tmp[16];
     char format[128];

     sprintf(format, "0x%%.%dX", precision);

     sprintf(tmp, format, num);
     Serial.println(tmp);
}

void setup()
{
       Serial.begin(9600);
       Serial.print("Setup: Examples of PrintHex usage\n\n");
}

void loop()
{
     printHex(375, 8);
     delay(1000);
}
