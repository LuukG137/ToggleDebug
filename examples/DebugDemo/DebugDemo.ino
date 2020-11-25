/*
#define DEBUG 0  *Debug mode off, none of the debug functions will be compiled.
#define DEBUG 1  *Debug mode. All debug functions are included and useful information like current method, line and millis are printed along with the debug message.
#define DEBUG 2  *Ram only mode. Only the freeRam function is compiled.
#define DEBUG 3  *String only mode. All the debug functions are compiled but will not print any extra information.

*Define DEBUG before including the library
*DEBUG will be defined as 0 if not defined by the user

DEBUG_BEGIN()   = Serial.begin()
DEBUG_PRINT()   = Serial.print()
DEBUG_PRINTLN() = Serial.println()
DEBUG_FLUSH()   = Serial.flush()

TDebug(timer, delay)  *Create debug timer instance. This timer is used for non blocking, timed printlns
TDEBUG_PRINT(timer, "Message")  *Print timed message every x milliseconds. Will show extra information like current millis, line and method if enabled
freeRam(timer)  *Print timed message which shows ammount of RAM left. //Returns true if memory leak has been detected
*/

#define DEBUG 1 //Toggle debug messages by commenting or de-commenting this define
#include <ToggleDebug.h>

TDebug(timedMessage, 3000); //Initialize timed debug message
TDebug(timedMessage2, 200);

TDebug(freeRamTimer, 6000); //Initialize timed debug message for freeRam() method

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

    freeRam(freeRamTimer) //Prints ammount of RAM left. Useful for finding memory leaks
    {
        DEBUG_PRINTLN("This message is printed if a memory change is detected");
    }
}
