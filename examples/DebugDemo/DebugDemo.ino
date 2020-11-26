/*
#define DEBUG 0  *Debug mode off, none of the debug functions will be compiled.
#define DEBUG 1  *Debug mode. All debug functions are included and useful information like current method, line and millis are printed along with the debug message.
#define DEBUG 2  *Ram only mode. Only the freeRam function is compiled.
#define DEBUG 3  *String only mode. All the debug functions are compiled but will not print any extra information.

#define FILE_SHOW_FULL_PATH * This will show the full file path in stead of the file name.

*Define DEBUG before including the library
*DEBUG will be defined as 0 if not defined by the user

DEBUG_BEGIN()   = Serial.begin()
DEBUG_PRINT()   = Serial.print()
DEBUG_PRINTLN() = Serial.println()
DEBUG_FLUSH()   = Serial.flush()

TDebug(timer, delay)  *Create debug timer instance. This timer is used for non blocking, timed printlns
TDEBUG_PRINT(timer instance, "Message")  *Print timed message every x milliseconds. Will show extra information like current millis, line and method if enabled
availableMem(timer instance, error method (optional))  *Print timed message which shows ammount of RAM left. Calls optional method if change in memory is detected
*/

#define DEBUG 1 //Toggle debug messages by commenting or de-commenting this define
#include <ToggleDebug.h>

TDebug(timedMessage, 3000); //Initialize timed debug message
TDebug(timedMessage2, 200);

TDebug(availableMemTimer, 6000); //Initialize timed debug message for availableMem() method

void setup()
{
    DEBUG_BEGIN(115200);

    DEBUG_PRINTLN("Println");
    DEBUG_PRINT("Print");
}

void loop()
{
    TDEBUG_PRINT(timedMessage, "This is a non blocking, timed and toggleable debug message");
    TDEBUG_PRINT(timedMessage2, ":)");

    availableMem(availableMemTimer, errorMethod()) //Prints ammount of unused RAM between the stack and heap. Useful for finding memory leaks.
}                                                  //Optional method can be passed that will fire when a memory error is detected. 

void errorMethod()
{
    DEBUG_PRINTLN("Prints if memory error is detected by availableMem method");
}