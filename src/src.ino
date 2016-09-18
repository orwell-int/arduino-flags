#include <Adafruit_NeoPixel.h>

#define PIN_FLAG_1     2
#define NUMPIXELS_FLAG      24

Adafruit_NeoPixel pixelsFlag_1 = Adafruit_NeoPixel(NUMPIXELS_FLAG, PIN_FLAG_1, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixelsFlag_1.begin();
  pixelsFlag_1.setBrightness(255);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:  
  while (Serial.available() > 0) 
  {
    int red = Serial.parseInt();
    // do it again:
    int green = Serial.parseInt();
    // do it again:
    int blue = Serial.parseInt();

    Serial.print(red);
    Serial.print(green);
    Serial.println(blue);

    if (Serial.read() == '\n') {
      Serial.write("RGB info received\n");
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);

      lightFlag(pixelsFlag_1, red, green, blue);

      // print the three numbers in one string as hexadecimal:
      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.println(blue, HEX);
    }

  }
}


void lightFlag(Adafruit_NeoPixel& flag, int red, int green, int blue) {
  for (int i=0; i<NUMPIXELS_FLAG; i++) {
    flag.setPixelColor(i,flag.Color(red, green, blue)); 
    flag.show();
  }
}

void lightPixels(Adafruit_NeoPixel& neoPixel, uint32_t rgb, int numPixels) {

    for(int i=0;i<numPixels;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      neoPixel.setPixelColor(i, rgb);
        
      neoPixel.show(); // This sends the updated pixel color to the hardware.
  }
}
