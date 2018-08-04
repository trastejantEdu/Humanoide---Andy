#include <SoftwareSerial.h>
#include <FastLED.h>
#include <Wire.h>
#include "movimientosOculares.h"
#include "accesoSensores.h"


#define LED_PIN     3
#define NUM_LEDS    14
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define t 50 //Tiempo entre acciones 
#define brillo 20
#define direccion 31//Direccion i2c
#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {

  //ARRANQUE DE LAS COMUNICACIONES
  Serial.begin(9600);  
  if(Serial.available()){
    Serial.println("-> Arranque Serial correcto");
  }
  //mySerial.begin(38400);
  //mySerial.listen();

  //Inicializacion de la comunicacion i2C
  Wire.begin(direccion);        // nos unimos al bus i2c bus con la dirección #direccion
  Wire.onReceive(receiveEvent);
  Serial.println("Arranque de I2C");
  /*
  if(mySerial.available()){
    mySerial.println("-> Conexion Raspberry...");
  }else{
    Serial.println("Fallo en el arranque de la conexion con el cerebro");
  }
  */

  //&DRE2@ IMPLEMENTAR COMPROBACIÓN DE LA CONEXION!!!
  
  //ARRANQUE DE LAS LIBRERIAS NEOPIXEL
  Serial.println("Arranque de  las librerias NEOPIXEL");
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );  
  currentPalette = RainbowColors_p;

  //AUTO-TESTIN OJOS
  apagarOjos();
  delay(200);
  encenderOjos();
  delay(200);

  //mySerial.println("READY");
  Serial.print("READY");
  
}

void receiveEvent(int howMany) {

  Serial.print("RX:");
  // Mientras tengamos caracteres en el buffer
  while(Wire.available()>0){
    int c = Wire.read(); // Leemos uno
    Serial.print(c);  // Imprimimos
    Serial.println(gesto(c));
  }
  Serial.println('|'); // Para que veamos por pantalla cuando acaba
}

String gesto(int orden){
   switch(Serial.read()){
        case 0:
          apagarOjos();
          Serial.println("-> Apagar ojos");
          break;
          
        case 1:
          encenderOjos();
          Serial.println("-> Encender ojos");
          break;
    
        case 2:
          guinaOjoDch(250);
          Serial.println("-> Guiñando ojo derecho");
          break;
  
        case 3:
          guinaOjoIzq (250);
          Serial.println("-> Guiñando ojo Izquierdo");
          break;
  
        case 4:
          mirarDerechaArriba();
          Serial.println("-> Mirando arriba");
          break;
  
        case 5:
          mirarDerechaAbajo();
          Serial.println("-> Mirando abajo a la derecha");
          break;
  
        case 6:
          mirarIzquierdaArriba();
          Serial.println("-> Mirando Arriba a la izquierda");
          break;
  
        case 7:
          mirarIzquierdaAbajo();
          Serial.println("-> Mirando abajo a la izquierda");
          break;
  
        case 8:
          noMirar();
          Serial.println("-> Sin mirar");
          break;
  
        case 9:
          luzOjos();
          Serial.println("-> Iluminando ojos");
          break;
  
        case 10:
          Serial.println("-> Consultando temperatura...");
          getTemp();
          break;
  
        case 11:
          Serial.println("->Consultando valor de humedad...");
          getHum();
          break;
  
        case 12:
          Serial.println("Chekeando sensores...");
          checkSensor();
          break;
          
        case 13:
          Serial.println("->Consultando la luminosidad");
          getLum(2);
          break;
          
        default:
          Serial.print(orden);
          break;
        }
      
}

void loop(){
  //CabeceraInicio($)ComandoDeSeleccion(n)Delimitador(%)orden(l)CaracterFinalizacion(#)
  
  delay(250);
  parpadeo(250,5);
  delay(500);
}




