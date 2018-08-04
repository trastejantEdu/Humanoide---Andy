/***
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

1.Devolver temperatura en grados celsius[floatgetTemp()]
2.Devolver humedad en porcentaje [float getHum()]
3.Comprobarfuncionamiento de los sensores [boolean checkSensor()]
4.Devolver luz en porcentaje [int getLum()]
                         


 */

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

float getTemp(){
  float temp = dht.readTemperature();
  return temp;  
  }

float getHum(){
  float h = dht.readHumidity();
  return h;
  }

boolean checkSensor(){
  float h = dht.readHumidity();
  float temp = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    return false;   
  }else{return true;}
 
 }

 int getLum(int _pin){
  int lum = analogRead(_pin);
  int lumPerCent = map(lum, 0,1024,0,100);
  return lumPerCent;
  
  }
