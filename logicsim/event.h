#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
  bool operator()(const Event* event1, const Event* event2) const {
    if(event1->time < event2->time){ // returns true if event1 time is less than event2 time
      return true;
    }
    else{
      return false;
    }
  }
} EventLess;
	
#endif
