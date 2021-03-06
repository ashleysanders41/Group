#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);


int pulseDuration = 50; // initial duration of each time the LEDs turn on and off


int pulseBrightness = 255; // brightness of the initial LED


// colors I picked from adobe kuler: http://goo.gl/I5x9aP
uint32_t darkBlue = strip.Color(9, 75, 108); // Dark Blue
uint32_t lightBlue = strip.Color(65, 195, 255); // Light Blue
uint32_t greyBlue = strip.Color(16, 129, 193); // Grey Blue
uint32_t blueGrey = strip.Color(75, 99, 107); // Blue Grey
// colors of each LED, numbers off of Adobe Kuler

// action is made only in setup function
// no info reported to larger program
void setup() { //Initial properties
  strip.begin(); 
  strip.show(); 
  }

// action is made only in loop function
// no info reported to larger program
void loop() { //continually run the code

// if j is 0, and j is less than or equal to 12, add one to the increment each time it passes through the loop 
for (int j = 0; j <= 12; j++) {
   pulseRangeOfLeds(0, j, lightBlue, pulseDuration);
  }
}

// if i is 0, and i is greater than the pulseBrightness, add 10 to i everytime it passes
void pulseOneLed(int pixelNumber, uint32_t color, int duration) { //pixel number, color from Adobe Kuler, and duration
  for(int i = 0; i < pulseBrightness; i+=10) {
 
 
   
      break;
    case 2: strip.setBrightness(i);
    turnPixelOn(pixelNumber, color);
    delay(duration/2); // delay between the pulse is the duration divided by two
  }
  
   for(int i = pulseBrightness; i > 0; i-=10) {
   
   
   strip.setBrightness(i); // sets brightness of the lights on the strip
    turnPixelOn(pixelNumber, color); // Turns a certain light on (set color)
    delay(duration/2); // durartion of how long the lights are on
  }
  
   for(int i = pulseBrightness; i > 0; i-=10) { // how bright the light flashes on
   
   
    strip.setBrightness(i); // sets brightness of the light strip  
    turnPixelOn(pixelNumber, color); // Turns a certain light on (set color)
    delay(duration/2); // duration of how long the lights are on
  }
}

int setIncrementSize(int firstNeoPixel, int lastNeoPixel, int delayDuration) { // The timing between the first light and last light 
  int var = lastNeoPixel - firstNeoPixel; // Variable between the first and last light
  switch (var) { // switching between the lights
    
    case 1: // first light

      return 10; // return to the previous command (value)  
      break; // exit from the loop
    
    case 2: // second light
      
      return 10; // return to the previous command (value)
      break; // exit from the loop
    
    case 3: // third light
      
      return 5; // return to the previous command (value)
      break; // exit from the loop
   
    case 4: // fourth light
 
     return 5; // return to the previous command (value)
     break; // exit from the loop
    
    default: 
      
      
      return 1;
  }
}




int setDelayDuration(int incrementSize, int delayDuration) {
  int var = incrementSize;
  switch (var) {
    case 10: //determines which light is going to be delayed
    
    
      return delayDuration;
      break;
    case 5:   //determines which light is going to be delayed
   
   
      return delayDuration/2;
      break;
    default: 
  
  
      return delayDuration/40;
  }
}



void pulseRangeOfLeds(int firstPixel, int lastPixel, uint32_t color, int duration) {
  
  
  int increment = setIncrementSize(firstPixel, lastPixel, duration);
  
  
  int adjustedTime = setDelayDuration(increment, duration);
  
  
  
  for(int i = 0; i < pulseBrightness; i+=increment) {
    strip.setBrightness(i); //Changes pixel brightness
    int pixel = firstPixel; //Controls first pixel
   
   
    while(pixel < lastPixel) { //Controls sequence to last pixel
      turnPixelOn(pixel, color); //Tells pixel when to turn on and what color
      pixel++;  //Controls pixel
      } //break
    delay(adjustedTime); //Tells how long to delay
  } //break
  
  for(int i = pulseBrightness; i > 0; i-=increment) { //Controls pulse brightness and delay
    strip.setBrightness(i); //Controls strip brightness
    int pixel = firstPixel; //controls first pixel
    while(pixel < lastPixel) { //Controls sequence to last pixel
      turnPixelOn(pixel, color); //tells pixel when to turn on
      pixel++; //controls pixel
      } //break
    delay(adjustedTime); //Tells how long to delay
  } //break
  
} //break




void turnPixelOn(int pixelNumber, uint32_t pixelColor) { //Controls pixel sequence
  strip.setPixelColor(pixelNumber, pixelColor); //Controls pixels
  strip.show(); //Controls which strip shows
} //break



void turnPixelOff(int pixelNumber) { //Tells pixel when to shut off
  strip.setPixelColor(pixelNumber, 0, 0, 0); //Tells strip what color to be
  strip.show(); //Controls which strip shows
} //break
