#ifndef ToggleDebug_h
#define ToggleDebug_h

#include "Arduino.h"

#if (DEBUG + 0 == 0)
#define DEBUG 0
#endif

#define TDEBUG_PRINT(inst, x)
#define DEBUG_BEGIN(x)
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define TDebug(name, delay)
#define availableMem(inst) if (0)
#define DEBUG_FLUSH()

#define FILE_NAME (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1: __FILE__)

#ifdef FILE_SHOW_FULL_PATH

#define FILE_NAME __FILE__

#endif

#if (DEBUG == 1) //Standard debug mode

#define TDEBUG_PRINT(inst, x) inst.debugPrint(String(millis()) + ": " + FILE_NAME + " " + __PRETTY_FUNCTION__ + " line:" + __LINE__ + " " + String(x)) //Add useful information to debug message
#define DEBUG_BEGIN(x) Serial.begin(x)
#define DEBUG_PRINT(x) Serial.print(String(x))
#define DEBUG_PRINTLN(x) Serial.println(String(millis()) + ": " + FILE_NAME + " " + __PRETTY_FUNCTION__ + " line:" + __LINE__ + " " + String(x))
#define TDebug(name, delay) ToggleDebug name(delay)
#define availableMem(inst) if(inst.getAvailableMemory(FILE_NAME, __PRETTY_FUNCTION__, __LINE__))
#define DEBUG_FLUSH() Serial.flush()

#elif (DEBUG == 2) //Ram only mode

#define DEBUG_BEGIN(x) Serial.begin(x)
#define TDebug(name, delay) ToggleDebug name(delay)
#define availableMem(inst) if(inst.getAvailableMemory(FILE_NAME, __PRETTY_FUNCTION__, __LINE__))
#define DEBUG_FLUSH() Serial.flush()

#elif (DEBUG == 3) //String only mode

#define TDEBUG_PRINT(inst, x) inst.debugPrint(x)
#define DEBUG_BEGIN(x) Serial.begin(String(x))
#define DEBUG_PRINT(x) Serial.print(String(x))
#define DEBUG_PRINTLN(x) Serial.println(String(x))
#define TDebug(name, delay) ToggleDebug name(delay)
#define availableMem(inst) if(inst.getAvailableMemory(FILE_NAME, __PRETTY_FUNCTION__, __LINE__))
#define DEBUG_FLUSH() Serial.flush()

#endif

class ToggleDebug
{
public:
    ToggleDebug(int delay);
    void debugPrint(String message);
    bool getAvailableMemory(String file, String method, int line);

private:
    unsigned long _timer;
    int _delay;
    int _prevMem;
};
#endif

//Todo: Pass existing method in getAvailableMemory instead of using if statement
