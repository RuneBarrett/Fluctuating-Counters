/*
  Counter.h - managing counters for RGB/HSV leds.
  Created by Rune B. Barrett, March 3, 2018.
  Released into the public domain.
*/
#ifndef Counter_h
#define Counter_h

#include "Arduino.h"

class Counter
{
public:
  Counter(int val, int speed, bool up);
  Counter(int val, int speed, bool up, int down, int upLim);
  Counter();
  int getVal();
  void count();
  void setUp(int v, int s);
private:
  int _val;
  int _speed;
  bool _up;
  int _frames;
  int _upLim;
  int _downLim;
};
#endif
