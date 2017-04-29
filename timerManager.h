/*
	timerManager.h - A singleton that holds all the Timer instances. It's used to
  update all timers at once

  Link - https://github.com/brunocalou/Timer

	Created by Bruno Calou Alves, Apr, 2017.
	Read LICENSE for more information.
*/

#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef NULL
#define NULL 0
#endif

#include "timer.h"

class TimerManager {
  friend class Timer;

public:
  static TimerManager& instance();

  /**
     Updates all the timers
   */
  void update();

  /*
		Starts all the timers
	*/
	void start();

	/*
		Stops and resets the all timers
	*/
	void stop();

	/*
		Pauses all the timers
	*/
	void pause();

	/*
		Resets all the timers. WARNING: The timers will not stop,
		the only thing that changes is the initial time
	*/
	void reset();

private:
  TimerManager();
  TimerManager(TimerManager const &);
  void operator=(TimerManager const &);

  /**
     Adds a timer to the TimerManager
   */
  void add(Timer *timer);

  /**
     Removes a timer from the TimerManager
     @return True if the timer was removed, false otherwise
   */
  bool remove(Timer *timer);

  class TimerNode {
  public:
    TimerNode(Timer *timer) {
      next = NULL;
      value = timer;
    }
    TimerNode *next;
    Timer *value;
  };

  TimerNode *first;
  TimerNode *last;
};
#endif //TIMERMANAGER_H
