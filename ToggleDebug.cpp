#include "ToggleDebug.h"

ToggleDebug::ToggleDebug(int delay)
{
    _delay = delay; //Initialize debugPrint delay
}

void ToggleDebug::debugPrint(String message) //Print debug message every x milliseconds
{
    if (millis() - _timer >= _delay)
    {
        _timer = millis();
        Serial.println(message);
        Serial.println();
    }
}

bool ToggleDebug::getMemory(String file, String method, int line)
{
    bool error = false;
    if (millis() - _timer >= _delay)
    {
        _timer = millis();
        extern int __heap_start, *__brkval;
        int v;
        int freeMemory = (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);

        if (_prevMem != freeMemory && _prevMem > 0)
        {
            Serial.println("Memory changed!");
            Serial.println("Previous free memory was " + String(_prevMem));
            error = true;
        }

        Serial.println(String(millis()) + ": " + file + " " + method + " line:" + line +  " Memory free: " + String(freeMemory) + " bytes");
        Serial.flush();

        _prevMem = freeMemory;
    }
    return error;
}
