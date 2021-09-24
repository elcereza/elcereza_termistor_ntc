/*  -----------------------------------------------------------------------------
    MIT License

    Copyright (c) 2021 Elcereza

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
    -----------------------------------------------------------------------------
    
    Curioso querendo saber como funciona a biblioteca?
    Então veja nosso post: https://elcereza.com/termistor_ntc/
*/

#include "Arduino.h"
#include "Elcereza_Thermistor_NTC.h"

Thermistor_NTC::Thermistor_NTC(int _pin, double _beta = 3600, int _rADC = 1024, double _R2 = 10000, double _Rt = 10000){
    pinMode(_pin, 0);

    pin = _pin;
    beta = _beta;
    rADC = _rADC;
    R2 = _R2;
    Rt = _Rt;

    if(_rADC < 25)
        rADC = pow(2, _rADC);
    else
        rADC = _rADC;
}

double Thermistor_NTC::getTempC(){
    double RawADC = analogRead(pin);
    return beta / log(((R2 * (rADC - RawADC)) / RawADC) / (Rt * exp(-beta/(273.0 + 25.0)))) - 273;
}

double Thermistor_NTC::getTempF(){
    return (getTempC() * 1.8) + 32;
}
