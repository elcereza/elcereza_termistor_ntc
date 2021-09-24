/*-----------------------------------------------------------------------  
  Esquemático da Montagem e Comandos: https://elcereza.com/

  Autor     : Gustavo Cereza
  Site      : https://elcereza.com/
  Canal     : https://t.me/elcereza
  Github    : https://github.com/elcereza
  Instagram : https://instagram.com/ellcereza/

  Quer entender como funciona um Termistor NTC? 
  Acesse: https://elcereza.com/termistor
-----------------------------------------------------------------------*/

#include <Elcereza_Thermistor_NTC.h>

Thermistor_NTC temp(3);                                                // Modo Simples
// Thermistor_NTC temp(3, 3600, 10, 10000, 10000);                     // Modo Avançado

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(String(temp.getTempC()) + "°C");
  Serial.println(String(temp.getTempF()) + "°F");
}
