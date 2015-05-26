# Timer
Arduino timer library. It supports callbacks with functions and methods, so it can be used inside another library

------------------------
##Installation
1. [Download](https://github.com/brunocalou/Timer/archive/master.zip) the latest release from github
2. Unzip and rename the folder to "Timer" (remove the -master)
3. Paste the modified folder on your Library folder (.../arduino/libraries)
4. Reopen the Arduino IDE

------------------------

##Library Reference

###`Timer` class

*  `Timer()` - Constructor

*  `void start()` - Starts the timer

*  `void stop()` - Pauses the timer. It can continue where it paused after calling start method

*  `void pause()` - Resets the timer. WARNING: The timer will not stop, the only thing that changes is the initial time

*  `unsigned long getElapsedTime()` - Returns the elapsed time in milliseconds

*  `void setInterval(unsigned long interval, unsigned int repeat_count=-1)` - Sets the interval time. The callback function will be called every "interval" ms. The repeat count will prevent the callback from being called after a number of repetetions (if it's > 0). WARNING: The timer will stop after that (if repeat count > 0)

*  `void setTimeout(unsigned long timeout)` - Sets the timeout time. The callback function will be called just once. WARNING: The timer will stop after that

*  `void clearInterval()` - Removes the interval, so the timer can be used as a normal timer

*  `void setCallback(void (*function)(void))` - Sets the callback function

*  `void update()` - Updates the timer. It must be called in a loop in order to make it work

*  `bool isPaused()` - Check if the timer is paused

*  `bool isStopped()` - Check if the timer is stopped

*  `bool isRunning()` - Check if the timer is running

*  **protected** `virtual void call()` - Calls the callback function

*  **private** `unsigned long initial_time` - Stores the start time

*  **private** `unsigned long current_time` - Stores the current time

*  **private** `bool is_running` - Stores if the timer is running

*  **private** `bool is_paused` - Stores if the timer is paused

*  **private** `unsigned long interval` - Stores the interval, if setted

*  **private** `unsigned long last_interval_time` - Stores the last time the callback was called

*  **private** `unsigned int repeat_count` - Stores the number of times remaining to call the callback function

*  **private** `unsigned int total_repeat_count` - Stores the number of times to call the callback function

*  **private** `bool interval_is_setted` - Stores if the interval was setted

*  **private** `void (*function_callback)(void)` - Stores the callback function

###`TimerForMethods` class

*  `TimerForMethods(Obj *object, void (Obj::*callback)(void))` - Constructor

*  `virtual void call()` - Calls the callback method

*  **private** `Obj *object` - Stores the object to be used

*  **private** `void (Obj::*method)(void)` - Stores the method to be called
