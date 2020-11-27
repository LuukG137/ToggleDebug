#ifndef ToggleDebug_h
#define ToggleDebug_h

#include "Arduino.h"

#if (DEBUG + 0 == 0)
#define DEBUG 0
#endif

#define FILE_NAME (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1: __FILE__)

#ifdef FILE_SHOW_FULL_PATH

#define FILE_NAME __FILE__

#endif

#define GETMEM(inst, errfunc, infoMode, ...) if(inst.getAvailableMemory(FILE_NAME, __PRETTY_FUNCTION__, __LINE__, infoMode)) { errfunc; }
#define DEFAULT ; //Default second argument for availableMem()
#define SHOW_INFO true
#define EXTRA_INFO String(millis()) + ": " + FILE_NAME + " " + __PRETTY_FUNCTION__ + " line:" + __LINE__ + " "

//Standard debug mode 1
#define TDEBUG_PRINT(inst, x) inst.debugPrint(EXTRA_INFO + String(x)) //Add useful information to debug message
#define DEBUG_BEGIN(x) Serial.begin(x)
#define DEBUG_PRINT(x) Serial.print(String(x))
#define DEBUG_PRINTLN(x) Serial.println(EXTRA_INFO + String(x))
#define TDebug(inst, delay) ToggleDebug inst(delay)
#define availableMem(...) GETMEM(__VA_ARGS__, SHOW_INFO, ,##__VA_ARGS__ DEFAULT)
#define DEBUG_FLUSH() Serial.flush()

#if defined(HIDE_EXTRA_INFO) //String only mode

#define SHOW_INFO false
#define EXTRA_INFO ""

#endif

#if (DEBUG == 0) //No debugging, nothing will be compiled

#define TDEBUG_PRINT(inst, x)
#define DEBUG_BEGIN(x)
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define TDebug(inst, delay)
#define availableMem(...)
#define DEBUG_FLUSH()

#elif (DEBUG == 2) //Ram only mode

#define TDEBUG_PRINT(inst, x)
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)

#endif

class ToggleDebug
{
public:
    ToggleDebug(int delay);
    void debugPrint(String message);
    bool getAvailableMemory(String file, String method, int line, bool extraInfo);

private:
    unsigned long _timer;
    int _delay;
    int _prevMem;
};
#endif
