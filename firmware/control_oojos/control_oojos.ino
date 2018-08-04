
#include <Adafruit_NeoPixel.h>
#include <TinyWire.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            3
#define NUMPIXELS      14

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte own_address = 10;


void setup() {


	
	// config TinyWire library for I2C slave functionality
	TinyWire.begin( own_address );
	// sets callback for the event of a slave receive
	TinyWire.onReceive( onI2CReceive );

 #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

   pixels.begin(); // This initializes the NeoPixel library.
}

void parpadeo (int tAbierto, int tCerrado, int R, int G, int B){
  for(int i=0;i<6;i++){
  /*---------- Ojo derecho ---------------------|---------------Ojo Izquierdo----------------------------------*/
    pixels.setPixelColor(6, pixels.Color(R,G,B));pixels.setPixelColor(13, pixels.Color(R,G,B));pixels.show();delay(250);  
    pixels.setPixelColor(5, pixels.Color(R,G,B));pixels.setPixelColor(12, pixels.Color(R,G,B));pixels.show();delay(250);
    pixels.setPixelColor(1, pixels.Color(R,G,B));pixels.setPixelColor(8, pixels.Color(R,G,B));pixels.show();delay(250);
    pixels.setPixelColor(0, pixels.Color(R,G,255));pixels.setPixelColor(7, pixels.Color(R,G,255));pixels.show();delay(250);
    pixels.setPixelColor(4, pixels.Color(R,G,B));pixels.setPixelColor(11, pixels.Color(R,G,B));pixels.show();delay(250);
    pixels.setPixelColor(2, pixels.Color(R,G,B));pixels.setPixelColor(9, pixels.Color(R,G,B));pixels.show();delay(250);
    pixels.setPixelColor(3, pixels.Color(R,G,B));pixels.setPixelColor(10, pixels.Color(R,G,B));pixels.show();delay(250);
    
  }
  delay(tCerrado);
/*----------------------------------------------|--------------------------------------------------------------*/
for(int i=0;i<6;i++){
    pixels.setPixelColor(3, pixels.Color(0,0,0));pixels.setPixelColor(10, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(4, pixels.Color(0,0,0));pixels.setPixelColor(9, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(2, pixels.Color(0,0,0));pixels.setPixelColor(11, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(0, pixels.Color(0,0,0));pixels.setPixelColor(7, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(5, pixels.Color(0,0,0));pixels.setPixelColor(8, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(1, pixels.Color(0,0,0));pixels.setPixelColor(12, pixels.Color(0,0,0));pixels.show();delay(250);
    pixels.setPixelColor(6, pixels.Color(0,0,0));pixels.setPixelColor(13, pixels.Color(0,0,0));pixels.show();delay(250);
    
}
    delay(tAbierto);
/*
     leds[6] = CRGB::Black; FastLED[6].showLeds(brillo);leds[13] = CRGB::Black; FastLED[13].showLeds(brillo);delay(t);
     leds[5] = CRGB::Black; FastLED[5].showLeds(brillo);leds[12] = CRGB::Black; FastLED[12].showLeds(brillo);delay(t);
     leds[1] = CRGB::Black; FastLED[1].showLeds(brillo);leds[8] = CRGB::Black; FastLED[8].showLeds(brillo);delay(t);
     leds[0] = CRGB::Black; FastLED[0].showLeds(brillo);leds[7] = CRGB::Black; FastLED[7].showLeds(brillo);delay(t);
     leds[4] = CRGB::Black; FastLED[4].showLeds(brillo);leds[11] = CRGB::Black; FastLED[11].showLeds(brillo);delay(t);
     leds[2] = CRGB::Black; FastLED[2].showLeds(brillo);leds[9] = CRGB::Black; FastLED[9].showLeds(brillo);delay(t);
     leds[3] = CRGB::Black; FastLED[3].showLeds(brillo);leds[10] = CRGB::Black; FastLED[10].showLeds(brillo);delay(t);
    delay(tCerrado);

     leds[3] = CRGB::White; FastLED[3].showLeds(brillo);leds[10] = CRGB::White; FastLED[10].showLeds(brillo);delay(t);
     leds[4] = CRGB::White; FastLED[4].showLeds(brillo);leds[9] = CRGB::White; FastLED[9].showLeds(brillo);delay(t);
     leds[2] = CRGB::White; FastLED[2].showLeds(brillo);leds[11] = CRGB::White; FastLED[11].showLeds(brillo);delay(t);
     leds[0] = CRGB::Blue; FastLED[0].showLeds(brillo);leds[7] = CRGB::Blue; FastLED[7].showLeds(brillo);delay(t);
     leds[5] = CRGB::White; FastLED[5].showLeds(brillo);leds[8] = CRGB::White; FastLED[8].showLeds(brillo);delay(t);
     leds[1] = CRGB::White; FastLED[1].showLeds(brillo);leds[12] = CRGB::White; FastLED[12].showLeds(brillo);delay(t);
     leds[6] = CRGB::White; FastLED[6].showLeds(brillo);leds[13] = CRGB::White; FastLED[13].showLeds(brillo);delay(t);

    delay(tAbierto);
*/
}

void loop() {
	parpadeo(5,3,255,255,255);
}

/*
I2C Slave Receive Callback:
Note that this function is called from an interrupt routine and shouldn't take long to execute
*/
void onI2CReceive(int howMany){
	// loops, until all received bytes are read
	while(TinyWire.available()>0){
		// toggles the led everytime, when an 'a' is received
		if(TinyWire.read()=='a'){
     parpadeo(5,3,0,150,0);
		}
   /*
   switch(TinyWire.read()){
        case 0:
          apagarOjos();
          break;
          
        case 1:
          encenderOjos();          
          break;
    
        case 2:
          guinaOjoDch(250);          
          break;
  
        case 3:
          guinaOjoIzq (250);          
          break;
  
        case 4:
          mirarDerechaArriba();
          
          break;
  
        case 5:
          mirarDerechaAbajo();
          
          break;
  
        case 6:
          mirarIzquierdaArriba();          
          break;
  
        case 7:
          mirarIzquierdaAbajo();          
          break;
  
        case 8:
          noMirar();          
          break;
  
        case 9:
          luzOjos();          
          break;
  
        case 10:          
          getTemp();
          break;
  
        case 11:          
          getHum();
          break;
  
        case 12:          
          checkSensor();
          break;
          
        case 13:          
          getLum(2);
          break;
          
        default:          
          break;
        }*/
		}
   
	}

