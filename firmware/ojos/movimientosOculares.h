#include <FastLED.h>

/***
 * 
 *   
 *

 _   _                   
| \ | |                  
|  \| | __ _ _ __   ___  
| . ` |/ _` | '_ \ / _ \ 
| |\  | (_| | | | | (_) |
\_| \_/\__,_|_| |_|\___/ 
------------------------
------------------------
www.trastejant.es

Funciones disponibles: 
  1.parpadeo [parpadeo [int tAbierto, int tCerrado)]
  2.Giñar ojo derecho [guinaOjoIzq (int duracion)]
  3.Guiñar ojo Izquierdo[guinaOjoIzq (int duracion)]
  4.Apagar ojos [apagarOjos()]
  5.Encender ojos [encenderOjos()]
  6.Mirar Arriba a la derecha [mirarDerechaArriba()]
  7.Mirar Derecha Abajo[mirarDerechaAbajo()]
  8.Mirar Izquierda [mirarIzquierdaArriba()]
  9.Mirar izquierda Abajo [mirarIzquierdaAbajo()]
  10. No mirar [noMirar()]
  11. Iliminar los ojos [luzOjos()]
*/



#define LED_PIN     3
#define NUM_LEDS    14
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define t 50 //Tiempo entre acciones 
#define brillo 20

CRGB leds[NUM_LEDS];


void parpadeo (int tAbierto, int tCerrado){


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

}

void guinaOjoDch (int duracion){

    leds[6] = CRGB::Black; FastLED.show();delay(250);
    leds[5] = CRGB::Black; FastLED.show();
    leds[1] = CRGB::Black; FastLED.show();delay(250);
    leds[0] = CRGB::Black; FastLED.show();delay(250);
    leds[4] = CRGB::Black; FastLED.show(); 
    leds[2] = CRGB::Black; FastLED.show();delay(250);
    leds[3] = CRGB::Black; FastLED.show();delay(250);
    delay(duracion);
    
    leds[3] = CRGB::White; FastLED.show();delay(250);
    leds[4] = CRGB::White; FastLED.show(); 
    leds[2] = CRGB::White; FastLED.show();delay(250);
    leds[0] = CRGB::Blue; FastLED.show(); delay(250);
    leds[5] = CRGB::White; FastLED.show(); 
    leds[1] = CRGB::White; FastLED.show(); delay(250);
    leds[6] = CRGB::White; FastLED.show(); delay(250);
    delay(duracion);  


}

void guinaOjoIzq (int duracion){

    leds[13] = CRGB::Black; FastLED.show();delay(250);
    leds[12] = CRGB::Black; FastLED.show();
    leds[8] = CRGB::Black; FastLED.show();delay(250);
    leds[7] = CRGB::Black; FastLED.show();delay(250);
    leds[11] = CRGB::Black; FastLED.show(); 
    leds[9] = CRGB::Black; FastLED.show();delay(250);
    leds[10] = CRGB::Black; FastLED.show();delay(250);
    delay(duracion);
    
    leds[10] = CRGB::White; FastLED.show();delay(250);
    leds[9] = CRGB::White; FastLED.show(); 
    leds[11] = CRGB::White; FastLED.show();delay(250);
    leds[7] = CRGB::Blue; FastLED.show(); delay(250);
    leds[8] = CRGB::White; FastLED.show(); 
    leds[12] = CRGB::White; FastLED.show(); delay(250);
    leds[13] = CRGB::White; FastLED.show(); delay(250);
    delay(duracion);  


}

void apagarOjos(){
 for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black; FastLED.show();    
  }
}

void luzOjos(){
 FastLED.setBrightness(20);
 for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red; FastLED.show();    
    delay(50);
  }
}

void encenderOjos(){
  //Ojo derecho
  leds[0] = CRGB::Blue; FastLED.show(); //iris
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::Blue; FastLED.show(); 
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);

}

void mirarDerechaArriba(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); //iris
  leds[1] = CRGB::Blue; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); 
  leds[8] = CRGB::Blue; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}

void mirarDerechaAbajo(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); 
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::Blue; FastLED.show();  //iris
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); 
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::Blue; FastLED.show(); //iris
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}

void mirarArriba(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); 
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::Blue; FastLED.show();  //iris
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); 
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::Blue; FastLED.show(); //iris
  delay(500);
  
}

void mirarAbajo(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); 
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::Blue; FastLED.show();  //iris
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); 
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::Blue; FastLED.show();  //iris
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}

void mirarIzquierdaArriba(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); //iris
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::Blue; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); //iris
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::Blue; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}

void mirarIzquierdaAbajo(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); //iris
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::Blue; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); //iris
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::Blue; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}

void noMirar(){

    //Ojo derecho
  leds[0] = CRGB::White; FastLED.show(); //iris
  leds[1] = CRGB::White; FastLED.show(); 
  leds[2] = CRGB::White; FastLED.show();  
  leds[3] = CRGB::White; FastLED.show();  
  leds[4] = CRGB::White; FastLED.show();  
  leds[5] = CRGB::White; FastLED.show();  
  leds[6] = CRGB::White; FastLED.show();  
  
  //Ojo izquierdo
  leds[7] = CRGB::White; FastLED.show(); //iris
  leds[8] = CRGB::White; FastLED.show();  
  leds[9] = CRGB::White; FastLED.show(); 
  leds[10] = CRGB::White; FastLED.show();  
  leds[11] = CRGB::White; FastLED.show();  
  leds[12] = CRGB::White; FastLED.show();  
  leds[13] = CRGB::White; FastLED.show(); 
  delay(500);
  
}
