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
    Então veja nosso post: https://elcereza.com/termistor/
*/

#ifndef Elcereza_Thermistor_NTC.h
#define Elcereza_Thermistor_NTC.h

#include "Arduino.h"
#include "math.h"

class Thermistor_NTC 
{
    public:
        Thermistor_NTC(int _pin, double _beta = 3600, int _rADC = 1024, double _R2 = 10000, double _Rt = 10000);
        double getTempC();
        double getTempF();
    private:
        int pin, rADC;
        double beta, Rt, R2;
};

#endif
